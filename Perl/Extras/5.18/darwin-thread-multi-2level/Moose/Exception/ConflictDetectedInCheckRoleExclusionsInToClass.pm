package Moose::Exception::ConflictDetectedInCheckRoleExclusionsInToClass;
BEGIN {
  $Moose::Exception::ConflictDetectedInCheckRoleExclusionsInToClass::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::ConflictDetectedInCheckRoleExclusionsInToClass::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Class', 'Moose::Exception::Role::Role';

sub _build_message {
    my $self = shift;
    "Conflict detected: " . $self->class->name . " excludes role '" . $self->role->name . "'";
}

1;
