package Moose::Exception::CanReblessOnlyIntoASubclass;
BEGIN {
  $Moose::Exception::CanReblessOnlyIntoASubclass::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::CanReblessOnlyIntoASubclass::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::ParamsHash', 'Moose::Exception::Role::Class', 'Moose::Exception::Role::Instance';

sub _build_message {
    my $self = shift;
    "You may rebless only into a subclass of (".blessed( $self->instance )."), of which (". $self->class->name .") isn't."
}

1;
