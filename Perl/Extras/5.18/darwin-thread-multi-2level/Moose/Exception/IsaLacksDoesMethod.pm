package Moose::Exception::IsaLacksDoesMethod;
BEGIN {
  $Moose::Exception::IsaLacksDoesMethod::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::IsaLacksDoesMethod::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::InvalidAttributeOptions';

sub _build_message {
    my $self = shift;
    "Cannot have an isa option which cannot ->does() on attribute (".$self->attribute_name.")";
}

1;
