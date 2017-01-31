package Moose::Exception::Role::Method;
BEGIN {
  $Moose::Exception::Role::Method::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::Role::Method::VERSION = '2.1202';
use Moose::Role;

has 'method' => (
    is       => 'ro',
    isa      => 'Moose::Meta::Method',
    required => 1,
);

1;
