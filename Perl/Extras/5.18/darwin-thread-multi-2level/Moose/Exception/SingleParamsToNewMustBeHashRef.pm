package Moose::Exception::SingleParamsToNewMustBeHashRef;
BEGIN {
  $Moose::Exception::SingleParamsToNewMustBeHashRef::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::SingleParamsToNewMustBeHashRef::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';

sub _build_message {
    "Single parameters to new() must be a HASH ref";
}

1;
