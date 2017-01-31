package Moose::Exception::MetaclassMustBeDerivedFromClassMOPClass;
BEGIN {
  $Moose::Exception::MetaclassMustBeDerivedFromClassMOPClass::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::MetaclassMustBeDerivedFromClassMOPClass::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';

has 'class_name' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1
);

sub _build_message {
    my $self = shift;
    "The metaclass (".$self->class_name.") must be derived from Class::MOP::Class";
}

1;
