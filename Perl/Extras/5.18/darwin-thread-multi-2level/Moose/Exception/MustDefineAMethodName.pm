package Moose::Exception::MustDefineAMethodName;
BEGIN {
  $Moose::Exception::MustDefineAMethodName::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::MustDefineAMethodName::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Instance';

sub _build_message {
    "You must define a method name";
}

1;
