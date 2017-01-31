package Moose::Exception::UnionCalledWithAnArrayRefAndAdditionalArgs;
BEGIN {
  $Moose::Exception::UnionCalledWithAnArrayRefAndAdditionalArgs::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::UnionCalledWithAnArrayRefAndAdditionalArgs::VERSION = '2.1202';
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
    "union called with an array reference and additional arguments";
}

1;
