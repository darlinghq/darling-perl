package Moose::Exception::OperatorIsRequired;
BEGIN {
  $Moose::Exception::OperatorIsRequired::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::OperatorIsRequired::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::ParamsHash';

has 'class' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1
);

sub _build_message {
    "operator is required";
}

1;
