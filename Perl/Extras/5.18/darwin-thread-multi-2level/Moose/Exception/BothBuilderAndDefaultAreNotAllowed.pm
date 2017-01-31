package Moose::Exception::BothBuilderAndDefaultAreNotAllowed;
BEGIN {
  $Moose::Exception::BothBuilderAndDefaultAreNotAllowed::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::BothBuilderAndDefaultAreNotAllowed::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::ParamsHash';

has 'class' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1
);

sub _build_message {
    "Setting both default and builder is not allowed.";
}

1;
