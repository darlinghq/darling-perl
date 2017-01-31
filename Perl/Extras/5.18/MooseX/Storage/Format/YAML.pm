package MooseX::Storage::Format::YAML;
{
  $MooseX::Storage::Format::YAML::VERSION = '0.45';
}
BEGIN {
  $MooseX::Storage::Format::YAML::AUTHORITY = 'cpan:STEVAN';
}
# ABSTRACT: A YAML serialization role
use Moose::Role;

# When I add YAML::LibYAML
# Tests break because tye YAML is invalid...?
# -dcp

use YAML::Any qw(Load Dump);

requires 'pack';
requires 'unpack';

sub thaw {
    my ( $class, $yaml, @args ) = @_;
    $class->unpack( Load($yaml), @args );
}

sub freeze {
    my ( $self, @args ) = @_;
    Dump( $self->pack(@args) );
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

MooseX::Storage::Format::YAML - A YAML serialization role

=head1 VERSION

version 0.45

=head1 SYNOPSIS

  package Point;
  use Moose;
  use MooseX::Storage;

  with Storage('format' => 'YAML');

  has 'x' => (is => 'rw', isa => 'Int');
  has 'y' => (is => 'rw', isa => 'Int');

  1;

  my $p = Point->new(x => 10, y => 10);

  ## methods to freeze/thaw into
  ## a specified serialization format
  ## (in this case YAML)

  # pack the class into a YAML string
  $p->freeze();

  # ----
  # __CLASS__: "Point"
  # x: 10
  # y: 10

  # unpack the JSON string into a class
  my $p2 = Point->thaw(<<YAML);
  ----
  __CLASS__: "Point"
  x: 10
  y: 10
  YAML

=head1 METHODS

=over 4

=item B<freeze>

=item B<thaw ($yaml)>

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
