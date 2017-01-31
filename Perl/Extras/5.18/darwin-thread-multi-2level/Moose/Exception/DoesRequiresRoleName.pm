package Moose::Exception::DoesRequiresRoleName;
BEGIN {
  $Moose::Exception::DoesRequiresRoleName::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::DoesRequiresRoleName::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';

has 'class' => (
    is       => 'ro',
    isa      => 'Moose::Meta::Class',
    required => 1,
);

sub _build_message {
    "You must supply a role name to does()";
}

1;
