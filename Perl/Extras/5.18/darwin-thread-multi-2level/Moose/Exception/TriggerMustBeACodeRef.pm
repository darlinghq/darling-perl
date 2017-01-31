package Moose::Exception::TriggerMustBeACodeRef;
BEGIN {
  $Moose::Exception::TriggerMustBeACodeRef::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::TriggerMustBeACodeRef::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::InvalidAttributeOptions';

sub _build_message {
    my $self = shift;
    "Trigger must be a CODE ref on attribute (".$self->attribute_name.")";
}

1;
