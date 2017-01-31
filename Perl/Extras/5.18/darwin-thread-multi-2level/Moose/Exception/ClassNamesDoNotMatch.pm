package Moose::Exception::ClassNamesDoNotMatch;
BEGIN {
  $Moose::Exception::ClassNamesDoNotMatch::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::ClassNamesDoNotMatch::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';

has class_name => (
    is       => 'ro',
    isa      => 'Str',
    required => 1,
);

has class => (
    is       => 'ro',
    isa      => 'Class::MOP::Class',
    required => 1,
);

sub _build_message {
    my $self = shift;
    "class_name (".$self-> class_name.") does not match class->name (".$self->class->name.")";
}

1;
