package Moose::Exception::CreateMOPClassTakesArrayRefOfSuperclasses;
BEGIN {
  $Moose::Exception::CreateMOPClassTakesArrayRefOfSuperclasses::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::CreateMOPClassTakesArrayRefOfSuperclasses::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::RoleForCreateMOPClass';

sub _build_message {
    "You must pass an ARRAY ref of superclasses";
}

1;
