package Moose::Exception::CreateTakesArrayRefOfRoles;
BEGIN {
  $Moose::Exception::CreateTakesArrayRefOfRoles::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::CreateTakesArrayRefOfRoles::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::RoleForCreate';

sub _build_message {
    "You must pass an ARRAY ref of roles";
}

1;

