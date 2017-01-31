package Moose::Exception::MustSpecifyAtleastOneMethod;
BEGIN {
  $Moose::Exception::MustSpecifyAtleastOneMethod::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::MustSpecifyAtleastOneMethod::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Role';

sub _build_message {
    "Must specify at least one method";
}

1;
