package Moose::Exception::RoleNameRequired;
BEGIN {
  $Moose::Exception::RoleNameRequired::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::RoleNameRequired::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Class';

sub _build_message {
    "You must supply a role name to look for";
}

1;
