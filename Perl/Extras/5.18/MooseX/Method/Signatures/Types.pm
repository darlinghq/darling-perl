package MooseX::Method::Signatures::Types;
{
  $MooseX::Method::Signatures::Types::VERSION = '0.47';
}
BEGIN {
  $MooseX::Method::Signatures::Types::AUTHORITY = 'cpan:ETHER';
}
#ABSTRACT: Provides common MooseX::Types used by MooseX::Method::Signatures

use MooseX::Types 0.19 -declare => [qw/ Injections PrototypeInjections Params /];
use MooseX::Types::Moose qw/Str ArrayRef/;
use MooseX::Types::Structured 0.24 qw/Dict/;
use Parse::Method::Signatures::Types qw/Param/;

subtype Injections,
    as ArrayRef[Str];

subtype PrototypeInjections,
    as Dict[declarator => Str, injections => Injections];

subtype Params,
    as ArrayRef[Param];

1;

__END__

=pod

=encoding UTF-8

=for :stopwords Florian Ragwitz

=head1 NAME

MooseX::Method::Signatures::Types - Provides common MooseX::Types used by MooseX::Method::Signatures

=head1 VERSION

version 0.47

=head1 AUTHOR

Florian Ragwitz <rafl@debian.org>

=head1 COPYRIGHT AND LICENSE

This software is copyright (c) 2013 by Florian Ragwitz.

This is free software; you can redistribute it and/or modify it under
the same terms as the Perl 5 programming language system itself.

=cut
