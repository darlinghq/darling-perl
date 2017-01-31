package Moose::Exception::NeitherAttributeNorAttributeNameIsGiven;
BEGIN {
  $Moose::Exception::NeitherAttributeNorAttributeNameIsGiven::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::NeitherAttributeNorAttributeNameIsGiven::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';

sub _build_message {
    "You need to give attribute or attribute_name or both";
}

1;
