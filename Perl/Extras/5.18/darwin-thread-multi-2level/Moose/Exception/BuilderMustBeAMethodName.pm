package Moose::Exception::BuilderMustBeAMethodName;
BEGIN {
  $Moose::Exception::BuilderMustBeAMethodName::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::BuilderMustBeAMethodName::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::ParamsHash';

has 'class' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1
);

sub _build_message {
    "builder must be a defined scalar value which is a method name";
}

1;
