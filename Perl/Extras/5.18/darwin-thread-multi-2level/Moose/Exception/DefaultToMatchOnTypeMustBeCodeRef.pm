package Moose::Exception::DefaultToMatchOnTypeMustBeCodeRef;
BEGIN {
  $Moose::Exception::DefaultToMatchOnTypeMustBeCodeRef::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::DefaultToMatchOnTypeMustBeCodeRef::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';

has 'to_match' => (
    is       => 'ro',
    isa      => 'Any',
    required => 1
);

has 'default_action' => (
    is       => 'ro',
    isa      => 'Any',
    required => 1
);

has 'cases_to_be_matched' => (
    is       => 'ro',
    isa      => 'ArrayRef',
    required => 1
);

sub _build_message {
    my $self = shift;
    my $default = $self->default_action;

    return "Default case must be a CODE ref, not $default";
}

1;
