package MooseX::Storage::IO::File;
use Moose::Role;

use MooseX::Storage::Engine::IO::File;

our $VERSION   = '0.31';
our $AUTHORITY = 'cpan:STEVAN';

requires 'thaw';
requires 'freeze';

sub load {
    my ( $class, $filename, @args ) = @_;
    $class->thaw( MooseX::Storage::Engine::IO::File->new( file => $filename )->load(), @args );
}

sub store {
    my ( $self, $filename, @args ) = @_;
    MooseX::Storage::Engine::IO::File->new( file => $filename )->store( $self->freeze(@args) );
}

no Moose::Role;

1;

__END__

=pod

=head1 NAME

MooseX::Storage::IO::File - A basic File I/O role

=head1 SYNOPSIS

  package Point;
  use Moose;
  use MooseX::Storage;

  with Storage('format' => 'JSON', 'io' => 'File');

  has 'x' => (is => 'rw', isa => 'Int');
  has 'y' => (is => 'rw', isa => 'Int');

  1;

  my $p = Point->new(x => 10, y => 10);

  ## methods to load/store a class
  ## on the file system

  $p->store('my_point.json');

  my $p2 = Point->load('my_point.json');

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

=head1 AUTHOR

Chris Prather E<lt>chris.prather@iinteractive.comE<gt>

Stevan Little E<lt>stevan.little@iinteractive.comE<gt>

=head1 COPYRIGHT AND LICENSE

Copyright 2007-2008 by Infinity Interactive, Inc.

L<http://www.iinteractive.com>

This library is free software; you can redistribute it and/or modify
it under the same terms as Perl itself.

=cut


