package MooseX::Storage::IO::StorableFile;
{
  $MooseX::Storage::IO::StorableFile::VERSION = '0.45';
}
BEGIN {
  $MooseX::Storage::IO::StorableFile::AUTHORITY = 'cpan:STEVAN';
}
# ABSTRACT: An Storable File I/O role
use Moose::Role;

use Storable ();

requires 'pack';
requires 'unpack';

sub load {
    my ( $class, $filename, @args ) = @_;
    # try thawing
    return $class->thaw( Storable::retrieve($filename), @args )
        if $class->can('thaw');
    # otherwise just unpack
    $class->unpack( Storable::retrieve($filename), @args );
}

sub store {
    my ( $self, $filename, @args ) = @_;
    Storable::nstore(
        # try freezing, otherwise just pack
        ($self->can('freeze') ? $self->freeze(@args) : $self->pack(@args)),
        $filename
    );
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

MooseX::Storage::IO::StorableFile - An Storable File I/O role

=head1 VERSION

version 0.45

=head1 SYNOPSIS

  package Point;
  use Moose;
  use MooseX::Storage;

  with Storage('io' => 'StorableFile');

  has 'x' => (is => 'rw', isa => 'Int');
  has 'y' => (is => 'rw', isa => 'Int');

  1;

  my $p = Point->new(x => 10, y => 10);

  ## methods to load/store a class
  ## on the file system

  $p->store('my_point');

  my $p2 = Point->load('my_point');

=head1 DESCRIPTION

This module will C<load> and C<store> Moose classes using Storable. It
uses C<Storable::nstore> by default so that it can be easily used
across machines or just locally.

One important thing to note is that this module does not mix well
with the other Format modules. Since Storable serialized perl data
structures in it's own format, those roles are largely unnecessary.

However, there is always the possibility that having a set of
C<freeze/thaw> hooks can be useful, so because of that this module
will attempt to use C<freeze> or C<thaw> if that method is available.
Of course, you should be careful when doing this as it could lead to
all sorts of hairy issues. But you have been warned.

=head1 METHODS

=over 4

=item B<load ($filename)>

=item B<store ($filename)>

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
