package Moose::Exception::InvalidTypeGivenToCreateParameterizedTypeConstraint;
BEGIN {
  $Moose::Exception::InvalidTypeGivenToCreateParameterizedTypeConstraint::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::InvalidTypeGivenToCreateParameterizedTypeConstraint::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::TypeConstraint';

sub _build_message {
    my $self = shift;
    "Could not parse type name (".$self->type_name.") correctly";
}

1;
