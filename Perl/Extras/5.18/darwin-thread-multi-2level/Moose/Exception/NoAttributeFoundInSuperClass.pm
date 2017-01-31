package Moose::Exception::NoAttributeFoundInSuperClass;
BEGIN {
  $Moose::Exception::NoAttributeFoundInSuperClass::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::NoAttributeFoundInSuperClass::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Class', 'Moose::Exception::Role::InvalidAttributeOptions';

sub _build_message {
    my $self = shift;
    "Could not find an attribute by the name of '".$self->attribute_name."' to inherit from in ".$self->class->name;
}

1;
