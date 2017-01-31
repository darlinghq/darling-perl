package MooseX::Storage::IO::AtomicFile;
{
  $MooseX::Storage::IO::AtomicFile::VERSION = '0.45';
}
BEGIN {
  $MooseX::Storage::IO::AtomicFile::AUTHORITY = 'cpan:STEVAN';
}
# ABSTRACT: An Atomic File I/O role
use Moose::Role;

use MooseX::Storage::Engine::IO::AtomicFile;

with 'MooseX::Storage::IO::File';

sub store {
    my ( $self, $filename, @args ) = @_;
    MooseX::Storage::Engine::IO::AtomicFile->new( file => $filename )->store( $self->freeze(@args) );
}

no Moose::Role;

1;

__END__

=pod

=encoding UTF-8

=for :stopwords Chris Prather Stevan Little יובל קוג'מן (Yuval Kogman) Infinity
Interactive, Inc.

=head1 NAME

MooseX::Storage::IO::AtomicFile - An Atomic File I/O role

=head1 VERSION

version 0.45

=head1 SYNOPSIS

  package Point;
  use Moose;
  use MooseX::Storage;

  with Storage('format' => 'JSON', 'io' => 'AtomicFile');

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
