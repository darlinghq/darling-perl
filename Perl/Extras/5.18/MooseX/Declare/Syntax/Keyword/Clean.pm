package MooseX::Declare::Syntax::Keyword::Clean;
{
  $MooseX::Declare::Syntax::Keyword::Clean::VERSION = '0.38';
}
BEGIN {
  $MooseX::Declare::Syntax::Keyword::Clean::AUTHORITY = 'cpan:FLORA';
}
# ABSTRACT: Explicit namespace cleanups

use Moose;

use constant NAMESPACING_ROLE => 'MooseX::Declare::Syntax::NamespaceHandling';
use Carp qw( cluck );

use namespace::clean -except => 'meta';


with qw(
    MooseX::Declare::Syntax::KeywordHandling
);

sub find_namespace_handler {
    my ($self, $ctx) = @_;

    for my $item (reverse @{ $ctx->stack }) {
        return $item
            if $item->handler->does(NAMESPACING_ROLE);
    }

    return undef;
}


sub parse {
    my ($self, $ctx) = @_;

    if (my $stack_item = $self->find_namespace_handler($ctx)) {
        my $namespace = $stack_item->namespace;

        cluck "Attempted to clean an already cleaned namespace ($namespace). Did you mean to use 'is dirty'?"
            unless $stack_item->is_dirty;
    }

    $ctx->skip_declarator;
    $ctx->inject_code_parts_here(
        ';use namespace::clean -except => [qw( meta )]',
    );
}


1;

__END__

=pod

=encoding UTF-8

=head1 NAME

MooseX::Declare::Syntax::Keyword::Clean - Explicit namespace cleanups

=head1 DESCRIPTION

This keyword will inject a call to L<namespace::clean> into its current
position.

=head1 METHODS

=head2 parse

  Object->parse(Object $context)

This will inject a call to L<namespace::clean> C<-except => 'meta'> into
the code at the position of the keyword.

=head1 CONSUMES

=over 4

=item *

L<MooseX::Declare::Syntax::KeywordHandling>

=back

=head1 SEE ALSO

=over 4

=item *

L<MooseX::Declare>

=item *

L<MooseX::Declare::Syntax::KeywordHandling>

=back

=head1 AUTHOR

Florian Ragwitz <rafl@debian.org>

=head1 COPYRIGHT AND LICENSE

This software is copyright (c) 2008 by Florian Ragwitz.

This is free software; you can redistribute it and/or modify it under
the same terms as the Perl 5 programming language system itself.

=cut
