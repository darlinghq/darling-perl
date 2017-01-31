package MooseX::Declare::Syntax::MethodDeclaration::Parameterized;
{
  $MooseX::Declare::Syntax::MethodDeclaration::Parameterized::VERSION = '0.38';
}
BEGIN {
  $MooseX::Declare::Syntax::MethodDeclaration::Parameterized::AUTHORITY = 'cpan:FLORA';
}

use Moose::Role;
use MooseX::Role::Parameterized 0.12 ();
use namespace::autoclean;

around register_method_declaration => sub {
    my ($next, $self, $parameterizable_meta, $name, $method) = @_;
    my $meta = $self->metaclass_for_method_application($parameterizable_meta, $name, $method);
    $self->$next($meta, $name, $method);
};

sub metaclass_for_method_application {
    return MooseX::Role::Parameterized->current_metaclass;
}

1;

__END__

=pod

=encoding UTF-8

=head1 NAME

MooseX::Declare::Syntax::MethodDeclaration::Parameterized

=head1 AUTHOR

Florian Ragwitz <rafl@debian.org>

=head1 COPYRIGHT AND LICENSE

This software is copyright (c) 2008 by Florian Ragwitz.

This is free software; you can redistribute it and/or modify it under
the same terms as the Perl 5 programming language system itself.

=cut
