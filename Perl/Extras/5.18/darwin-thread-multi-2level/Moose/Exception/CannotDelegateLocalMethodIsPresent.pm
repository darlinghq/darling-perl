package Moose::Exception::CannotDelegateLocalMethodIsPresent;
BEGIN {
  $Moose::Exception::CannotDelegateLocalMethodIsPresent::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::CannotDelegateLocalMethodIsPresent::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Attribute', 'Moose::Exception::Role::Method';

sub _build_message {
    my $self = shift;
    "You cannot overwrite a locally defined method (".$self->method->name.") with a delegation";
}

1;
