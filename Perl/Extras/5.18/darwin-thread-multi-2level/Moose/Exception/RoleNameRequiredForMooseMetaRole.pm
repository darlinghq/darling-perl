package Moose::Exception::RoleNameRequiredForMooseMetaRole;
BEGIN {
  $Moose::Exception::RoleNameRequiredForMooseMetaRole::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::RoleNameRequiredForMooseMetaRole::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Role';

sub _build_message {
    "You must supply a role name to look for";
}

1;
