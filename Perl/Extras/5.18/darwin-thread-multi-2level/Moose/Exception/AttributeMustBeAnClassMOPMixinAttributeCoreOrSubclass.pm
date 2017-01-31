package Moose::Exception::AttributeMustBeAnClassMOPMixinAttributeCoreOrSubclass;
BEGIN {
  $Moose::Exception::AttributeMustBeAnClassMOPMixinAttributeCoreOrSubclass::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::AttributeMustBeAnClassMOPMixinAttributeCoreOrSubclass::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Class';

has 'attribute' => (
    is       => 'ro',
    isa      => 'Any',
    required => 1
);

sub _build_message {
    "Your attribute must be an instance of Class::MOP::Mixin::AttributeCore (or a subclass)";
}

1;
