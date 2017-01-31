package Moose::Exception::Role::ParamsHash;
BEGIN {
  $Moose::Exception::Role::ParamsHash::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::Role::ParamsHash::VERSION = '2.1202';
use Moose::Role;

has 'params' => (
    is       => 'ro',
    isa      => 'HashRef',
    required => 1,
);

1;
