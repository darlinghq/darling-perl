package Moose::Exception::CannotCalculateNativeType;
BEGIN {
  $Moose::Exception::CannotCalculateNativeType::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::CannotCalculateNativeType::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Instance';

sub _build_message {
    my $self = shift;
    "Cannot calculate native type for " . ref $self->instance;
}

1;
