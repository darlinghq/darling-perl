package Moose::Exception::CircularReferenceInAlso;
BEGIN {
  $Moose::Exception::CircularReferenceInAlso::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::CircularReferenceInAlso::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';

has 'also_parameter' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1
);

has 'stack' => (
    is       => 'ro',
    isa      => 'ArrayRef',
    required => 1
);

sub _build_message {
    my $self = shift;
    my $also_member = $self->also_parameter;

    my @stack = @{$self->stack};
    my $existing_stack = join( ', ', @stack);

    return "Circular reference in 'also' parameter to Moose::Exporter between "
           ."$existing_stack and $also_member";
}

1;
