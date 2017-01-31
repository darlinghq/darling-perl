package Moose::Exception::CanExtendOnlyClasses;
BEGIN {
  $Moose::Exception::CanExtendOnlyClasses::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::CanExtendOnlyClasses::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';

has 'role' => (
    is       => 'ro',
    isa      => 'Moose::Meta::Role',
    required => 1,
);

sub _build_message {
    my $self = shift;
    "You cannot inherit from a Moose Role (".$self->role->name.")";
}

1;
