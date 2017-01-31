package Moose::Exception::MetaclassMustBeASubclassOfMooseMetaClass;
BEGIN {
  $Moose::Exception::MetaclassMustBeASubclassOfMooseMetaClass::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::MetaclassMustBeASubclassOfMooseMetaClass::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Class';

sub _build_message {
    my $self = shift;
    "The Metaclass ".$self->class_name." must be a subclass of Moose::Meta::Class."
}

1;
