package Moose::Exception::CannotDelegateWithoutIsa;
BEGIN {
  $Moose::Exception::CannotDelegateWithoutIsa::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::CannotDelegateWithoutIsa::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Attribute';

sub _build_message {
    "Cannot delegate methods based on a Regexp without a type constraint (isa)";
}

1;
