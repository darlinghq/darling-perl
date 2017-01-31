package Moose::Exception::EnumCalledWithAnArrayRefAndAdditionalArgs;
BEGIN {
  $Moose::Exception::EnumCalledWithAnArrayRefAndAdditionalArgs::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::EnumCalledWithAnArrayRefAndAdditionalArgs::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';

has 'array' => (
    is       => 'ro',
    isa      => 'ArrayRef',
    required => 1
);

has 'args' => (
    is       => 'ro',
    isa      => 'ArrayRef',
    required => 1
);

sub _build_message {
    "enum called with an array reference and additional arguments. Did you mean to parenthesize the enum call's parameters?";
}

1;
