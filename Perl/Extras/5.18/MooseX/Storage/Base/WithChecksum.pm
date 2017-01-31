package MooseX::Storage::Base::WithChecksum;
{
  $MooseX::Storage::Base::WithChecksum::VERSION = '0.45';
}
BEGIN {
  $MooseX::Storage::Base::WithChecksum::AUTHORITY = 'cpan:STEVAN';
}
# ABSTRACT: A more secure serialization role
use Moose::Role;

with 'MooseX::Storage::Basic';

use Digest       ();
use Data::Dumper ();

our $DIGEST_MARKER = '__DIGEST__';

around pack => sub {
    my $orig = shift;
    my $self = shift;
    my @args = @_;

    my $collapsed = $self->$orig( @args );

    $collapsed->{$DIGEST_MARKER} = $self->_digest_packed($collapsed, @args);

    return $collapsed;
};

around unpack  => sub {
    my ($orig, $class, $data, @args) = @_;

    # check checksum on data
    my $old_checksum = delete $data->{$DIGEST_MARKER};

    my $checksum = $class->_digest_packed($data, @args);

    ($checksum eq $old_checksum)
        || confess "Bad Checksum got=($checksum) expected=($old_checksum)";

    $class->$orig( $data, @args );
};


sub _digest_packed {
    my ( $self, $collapsed, @args ) = @_;

    my $d = $self->_digest_object(@args);

    {
        local $Data::Dumper::Indent   = 0;
        local $Data::Dumper::Sortkeys = 1;
        local $Data::Dumper::Terse    = 1;
        local $Data::Dumper::Useqq    = 0;
        local $Data::Dumper::Deparse  = 0; # FIXME?
        my $str = Data::Dumper::Dumper($collapsed);
        # NOTE:
        # Canonicalize numbers to strings even if it
        # mangles numbers inside strings. It really
        # does not matter since its just the checksum
        # anyway.
        # - YK/SL
        $str =~ s/(?<! ['"] ) \b (\d+) \b (?! ['"] )/'$1'/gx;
        $d->add( $str );
    }

    return $d->hexdigest;
}

sub _digest_object {
    my ( $self, %options ) = @_;
    my $digest_opts = $options{digest};

    $digest_opts = [ $digest_opts ]
        if !ref($digest_opts) or ref($digest_opts) ne 'ARRAY';

    my ( $d, @args ) = @$digest_opts;

    if ( ref $d ) {
        if ( $d->can("clone") ) {
            return $d->clone;
        }
        elsif ( $d->can("reset") ) {
            $d->reset;
            return $d;
        }
        else {
            die "Can't clone or reset digest object: $d";
        }
    }
    else {
        return Digest->new($d || "SHA-1", @args);
    }
}

no Moose::Role;

1;

__END__

=pod

=encoding UTF-8

=for :stopwords Chris Prather Stevan Little יובל קוג'מן (Yuval Kogman) Infinity
Interactive, Inc. Florian Ragwitz Johannes Plunien Jonathan Rockway Yu Jos
Boumans Karen Etheridge Ricardo Signes Robert Boone Shawn M Moore Tomas
Doran Cory Yuval Kogman Watson Dagfinn Ilmari Mannsåker David Golden
Steinbrunner

=head1 NAME

MooseX::Storage::Base::WithChecksum - A more secure serialization role

=head1 VERSION

version 0.45

=head1 DESCRIPTION

This is an early implementation of a more secure Storage role,
which does integrity checks on the data. It is still being
developed so I recommend using it with caution.

Any thoughts, ideas or suggestions on improving our technique
are very welcome.

=head1 METHODS

=over 4

=item B<pack (?$salt)>

=item B<unpack ($data, ?$salt)>

=back

=head2 Introspection

=over 4

=item B<meta>

=back

=head1 BUGS

All complex software has bugs lurking in it, and this module is no
exception. If you find a bug please either email me, or add the bug
to cpan-RT.

=head1 AUTHORS

=over 4

=item *

Chris Prather <chris.prather@iinteractive.com>

=item *

Stevan Little <stevan.little@iinteractive.com>

=item *

יובל קוג'מן (Yuval Kogman) <nothingmuch@woobling.org>

=back

=head1 COPYRIGHT AND LICENSE

This software is copyright (c) 2007 by Infinity Interactive, Inc..

This is free software; you can redistribute it and/or modify it under
the same terms as the Perl 5 programming language system itself.

=cut
