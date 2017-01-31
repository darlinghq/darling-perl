package MooseX::Getopt::OptionTypeMap;
{
  $MooseX::Getopt::OptionTypeMap::VERSION = '0.59';
}
BEGIN {
  $MooseX::Getopt::OptionTypeMap::AUTHORITY = 'cpan:STEVAN';
}
# ABSTRACT: Storage for the option to type mappings

use Moose 'confess', 'blessed';
use Moose::Util::TypeConstraints 'find_type_constraint';

my %option_type_map = (
    'Bool'     => '!',
    'Str'      => '=s',
    'Int'      => '=i',
    'Num'      => '=f',
    'ArrayRef' => '=s@',
    'HashRef'  => '=s%',
);

sub has_option_type {
    my (undef, $type_or_name) = @_;

    if (blessed($type_or_name)
        && $type_or_name->isa('Moose::Meta::TypeConstraint::Union')) {
        foreach my $union_type (@{$type_or_name->type_constraints}) {
            return 1
                if __PACKAGE__->has_option_type($union_type);
        }
        return 0;
    }

    return 1 if exists $option_type_map{blessed($type_or_name) ? $type_or_name->name : $type_or_name};

    my $current = blessed($type_or_name) ? $type_or_name : find_type_constraint($type_or_name);

    (defined $current)
        || confess "Could not find the type constraint for '$type_or_name'";

    while (my $parent = $current->parent) {
        return 1 if exists $option_type_map{$parent->name};
        $current = $parent;
    }

    return 0;
}

sub get_option_type {
    my (undef, $type_or_name) = @_;

    if (blessed($type_or_name)
        && $type_or_name->isa('Moose::Meta::TypeConstraint::Union')) {
        foreach my $union_type (@{$type_or_name->type_constraints}) {
            my $option_type = __PACKAGE__->get_option_type($union_type);
            return $option_type
                if defined $option_type;
        }
        return;
    }

    my $name = blessed($type_or_name) ? $type_or_name->name : $type_or_name;

    return $option_type_map{$name} if exists $option_type_map{$name};

    my $current = ref $type_or_name ? $type_or_name : find_type_constraint($type_or_name);

    (defined $current)
        || confess "Could not find the type constraint for '$type_or_name'";

    while ( $current = $current->parent ) {
        return $option_type_map{$current->name}
            if exists $option_type_map{$current->name};
    }

    return;
}

sub add_option_type_to_map {
    my (undef, $type_name, $option_string) = @_;
    (defined $type_name && defined $option_string)
        || confess "You must supply both a type name and an option string";

    if ( blessed($type_name) ) {
        $type_name = $type_name->name;
    } else {
        (find_type_constraint($type_name))
            || confess "The type constraint '$type_name' does not exist";
    }

    $option_type_map{$type_name} = $option_string;
}

no Moose::Util::TypeConstraints;
no Moose;

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

MooseX::Getopt::OptionTypeMap - Storage for the option to type mappings

=head1 VERSION

version 0.59

=head1 DESCRIPTION

See the I<Custom Type Constraints> section in the L<MooseX::Getopt> docs
for more info about how to use this module.

=head1 METHODS

=head2 B<has_option_type ($type_or_name)>

=head2 B<get_option_type ($type_or_name)>

=head2 B<add_option_type_to_map ($type_name, $option_spec)>

=head1 AUTHOR

Stevan Little <stevan@iinteractive.com>

=head1 COPYRIGHT AND LICENSE

This software is copyright (c) 2007 by Infinity Interactive, Inc.

This is free software; you can redistribute it and/or modify it under
the same terms as the Perl 5 programming language system itself.

=cut
