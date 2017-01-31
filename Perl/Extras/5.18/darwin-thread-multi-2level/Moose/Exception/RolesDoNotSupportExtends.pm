package Moose::Exception::RolesDoNotSupportExtends;
BEGIN {
  $Moose::Exception::RolesDoNotSupportExtends::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::RolesDoNotSupportExtends::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';

sub _build_message {
    "Roles do not support 'extends' (you can use 'with' to specialize a role)";
}

1;
