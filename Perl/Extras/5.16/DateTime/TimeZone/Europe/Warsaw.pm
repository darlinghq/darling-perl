# This file is auto-generated by the Perl DateTime Suite time zone
# code generator (0.07) This code generator comes with the
# DateTime::TimeZone module distribution in the tools/ directory

#
# Generated from /tmp/R1hmpaTdno/europe.  Olson data version 2012g
#
# Do not edit this file directly.
#
package DateTime::TimeZone::Europe::Warsaw;
{
  $DateTime::TimeZone::Europe::Warsaw::VERSION = '1.51';
}

use strict;

use Class::Singleton 1.03;
use DateTime::TimeZone;
use DateTime::TimeZone::OlsonDB;

@DateTime::TimeZone::Europe::Warsaw::ISA = ( 'Class::Singleton', 'DateTime::TimeZone' );

my $spans =
[
    [
DateTime::TimeZone::NEG_INFINITY,
59295537360,
DateTime::TimeZone::NEG_INFINITY,
59295542400,
5040,
0,
'LMT'
    ],
    [
59295537360,
60418650960,
59295542400,
60418656000,
5040,
0,
'WMT'
    ],
    [
60418650960,
60441976800,
60418654560,
60441980400,
3600,
0,
'CET'
    ],
    [
60441976800,
60455199600,
60441984000,
60455206800,
7200,
1,
'CEST'
    ],
    [
60455199600,
60472227600,
60455203200,
60472231200,
3600,
0,
'CET'
    ],
    [
60472227600,
60485533200,
60472234800,
60485540400,
7200,
1,
'CEST'
    ],
    [
60485533200,
60503677200,
60485536800,
60503680800,
3600,
0,
'CET'
    ],
    [
60503677200,
60516982800,
60503684400,
60516990000,
7200,
1,
'CEST'
    ],
    [
60516982800,
60535209600,
60516990000,
60535216800,
7200,
0,
'EET'
    ],
    [
60535209600,
60548515200,
60535220400,
60548526000,
10800,
1,
'EEST'
    ],
    [
60548515200,
60633957600,
60548522400,
60633964800,
7200,
0,
'EET'
    ],
    [
60633957600,
61203949200,
60633961200,
61203952800,
3600,
0,
'CET'
    ],
    [
61203949200,
61278426000,
61203956400,
61278433200,
7200,
1,
'CEST'
    ],
    [
61278426000,
61291126800,
61278429600,
61291130400,
3600,
0,
'CET'
    ],
    [
61291126800,
61307456400,
61291134000,
61307463600,
7200,
1,
'CEST'
    ],
    [
61307456400,
61323181200,
61307460000,
61323184800,
3600,
0,
'CET'
    ],
    [
61323181200,
61338808800,
61323188400,
61338816000,
7200,
1,
'CEST'
    ],
    [
61338808800,
61339075200,
61338816000,
61339082400,
7200,
1,
'CEST'
    ],
    [
61339075200,
61356956400,
61339078800,
61356960000,
3600,
0,
'CET'
    ],
    [
61356956400,
61373023200,
61356963600,
61373030400,
7200,
1,
'CEST'
    ],
    [
61373023200,
61387196400,
61373026800,
61387200000,
3600,
0,
'CET'
    ],
    [
61387196400,
61402410000,
61387203600,
61402417200,
7200,
1,
'CEST'
    ],
    [
61402410000,
61420467600,
61402413600,
61420471200,
3600,
0,
'CET'
    ],
    [
61420467600,
61433773200,
61420474800,
61433780400,
7200,
1,
'CEST'
    ],
    [
61433773200,
61450707600,
61433776800,
61450711200,
3600,
0,
'CET'
    ],
    [
61450707600,
61465222800,
61450714800,
61465230000,
7200,
1,
'CEST'
    ],
    [
61465222800,
61481552400,
61465226400,
61481556000,
3600,
0,
'CET'
    ],
    [
61481552400,
61496672400,
61481559600,
61496679600,
7200,
1,
'CEST'
    ],
    [
61496672400,
61738588800,
61496676000,
61738592400,
3600,
0,
'CET'
    ],
    [
61738588800,
61748870400,
61738596000,
61748877600,
7200,
1,
'CEST'
    ],
    [
61748870400,
61764595200,
61748874000,
61764598800,
3600,
0,
'CET'
    ],
    [
61764595200,
61780320000,
61764602400,
61780327200,
7200,
1,
'CEST'
    ],
    [
61780320000,
61801488000,
61780323600,
61801491600,
3600,
0,
'CET'
    ],
    [
61801488000,
61812374400,
61801495200,
61812381600,
7200,
1,
'CEST'
    ],
    [
61812374400,
61828099200,
61812378000,
61828102800,
3600,
0,
'CET'
    ],
    [
61828099200,
61843824000,
61828106400,
61843831200,
7200,
1,
'CEST'
    ],
    [
61843824000,
61864387200,
61843827600,
61864390800,
3600,
0,
'CET'
    ],
    [
61864387200,
61875273600,
61864394400,
61875280800,
7200,
1,
'CEST'
    ],
    [
61875273600,
61895836800,
61875277200,
61895840400,
3600,
0,
'CET'
    ],
    [
61895836800,
61906723200,
61895844000,
61906730400,
7200,
1,
'CEST'
    ],
    [
61906723200,
61927286400,
61906726800,
61927290000,
3600,
0,
'CET'
    ],
    [
61927286400,
61938172800,
61927293600,
61938180000,
7200,
1,
'CEST'
    ],
    [
61938172800,
61959340800,
61938176400,
61959344400,
3600,
0,
'CET'
    ],
    [
61959340800,
61969622400,
61959348000,
61969629600,
7200,
1,
'CEST'
    ],
    [
61969622400,
62356604400,
61969626000,
62356608000,
3600,
0,
'CET'
    ],
    [
62356604400,
62364556800,
62356608000,
62364560400,
3600,
0,
'CET'
    ],
    [
62364556800,
62379676800,
62364564000,
62379684000,
7200,
1,
'CEST'
    ],
    [
62379676800,
62396006400,
62379680400,
62396010000,
3600,
0,
'CET'
    ],
    [
62396006400,
62411731200,
62396013600,
62411738400,
7200,
1,
'CEST'
    ],
    [
62411731200,
62427456000,
62411734800,
62427459600,
3600,
0,
'CET'
    ],
    [
62427456000,
62443180800,
62427463200,
62443188000,
7200,
1,
'CEST'
    ],
    [
62443180800,
62459510400,
62443184400,
62459514000,
3600,
0,
'CET'
    ],
    [
62459510400,
62474630400,
62459517600,
62474637600,
7200,
1,
'CEST'
    ],
    [
62474630400,
62490355200,
62474634000,
62490358800,
3600,
0,
'CET'
    ],
    [
62490355200,
62506080000,
62490362400,
62506087200,
7200,
1,
'CEST'
    ],
    [
62506080000,
62521804800,
62506083600,
62521808400,
3600,
0,
'CET'
    ],
    [
62521804800,
62537529600,
62521812000,
62537536800,
7200,
1,
'CEST'
    ],
    [
62537529600,
62553254400,
62537533200,
62553258000,
3600,
0,
'CET'
    ],
    [
62553254400,
62568979200,
62553261600,
62568986400,
7200,
1,
'CEST'
    ],
    [
62568979200,
62584704000,
62568982800,
62584707600,
3600,
0,
'CET'
    ],
    [
62584704000,
62601033600,
62584711200,
62601040800,
7200,
1,
'CEST'
    ],
    [
62601033600,
62616758400,
62601037200,
62616762000,
3600,
0,
'CET'
    ],
    [
62616758400,
62632483200,
62616765600,
62632490400,
7200,
1,
'CEST'
    ],
    [
62632483200,
62648208000,
62632486800,
62648211600,
3600,
0,
'CET'
    ],
    [
62648208000,
62663932800,
62648215200,
62663940000,
7200,
1,
'CEST'
    ],
    [
62663932800,
62679657600,
62663936400,
62679661200,
3600,
0,
'CET'
    ],
    [
62679657600,
62695382400,
62679664800,
62695389600,
7200,
1,
'CEST'
    ],
    [
62695382400,
62703673200,
62695386000,
62703676800,
3600,
0,
'CET'
    ],
    [
62703673200,
62711110800,
62703676800,
62711114400,
3600,
0,
'CET'
    ],
    [
62711110800,
62726835600,
62711118000,
62726842800,
7200,
1,
'CEST'
    ],
    [
62726835600,
62742560400,
62726839200,
62742564000,
3600,
0,
'CET'
    ],
    [
62742560400,
62758285200,
62742567600,
62758292400,
7200,
1,
'CEST'
    ],
    [
62758285200,
62774010000,
62758288800,
62774013600,
3600,
0,
'CET'
    ],
    [
62774010000,
62790339600,
62774017200,
62790346800,
7200,
1,
'CEST'
    ],
    [
62790339600,
62806064400,
62790343200,
62806068000,
3600,
0,
'CET'
    ],
    [
62806064400,
62821789200,
62806071600,
62821796400,
7200,
1,
'CEST'
    ],
    [
62821789200,
62837514000,
62821792800,
62837517600,
3600,
0,
'CET'
    ],
    [
62837514000,
62853238800,
62837521200,
62853246000,
7200,
1,
'CEST'
    ],
    [
62853238800,
62868963600,
62853242400,
62868967200,
3600,
0,
'CET'
    ],
    [
62868963600,
62884688400,
62868970800,
62884695600,
7200,
1,
'CEST'
    ],
    [
62884688400,
62900413200,
62884692000,
62900416800,
3600,
0,
'CET'
    ],
    [
62900413200,
62916138000,
62900420400,
62916145200,
7200,
1,
'CEST'
    ],
    [
62916138000,
62931862800,
62916141600,
62931866400,
3600,
0,
'CET'
    ],
    [
62931862800,
62947587600,
62931870000,
62947594800,
7200,
1,
'CEST'
    ],
    [
62947587600,
62963917200,
62947591200,
62963920800,
3600,
0,
'CET'
    ],
    [
62963917200,
62982061200,
62963924400,
62982068400,
7200,
1,
'CEST'
    ],
    [
62982061200,
62995366800,
62982064800,
62995370400,
3600,
0,
'CET'
    ],
    [
62995366800,
63013510800,
62995374000,
63013518000,
7200,
1,
'CEST'
    ],
    [
63013510800,
63026816400,
63013514400,
63026820000,
3600,
0,
'CET'
    ],
    [
63026816400,
63044960400,
63026823600,
63044967600,
7200,
1,
'CEST'
    ],
    [
63044960400,
63058266000,
63044964000,
63058269600,
3600,
0,
'CET'
    ],
    [
63058266000,
63077014800,
63058273200,
63077022000,
7200,
1,
'CEST'
    ],
    [
63077014800,
63089715600,
63077018400,
63089719200,
3600,
0,
'CET'
    ],
    [
63089715600,
63108464400,
63089722800,
63108471600,
7200,
1,
'CEST'
    ],
    [
63108464400,
63121165200,
63108468000,
63121168800,
3600,
0,
'CET'
    ],
    [
63121165200,
63139914000,
63121172400,
63139921200,
7200,
1,
'CEST'
    ],
    [
63139914000,
63153219600,
63139917600,
63153223200,
3600,
0,
'CET'
    ],
    [
63153219600,
63171363600,
63153226800,
63171370800,
7200,
1,
'CEST'
    ],
    [
63171363600,
63184669200,
63171367200,
63184672800,
3600,
0,
'CET'
    ],
    [
63184669200,
63202813200,
63184676400,
63202820400,
7200,
1,
'CEST'
    ],
    [
63202813200,
63216118800,
63202816800,
63216122400,
3600,
0,
'CET'
    ],
    [
63216118800,
63234867600,
63216126000,
63234874800,
7200,
1,
'CEST'
    ],
    [
63234867600,
63247568400,
63234871200,
63247572000,
3600,
0,
'CET'
    ],
    [
63247568400,
63266317200,
63247575600,
63266324400,
7200,
1,
'CEST'
    ],
    [
63266317200,
63279018000,
63266320800,
63279021600,
3600,
0,
'CET'
    ],
    [
63279018000,
63297766800,
63279025200,
63297774000,
7200,
1,
'CEST'
    ],
    [
63297766800,
63310467600,
63297770400,
63310471200,
3600,
0,
'CET'
    ],
    [
63310467600,
63329216400,
63310474800,
63329223600,
7200,
1,
'CEST'
    ],
    [
63329216400,
63342522000,
63329220000,
63342525600,
3600,
0,
'CET'
    ],
    [
63342522000,
63360666000,
63342529200,
63360673200,
7200,
1,
'CEST'
    ],
    [
63360666000,
63373971600,
63360669600,
63373975200,
3600,
0,
'CET'
    ],
    [
63373971600,
63392115600,
63373978800,
63392122800,
7200,
1,
'CEST'
    ],
    [
63392115600,
63405421200,
63392119200,
63405424800,
3600,
0,
'CET'
    ],
    [
63405421200,
63424170000,
63405428400,
63424177200,
7200,
1,
'CEST'
    ],
    [
63424170000,
63436870800,
63424173600,
63436874400,
3600,
0,
'CET'
    ],
    [
63436870800,
63455619600,
63436878000,
63455626800,
7200,
1,
'CEST'
    ],
    [
63455619600,
63468320400,
63455623200,
63468324000,
3600,
0,
'CET'
    ],
    [
63468320400,
63487069200,
63468327600,
63487076400,
7200,
1,
'CEST'
    ],
    [
63487069200,
63500374800,
63487072800,
63500378400,
3600,
0,
'CET'
    ],
    [
63500374800,
63518518800,
63500382000,
63518526000,
7200,
1,
'CEST'
    ],
    [
63518518800,
63531824400,
63518522400,
63531828000,
3600,
0,
'CET'
    ],
    [
63531824400,
63549968400,
63531831600,
63549975600,
7200,
1,
'CEST'
    ],
    [
63549968400,
63563274000,
63549972000,
63563277600,
3600,
0,
'CET'
    ],
    [
63563274000,
63581418000,
63563281200,
63581425200,
7200,
1,
'CEST'
    ],
    [
63581418000,
63594723600,
63581421600,
63594727200,
3600,
0,
'CET'
    ],
    [
63594723600,
63613472400,
63594730800,
63613479600,
7200,
1,
'CEST'
    ],
    [
63613472400,
63626173200,
63613476000,
63626176800,
3600,
0,
'CET'
    ],
    [
63626173200,
63644922000,
63626180400,
63644929200,
7200,
1,
'CEST'
    ],
    [
63644922000,
63657622800,
63644925600,
63657626400,
3600,
0,
'CET'
    ],
    [
63657622800,
63676371600,
63657630000,
63676378800,
7200,
1,
'CEST'
    ],
    [
63676371600,
63689677200,
63676375200,
63689680800,
3600,
0,
'CET'
    ],
    [
63689677200,
63707821200,
63689684400,
63707828400,
7200,
1,
'CEST'
    ],
    [
63707821200,
63721126800,
63707824800,
63721130400,
3600,
0,
'CET'
    ],
    [
63721126800,
63739270800,
63721134000,
63739278000,
7200,
1,
'CEST'
    ],
    [
63739270800,
63752576400,
63739274400,
63752580000,
3600,
0,
'CET'
    ],
    [
63752576400,
63771325200,
63752583600,
63771332400,
7200,
1,
'CEST'
    ],
    [
63771325200,
63784026000,
63771328800,
63784029600,
3600,
0,
'CET'
    ],
    [
63784026000,
63802774800,
63784033200,
63802782000,
7200,
1,
'CEST'
    ],
    [
63802774800,
63815475600,
63802778400,
63815479200,
3600,
0,
'CET'
    ],
    [
63815475600,
63834224400,
63815482800,
63834231600,
7200,
1,
'CEST'
    ],
];

sub olson_version { '2012g' }

sub has_dst_changes { 68 }

sub _max_year { 2022 }

sub _new_instance
{
    return shift->_init( @_, spans => $spans );
}

sub _last_offset { 3600 }

my $last_observance = bless( {
  'format' => 'CE%sT',
  'gmtoff' => '1:00',
  'local_start_datetime' => bless( {
    'formatter' => undef,
    'local_rd_days' => 725737,
    'local_rd_secs' => 0,
    'offset_modifier' => 0,
    'rd_nanosecs' => 0,
    'tz' => bless( {
      'name' => 'floating',
      'offset' => 0
    }, 'DateTime::TimeZone::Floating' ),
    'utc_rd_days' => 725737,
    'utc_rd_secs' => 0,
    'utc_year' => 1989
  }, 'DateTime' ),
  'offset_from_std' => 0,
  'offset_from_utc' => 3600,
  'until' => [],
  'utc_start_datetime' => bless( {
    'formatter' => undef,
    'local_rd_days' => 725736,
    'local_rd_secs' => 82800,
    'offset_modifier' => 0,
    'rd_nanosecs' => 0,
    'tz' => bless( {
      'name' => 'floating',
      'offset' => 0
    }, 'DateTime::TimeZone::Floating' ),
    'utc_rd_days' => 725736,
    'utc_rd_secs' => 82800,
    'utc_year' => 1988
  }, 'DateTime' )
}, 'DateTime::TimeZone::OlsonDB::Observance' )
;
sub _last_observance { $last_observance }

my $rules = [
  bless( {
    'at' => '1:00u',
    'from' => '1996',
    'in' => 'Oct',
    'letter' => '',
    'name' => 'EU',
    'offset_from_std' => 0,
    'on' => 'lastSun',
    'save' => '0',
    'to' => 'max',
    'type' => undef
  }, 'DateTime::TimeZone::OlsonDB::Rule' ),
  bless( {
    'at' => '1:00u',
    'from' => '1981',
    'in' => 'Mar',
    'letter' => 'S',
    'name' => 'EU',
    'offset_from_std' => 3600,
    'on' => 'lastSun',
    'save' => '1:00',
    'to' => 'max',
    'type' => undef
  }, 'DateTime::TimeZone::OlsonDB::Rule' )
]
;
sub _rules { $rules }


1;

