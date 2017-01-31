package MooseX::Getopt::Meta::Attribute::NoGetopt;
{
  $MooseX::Getopt::Meta::Attribute::NoGetopt::VERSION = '0.59';
}
BEGIN {
  $MooseX::Getopt::Meta::Attribute::NoGetopt::AUTHORITY = 'cpan:STEVAN';
}
# ABSTRACT: Optional meta attribute for ignoring parameters

use Moose;

extends 'Moose::Meta::Attribute'; # << Moose extending Moose :)
   with 'MooseX::Getopt::Meta::Attribute::Trait::NoGetopt';

no Moose;

# register this as a metaclass alias ...
package # stop confusing PAUSE
    Moose::Meta::Attribute::Custom::NoGetopt;
sub register_implementation { 'MooseX::Getopt::Meta::Attribute::NoGetopt' }

1;

__END__

=pod

=encoding UTF-8

=for :stopwords Stevan Little Infinity Interactive, Inc Brandon Devin Austin Drew Taylor
Florian Ragwitz Gordon Irving Hans Dieter L Pearcey Hinrik Örn Sigurðsson
Jesse Luehrs John Goulah Jonathan Swartz Black Justin Hunter Karen
Etheridge Nelo Onyiah Ricardo SIGNES Ryan D Chris Johnson Shlomi Fish Todd
Hepler Tomas Doran Yuval Prather Kogman Ævar Arnfjörð Bjarmason Dagfinn
Ilmari Mannsåker Damien Krotkine

=head1 NAME

MooseX::Getopt::Meta::Attribute::NoGetopt - Optional meta attribute for ignoring parameters

=head1 VERSION

version 0.59

=head1 SYNOPSIS

  package App;
  use Moose;

  with 'MooseX::Getopt';

  has 'data' => (
      metaclass => 'NoGetopt',  # do not attempt to capture this param
      is        => 'ro',
      isa       => 'Str',
      default   => 'file.dat',
  );

=head1 DESCRIPTION

This is a custom attribute metaclass which can be used to specify
that a specific attribute should B<not> be processed by
C<MooseX::Getopt>. All you need to do is specify the C<NoGetopt>
metaclass.

  has 'foo' => (metaclass => 'MooseX::Getopt::Meta::Attribute::NoGetopt', ... );

=head2 Use 'traits' instead of 'metaclass'

You should rarely need to explicitly set the attribute metaclass. It is much
preferred to simply provide a trait (a role applied to the attribute
metaclass), which allows other code to further modify the attribute by applying
additional roles.

Therefore, you should first try to do this:

  has 'foo' => (traits => ['NoGetopt', ...], ...);

=head2 Custom Metaclass alias

This now takes advantage of the Moose 0.19 feature to support
custom attribute metaclass. This means you can also
use this as the B<NoGetopt> alias, like so:

  has 'foo' => (metaclass => 'NoGetopt', cmd_flag => 'f');

=head1 AUTHOR

Stevan Little <stevan@iinteractive.com>

=head1 COPYRIGHT AND LICENSE

This software is copyright (c) 2007 by Infinity Interactive, Inc.

This is free software; you can redistribute it and/or modify it under
the same terms as the Perl 5 programming language system itself.

=cut
