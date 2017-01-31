package Moose::Exception::MethodModifierNeedsMethodName;
BEGIN {
  $Moose::Exception::MethodModifierNeedsMethodName::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::MethodModifierNeedsMethodName::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Class';

sub _build_message {
    "You must pass in a method name";
}

1;
