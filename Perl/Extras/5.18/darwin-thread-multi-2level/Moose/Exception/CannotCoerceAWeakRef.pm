package Moose::Exception::CannotCoerceAWeakRef;
BEGIN {
  $Moose::Exception::CannotCoerceAWeakRef::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::CannotCoerceAWeakRef::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::InvalidAttributeOptions';

sub _build_message {
    my $self = shift;
    "You cannot have a weak reference to a coerced value on attribute (".$self->attribute_name.")";
}

1;
