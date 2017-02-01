# This file is auto-generated by the Perl DateTime Suite time zone
# code generator (0.07) This code generator comes with the
# DateTime::TimeZone module distribution in the tools/ directory

#
# Generated from /tmp/R1hmpaTdno/australasia.  Olson data version 2012g
#
# Do not edit this file directly.
#
package DateTime::TimeZone::Pacific::Fakaofo;
{
  $DateTime::TimeZone::Pacific::Fakaofo::VERSION = '1.51';
}

use strict;

use Class::Singleton 1.03;
use DateTime::TimeZone;
use DateTime::TimeZone::OlsonDB;

@DateTime::TimeZone::Pacific::Fakaofo::ISA = ( 'Class::Singleton', 'DateTime::TimeZone' );

my $spans =
[
    [
DateTime::TimeZone::NEG_INFINITY,
59958271496,
DateTime::TimeZone::NEG_INFINITY,
59958230400,
-41096,
0,
'LMT'
    ],
    [
59958271496,
63460926000,
59958231896,
63460886400,
-39600,
0,
'TKT'
    ],
    [
63460926000,
DateTime::TimeZone::INFINITY,
63460972800,
DateTime::TimeZone::INFINITY,
46800,
0,
'TKT'
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
