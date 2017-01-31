package Moose::Exception::MustPassEvenNumberOfAttributeOptions;
BEGIN {
  $Moose::Exception::MustPassEvenNumberOfAttributeOptions::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::MustPassEvenNumberOfAttributeOptions::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';

has 'options' => (
    is       => 'ro',
    isa      => 'ArrayRef',
    required => 1
);

has 'attribute_name' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1,
);

sub _build_message {
    return 'You must pass an even number of attribute options';
}

1;
