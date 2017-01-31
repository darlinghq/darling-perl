package Moose::Exception::InvalidHasProvidedInARole;
BEGIN {
  $Moose::Exception::InvalidHasProvidedInARole::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::InvalidHasProvidedInARole::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Role';

has 'attribute_name' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1,
);

sub _build_message {
    "Usage: has 'name' => ( key => value, ... )";
}

1;
