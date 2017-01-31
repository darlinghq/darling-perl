package MooseX::Storage::Basic;
{
  $MooseX::Storage::Basic::VERSION = '0.45';
}
BEGIN {
  $MooseX::Storage::Basic::AUTHORITY = 'cpan:STEVAN';
}
# ABSTRACT: The simplest level of serialization
use Moose::Role;

use MooseX::Storage::Engine;
use String::RewritePrefix;

sub pack {
    my ( $self, %args ) = @_;
    my $e = $self->_storage_get_engine_class(%args)->new( object => $self );
    $e->collapse_object(%args);
}

sub unpack {
    my ($class, $data, %args) = @_;
    my $e = $class->_storage_get_engine_class(%args)->new(class => $class);

    $class->_storage_construct_instance(
        $e->expand_object($data, %args),
        \%args
    );
}

sub _storage_get_engine_class {
    my ($self, %args) = @_;

    return 'MooseX::Storage::Engine'
        unless (
            exists $args{engine_traits}
         && ref($args{engine_traits}) eq 'ARRAY'
         && scalar(@{$args{engine_traits}})
    );

    my @roles = String::RewritePrefix->rewrite(
        {
            '' => 'MooseX::Storage::Engine::Trait::',
            '+' => '',
        },
        @{$args{engine_traits}}
    );

    Moose::Meta::Class->create_anon_class(
        superclasses => ['MooseX::Storage::Engine'],
        roles => [ @roles ],
        cache => 1,
    )->name;
}

sub _storage_construct_instance {
    my ($class, $args, $opts) = @_;
    my %i = defined $opts->{'inject'} ? %{ $opts->{'inject'} } : ();

    $class->new( %$args, %i );
}

no Moose::Role;

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

MooseX::Storage::Basic - The simplest level of serialization

=head1 VERSION

version 0.45

=head1 SYNOPSIS

  package Point;
  use Moose;
  use MooseX::Storage;

  with Storage;

  has 'x' => (is => 'rw', isa => 'Int');
  has 'y' => (is => 'rw', isa => 'Int');

  1;

  my $p = Point->new(x => 10, y => 10);

  ## methods to pack/unpack an
  ## object in perl data structures

  # pack the class into a hash
  $p->pack(); # { __CLASS__ => 'Point-0.01', x => 10, y => 10 }

  # unpack the hash into a class
  my $p2 = Point->unpack({ __CLASS__ => 'Point-0.01', x => 10, y => 10 });

  # unpack the hash, with insertion of paramaters
  my $p3 = Point->unpack( $p->pack, inject => { x => 11 } );

=head1 DESCRIPTION

This is the most basic form of serialization. This is used by default
but the exported C<Storage> function.

=head1 METHODS

=over 4

=item B<pack ([ disable_cycle_check => 1])>

Providing the C<disable_cycle_check> argument disables checks for any cyclical
references. The current implementation for this check is rather naive, so if
you know what you are doing, you can bypass this check.

This trait is applied on a perl-case basis. To set this flag for all objects
that inherit from this role, see L<MooseX::Storage::Traits::DisableCycleDetection>.

=item B<unpack ($data [, insert => { key => val, ... } ] )>

Providing the C<insert> argument let's you supply additional arguments to
the class' C<new> function, or override ones from the serialized data.

=back

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
