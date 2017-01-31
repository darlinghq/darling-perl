package Moose::Exception::CreateMOPClassTakesArrayRefOfAttributes;
BEGIN {
  $Moose::Exception::CreateMOPClassTakesArrayRefOfAttributes::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::CreateMOPClassTakesArrayRefOfAttributes::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::RoleForCreateMOPClass';

sub _build_message {
    "You must pass an ARRAY ref of attributes";
}

1;
