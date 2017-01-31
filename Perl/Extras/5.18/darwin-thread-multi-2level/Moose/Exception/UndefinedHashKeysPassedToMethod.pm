package Moose::Exception::UndefinedHashKeysPassedToMethod;
BEGIN {
  $Moose::Exception::UndefinedHashKeysPassedToMethod::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::UndefinedHashKeysPassedToMethod::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';

has 'hash_keys' => (
    is         => 'ro',
    isa        => 'ArrayRef',
    required   => 1
);

has 'method_name' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1
);

sub _build_message {
    my $self = shift;
    "Hash keys passed to ".$self->method_name." must be defined";
}

1;
