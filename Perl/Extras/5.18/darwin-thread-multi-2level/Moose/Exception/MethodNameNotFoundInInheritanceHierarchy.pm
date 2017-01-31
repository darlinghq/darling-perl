package Moose::Exception::MethodNameNotFoundInInheritanceHierarchy;
BEGIN {
  $Moose::Exception::MethodNameNotFoundInInheritanceHierarchy::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::MethodNameNotFoundInInheritanceHierarchy::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Class';

has 'method_name' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1
);

sub _build_message {
    my $self = shift;
    "The method '".$self->method_name."' was not found in the inheritance hierarchy for ".$self->class->name;
}

1;
