package Moose::Exception::NoParentGivenToSubtype;
BEGIN {
  $Moose::Exception::NoParentGivenToSubtype::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::NoParentGivenToSubtype::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';

has 'name' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1
);

sub _build_message {
    "A subtype cannot consist solely of a name, it must have a parent";
}

1;
