package Moose::Exception::MustHaveAtLeastOneValueToEnumerate;
BEGIN {
  $Moose::Exception::MustHaveAtLeastOneValueToEnumerate::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::MustHaveAtLeastOneValueToEnumerate::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::ParamsHash';

has 'class' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1
);

sub _build_message {
    "You must have at least one value to enumerate through";
}

1;
