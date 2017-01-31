# This file is auto-generated by the Perl DateTime Suite time zone
# code generator (0.07) This code generator comes with the
# DateTime::TimeZone module distribution in the tools/ directory

#
# Generated from /tmp/R1hmpaTdno/northamerica.  Olson data version 2012g
#
# Do not edit this file directly.
#
package DateTime::TimeZone::America::Creston;
{
  $DateTime::TimeZone::America::Creston::VERSION = '1.51';
}

use strict;

use Class::Singleton 1.03;
use DateTime::TimeZone;
use DateTime::TimeZone::OlsonDB;

@DateTime::TimeZone::America::Creston::ISA = ( 'Class::Singleton', 'DateTime::TimeZone' );

my $spans =
[
    [
DateTime::TimeZone::NEG_INFINITY,
59421800764,
DateTime::TimeZone::NEG_INFINITY,
59421772800,
-27964,
0,
'LMT'
    ],
    [
59421800764,
60455228400,
59421775564,
60455203200,
-25200,
0,
'MST'
    ],
    [
60455228400,
60507849600,
60455199600,
60507820800,
-28800,
0,
'PST'
    ],
    [
60507849600,
DateTime::TimeZone::INFINITY,
60507824400,
DateTime::TimeZone::INFINITY,
-25200,
0,
'MST'
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

