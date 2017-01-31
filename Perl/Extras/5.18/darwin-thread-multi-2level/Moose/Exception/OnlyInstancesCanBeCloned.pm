package Moose::Exception::OnlyInstancesCanBeCloned;
BEGIN {
  $Moose::Exception::OnlyInstancesCanBeCloned::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::OnlyInstancesCanBeCloned::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Class', 'Moose::Exception::Role::ParamsHash';

has 'instance' => (
    is       => 'ro',
    isa      => 'Any',
    required => 1,
);

sub _build_message {
    my $self = shift;
    "You can only clone instances, (".$self->instance.") is not a blessed instance";
}

1;
