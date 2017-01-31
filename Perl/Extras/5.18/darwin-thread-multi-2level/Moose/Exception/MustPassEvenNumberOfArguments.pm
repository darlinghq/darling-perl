package Moose::Exception::MustPassEvenNumberOfArguments;
BEGIN {
  $Moose::Exception::MustPassEvenNumberOfArguments::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::MustPassEvenNumberOfArguments::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';

has 'args' => (
    is         => 'ro',
    isa        => 'ArrayRef',
    required   => 1
);

has 'method_name' => (
    is         => 'ro',
    isa        => 'Str',
    required   => 1
);

sub _build_message {
    my $self = shift;
    "You must pass an even number of arguments to ".$self->method_name;
}

1;
