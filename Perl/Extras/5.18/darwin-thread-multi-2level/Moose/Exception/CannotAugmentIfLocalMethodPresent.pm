package Moose::Exception::CannotAugmentIfLocalMethodPresent;
BEGIN {
  $Moose::Exception::CannotAugmentIfLocalMethodPresent::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::CannotAugmentIfLocalMethodPresent::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::Class', 'Moose::Exception::Role::Method';

sub _build_message {
    "Cannot add an augment method if a local method is already present";
}

1;
