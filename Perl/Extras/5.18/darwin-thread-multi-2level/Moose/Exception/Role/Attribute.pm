package Moose::Exception::Role::Attribute;
BEGIN {
  $Moose::Exception::Role::Attribute::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::Role::Attribute::VERSION = '2.1202';
use Moose::Role;

has 'attribute' => (
    is        => 'ro',
    isa       => 'Class::MOP::Attribute',
    predicate => 'is_attribute_set'
);

1;
