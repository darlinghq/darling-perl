package Moose::Exception::CallingReadOnlyMethodOnAnImmutableInstance;
BEGIN {
  $Moose::Exception::CallingReadOnlyMethodOnAnImmutableInstance::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::CallingReadOnlyMethodOnAnImmutableInstance::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';

has 'method_name' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1
);

sub _build_message {
    my $self = shift;
    "The '".$self->method_name."' method is read-only when called on an immutable instance";
}

1;
