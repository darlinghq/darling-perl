package Moose::Exception::NoImmutableTraitSpecifiedForClass;
BEGIN {
  $Moose::Exception::NoImmutableTraitSpecifiedForClass::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::NoImmutableTraitSpecifiedForClass::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Class', 'Moose::Exception::Role::ParamsHash';

sub _build_message {
    my $self = shift;
    "no immutable trait specified for ".$self->class;
}

1;
