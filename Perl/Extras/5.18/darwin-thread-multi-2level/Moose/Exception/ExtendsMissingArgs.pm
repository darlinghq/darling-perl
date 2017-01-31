package Moose::Exception::ExtendsMissingArgs;
BEGIN {
  $Moose::Exception::ExtendsMissingArgs::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::ExtendsMissingArgs::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Class';

sub _build_message {
    "Must derive at least one class";
}

1;
