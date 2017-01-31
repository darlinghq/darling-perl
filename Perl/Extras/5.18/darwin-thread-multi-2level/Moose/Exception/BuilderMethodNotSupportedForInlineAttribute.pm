package Moose::Exception::BuilderMethodNotSupportedForInlineAttribute;
BEGIN {
  $Moose::Exception::BuilderMethodNotSupportedForInlineAttribute::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::BuilderMethodNotSupportedForInlineAttribute::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Instance', 'Moose::Exception::Role::Class';

has 'attribute_name' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1
);

has 'builder' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1
);

sub _build_message {
    my $self = shift;
    $self->class_name." does not support builder method '". $self->builder ."' for attribute '" . $self->attribute_name . "'";
}

1;
