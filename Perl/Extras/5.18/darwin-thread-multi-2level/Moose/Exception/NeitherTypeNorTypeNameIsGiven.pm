package Moose::Exception::NeitherTypeNorTypeNameIsGiven;
BEGIN {
  $Moose::Exception::NeitherTypeNorTypeNameIsGiven::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::NeitherTypeNorTypeNameIsGiven::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';

sub _build_message {
    "You need to give type or type_name or both";
}

1;
