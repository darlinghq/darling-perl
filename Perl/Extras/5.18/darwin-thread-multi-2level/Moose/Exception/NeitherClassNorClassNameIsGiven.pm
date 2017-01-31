package Moose::Exception::NeitherClassNorClassNameIsGiven;
BEGIN {
  $Moose::Exception::NeitherClassNorClassNameIsGiven::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::NeitherClassNorClassNameIsGiven::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';

sub _build_message {
    "You need to give class or class_name or both";
}

1;
