package Moose::Exception::InitializeTakesUnBlessedPackageName;
BEGIN {
  $Moose::Exception::InitializeTakesUnBlessedPackageName::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::InitializeTakesUnBlessedPackageName::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';

has 'package_name' => (
    is       => 'ro',
    isa      => 'Any',
    required => 1,
);

sub _build_message {
    "You must pass a package name and it cannot be blessed";
}

1;
