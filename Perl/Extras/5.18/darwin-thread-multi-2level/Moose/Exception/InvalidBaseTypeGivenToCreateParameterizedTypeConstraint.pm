package Moose::Exception::InvalidBaseTypeGivenToCreateParameterizedTypeConstraint;
BEGIN {
  $Moose::Exception::InvalidBaseTypeGivenToCreateParameterizedTypeConstraint::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::InvalidBaseTypeGivenToCreateParameterizedTypeConstraint::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::TypeConstraint';

sub _build_message {
    my $self = shift;
    "Could not locate the base type (".$self->type_name.")";
}

1;
