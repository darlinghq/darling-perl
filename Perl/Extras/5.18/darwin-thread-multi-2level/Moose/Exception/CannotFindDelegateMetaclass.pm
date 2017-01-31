package Moose::Exception::CannotFindDelegateMetaclass;
BEGIN {
  $Moose::Exception::CannotFindDelegateMetaclass::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::CannotFindDelegateMetaclass::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Attribute';

sub _build_message {
    my $self = shift;
    "Cannot find delegate metaclass for attribute ".$self->attribute->name;
}

1;
