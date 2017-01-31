package Moose::Exception::MustSupplyAnAttributeToConstructWith;
BEGIN {
  $Moose::Exception::MustSupplyAnAttributeToConstructWith::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::MustSupplyAnAttributeToConstructWith::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::ParamsHash';

has 'class' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1
);

sub _build_message {
    "You must supply an attribute to construct with";
}

1;
