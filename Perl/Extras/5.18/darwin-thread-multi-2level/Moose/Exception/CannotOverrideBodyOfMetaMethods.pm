package Moose::Exception::CannotOverrideBodyOfMetaMethods;
BEGIN {
  $Moose::Exception::CannotOverrideBodyOfMetaMethods::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::CannotOverrideBodyOfMetaMethods::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::ParamsHash';

has 'class' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1
);

sub _build_message {
    "Overriding the body of meta methods is not allowed";
}

1;
