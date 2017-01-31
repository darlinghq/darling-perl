package Moose::Exception::TypeConstraintIsAlreadyCreated;
BEGIN {
  $Moose::Exception::TypeConstraintIsAlreadyCreated::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::TypeConstraintIsAlreadyCreated::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::TypeConstraint';

has 'package_defined_in' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1,
);

sub _build_message {
    my $self = shift;
    "The type constraint '".$self->type->name."' has already been created in ".$self->type->_package_defined_in." and cannot be created again in ".$self->package_defined_in;
}

1;
