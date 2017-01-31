package Moose::Exception::AttachToClassNeedsAClassMOPClassInstanceOrASubclass;
BEGIN {
  $Moose::Exception::AttachToClassNeedsAClassMOPClassInstanceOrASubclass::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::AttachToClassNeedsAClassMOPClassInstanceOrASubclass::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Attribute';

has 'class' => (
    is       => 'ro',
    isa      => 'Any',
    required => 1
);

sub _build_message {
    "You must pass a Class::MOP::Class instance (or a subclass)";
}

1;
