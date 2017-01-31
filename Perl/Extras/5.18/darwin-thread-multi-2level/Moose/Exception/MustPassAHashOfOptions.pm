package Moose::Exception::MustPassAHashOfOptions;
BEGIN {
  $Moose::Exception::MustPassAHashOfOptions::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::MustPassAHashOfOptions::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::ParamsHash';

has 'class' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1
);

sub _build_message {
    "You must pass a hash of options";
}

1;
