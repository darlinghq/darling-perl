package Moose::Exception::CannotApplyBaseClassRolesToRole;
BEGIN {
  $Moose::Exception::CannotApplyBaseClassRolesToRole::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::CannotApplyBaseClassRolesToRole::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::ParamsHash', 'Moose::Exception::Role::Role';

sub _build_message {
    "You can only apply base class roles to a Moose class, not a role.";
}

1;
