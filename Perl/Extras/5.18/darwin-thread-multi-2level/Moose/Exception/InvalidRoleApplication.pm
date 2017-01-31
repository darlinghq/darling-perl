package Moose::Exception::InvalidRoleApplication;
BEGIN {
  $Moose::Exception::InvalidRoleApplication::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::InvalidRoleApplication::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Class';

has 'application' => (
    is       => 'ro',
    isa      => "Any",
    required => 1,
);

sub _build_message {
    "Role applications must be instances of Moose::Meta::Role::Application::ToClass";
}

1;
