package Moose::Exception::CannotCreateMethodAliasLocalMethodIsPresent;
BEGIN {
  $Moose::Exception::CannotCreateMethodAliasLocalMethodIsPresent::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::CannotCreateMethodAliasLocalMethodIsPresent::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Role', 'Moose::Exception::Role::Method';

has 'role_being_applied' => (
    is       => 'ro',
    isa      => 'Moose::Meta::Role',
    required => 1
);

has 'aliased_method_name' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1
);

sub _build_message {
    "Cannot create a method alias if a local method of the same name exists";
}

1;
