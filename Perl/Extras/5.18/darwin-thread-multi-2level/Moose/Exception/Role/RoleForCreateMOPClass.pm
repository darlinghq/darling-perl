package Moose::Exception::Role::RoleForCreateMOPClass;
BEGIN {
  $Moose::Exception::Role::RoleForCreateMOPClass::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::Role::RoleForCreateMOPClass::VERSION = '2.1202';
use Moose::Role;
with 'Moose::Exception::Role::ParamsHash';

has 'class' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1,
);

1;

