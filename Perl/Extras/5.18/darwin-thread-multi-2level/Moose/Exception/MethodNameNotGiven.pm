package Moose::Exception::MethodNameNotGiven;
BEGIN {
  $Moose::Exception::MethodNameNotGiven::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::MethodNameNotGiven::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Class';

sub _build_message {
    "You must define a method name to find";
}

1;
