package Moose::Exception::CannotCreateHigherOrderTypeWithoutATypeParameter;
BEGIN {
  $Moose::Exception::CannotCreateHigherOrderTypeWithoutATypeParameter::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::CannotCreateHigherOrderTypeWithoutATypeParameter::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::TypeConstraint';

sub _build_message {
    "You cannot create a Higher Order type without a type parameter";
}

1;
