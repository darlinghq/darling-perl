package Moose::Exception::UnionTakesAtleastTwoTypeNames;
BEGIN {
  $Moose::Exception::UnionTakesAtleastTwoTypeNames::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::UnionTakesAtleastTwoTypeNames::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';

sub _build_message {
    "You must pass in at least 2 type names to make a union";
}

1;
