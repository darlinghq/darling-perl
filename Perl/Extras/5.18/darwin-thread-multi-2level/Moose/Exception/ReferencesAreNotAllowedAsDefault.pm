package Moose::Exception::ReferencesAreNotAllowedAsDefault;
BEGIN {
  $Moose::Exception::ReferencesAreNotAllowedAsDefault::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::ReferencesAreNotAllowedAsDefault::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::ParamsHash';

has 'class' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1
);

has 'attribute_name' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1
);

sub _build_message {
    my $self = shift;
    "References are not allowed as default values, you must wrap the default of '".
        $self->attribute_name."' in a CODE reference (ex: sub { [] } and not [])";
}

1;
