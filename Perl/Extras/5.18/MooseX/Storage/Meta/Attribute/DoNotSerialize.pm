package MooseX::Storage::Meta::Attribute::DoNotSerialize;
{
  $MooseX::Storage::Meta::Attribute::DoNotSerialize::VERSION = '0.45';
}
BEGIN {
  $MooseX::Storage::Meta::Attribute::DoNotSerialize::AUTHORITY = 'cpan:STEVAN';
}
# ABSTRACT: A custom meta-attribute to bypass serialization
use Moose;

extends 'Moose::Meta::Attribute';
   with 'MooseX::Storage::Meta::Attribute::Trait::DoNotSerialize';

# register this alias ...
package Moose::Meta::Attribute::Custom::DoNotSerialize;
{
  $Moose::Meta::Attribute::Custom::DoNotSerialize::VERSION = '0.45';
}
BEGIN {
  $Moose::Meta::Attribute::Custom::DoNotSerialize::AUTHORITY = 'cpan:STEVAN';
}

sub register_implementation { 'MooseX::Storage::Meta::Attribute::DoNotSerialize' }

1;

__END__

=pod

=encoding UTF-8

=for :stopwords Chris Prather Stevan Little יובל קוג'מן (Yuval Kogman) Infinity
Interactive, Inc. Florian Ragwitz Johannes Plunien Jonathan Rockway Yu Jos
Boumans Karen Etheridge Ricardo Signes Robert Boone Shawn M Moore Tomas
Doran Cory Yuval Kogman Watson Dagfinn Ilmari Mannsåker David Golden
Steinbrunner culted

=head1 NAME

MooseX::Storage::Meta::Attribute::DoNotSerialize - A custom meta-attribute to bypass serialization

=head1 VERSION

version 0.45

=head1 SYNOPSIS

  package Point;
  use Moose;
  use MooseX::Storage;

  with Storage('format' => 'JSON', 'io' => 'File');

  has 'x' => (is => 'rw', isa => 'Int');
  has 'y' => (is => 'rw', isa => 'Int');

  has 'foo' => (
      metaclass => 'DoNotSerialize',
      is        => 'rw',
      isa       => 'CodeRef',
  );

  1;

=head1 DESCRIPTION

Sometimes you don't want a particular attribute to be part of the
serialization, in this case, you want to make sure that attribute
uses this custom meta-attribute. See the SYNOPSIS for a nice example
that can be easily cargo-culted.

=head1 METHODS

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
