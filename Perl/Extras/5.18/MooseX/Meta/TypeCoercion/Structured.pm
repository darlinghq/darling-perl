package ## Hide from PAUSE
 MooseX::Meta::TypeCoercion::Structured;
# ABSTRACT: Coerce structured type constraints

use Moose;
extends 'Moose::Meta::TypeCoercion';

# We need to make sure we can properly coerce the structure elements inside a
# structured type constraint.  However requirements for the best way to allow
# this are still in flux.  For now this class is a placeholder.
# see also Moose::Meta::TypeCoercion.

__PACKAGE__->meta->make_immutable(inline_constructor => 0);

__END__

=pod

=encoding UTF-8

=for :stopwords John Napiorkowski Florian Ragwitz יובל קוג'מן (Yuval Kogman) Tomas (t0m)
Doran Robert Sedlacek Ansgar 'phaylon' Stevan Little arcanez Burchardt Dave
Rolsky Jesse Luehrs Karen Etheridge Ricardo Signes

=head1 NAME

MooseX::Meta::TypeCoercion::Structured - Coerce structured type constraints

=head1 VERSION

version 0.30

=head1 AUTHORS

=over 4

=item *

John Napiorkowski <jjnapiork@cpan.org>

=item *

Florian Ragwitz <rafl@debian.org>

=item *

יובל קוג'מן (Yuval Kogman) <nothingmuch@woobling.org>

=item *

Tomas (t0m) Doran <bobtfish@bobtfish.net>

=item *

Robert Sedlacek <rs@474.at>

=back

=head1 COPYRIGHT AND LICENSE

This software is copyright (c) 2008 by John Napiorkowski.

This is free software; you can redistribute it and/or modify it under
the same terms as the Perl 5 programming language system itself.

=cut
