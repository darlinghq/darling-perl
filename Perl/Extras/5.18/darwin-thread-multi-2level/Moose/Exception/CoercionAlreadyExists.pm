package Moose::Exception::CoercionAlreadyExists;
BEGIN {
  $Moose::Exception::CoercionAlreadyExists::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::CoercionAlreadyExists::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Instance';

has 'constraint_name' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1
);

sub _build_message {
    my $self = shift;
    "A coercion action already exists for '".$self->constraint_name."'";
}

1;
