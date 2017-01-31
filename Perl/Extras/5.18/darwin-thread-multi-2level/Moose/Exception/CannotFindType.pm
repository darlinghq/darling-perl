package Moose::Exception::CannotFindType;
BEGIN {
  $Moose::Exception::CannotFindType::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::CannotFindType::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';

has 'type_name' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1
);

sub _build_message {
    my $self = shift;
    "Cannot find type '".$self->type_name."', perhaps you forgot to load it";
}

1;
