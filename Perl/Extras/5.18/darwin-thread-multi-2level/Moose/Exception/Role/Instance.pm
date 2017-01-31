package Moose::Exception::Role::Instance;
BEGIN {
  $Moose::Exception::Role::Instance::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::Role::Instance::VERSION = '2.1202';
use Moose::Role;

has 'instance' => (
    is       => 'ro',
    isa      => 'Object',
    required => 1,
);

1;
