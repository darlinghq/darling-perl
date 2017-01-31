package Moose::Exception::RolesDoNotSupportInner;
BEGIN {
  $Moose::Exception::RolesDoNotSupportInner::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::RolesDoNotSupportInner::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';

sub _build_message {
    "Roles cannot support 'inner'";
}

1;
