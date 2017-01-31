package MooseX::Declare::Syntax::Keyword::Method;
{
  $MooseX::Declare::Syntax::Keyword::Method::VERSION = '0.38';
}
BEGIN {
  $MooseX::Declare::Syntax::Keyword::Method::AUTHORITY = 'cpan:FLORA';
}
# ABSTRACT: Handle method declarations

use Moose;

use namespace::clean -except => 'meta';


with 'MooseX::Declare::Syntax::MethodDeclaration';


sub register_method_declaration {
    my ($self, $meta, $name, $method) = @_;
    return $meta->add_method($name, $method);
}


1;

__END__

=pod

=encoding UTF-8

=head1 NAME

MooseX::Declare::Syntax::Keyword::Method - Handle method declarations

=head1 DESCRIPTION

This role is an extension of L<MooseX::Declare::Syntax::MethodDeclaration>
that allows you to install keywords that declare methods.

=head1 METHODS

=head2 register_method_declaration

  Object->register_method_declaration (Object $metaclass, Str $name, Object $method)

This method required by the method declaration role will register the finished
method object via the C<< $metaclass->add_method >> method.

  MethodModifier->new(
      identifier           => 'around',
      modifier_type        => 'around',
      prototype_injections => {
          declarator => 'around',
          injections => [ 'CodeRef $orig' ],
      },
  );

This will mean that the signature C<(Str $foo)> will become
C<CodeRef $orig: Object $self, Str $foo> and and C<()> will become
C<CodeRef $orig: Object $self>.

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
