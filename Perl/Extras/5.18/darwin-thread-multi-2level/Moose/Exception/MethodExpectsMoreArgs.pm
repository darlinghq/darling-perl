package Moose::Exception::MethodExpectsMoreArgs;
BEGIN {
  $Moose::Exception::MethodExpectsMoreArgs::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::MethodExpectsMoreArgs::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';

has 'method_name' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1
);

has 'minimum_args' => (
    is       => 'ro',
    isa      => 'Int',
    required => 1
);

sub _build_message {
    my $self = shift;
    "Cannot call ".$self->method_name." without at least ".$self->minimum_args." argument".($self->minimum_args == 1 ? '' : 's');
}

1;
