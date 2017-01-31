package Moose::Exception::InvalidNameForType;
BEGIN {
  $Moose::Exception::InvalidNameForType::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::InvalidNameForType::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';

has 'name' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1,
);

sub _build_message {
    my $self = shift;
    $self->name." contains invalid characters for a type name. Names can contain alphanumeric character, ':', and '.'";
}
1;
