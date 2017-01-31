package Moose::Exception::IllegalInheritedOptions;
BEGIN {
  $Moose::Exception::IllegalInheritedOptions::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::IllegalInheritedOptions::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::ParamsHash';

has 'illegal_options' => (
    is       => 'ro',
    traits   => ['Array'],
    handles  => {
        _join_options => 'join',
    },
    required => 1,
);

sub _build_message {
    my $self = shift;
    "Illegal inherited options => (".$self->_join_options(', ').")";
}

1;
