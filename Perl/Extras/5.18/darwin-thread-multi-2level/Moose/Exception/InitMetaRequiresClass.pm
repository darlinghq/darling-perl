package Moose::Exception::InitMetaRequiresClass;
BEGIN {
  $Moose::Exception::InitMetaRequiresClass::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Exception::InitMetaRequiresClass::VERSION = '2.1202';
use Moose;
extends 'Moose::Exception';
with 'Moose::Exception::Role::ParamsHash';

sub _build_message {
    "Cannot call init_meta without specifying a for_class";
}

1;
