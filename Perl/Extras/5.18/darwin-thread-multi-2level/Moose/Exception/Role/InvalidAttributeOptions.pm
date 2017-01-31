package Moose::Exception::Role::InvalidAttributeOptions;
BEGIN {
  $Moose::Exception::Role::InvalidAttributeOptions::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::Role::InvalidAttributeOptions::VERSION = '2.1202';
use Moose::Role;
with 'Moose::Exception::Role::ParamsHash';

has 'attribute_name' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1,
);

1;
