#!/usr/bin/perl

# Copyright 2005-2006 Messiah College. All rights reserved.
# Jason Long <jlong@messiah.edu>

# Copyright (c) 2004 Anthony D. Urso. All rights reserved.
# This program is free software; you can redistribute it and/or
# modify it under the same terms as Perl itself.

use strict;
use warnings;

use Mail::DKIM::PublicKey;
use Mail::DKIM::Algorithm::dk_rsa_sha1;

package Mail::DKIM::DkSignature;
use base "Mail::DKIM::Signature";
use Carp;

=head1 NAME

Mail::DKIM::DkSignature - represents a DomainKeys-Signature header

=head1 CONSTRUCTORS

=head2 new()

Create a new DomainKey signature from parameters

  my $signature = Mail::DKIM::DkSignature->new(
                      [ Algorithm => "rsa-sha1", ]
                      [ Signature => $base64, ]
                      [ Method => "simple", ]
                      [ Domain => "example.org", ]
                      [ Headers => "from:subject:date:message-id", ]
                      [ Query => "dns", ]
                      [ Selector => "alpha", ]
                      [ Key => $private_key, ]
                  );

=cut

sub new {
	my $type = shift;
	my %prms = @_;
	my $self = {};
	bless $self, $type;

	$self->algorithm($prms{'Algorithm'} || "rsa-sha1");
	$self->signature($prms{'Signature'});
	$self->canonicalization($prms{'Method'} || "simple");
	$self->domain($prms{'Domain'});
	$self->headerlist($prms{'Headers'});
	$self->protocol($prms{'Query'} || "dns");
	$self->selector($prms{'Selector'});
	$self->key($prms{'Key'}) if defined $prms{'Key'};

	return $self;
}

=head2 parse()

Create a new signature from a DomainKey-Signature header

  my $sig = Mail::DKIM::DkSignature->parse(
                  "DomainKey-Signature: a=rsa-sha1; b=yluiJ7+0=; c=nofws"
            );

Constructs a signature by parsing the provided DomainKey-Signature header
content. You do not have to include the header name
(i.e. "DomainKey-Signature:")
but it is recommended, so the header name can be preserved and returned
the same way in L</"as_string()">.

Note: The input to this constructor is in the same format as the output
of the as_string method.

=cut

sub parse
{
	my $class = shift;
	croak "wrong number of arguments" unless (@_ == 1);
	my ($string) = @_;

	# remove line terminator, if present
	$string =~ s/\015\012\z//;

	# remove field name, if present
	my $prefix;
	if ($string =~ /^(domainkey-signature:)(.*)/si)
	{
		# save the field name (capitalization), so that it can be
		# restored later
		$prefix = $1;
		$string = $2;
	}

	my $self = $class->Mail::DKIM::KeyValueList::parse($string);
	$self->{prefix} = $prefix;

	return $self;
}


=head1 METHODS

=cut

=head2 as_string()

Convert the signature header as a string.

  print $signature->as_string . "\n";

outputs

  DomainKey-Signature: a=rsa-sha1; b=yluiJ7+0=; c=nofws

As shown in the example, the as_string method can be used to generate
the DomainKey-Signature that gets prepended to a signed message.

=cut

sub as_string_without_data
{
	croak "as_string_without_data not implemented";
}

sub body_count
{
	croak "body_count not implemented";
}

sub body_hash
{
	croak "body_hash not implemented";
}

=head2 algorithm()

Get or set the algorithm (a=) field

The algorithm used to generate the signature.
Defaults to "rsa-sha1", an RSA-signed SHA-1 digest.

=cut

sub algorithm
{
	my $self = shift;

	if (@_)
	{
		$self->set_tag("a", shift);
	}

	my $a = $self->get_tag("a");
	return defined $a && $a ne '' ? lc $a : 'rsa-sha1';
}	

=head2 canonicalization()

Get or set the canonicalization (c=) field.

  $signature->canonicalization("nofws");
  $signature->canonicalization("simple");

  $method = $signature->canonicalization;

Message canonicalization (default is "simple"). This informs the
verifier of the type of canonicalization used to prepare the message for
signing.

=cut

sub canonicalization
{
	my $self = shift;
	croak "too many arguments" if (@_ > 1);

	if (@_)
	{
		$self->set_tag("c", shift);
	}

	return lc($self->get_tag("c")) || "simple";
}	

sub DEFAULT_PREFIX
{
	return "DomainKey-Signature:";
}

=head2 domain()

Get or set the domain (d=) field.

  my $d = $signature->domain;          # gets the domain value
  $signature->domain("example.org");   # sets the domain value

The domain of the signing entity, as specified in the signature.
This is the domain that will be queried for the public key.

=cut

sub domain
{
	my $self = shift;

	if (@_)
	{
		$self->set_tag("d", shift);
	}

	my $d = $self->get_tag("d");
	return defined $d ? lc $d : undef;
}	

sub expiration
{
	my $self = shift;
	croak "cannot change expiration on " . ref($self) if @_;
	return undef;
}

use MIME::Base64;

sub check_canonicalization
{
	my $self = shift;

	my $c = $self->canonicalization;

	my @known = ("nofws", "simple");
	return unless (grep { $_ eq $c } @known);
	return 1;
}

# checks whether the protocol found on this subject is valid for
# fetching the public key
# returns a true value if protocol is "dns", false otherwise
#
sub check_protocol
{
	my $self = shift;

	my $protocol = $self->protocol;
	return unless $protocol;
	return ($protocol eq "dns");
}

sub check_version
{
	#DomainKeys doesn't have a v= tag
	return 1;
}

sub get_algorithm_class
{
	my $self = shift;
	croak "wrong number of arguments" unless (@_ == 1);
	my ($algorithm) = @_;

	my $class =
		$algorithm eq "rsa-sha1" ? "Mail::DKIM::Algorithm::dk_rsa_sha1" :
		undef;
	return $class;
}

# get_public_key - same as parent class

sub hash_algorithm
{
	my $self = shift;
	my $algorithm = $self->algorithm;

	return $algorithm eq "rsa-sha1" ? "sha1" : undef;
}

=head2 headerlist()

Get or set the signed header fields (h=) field.

  $signature->headerlist("a:b:c");

  my $headerlist = $signature->headerlist;

  my @headers = $signature->headerlist;

Signed header fields. A colon-separated list of header field names
that identify the header fields presented to the signing algorithm.

In scalar context, the list of header field names will be returned
as a single string, with the names joined together with colons.
In list context, the header field names will be returned as a list.

=cut

#sub headerlist
# is in Signature.pm

=head2 identity()

Get the signing identity.

  my $i = $signature->identity;

In DomainKey signatures, the signing identity is the first address
found in the Sender header or the From header. This field is
populated by the L<Verifier|Mail::DKIM::Verifier> when processing a DomainKey signature.

=cut

sub identity
{
	my $self = shift;
	croak "cannot change identity on " . ref($self) if @_;
	return $self->{dk_identity};
}

=head2 identity_source()

Determine which header had the identity.

  my $source = $signature->identity_source;

If the message is being verified, this method will tell you which
of the message headers was used to determine the signature identity.
Possible values are "header.sender" and "header.from".

=cut

sub identity_source
{
	my $self = shift;
	croak "unexpected argument" if @_;
	return $self->{dk_identity_source};
}

# init_identity() - initialize the DomainKeys concept of identity
#
# The signing identity of a DomainKeys signature is the sender
# of the message itself, i.e. the address in the Sender/From header.
# The sender may not be known when the signature object is
# constructed (since the signature usually precedes the From/Sender
# header), so use this method when you have the From/Sender value.
# See also finish_header() in Mail::DKIM::Verifier.
#
sub init_identity
{
	my $self = shift;
	$self->{dk_identity} = shift;
	$self->{dk_identity_source} = shift;
}

sub method
{
	croak "method not implemented (use canonicalization instead)";
}	

=head2 protocol()

Get or set the query methods (q=) field.

A colon-separated list of query methods used to retrieve the public
key (default is "dns").

=cut

sub protocol {
	my $self = shift;

	(@_) and
		$self->set_tag("q", shift);

	# although draft-delany-domainkeys-base-06 does mandate presence of a
	# q=dns tag, it is quote common that q tag is missing - be merciful
	return !defined($self->get_tag("q")) ? 'dns' : $self->get_tag("q");
}	

=head2 selector()

Get or set the selector (s=) field.

The selector subdivides the namespace for the "d=" (domain) tag.

=cut

# same as parent class

=head2 signature()

Get or set the signature data (b=) field.

The signature data. Whitespace is automatically stripped from the
returned value.

=cut

# same as parent class

sub timestamp
{
	croak "timestamp not implemented";
}

sub version
{
	croak "version not implemented";
}

=head1 SEE ALSO

L<Mail::DKIM::Signature> for DKIM-Signature headers

=head1 AUTHOR

Jason Long, E<lt>jlong@messiah.eduE<gt>

=head1 COPYRIGHT AND LICENSE

Copyright (C) 2006-2007,2010 by Messiah College

This library is free software; you can redistribute it and/or modify
it under the same terms as Perl itself, either Perl version 5.8.6 or,
at your option, any later version of Perl 5 you may have available.

=cut

1;
