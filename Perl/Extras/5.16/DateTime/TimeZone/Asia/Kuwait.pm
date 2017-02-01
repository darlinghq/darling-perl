# This file is auto-generated by the Perl DateTime Suite time zone
# code generator (0.07) This code generator comes with the
# DateTime::TimeZone module distribution in the tools/ directory

#
# Generated from /tmp/R1hmpaTdno/asia.  Olson data version 2012g
#
# Do not edit this file directly.
#
package DateTime::TimeZone::Asia::Kuwait;
{
  $DateTime::TimeZone::Asia::Kuwait::VERSION = '1.51';
}

use strict;

use Class::Singleton 1.03;
use DateTime::TimeZone;
use DateTime::TimeZone::OlsonDB;

@DateTime::TimeZone::Asia::Kuwait::ISA = ( 'Class::Singleton', 'DateTime::TimeZone' );

my $spans =
[
    [
DateTime::TimeZone::NEG_INFINITY,
61504519684,
DateTime::TimeZone::NEG_INFINITY,
61504531200,
11516,
0,
'LMT'
    ],
    [
61504519684,
DateTime::TimeZone::INFINITY,
61504530484,
DateTime::TimeZone::INFINITY,
10800,
0,
'AST'
    ],
];

sub olson_version { '2012g' }

sub has_dst_changes { 0 }

sub _max_year { 2022 }

sub _new_instance
{
    return shift->_init( @_, spans => $spans );
}



1;
