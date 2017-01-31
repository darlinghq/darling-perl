package Moose::Exception::ConflictDetectedInCheckRoleExclusions;
BEGIN {
  $Moose::Exception::ConflictDetectedInCheckRoleExclusions::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::ConflictDetectedInCheckRoleExclusions::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Role';

has 'excluded_role' => (
    is       => 'ro',
    isa      => 'Moose::Meta::Role',
    required => 1
);

sub _build_message {
    my $self = shift;
    "Conflict detected: " . $self->role->name . " excludes role '" . $self->excluded_role->name . "'";
}

1;
