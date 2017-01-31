package Moose::Exception::MustSpecifyAtleastOneRole;
BEGIN {
  $Moose::Exception::MustSpecifyAtleastOneRole::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::MustSpecifyAtleastOneRole::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Role';

sub _build_message {
    "Must specify at least one role";
}

1;
