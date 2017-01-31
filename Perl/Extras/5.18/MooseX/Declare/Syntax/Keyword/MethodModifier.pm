package MooseX::Declare::Syntax::Keyword::MethodModifier;
{
  $MooseX::Declare::Syntax::Keyword::MethodModifier::VERSION = '0.38';
}
BEGIN {
  $MooseX::Declare::Syntax::Keyword::MethodModifier::AUTHORITY = 'cpan:FLORA';
}
# ABSTRACT: Handle method modifier declarations

use Moose;
use Moose::Util;
use Moose::Util::TypeConstraints;

use namespace::clean -except => 'meta';


with 'MooseX::Declare::Syntax::MethodDeclaration';


has modifier_type => (
    is          => 'rw',
    isa         => enum([qw( around after before override augment )]),
    required    => 1,
);


sub register_method_declaration {
    my ($self, $meta, $name, $method) = @_;
    return Moose::Util::add_method_modifier($meta->name, $self->modifier_type, [$name, $method->body]);
}


1;

__END__

=pod

=encoding UTF-8

=head1 NAME

MooseX::Declare::Syntax::Keyword::MethodModifier - Handle method modifier declarations

=head1 DESCRIPTION

Allows the implementation of method modification handlers like C<around> and
C<before>.

=head1 ATTRIBUTES

=head2 modifier_type

A required string that is one of:

=over 4

=item *

around

=item *

after

=item *

before

=item *

override

=item *

augment

=back

=head1 METHODS

=head2 register_method_declaration

  Object->register_method_declaration (Object $metaclass, Str $name, Object $method)

This will add the method modifier to the C<$metaclass> via L<Moose::Util>s
C<add_method_modifier>, whose return value will also be returned from this
method.

=head1 CONSUMES

=over 4

=item *

L<MooseX::Declare::Syntax::MethodDeclaration>

=back

=head1 SEE ALSO

=over 4

=item *

L<MooseX::Declare>

=item *

L<MooseX::Declare::Syntax::MooseSetup>

=item *

L<MooseX::Declare::Syntax::MethodDeclaration>

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
