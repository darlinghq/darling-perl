package Moose::Exception::CannotOverrideLocalMethodIsPresent;
BEGIN {
  $Moose::Exception::CannotOverrideLocalMethodIsPresent::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::CannotOverrideLocalMethodIsPresent::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Class', 'Moose::Exception::Role::Method';

sub _build_message {
    "Cannot add an override method if a local method is already present";
}

1;
