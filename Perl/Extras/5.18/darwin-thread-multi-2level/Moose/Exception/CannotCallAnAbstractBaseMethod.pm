package Moose::Exception::CannotCallAnAbstractBaseMethod;
BEGIN {
  $Moose::Exception::CannotCallAnAbstractBaseMethod::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::CannotCallAnAbstractBaseMethod::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';

has 'package_name' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1
);

sub _build_message {
    my $self = shift;
    $self->package_name. " is an abstract base class, you must provide a constructor.";
}

1;
