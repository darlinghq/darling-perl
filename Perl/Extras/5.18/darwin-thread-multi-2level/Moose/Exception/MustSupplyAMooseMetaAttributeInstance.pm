package Moose::Exception::MustSupplyAMooseMetaAttributeInstance;
BEGIN {
  $Moose::Exception::MustSupplyAMooseMetaAttributeInstance::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::MustSupplyAMooseMetaAttributeInstance::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::ParamsHash';

has 'class' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1
);

sub _build_message {
    "You must supply an attribute which is a 'Moose::Meta::Attribute' instance";
}

1;
