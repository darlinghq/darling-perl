package Moose::Exception::TypeParameterMustBeMooseMetaType;
BEGIN {
  $Moose::Exception::TypeParameterMustBeMooseMetaType::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::TypeParameterMustBeMooseMetaType::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::TypeConstraint';

sub _build_message {
    "The type parameter must be a Moose meta type";
}

1;
