package Moose::Exception::RolesDoNotSupportRegexReferencesForMethodModifiers;
BEGIN {
  $Moose::Exception::RolesDoNotSupportRegexReferencesForMethodModifiers::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::RolesDoNotSupportRegexReferencesForMethodModifiers::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Role';

has 'modifier_type' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1
);

sub _build_message {
    my $self = shift;
    "Roles do not currently support regex references for ".$self->modifier_type." method modifiers";
}

1;
