package MooseX::Declare::Syntax::Keyword::Namespace;
{
  $MooseX::Declare::Syntax::Keyword::Namespace::VERSION = '0.38';
}
BEGIN {
  $MooseX::Declare::Syntax::Keyword::Namespace::AUTHORITY = 'cpan:FLORA';
}
# ABSTRACT: Declare outer namespace

use Moose;
use Carp qw( confess );

use MooseX::Declare::Util qw( outer_stack_push outer_stack_peek );

use namespace::clean -except => 'meta';


with qw(
    MooseX::Declare::Syntax::KeywordHandling
);


sub parse {
    my ($self, $ctx) = @_;

    confess "Nested namespaces are not supported yet"
        if outer_stack_peek $ctx->caller_file;

    $ctx->skip_declarator;
    my $namespace = $ctx->strip_word
        or confess "Expected a namespace argument to use from here on";

    confess "Relative namespaces are currently not supported"
        if $namespace =~ /^::/;

    $ctx->skipspace;

    my $next_char = $ctx->peek_next_char;
    confess "Expected end of statement after namespace argument"
        unless $next_char eq ';';

    outer_stack_push $ctx->caller_file, $namespace;
}


1;

__END__

=pod

=encoding UTF-8

=head1 NAME

MooseX::Declare::Syntax::Keyword::Namespace - Declare outer namespace

=head1 SYNOPSIS

  use MooseX::Declare;

  namespace Foo::Bar;

  class ::Baz extends ::Qux with ::Fnording {
      ...
  }

=head1 DESCRIPTION

The C<namespace> keyword allows you to declare an outer namespace under
which other namespaced constructs can be nested. The L</SYNOPSIS> is
effectively the same as

  use MooseX::Declare;

  class Foo::Bar::Baz extends Foo::Bar::Qux with Foo::Bar::Fnording {
      ...
  }

=head1 METHODS

=head2 parse

  Object->parse(Object $context)

Will skip the declarator, parse the namespace and push the namespace
in the file package stack.

=head1 CONSUMES

=over 4

=item *

L<MooseX::Declare::Syntax::KeywordHandling>

=back

=head1 SEE ALSO

=over 4

=item *

L<MooseX::Declare>

=back

=head1 AUTHOR

Florian Ragwitz <rafl@debian.org>

=head1 COPYRIGHT AND LICENSE

This software is copyright (c) 2008 by Florian Ragwitz.

This is free software; you can redistribute it and/or modify it under
the same terms as the Perl 5 programming language system itself.

=cut
