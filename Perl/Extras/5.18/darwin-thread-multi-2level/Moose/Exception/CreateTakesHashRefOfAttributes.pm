package Moose::Exception::CreateTakesHashRefOfAttributes;
BEGIN {
  $Moose::Exception::CreateTakesHashRefOfAttributes::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::CreateTakesHashRefOfAttributes::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::RoleForCreate';

sub _build_message {
    "You must pass a HASH ref of attributes";
}

1;
