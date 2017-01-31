package MooseX::Storage::Engine::Trait::DisableCycleDetection;
{
  $MooseX::Storage::Engine::Trait::DisableCycleDetection::VERSION = '0.45';
}
BEGIN {
  $MooseX::Storage::Engine::Trait::DisableCycleDetection::AUTHORITY = 'cpan:STEVAN';
}
# ABSTRACT: A custom trait to bypass cycle detection

use Moose::Role;

around 'check_for_cycle_in_collapse' => sub {
    my ($orig, $self, $attr, $value) = @_;
    # See NOTE in MX::Storage::Engine
    return $value;
};

1;

__END__

=pod

=encoding UTF-8

=for :stopwords Chris Prather Stevan Little יובל קוג'מן (Yuval Kogman) Infinity
Interactive, Inc. Florian Ragwitz Johannes Plunien Jonathan Rockway Yu Jos
Boumans Karen Etheridge Ricardo Signes Robert Boone Shawn M Moore Tomas
Doran Cory Yuval Kogman Watson Dagfinn Ilmari Mannsåker David Golden
Steinbrunner

=head1 NAME

MooseX::Storage::Engine::Trait::DisableCycleDetection - A custom trait to bypass cycle detection

=head1 VERSION

version 0.45

=head1 SYNOPSIS

    package Double;
    use Moose;
    use MooseX::Storage;
    with Storage( traits => ['DisableCycleDetection'] );

    has 'x' => ( is => 'rw', isa => 'HashRef' );
    has 'y' => ( is => 'rw', isa => 'HashRef' );

    my $ref = {};

    my $double = Double->new( 'x' => $ref, 'y' => $ref );

    $double->pack;

=head1 DESCRIPTION

C<MooseX::Storage> implements a primitive check for circular references.
This check also triggers on simple cases as shown in the Synopsis.
Providing the C<DisableCycleDetection> traits disables checks for any cyclical
references, so if you know what you are doing, you can bypass this check.

This trait is applied to an instance of L<MooseX::Storage::Engine>, for the
user-visible version shown in the SYNOPSIS, see L<MooseX::Storage::Traits::DisableCycleDetection>

=head1 METHODS

=head2 Introspection

=over 4

=item B<meta>

=back

=head1 BUGS

All complex software has bugs lurking in it, and this module is no
exception. If you find a bug please either email me, or add the bug
to cpan-RT.

=head1 AUTHORS

=over 4

=item *

Chris Prather <chris.prather@iinteractive.com>

=item *

Stevan Little <stevan.little@iinteractive.com>

=item *

יובל קוג'מן (Yuval Kogman) <nothingmuch@woobling.org>

=back

=head1 COPYRIGHT AND LICENSE

This software is copyright (c) 2007 by Infinity Interactive, Inc..

This is free software; you can redistribute it and/or modify it under
the same terms as the Perl 5 programming language system itself.

=cut
