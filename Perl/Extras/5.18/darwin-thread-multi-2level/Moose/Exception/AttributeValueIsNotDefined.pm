package Moose::Exception::AttributeValueIsNotDefined;
BEGIN {
  $Moose::Exception::AttributeValueIsNotDefined::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::AttributeValueIsNotDefined::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Instance', 'Moose::Exception::Role::Attribute';

has 'method' => (
    is       => 'ro',
    isa      => 'Moose::Meta::Method::Delegation',
    required => 1,
);

sub _build_message {
    my $self = shift;
    "Cannot delegate ".$self->method->name." to "
    .$self->method->delegate_to_method." because the value of "
    . $self->attribute->name . " is not defined";
}

1;
