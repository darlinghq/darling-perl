package MooseX::Declare::StackItem;
{
  $MooseX::Declare::StackItem::VERSION = '0.38';
}
BEGIN {
  $MooseX::Declare::StackItem::AUTHORITY = 'cpan:FLORA';
}

use Moose;

use namespace::clean -except => 'meta';
use overload '""' => 'as_string', fallback => 1;

has identifier => (
    is          => 'rw',
    isa         => 'Str',
    required    => 1,
);

has handler => (
    is          => 'ro',
    required    => 1,
    default     => '',
);

has is_dirty => (
    is          => 'ro',
    isa         => 'Bool',
);

has is_parameterized => (
    is  => 'ro',
    isa => 'Bool',
);

has namespace => (
    is          => 'ro',
    isa         => 'Str|Undef',

);

sub as_string {
    my ($self) = @_;
    return $self->identifier;
}

sub serialize {
    my ($self) = @_;
    return sprintf '%s->new(%s)',
        ref($self),
        join ', ', map { defined($_) ? "q($_)" : 'undef' }
        'identifier',       $self->identifier,
        'handler',          $self->handler,
        'is_dirty',         ( $self->is_dirty         ? 1 : 0 ),
        'is_parameterized', ( $self->is_parameterized ? 1 : 0 ),
        'namespace',        $self->namespace,
        ;
}

__PACKAGE__->meta->make_immutable;

1;

__END__

=pod

=encoding UTF-8

=head1 NAME

MooseX::Declare::StackItem

=head1 AUTHOR

Florian Ragwitz <rafl@debian.org>

=head1 COPYRIGHT AND LICENSE

This software is copyright (c) 2008 by Florian Ragwitz.

This is free software; you can redistribute it and/or modify it under
the same terms as the Perl 5 programming language system itself.

=cut
