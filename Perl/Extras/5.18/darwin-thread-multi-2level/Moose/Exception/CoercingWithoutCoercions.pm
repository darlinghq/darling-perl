package Moose::Exception::CoercingWithoutCoercions;
BEGIN {
  $Moose::Exception::CoercingWithoutCoercions::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::CoercingWithoutCoercions::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';

has 'type' => (
    is       => 'ro',
    isa      => "Moose::Meta::TypeConstraint",
    required => 1,
);

sub _build_message {
    my $self = shift;
    "Cannot coerce without a type coercion";
}
1;
