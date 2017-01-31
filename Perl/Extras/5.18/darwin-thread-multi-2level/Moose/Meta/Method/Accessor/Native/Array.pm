package Moose::Meta::Method::Accessor::Native::Array;
BEGIN {
  $Moose::Meta::Method::Accessor::Native::Array::AUTHORITY = 'cpan:STEVAN';
}
$Moose::Meta::Method::Accessor::Native::Array::VERSION = '2.1202';
use strict;
use warnings;

use Moose::Role;

use Scalar::Util qw( looks_like_number );

sub _inline_check_var_is_valid_index {
    my $self = shift;
    my ($var) = @_;

    return (
        'if (!defined(' . $var . ') || ' . $var . ' !~ /^-?\d+$/) {',
            $self->_inline_throw_exception( "InvalidArgumentToMethod => ".
                                            'argument                => '.$var.','.
                                            'method_name             => "'.$self->delegate_to_method.'",'.
                                            'type_of_argument        => "integer",'.
                                            'type                    => "Int",'.
                                            'argument_noun           => "index"',
            ) . ';',
        '}',
    );
}

no Moose::Role;

1;
