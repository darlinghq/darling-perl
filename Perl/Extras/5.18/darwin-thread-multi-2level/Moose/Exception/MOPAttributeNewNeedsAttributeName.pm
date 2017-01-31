package Moose::Exception::MOPAttributeNewNeedsAttributeName;
BEGIN {
  $Moose::Exception::MOPAttributeNewNeedsAttributeName::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::MOPAttributeNewNeedsAttributeName::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::ParamsHash';

has 'class' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1
);

sub _build_message {
    "You must provide a name for the attribute";
}

1;
