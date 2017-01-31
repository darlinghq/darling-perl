package Moose::Exception::CanOnlyWrapBlessedCode;
BEGIN {
  $Moose::Exception::CanOnlyWrapBlessedCode::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::CanOnlyWrapBlessedCode::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::ParamsHash';

has 'class' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1
);

has 'code' => (
    is       => 'ro',
    isa      => 'Any',
    required => 1
);

sub _build_message {
    "Can only wrap blessed CODE";
}

1;
