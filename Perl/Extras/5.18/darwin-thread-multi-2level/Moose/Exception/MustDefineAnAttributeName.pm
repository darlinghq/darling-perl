package Moose::Exception::MustDefineAnAttributeName;
BEGIN {
  $Moose::Exception::MustDefineAnAttributeName::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::MustDefineAnAttributeName::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Class';

sub _build_message {
    "You must define an attribute name";
}

1;
