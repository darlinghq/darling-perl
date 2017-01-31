package Moose::Exception::RoleNamesDoNotMatch;
BEGIN {
  $Moose::Exception::RoleNamesDoNotMatch::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::RoleNamesDoNotMatch::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';

has role_name => (
    is       => 'ro',
    isa      => 'Str',
    required => 1,
);

has role => (
    is       => 'ro',
    isa      => 'Moose::Meta::Role',
    required => 1,
);

sub _build_message {
    my $self = shift;
    "role_name (".$self-> role_name.") does not match role->name (".$self->role->name.")";
}

1;
