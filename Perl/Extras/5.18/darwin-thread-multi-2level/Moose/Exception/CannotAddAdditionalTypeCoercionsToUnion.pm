package Moose::Exception::CannotAddAdditionalTypeCoercionsToUnion;
BEGIN {
  $Moose::Exception::CannotAddAdditionalTypeCoercionsToUnion::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::CannotAddAdditionalTypeCoercionsToUnion::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';

has 'type_coercion_union_object' => (
    is       => 'ro',
    isa      => 'Moose::Meta::TypeCoercion::Union',
    required => 1
);

sub _build_message {
    return "Cannot add additional type coercions to Union types";
}

1;
