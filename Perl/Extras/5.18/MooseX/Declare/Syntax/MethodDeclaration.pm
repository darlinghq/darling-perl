package MooseX::Declare::Syntax::MethodDeclaration;
{
  $MooseX::Declare::Syntax::MethodDeclaration::VERSION = '0.38';
}
BEGIN {
  $MooseX::Declare::Syntax::MethodDeclaration::AUTHORITY = 'cpan:FLORA';
}
# ABSTRACT: Handles method declarations

use Moose::Role;
use MooseX::Method::Signatures::Meta::Method;
use MooseX::Method::Signatures 0.36 ();
use MooseX::Method::Signatures::Types qw/PrototypeInjections/;

use namespace::clean -except => 'meta';


with qw(
    MooseX::Declare::Syntax::KeywordHandling
);


requires qw(
    register_method_declaration
);


has prototype_injections => (
    is          => 'ro',
    isa         => PrototypeInjections,
    predicate   => 'has_prototype_injections',
);


sub parse {
    my ($self, $ctx) = @_;

    my %args = (
        context                   => $ctx->_dd_context,
        initialized_context       => 1,
        custom_method_application => sub {
            my ($meta, $name, $method) = @_;
            $self->register_method_declaration($meta, $name, $method);
        },
    );

    $args{prototype_injections} = $self->prototype_injections
        if $self->has_prototype_injections;

    my $mxms = MooseX::Method::Signatures->new(%args);
    $mxms->parser;
}


1;

__END__

=pod

=encoding UTF-8

=head1 NAME

MooseX::Declare::Syntax::MethodDeclaration - Handles method declarations

=head1 DESCRIPTION

A role for keyword handlers that gives a framework to add or modify
methods or things that look like methods.

=head1 ATTRIBUTES

=head2 prototype_injections

An optional structure describing additional things to be added to a methods
signature. A popular example is found in the C<around>
L<method modifier handler|MooseX::Declare::Syntax::Keyword::MethodModifier>:

=head1 METHODS

=head2 parse

  Object->parse (Object $ctx);

Reads a name and a prototype and builds the method meta object then registers
it into the current class using MooseX::Method::Signatures and a
C<custom_method_application>, that calls L</register_method_declaration>.

=head1 CONSUMES

=over 4

=item *

L<MooseX::Declare::Syntax::KeywordHandling>

=back

=head1 REQUIRED METHODS

=head2 register_method_declaration

  Object->register_method_declaration (Object $metaclass, Str $name, Object $method)

This method will be called with the target metaclass and the final built
L<method meta object|MooseX::Method::Signatures::Meta::Method> and its name.
The value it returns will be the value returned where the method was declared.

=head1 SEE ALSO

=over 4

=item *

L<MooseX::Declare>

=item *

L<MooseX::Declare::Syntax::NamespaceHandling>

=item *

L<MooseX::Declare::Syntax::MooseSetup>

=item *

L<MooseX::Method::Signatures>

=back

=head1 AUTHOR

Florian Ragwitz <rafl@debian.org>

=head1 COPYRIGHT AND LICENSE

This software is copyright (c) 2008 by Florian Ragwitz.

This is free software; you can redistribute it and/or modify it under
the same terms as the Perl 5 programming language system itself.

=cut
