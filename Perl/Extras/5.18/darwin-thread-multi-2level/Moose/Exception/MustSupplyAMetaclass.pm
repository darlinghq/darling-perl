package Moose::Exception::MustSupplyAMetaclass;
BEGIN {
  $Moose::Exception::MustSupplyAMetaclass::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::MustSupplyAMetaclass::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::ParamsHash';

has 'class' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1
);

sub _build_message {
    my $self = shift;
    "You must pass a metaclass instance if you want to inline";
}

1;
