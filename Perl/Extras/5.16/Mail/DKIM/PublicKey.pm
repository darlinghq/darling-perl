#!/usr/bin/perl

# Copyright 2005 Messiah College. All rights reserved.
# Jason Long <jlong@messiah.edu>

# Copyright (c) 2004 Anthony D. Urso. All rights reserved.
# This program is free software; you can redistribute it and/or
# modify it under the same terms as Perl itself.

use strict;
use warnings;

package Mail::DKIM::PublicKey;

use base ("Mail::DKIM::KeyValueList", "Mail::DKIM::Key");
*calculate_EM = \&Mail::DKIM::Key::calculate_EM;

use Mail::DKIM::DNS;

sub new {
	my $type = shift;
	my %prms = @_;

	my $self = {};

	$self->{'GRAN'} = $prms{'Granularity'};
	$self->{'NOTE'} = $prms{'Note'};
	$self->{'TEST'} = $prms{'Testing'};
	$self->{'TYPE'} = ($prms{'Type'} or "rsa");
	$self->{'DATA'} = $prms{'Data'};

	bless $self, $type;
}

=head1 CONSTRUCTOR

=head2 fetch() - retrieve a public key record from DNS

  my $public_key = Mail::DKIM::PublicKey->fetch(
                      Protocol => "dns",
                      Selector => "brisbane",
                      Domain => "example.com",
                    );

If the public key is found, a L<Mail::DKIM::PublicKey> object
is returned, representing the information found in DNS.
If the public key does not exist in DNS, then C<undef> is
returned.
If a DNS error occurs while fetching the key, then this method
will C<die>.
If the public key was found, but is not valid (e.g. it is "revoked"),
then this method will C<die>.

=cut

sub fetch
{
	my $class = shift;
	my $waiter = $class->fetch_async(@_);
	my $self = $waiter->();
	return $self;
}

#EXPERIMENTAL1
# my $x = Mail::DKIM::PublicKey->fetch_async(
#                     Protocol => "dns",
#                     etc.,
#                   );
# my $public_key = $x->();

#EXPERIMENTAL2
# my ($pubk, $E);
# my $x = Mail::DKIM::PublicKey->fetch_async(
#                     Protocol => "dns",
#                     etc.,
#                     Callbacks => { },
#                   );
# return $x->();

sub fetch_async
{
	my $class = shift;
	my %prms = @_;

	my ($query_type, $query_options) = split(/\//, $prms{Protocol}, 2);
	if (lc($query_type) ne "dns")
	{
		die "unknown query type '$query_type'\n";
	}

	my $host = $prms{Selector} . "._domainkey." . $prms{Domain};
	my %callbacks = %{$prms{Callbacks} || {}};
	my $on_success = $callbacks{Success} || sub { $_[0] };
	$callbacks{Success} = sub {
			my @resp = @_;
			unless (@resp)
			{
				# no response => NXDOMAIN
				return $on_success->();
			}

			my $strn;
			foreach my $ans (@resp) {
				next unless $ans->type eq "TXT";
				$strn = join "", $ans->char_str_list;
				last;
			}

			$strn or
				return $on_success->();

			my $self = $class->parse($strn);
			$self->{Selector} = $prms{'Selector'};
			$self->{Domain} = $prms{'Domain'};
			$self->check;
			return $on_success->($self);
		};

	#
	# perform DNS query for public key...
	#
	my $waiter = Mail::DKIM::DNS::query_async(
			$host, "TXT",
			Callbacks => \%callbacks,
			);
	return $waiter;
}

=head1 METHODS

=cut

# check syntax of the public key
# throw an error if any errors are detected
sub check
{
	my $self = shift;

	# check public key version tag
	if (my $v = $self->get_tag("v"))
	{
		unless ($v eq "DKIM1")
		{
			die "unsupported version\n";
		}
	}

	# check public key granularity
	my $g = $self->granularity;

	# check key type
	if (my $k = $self->get_tag("k"))
	{
		unless ($k eq "rsa")
		{
			die "unsupported key type\n";
		}
	}

	# check public-key data
	my $p = $self->data;
	if (not defined $p)
	{
		die "missing p= tag\n";
	}
	if ($p eq "")
	{
		die "revoked\n";
	}
	unless ($p =~ /^[A-Za-z0-9\+\/\=]+$/)
	{
		die "invalid data\n";
	}

	# have OpenSSL load the key
	eval
	{
		$self->cork;
	};
	if ($@)
	{
		# see also finish_body
		chomp (my $E = $@);
		if ($E =~ /(OpenSSL error: .*?) at /)
		{
			$E = "$1";
		}
		elsif ($E =~ /^(panic:.*?) at /)
		{
			$E = "OpenSSL $1";
		}
		die "$E\n";
	}

	# check service type
	if (my $s = $self->get_tag("s"))
	{
		my @list = split(/:/, $s);
		unless (grep { $_ eq "*" || $_ eq "email" } @list)
		{
			die "does not support email\n";
		}
	}

	return 1;
}

# check_granularity() - check whether this key matches signature identity
# 
# a public key record can restrict what identities it may sign with,
#   g=, granularity, restricts the local part of the identity
#   t=s, restricts whether subdomains can be used
#
# This method returns true if the given identity is allowed by this
# public key; it returns false otherwise.
# If false is returned, you can check C<$@> for an explanation of
# why.
#
sub check_granularity
{
	my $self = shift;
	my ($identity, $empty_g_means_wildcard) = @_;

	# check granularity
	my $g = $self->granularity;

	# yuck- what is this $empty_g_means_wildcard parameter?
	# well, it turns out that with DomainKeys signatures,
	# an empty g= is the same as g=*
	if ($g eq "" && $empty_g_means_wildcard)
	{
		$g = "*";
	}

	# split i= value into a "local part" and a "domain part"
	my ($local_part, $domain_part);
	if ($identity =~ /^(.*)\@([^@]*)$/)
	{
		$local_part = $1;
		$domain_part = $2;
	}
	else
	{
		$local_part = "";
		$domain_part = $identity;
	}


	my ($begins, $ends) = split /\*/, $g, 2;
	if (defined $ends)
	{
		# the g= tag contains an asterisk

		# the local part must be at least as long as the pattern
		if (length($local_part) < length($begins) + length($ends)
			or
		# the local part must begin with $begins
			substr($local_part, 0, length($begins)) ne $begins
			or
		# the local part must end with $ends
			(length($ends) && substr($local_part, -length($ends)) ne $ends))
		{
			$@ = "granularity mismatch\n";
			return;
		}
	}
	else
	{
		if ($g eq "")
		{
			$@ = "granularity is empty\n";
			return;
		}
		unless ($local_part eq $begins)
		{
			$@ = "granularity mismatch\n";
			return;
		}
	}

	# check subdomains
	if ($self->subdomain_flag)
	{
		unless ($domain_part eq lc($self->{'Domain'}))
		{
			$@ = "does not support signing subdomains\n";
			return;
		}
	}

	return 1;
}

# returns true if the actual hash algorithm used is listed by this
# public key; dies otherwise
#
sub check_hash_algorithm
{
	my $self = shift;
	my ($hash_algorithm) = @_;

	# check hash algorithm
	if (my $h = $self->get_tag("h"))
	{
		my @list = split(/:/, $h);
		unless (grep { $_ eq $hash_algorithm } @list)
		{
			die "does not support hash algorithm '$hash_algorithm'\n";
		}
	}
	return 1;
}

# Create an OpenSSL public key object from the Base64-encoded data
# found in this public key's DNS record. The OpenSSL object is saved
# in the "cork" property.
sub convert
{
	use Crypt::OpenSSL::RSA;

	my $self = shift;


	$self->data or
		return;

	# have to PKCS1ify the pubkey because openssl is too finicky...
	my $cert = "-----BEGIN PUBLIC KEY-----\n";

	for (my $i = 0; $i < length $self->data; $i += 64) {
		$cert .= substr $self->data, $i, 64;
		$cert .= "\n";
	}	

	$cert .= "-----END PUBLIC KEY-----\n";

	my $cork = Crypt::OpenSSL::RSA->new_public_key($cert)
		or die "unable to generate public key object";

	# segfaults on my machine
#	$cork->check_key or
#		return;

	$self->cork($cork);

	return 1;
}

sub verify {
	my $self = shift;
	my %prms = @_;


	my $rtrn;

	eval {
		$rtrn = $self->cork->verify($prms{'Text'}, $prms{'Signature'});
	}; 

	$@ and
		$self->errorstr($@),
		return;
	
	return $rtrn;
}

=head2 granularity() - get or set the granularity (g=) field

  my $g = $public_key->granularity;

  $public_key->granularity("*");

Granularity of the key. The value must match the Local-part of the
effective "i=" tag of the DKIM-Signature header field.
The granularity is a literal value, or a pattern with a single '*'
wildcard character that matches zero or more characters.

If no granularity is defined, then the default value, '*', will
be returned.

=cut

sub granularity
{
	my $self = shift;

	# set new granularity if provided
	(@_) and 
		$self->set_tag("g", shift);

	my $g = $self->get_tag("g");
	if (defined $g)
	{
		return $g;
	}
	else
	{
		return '*';
	}
}

sub notes
{
	my $self = shift;

	(@_) and 
		$self->set_tag("n", shift);

	return $self->get_tag("n");
}

sub data
{
	my $self = shift;

	(@_) and 
		$self->set_tag("p", shift);

	my $p = $self->get_tag("p");
	# remove whitespace (actually only LWSP is allowed)
	$p =~ tr/\015\012 \t//d  if defined $p;
	return $p;
}

sub flags
{
	my $self = shift;

	(@_) and 
		$self->set_tag("t", shift);

	return $self->get_tag("t") || "";
}

# subdomain_flag() - checks whether "s" is specified in flags
#
# returns true if "s" is found, false otherwise
#
sub subdomain_flag
{
	my $self = shift;
	my @flags = split /:/, $self->flags;
	return grep { $_ eq "s" } @flags;
}

sub revoked
{
	my $self = shift;

	$self->data or
		return 1;

	return;
}

sub testing
{
	my $self = shift;

	my $flags = $self->flags;
	my @flaglist = split(/:/, $flags);
	if (grep { $_ eq "y" } @flaglist)
	{
		return 1;
	}
	return undef;
}

sub verify_sha1_digest
{
	my $self = shift;
	my ($digest, $signature) = @_;
	return $self->verify_digest("SHA-1", $digest, $signature);
}

# verify_digest() - returns true if the digest verifies, false otherwise
#
# if false, $@ is set to a description of the problem
#
sub verify_digest
{
	my $self = shift;
	my ($digest_algorithm, $digest, $signature) = @_;

	my $rsa_pub = $self->cork;
	if (!$rsa_pub) {
		$@ = $@ ne '' ? "RSA failed: $@" : "RSA unknown problem";
		$@ .= ", s=$self->{Selector} d=$self->{Domain}";
		return;
	}

	$rsa_pub->use_no_padding;
	my $verify_result = $rsa_pub->encrypt($signature);

	my $k = $rsa_pub->size;
	my $expected = calculate_EM($digest_algorithm, $digest, $k);
	return 1 if ($verify_result eq $expected);

	# well, the RSA verification failed; I wonder if the RSA signing
	# was performed on a different digest value? I think we can check...

	# basically, if the $verify_result has the same prefix as $expected,
	# then only the digest was different

	my $digest_len = length $digest;
	my $prefix_len = length($expected) - $digest_len;
	if (substr($verify_result, 0, $prefix_len)
		eq substr($expected, 0, $prefix_len))
	{
		$@ = "message has been altered";
		return;
	}

	$@ = "bad RSA signature";
	return;
}

1;
