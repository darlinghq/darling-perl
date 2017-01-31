package Moose::Exception::UnableToRecognizeDelegateMetaclass;
BEGIN {
  $Moose::Exception::UnableToRecognizeDelegateMetaclass::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::UnableToRecognizeDelegateMetaclass::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Attribute';

has 'delegate_metaclass' => (
    is       => 'ro',
    isa      => 'Any',
    required => 1
);

sub _build_message {
    my $self = shift;
    my $meta = $self->delegate_metaclass;

    return "Unable to recognize the delegate metaclass '$meta'";
}

1;
