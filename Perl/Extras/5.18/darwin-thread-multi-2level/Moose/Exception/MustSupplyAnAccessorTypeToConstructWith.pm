package Moose::Exception::MustSupplyAnAccessorTypeToConstructWith;
BEGIN {
  $Moose::Exception::MustSupplyAnAccessorTypeToConstructWith::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::MustSupplyAnAccessorTypeToConstructWith::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::ParamsHash';

has 'class' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1
);

sub _build_message {
    "You must supply an accessor_type to construct with";
}

1;
