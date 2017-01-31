package Moose::Exception::TypeNamesDoNotMatch;
BEGIN {
  $Moose::Exception::TypeNamesDoNotMatch::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::TypeNamesDoNotMatch::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';

has type_name => (
    is       => 'ro',
    isa      => 'Str',
    required => 1,
);

has type => (
    is       => 'ro',
    isa      => 'Moose::Meta::TypeConstraint',
    required => 1,
);

sub _build_message {
    my $self = shift;
    "type_name (".$self-> type_name.") does not match type->name (".$self->type->name.")";
}

1;
