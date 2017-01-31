package Moose::Exception::CannotRegisterUnnamedTypeConstraint;
BEGIN {
  $Moose::Exception::CannotRegisterUnnamedTypeConstraint::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::CannotRegisterUnnamedTypeConstraint::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::TypeConstraint';

sub _build_message {
    "can't register an unnamed type constraint";
}

1;
