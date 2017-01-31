package Moose::Exception::MustProvideANameForTheAttribute;
BEGIN {
  $Moose::Exception::MustProvideANameForTheAttribute::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::MustProvideANameForTheAttribute::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::ParamsHash';

has 'class' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1
);

sub _build_message {
    "You must provide a name for the attribute";
}

1;
