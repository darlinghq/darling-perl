package Moose::Exception::CanReblessOnlyIntoASuperclass;
BEGIN {
  $Moose::Exception::CanReblessOnlyIntoASuperclass::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::CanReblessOnlyIntoASuperclass::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Class', 'Moose::Exception::Role::Instance';

sub _build_message {
    my $self = shift;
    "You may rebless only into a superclass of (".blessed( $self->instance )."), of which (". $self->class->name .") isn't."
}

1;
