# $Id: ErrNo.pm,v 1.1.2.1 2004/04/20 20:09:48 pajas Exp $
#
#
# This is free software, you may use it and distribute it under the same terms as
# Perl itself.
#
# Copyright 2001-2003 AxKit.com Ltd., 2002-2006 Christian Glahn, 2006-2009 Petr Pajas
#
#

package XML::LibXML::ErrNo;

use strict;
use vars qw($VERSION);

$VERSION = "2.0008"; # VERSION TEMPLATE: DO NOT CHANGE

use constant ERR_OK                               => 0;
use constant ERR_INTERNAL_ERROR                   => 1;
use constant ERR_NO_MEMORY                        => 2;
use constant ERR_DOCUMENT_START                   => 3;
use constant ERR_DOCUMENT_EMPTY                   => 4;
use constant ERR_DOCUMENT_END                     => 5;
use constant ERR_INVALID_HEX_CHARREF              => 6;
use constant ERR_INVALID_DEC_CHARREF              => 7;
use constant ERR_INVALID_CHARREF                  => 8;
use constant ERR_INVALID_CHAR                     => 9;
use constant ERR_CHARREF_AT_EOF                   => 10;
use constant ERR_CHARREF_IN_PROLOG                => 11;
use constant ERR_CHARREF_IN_EPILOG                => 12;
use constant ERR_CHARREF_IN_DTD                   => 13;
use constant ERR_ENTITYREF_AT_EOF                 => 14;
use constant ERR_ENTITYREF_IN_PROLOG              => 15;
use constant ERR_ENTITYREF_IN_EPILOG              => 16;
use constant ERR_ENTITYREF_IN_DTD                 => 17;
use constant ERR_PEREF_AT_EOF                     => 18;
use constant ERR_PEREF_IN_PROLOG                  => 19;
use constant ERR_PEREF_IN_EPILOG                  => 20;
use constant ERR_PEREF_IN_INT_SUBSET              => 21;
use constant ERR_ENTITYREF_NO_NAME                => 22;
use constant ERR_ENTITYREF_SEMICOL_MISSING        => 23;
use constant ERR_PEREF_NO_NAME                    => 24;
use constant ERR_PEREF_SEMICOL_MISSING            => 25;
use constant ERR_UNDECLARED_ENTITY                => 26;
use constant WAR_UNDECLARED_ENTITY                => 27;
use constant ERR_UNPARSED_ENTITY                  => 28;
use constant ERR_ENTITY_IS_EXTERNAL               => 29;
use constant ERR_ENTITY_IS_PARAMETER              => 30;
use constant ERR_UNKNOWN_ENCODING                 => 31;
use constant ERR_UNSUPPORTED_ENCODING             => 32;
use constant ERR_STRING_NOT_STARTED               => 33;
use constant ERR_STRING_NOT_CLOSED                => 34;
use constant ERR_NS_DECL_ERROR                    => 35;
use constant ERR_ENTITY_NOT_STARTED               => 36;
use constant ERR_ENTITY_NOT_FINISHED              => 37;
use constant ERR_LT_IN_ATTRIBUTE                  => 38;
use constant ERR_ATTRIBUTE_NOT_STARTED            => 39;
use constant ERR_ATTRIBUTE_NOT_FINISHED           => 40;
use constant ERR_ATTRIBUTE_WITHOUT_VALUE          => 41;
use constant ERR_ATTRIBUTE_REDEFINED              => 42;
use constant ERR_LITERAL_NOT_STARTED              => 43;
use constant ERR_LITERAL_NOT_FINISHED             => 44;
use constant ERR_COMMENT_NOT_FINISHED             => 45;
use constant ERR_PI_NOT_STARTED                   => 46;
use constant ERR_PI_NOT_FINISHED                  => 47;
use constant ERR_NOTATION_NOT_STARTED             => 48;
use constant ERR_NOTATION_NOT_FINISHED            => 49;
use constant ERR_ATTLIST_NOT_STARTED              => 50;
use constant ERR_ATTLIST_NOT_FINISHED             => 51;
use constant ERR_MIXED_NOT_STARTED                => 52;
use constant ERR_MIXED_NOT_FINISHED               => 53;
use constant ERR_ELEMCONTENT_NOT_STARTED          => 54;
use constant ERR_ELEMCONTENT_NOT_FINISHED         => 55;
use constant ERR_XMLDECL_NOT_STARTED              => 56;
use constant ERR_XMLDECL_NOT_FINISHED             => 57;
use constant ERR_CONDSEC_NOT_STARTED              => 58;
use constant ERR_CONDSEC_NOT_FINISHED             => 59;
use constant ERR_EXT_SUBSET_NOT_FINISHED          => 60;
use constant ERR_DOCTYPE_NOT_FINISHED             => 61;
use constant ERR_MISPLACED_CDATA_END              => 62;
use constant ERR_CDATA_NOT_FINISHED               => 63;
use constant ERR_RESERVED_XML_NAME                => 64;
use constant ERR_SPACE_REQUIRED                   => 65;
use constant ERR_SEPARATOR_REQUIRED               => 66;
use constant ERR_NMTOKEN_REQUIRED                 => 67;
use constant ERR_NAME_REQUIRED                    => 68;
use constant ERR_PCDATA_REQUIRED                  => 69;
use constant ERR_URI_REQUIRED                     => 70;
use constant ERR_PUBID_REQUIRED                   => 71;
use constant ERR_LT_REQUIRED                      => 72;
use constant ERR_GT_REQUIRED                      => 73;
use constant ERR_LTSLASH_REQUIRED                 => 74;
use constant ERR_EQUAL_REQUIRED                   => 75;
use constant ERR_TAG_NAME_MISMATCH                => 76;
use constant ERR_TAG_NOT_FINISHED                 => 77;
use constant ERR_STANDALONE_VALUE                 => 78;
use constant ERR_ENCODING_NAME                    => 79;
use constant ERR_HYPHEN_IN_COMMENT                => 80;
use constant ERR_INVALID_ENCODING                 => 81;
use constant ERR_EXT_ENTITY_STANDALONE            => 82;
use constant ERR_CONDSEC_INVALID                  => 83;
use constant ERR_VALUE_REQUIRED                   => 84;
use constant ERR_NOT_WELL_BALANCED                => 85;
use constant ERR_EXTRA_CONTENT                    => 86;
use constant ERR_ENTITY_CHAR_ERROR                => 87;
use constant ERR_ENTITY_PE_INTERNAL               => 88;
use constant ERR_ENTITY_LOOP                      => 89;
use constant ERR_ENTITY_BOUNDARY                  => 90;
use constant ERR_INVALID_URI                      => 91;
use constant ERR_URI_FRAGMENT                     => 92;
use constant WAR_CATALOG_PI                       => 93;
use constant ERR_NO_DTD                           => 94;
use constant ERR_CONDSEC_INVALID_KEYWORD          => 95;
use constant ERR_VERSION_MISSING                  => 96;
use constant WAR_UNKNOWN_VERSION                  => 97;
use constant WAR_LANG_VALUE                       => 98;
use constant WAR_NS_URI                           => 99;
use constant WAR_NS_URI_RELATIVE                  => 100;
use constant NS_ERR_XML_NAMESPACE                 => 200;
use constant NS_ERR_UNDEFINED_NAMESPACE           => 201;
use constant NS_ERR_QNAME                         => 202;
use constant NS_ERR_ATTRIBUTE_REDEFINED           => 203;
use constant DTD_ATTRIBUTE_DEFAULT                => 500;
use constant DTD_ATTRIBUTE_REDEFINED              => 501;
use constant DTD_ATTRIBUTE_VALUE                  => 502;
use constant DTD_CONTENT_ERROR                    => 503;
use constant DTD_CONTENT_MODEL                    => 504;
use constant DTD_CONTENT_NOT_DETERMINIST          => 505;
use constant DTD_DIFFERENT_PREFIX                 => 506;
use constant DTD_ELEM_DEFAULT_NAMESPACE           => 507;
use constant DTD_ELEM_NAMESPACE                   => 508;
use constant DTD_ELEM_REDEFINED                   => 509;
use constant DTD_EMPTY_NOTATION                   => 510;
use constant DTD_ENTITY_TYPE                      => 511;
use constant DTD_ID_FIXED                         => 512;
use constant DTD_ID_REDEFINED                     => 513;
use constant DTD_ID_SUBSET                        => 514;
use constant DTD_INVALID_CHILD                    => 515;
use constant DTD_INVALID_DEFAULT                  => 516;
use constant DTD_LOAD_ERROR                       => 517;
use constant DTD_MISSING_ATTRIBUTE                => 518;
use constant DTD_MIXED_CORRUPT                    => 519;
use constant DTD_MULTIPLE_ID                      => 520;
use constant DTD_NO_DOC                           => 521;
use constant DTD_NO_DTD                           => 522;
use constant DTD_NO_ELEM_NAME                     => 523;
use constant DTD_NO_PREFIX                        => 524;
use constant DTD_NO_ROOT                          => 525;
use constant DTD_NOTATION_REDEFINED               => 526;
use constant DTD_NOTATION_VALUE                   => 527;
use constant DTD_NOT_EMPTY                        => 528;
use constant DTD_NOT_PCDATA                       => 529;
use constant DTD_NOT_STANDALONE                   => 530;
use constant DTD_ROOT_NAME                        => 531;
use constant DTD_STANDALONE_WHITE_SPACE           => 532;
use constant DTD_UNKNOWN_ATTRIBUTE                => 533;
use constant DTD_UNKNOWN_ELEM                     => 534;
use constant DTD_UNKNOWN_ENTITY                   => 535;
use constant DTD_UNKNOWN_ID                       => 536;
use constant DTD_UNKNOWN_NOTATION                 => 537;
use constant HTML_STRUCURE_ERROR                  => 800;
use constant HTML_UNKNOWN_TAG                     => 801;
use constant RNGP_ANYNAME_ATTR_ANCESTOR           => 1000;
use constant RNGP_ATTR_CONFLICT                   => 1001;
use constant RNGP_ATTRIBUTE_CHILDREN              => 1002;
use constant RNGP_ATTRIBUTE_CONTENT               => 1003;
use constant RNGP_ATTRIBUTE_EMPTY                 => 1004;
use constant RNGP_ATTRIBUTE_NOOP                  => 1005;
use constant RNGP_CHOICE_CONTENT                  => 1006;
use constant RNGP_CHOICE_EMPTY                    => 1007;
use constant RNGP_CREATE_FAILURE                  => 1008;
use constant RNGP_DATA_CONTENT                    => 1009;
use constant RNGP_DEF_CHOICE_AND_INTERLEAVE       => 1010;
use constant RNGP_DEFINE_CREATE_FAILED            => 1011;
use constant RNGP_DEFINE_EMPTY                    => 1012;
use constant RNGP_DEFINE_MISSING                  => 1013;
use constant RNGP_DEFINE_NAME_MISSING             => 1014;
use constant RNGP_ELEM_CONTENT_EMPTY              => 1015;
use constant RNGP_ELEM_CONTENT_ERROR              => 1016;
use constant RNGP_ELEMENT_EMPTY                   => 1017;
use constant RNGP_ELEMENT_CONTENT                 => 1018;
use constant RNGP_ELEMENT_NAME                    => 1019;
use constant RNGP_ELEMENT_NO_CONTENT              => 1020;
use constant RNGP_ELEM_TEXT_CONFLICT              => 1021;
use constant RNGP_EMPTY                           => 1022;
use constant RNGP_EMPTY_CONSTRUCT                 => 1023;
use constant RNGP_EMPTY_CONTENT                   => 1024;
use constant RNGP_EMPTY_NOT_EMPTY                 => 1025;
use constant RNGP_ERROR_TYPE_LIB                  => 1026;
use constant RNGP_EXCEPT_EMPTY                    => 1027;
use constant RNGP_EXCEPT_MISSING                  => 1028;
use constant RNGP_EXCEPT_MULTIPLE                 => 1029;
use constant RNGP_EXCEPT_NO_CONTENT               => 1030;
use constant RNGP_EXTERNALREF_EMTPY               => 1031;
use constant RNGP_EXTERNAL_REF_FAILURE            => 1032;
use constant RNGP_EXTERNALREF_RECURSE             => 1033;
use constant RNGP_FORBIDDEN_ATTRIBUTE             => 1034;
use constant RNGP_FOREIGN_ELEMENT                 => 1035;
use constant RNGP_GRAMMAR_CONTENT                 => 1036;
use constant RNGP_GRAMMAR_EMPTY                   => 1037;
use constant RNGP_GRAMMAR_MISSING                 => 1038;
use constant RNGP_GRAMMAR_NO_START                => 1039;
use constant RNGP_GROUP_ATTR_CONFLICT             => 1040;
use constant RNGP_HREF_ERROR                      => 1041;
use constant RNGP_INCLUDE_EMPTY                   => 1042;
use constant RNGP_INCLUDE_FAILURE                 => 1043;
use constant RNGP_INCLUDE_RECURSE                 => 1044;
use constant RNGP_INTERLEAVE_ADD                  => 1045;
use constant RNGP_INTERLEAVE_CREATE_FAILED        => 1046;
use constant RNGP_INTERLEAVE_EMPTY                => 1047;
use constant RNGP_INTERLEAVE_NO_CONTENT           => 1048;
use constant RNGP_INVALID_DEFINE_NAME             => 1049;
use constant RNGP_INVALID_URI                     => 1050;
use constant RNGP_INVALID_VALUE                   => 1051;
use constant RNGP_MISSING_HREF                    => 1052;
use constant RNGP_NAME_MISSING                    => 1053;
use constant RNGP_NEED_COMBINE                    => 1054;
use constant RNGP_NOTALLOWED_NOT_EMPTY            => 1055;
use constant RNGP_NSNAME_ATTR_ANCESTOR            => 1056;
use constant RNGP_NSNAME_NO_NS                    => 1057;
use constant RNGP_PARAM_FORBIDDEN                 => 1058;
use constant RNGP_PARAM_NAME_MISSING              => 1059;
use constant RNGP_PARENTREF_CREATE_FAILED         => 1060;
use constant RNGP_PARENTREF_NAME_INVALID          => 1061;
use constant RNGP_PARENTREF_NO_NAME               => 1062;
use constant RNGP_PARENTREF_NO_PARENT             => 1063;
use constant RNGP_PARENTREF_NOT_EMPTY             => 1064;
use constant RNGP_PARSE_ERROR                     => 1065;
use constant RNGP_PAT_ANYNAME_EXCEPT_ANYNAME      => 1066;
use constant RNGP_PAT_ATTR_ATTR                   => 1067;
use constant RNGP_PAT_ATTR_ELEM                   => 1068;
use constant RNGP_PAT_DATA_EXCEPT_ATTR            => 1069;
use constant RNGP_PAT_DATA_EXCEPT_ELEM            => 1070;
use constant RNGP_PAT_DATA_EXCEPT_EMPTY           => 1071;
use constant RNGP_PAT_DATA_EXCEPT_GROUP           => 1072;
use constant RNGP_PAT_DATA_EXCEPT_INTERLEAVE      => 1073;
use constant RNGP_PAT_DATA_EXCEPT_LIST            => 1074;
use constant RNGP_PAT_DATA_EXCEPT_ONEMORE         => 1075;
use constant RNGP_PAT_DATA_EXCEPT_REF             => 1076;
use constant RNGP_PAT_DATA_EXCEPT_TEXT            => 1077;
use constant RNGP_PAT_LIST_ATTR                   => 1078;
use constant RNGP_PAT_LIST_ELEM                   => 1079;
use constant RNGP_PAT_LIST_INTERLEAVE             => 1080;
use constant RNGP_PAT_LIST_LIST                   => 1081;
use constant RNGP_PAT_LIST_REF                    => 1082;
use constant RNGP_PAT_LIST_TEXT                   => 1083;
use constant RNGP_PAT_NSNAME_EXCEPT_ANYNAME       => 1084;
use constant RNGP_PAT_NSNAME_EXCEPT_NSNAME        => 1085;
use constant RNGP_PAT_ONEMORE_GROUP_ATTR          => 1086;
use constant RNGP_PAT_ONEMORE_INTERLEAVE_ATTR     => 1087;
use constant RNGP_PAT_START_ATTR                  => 1088;
use constant RNGP_PAT_START_DATA                  => 1089;
use constant RNGP_PAT_START_EMPTY                 => 1090;
use constant RNGP_PAT_START_GROUP                 => 1091;
use constant RNGP_PAT_START_INTERLEAVE            => 1092;
use constant RNGP_PAT_START_LIST                  => 1093;
use constant RNGP_PAT_START_ONEMORE               => 1094;
use constant RNGP_PAT_START_TEXT                  => 1095;
use constant RNGP_PAT_START_VALUE                 => 1096;
use constant RNGP_PREFIX_UNDEFINED                => 1097;
use constant RNGP_REF_CREATE_FAILED               => 1098;
use constant RNGP_REF_CYCLE                       => 1099;
use constant RNGP_REF_NAME_INVALID                => 1100;
use constant RNGP_REF_NO_DEF                      => 1101;
use constant RNGP_REF_NO_NAME                     => 1102;
use constant RNGP_REF_NOT_EMPTY                   => 1103;
use constant RNGP_START_CHOICE_AND_INTERLEAVE     => 1104;
use constant RNGP_START_CONTENT                   => 1105;
use constant RNGP_START_EMPTY                     => 1106;
use constant RNGP_START_MISSING                   => 1107;
use constant RNGP_TEXT_EXPECTED                   => 1108;
use constant RNGP_TEXT_HAS_CHILD                  => 1109;
use constant RNGP_TYPE_MISSING                    => 1110;
use constant RNGP_TYPE_NOT_FOUND                  => 1111;
use constant RNGP_TYPE_VALUE                      => 1112;
use constant RNGP_UNKNOWN_ATTRIBUTE               => 1113;
use constant RNGP_UNKNOWN_COMBINE                 => 1114;
use constant RNGP_UNKNOWN_CONSTRUCT               => 1115;
use constant RNGP_UNKNOWN_TYPE_LIB                => 1116;
use constant RNGP_URI_FRAGMENT                    => 1117;
use constant RNGP_URI_NOT_ABSOLUTE                => 1118;
use constant RNGP_VALUE_EMPTY                     => 1119;
use constant RNGP_VALUE_NO_CONTENT                => 1120;
use constant RNGP_XMLNS_NAME                      => 1121;
use constant RNGP_XML_NS                          => 1122;
use constant XPATH_EXPRESSION_OK                  => 1200;
use constant XPATH_NUMBER_ERROR                   => 1201;
use constant XPATH_UNFINISHED_LITERAL_ERROR       => 1202;
use constant XPATH_START_LITERAL_ERROR            => 1203;
use constant XPATH_VARIABLE_REF_ERROR             => 1204;
use constant XPATH_UNDEF_VARIABLE_ERROR           => 1205;
use constant XPATH_INVALID_PREDICATE_ERROR        => 1206;
use constant XPATH_EXPR_ERROR                     => 1207;
use constant XPATH_UNCLOSED_ERROR                 => 1208;
use constant XPATH_UNKNOWN_FUNC_ERROR             => 1209;
use constant XPATH_INVALID_OPERAND                => 1210;
use constant XPATH_INVALID_TYPE                   => 1211;
use constant XPATH_INVALID_ARITY                  => 1212;
use constant XPATH_INVALID_CTXT_SIZE              => 1213;
use constant XPATH_INVALID_CTXT_POSITION          => 1214;
use constant XPATH_MEMORY_ERROR                   => 1215;
use constant XPTR_SYNTAX_ERROR                    => 1216;
use constant XPTR_RESOURCE_ERROR                  => 1217;
use constant XPTR_SUB_RESOURCE_ERROR              => 1218;
use constant XPATH_UNDEF_PREFIX_ERROR             => 1219;
use constant XPATH_ENCODING_ERROR                 => 1220;
use constant XPATH_INVALID_CHAR_ERROR             => 1221;
use constant TREE_INVALID_HEX                     => 1300;
use constant TREE_INVALID_DEC                     => 1301;
use constant TREE_UNTERMINATED_ENTITY             => 1302;
use constant SAVE_NOT_UTF8                        => 1400;
use constant SAVE_CHAR_INVALID                    => 1401;
use constant SAVE_NO_DOCTYPE                      => 1402;
use constant SAVE_UNKNOWN_ENCODING                => 1403;
use constant REGEXP_COMPILE_ERROR                 => 1450;
use constant IO_UNKNOWN                           => 1500;
use constant IO_EACCES                            => 1501;
use constant IO_EAGAIN                            => 1502;
use constant IO_EBADF                             => 1503;
use constant IO_EBADMSG                           => 1504;
use constant IO_EBUSY                             => 1505;
use constant IO_ECANCELED                         => 1506;
use constant IO_ECHILD                            => 1507;
use constant IO_EDEADLK                           => 1508;
use constant IO_EDOM                              => 1509;
use constant IO_EEXIST                            => 1510;
use constant IO_EFAULT                            => 1511;
use constant IO_EFBIG                             => 1512;
use constant IO_EINPROGRESS                       => 1513;
use constant IO_EINTR                             => 1514;
use constant IO_EINVAL                            => 1515;
use constant IO_EIO                               => 1516;
use constant IO_EISDIR                            => 1517;
use constant IO_EMFILE                            => 1518;
use constant IO_EMLINK                            => 1519;
use constant IO_EMSGSIZE                          => 1520;
use constant IO_ENAMETOOLONG                      => 1521;
use constant IO_ENFILE                            => 1522;
use constant IO_ENODEV                            => 1523;
use constant IO_ENOENT                            => 1524;
use constant IO_ENOEXEC                           => 1525;
use constant IO_ENOLCK                            => 1526;
use constant IO_ENOMEM                            => 1527;
use constant IO_ENOSPC                            => 1528;
use constant IO_ENOSYS                            => 1529;
use constant IO_ENOTDIR                           => 1530;
use constant IO_ENOTEMPTY                         => 1531;
use constant IO_ENOTSUP                           => 1532;
use constant IO_ENOTTY                            => 1533;
use constant IO_ENXIO                             => 1534;
use constant IO_EPERM                             => 1535;
use constant IO_EPIPE                             => 1536;
use constant IO_ERANGE                            => 1537;
use constant IO_EROFS                             => 1538;
use constant IO_ESPIPE                            => 1539;
use constant IO_ESRCH                             => 1540;
use constant IO_ETIMEDOUT                         => 1541;
use constant IO_EXDEV                             => 1542;
use constant IO_NETWORK_ATTEMPT                   => 1543;
use constant IO_ENCODER                           => 1544;
use constant IO_FLUSH                             => 1545;
use constant IO_WRITE                             => 1546;
use constant IO_NO_INPUT                          => 1547;
use constant IO_BUFFER_FULL                       => 1548;
use constant IO_LOAD_ERROR                        => 1549;
use constant IO_ENOTSOCK                          => 1550;
use constant IO_EISCONN                           => 1551;
use constant IO_ECONNREFUSED                      => 1552;
use constant IO_ENETUNREACH                       => 1553;
use constant IO_EADDRINUSE                        => 1554;
use constant IO_EALREADY                          => 1555;
use constant IO_EAFNOSUPPORT                      => 1556;
use constant XINCLUDE_RECURSION                   => 1600;
use constant XINCLUDE_PARSE_VALUE                 => 1601;
use constant XINCLUDE_ENTITY_DEF_MISMATCH         => 1602;
use constant XINCLUDE_NO_HREF                     => 1603;
use constant XINCLUDE_NO_FALLBACK                 => 1604;
use constant XINCLUDE_HREF_URI                    => 1605;
use constant XINCLUDE_TEXT_FRAGMENT               => 1606;
use constant XINCLUDE_TEXT_DOCUMENT               => 1607;
use constant XINCLUDE_INVALID_CHAR                => 1608;
use constant XINCLUDE_BUILD_FAILED                => 1609;
use constant XINCLUDE_UNKNOWN_ENCODING            => 1610;
use constant XINCLUDE_MULTIPLE_ROOT               => 1611;
use constant XINCLUDE_XPTR_FAILED                 => 1612;
use constant XINCLUDE_XPTR_RESULT                 => 1613;
use constant XINCLUDE_INCLUDE_IN_INCLUDE          => 1614;
use constant XINCLUDE_FALLBACKS_IN_INCLUDE        => 1615;
use constant XINCLUDE_FALLBACK_NOT_IN_INCLUDE     => 1616;
use constant CATALOG_MISSING_ATTR                 => 1650;
use constant CATALOG_ENTRY_BROKEN                 => 1651;
use constant CATALOG_PREFER_VALUE                 => 1652;
use constant CATALOG_NOT_CATALOG                  => 1653;
use constant CATALOG_RECURSION                    => 1654;
use constant SCHEMAP_PREFIX_UNDEFINED             => 1700;
use constant SCHEMAP_ATTRFORMDEFAULT_VALUE        => 1701;
use constant SCHEMAP_ATTRGRP_NONAME_NOREF         => 1702;
use constant SCHEMAP_ATTR_NONAME_NOREF            => 1703;
use constant SCHEMAP_COMPLEXTYPE_NONAME_NOREF     => 1704;
use constant SCHEMAP_ELEMFORMDEFAULT_VALUE        => 1705;
use constant SCHEMAP_ELEM_NONAME_NOREF            => 1706;
use constant SCHEMAP_EXTENSION_NO_BASE            => 1707;
use constant SCHEMAP_FACET_NO_VALUE               => 1708;
use constant SCHEMAP_FAILED_BUILD_IMPORT          => 1709;
use constant SCHEMAP_GROUP_NONAME_NOREF           => 1710;
use constant SCHEMAP_IMPORT_NAMESPACE_NOT_URI     => 1711;
use constant SCHEMAP_IMPORT_REDEFINE_NSNAME       => 1712;
use constant SCHEMAP_IMPORT_SCHEMA_NOT_URI        => 1713;
use constant SCHEMAP_INVALID_BOOLEAN              => 1714;
use constant SCHEMAP_INVALID_ENUM                 => 1715;
use constant SCHEMAP_INVALID_FACET                => 1716;
use constant SCHEMAP_INVALID_FACET_VALUE          => 1717;
use constant SCHEMAP_INVALID_MAXOCCURS            => 1718;
use constant SCHEMAP_INVALID_MINOCCURS            => 1719;
use constant SCHEMAP_INVALID_REF_AND_SUBTYPE      => 1720;
use constant SCHEMAP_INVALID_WHITE_SPACE          => 1721;
use constant SCHEMAP_NOATTR_NOREF                 => 1722;
use constant SCHEMAP_NOTATION_NO_NAME             => 1723;
use constant SCHEMAP_NOTYPE_NOREF                 => 1724;
use constant SCHEMAP_REF_AND_SUBTYPE              => 1725;
use constant SCHEMAP_RESTRICTION_NONAME_NOREF     => 1726;
use constant SCHEMAP_SIMPLETYPE_NONAME            => 1727;
use constant SCHEMAP_TYPE_AND_SUBTYPE             => 1728;
use constant SCHEMAP_UNKNOWN_ALL_CHILD            => 1729;
use constant SCHEMAP_UNKNOWN_ANYATTRIBUTE_CHILD   => 1730;
use constant SCHEMAP_UNKNOWN_ATTR_CHILD           => 1731;
use constant SCHEMAP_UNKNOWN_ATTRGRP_CHILD        => 1732;
use constant SCHEMAP_UNKNOWN_ATTRIBUTE_GROUP      => 1733;
use constant SCHEMAP_UNKNOWN_BASE_TYPE            => 1734;
use constant SCHEMAP_UNKNOWN_CHOICE_CHILD         => 1735;
use constant SCHEMAP_UNKNOWN_COMPLEXCONTENT_CHILD => 1736;
use constant SCHEMAP_UNKNOWN_COMPLEXTYPE_CHILD    => 1737;
use constant SCHEMAP_UNKNOWN_ELEM_CHILD           => 1738;
use constant SCHEMAP_UNKNOWN_EXTENSION_CHILD      => 1739;
use constant SCHEMAP_UNKNOWN_FACET_CHILD          => 1740;
use constant SCHEMAP_UNKNOWN_FACET_TYPE           => 1741;
use constant SCHEMAP_UNKNOWN_GROUP_CHILD          => 1742;
use constant SCHEMAP_UNKNOWN_IMPORT_CHILD         => 1743;
use constant SCHEMAP_UNKNOWN_LIST_CHILD           => 1744;
use constant SCHEMAP_UNKNOWN_NOTATION_CHILD       => 1745;
use constant SCHEMAP_UNKNOWN_PROCESSCONTENT_CHILD => 1746;
use constant SCHEMAP_UNKNOWN_REF                  => 1747;
use constant SCHEMAP_UNKNOWN_RESTRICTION_CHILD    => 1748;
use constant SCHEMAP_UNKNOWN_SCHEMAS_CHILD        => 1749;
use constant SCHEMAP_UNKNOWN_SEQUENCE_CHILD       => 1750;
use constant SCHEMAP_UNKNOWN_SIMPLECONTENT_CHILD  => 1751;
use constant SCHEMAP_UNKNOWN_SIMPLETYPE_CHILD     => 1752;
use constant SCHEMAP_UNKNOWN_TYPE                 => 1753;
use constant SCHEMAP_UNKNOWN_UNION_CHILD          => 1754;
use constant SCHEMAP_ELEM_DEFAULT_FIXED           => 1755;
use constant SCHEMAP_REGEXP_INVALID               => 1756;
use constant SCHEMAP_FAILED_LOAD                  => 1756;
use constant SCHEMAP_NOTHING_TO_PARSE             => 1757;
use constant SCHEMAP_NOROOT                       => 1758;
use constant SCHEMAP_REDEFINED_GROUP              => 1759;
use constant SCHEMAP_REDEFINED_TYPE               => 1760;
use constant SCHEMAP_REDEFINED_ELEMENT            => 1761;
use constant SCHEMAP_REDEFINED_ATTRGROUP          => 1762;
use constant SCHEMAP_REDEFINED_ATTR               => 1763;
use constant SCHEMAP_REDEFINED_NOTATION           => 1764;
use constant SCHEMAP_FAILED_PARSE                 => 1765;
use constant SCHEMAV_NOROOT                       => 1800;
use constant SCHEMAV_UNDECLAREDELEM               => 1801;
use constant SCHEMAV_NOTTOPLEVEL                  => 1802;
use constant SCHEMAV_MISSING                      => 1803;
use constant SCHEMAV_WRONGELEM                    => 1804;
use constant SCHEMAV_NOTYPE                       => 1805;
use constant SCHEMAV_NOROLLBACK                   => 1806;
use constant SCHEMAV_ISABSTRACT                   => 1807;
use constant SCHEMAV_NOTEMPTY                     => 1808;
use constant SCHEMAV_ELEMCONT                     => 1809;
use constant SCHEMAV_HAVEDEFAULT                  => 1810;
use constant SCHEMAV_NOTNILLABLE                  => 1811;
use constant SCHEMAV_EXTRACONTENT                 => 1812;
use constant SCHEMAV_INVALIDATTR                  => 1813;
use constant SCHEMAV_INVALIDELEM                  => 1814;
use constant SCHEMAV_NOTDETERMINIST               => 1815;
use constant SCHEMAV_CONSTRUCT                    => 1816;
use constant SCHEMAV_INTERNAL                     => 1817;
use constant SCHEMAV_NOTSIMPLE                    => 1818;
use constant SCHEMAV_ATTRUNKNOWN                  => 1819;
use constant SCHEMAV_ATTRINVALID                  => 1820;
use constant SCHEMAV_VALUE                        => 1821;
use constant SCHEMAV_FACET                        => 1822;
use constant XPTR_UNKNOWN_SCHEME                  => 1900;
use constant XPTR_CHILDSEQ_START                  => 1901;
use constant XPTR_EVAL_FAILED                     => 1902;
use constant XPTR_EXTRA_OBJECTS                   => 1903;
use constant C14N_CREATE_CTXT                     => 1950;
use constant C14N_REQUIRES_UTF8                   => 1951;
use constant C14N_CREATE_STACK                    => 1952;
use constant C14N_INVALID_NODE                    => 1953;
use constant FTP_PASV_ANSWER                      => 2000;
use constant FTP_EPSV_ANSWER                      => 2001;
use constant FTP_ACCNT                            => 2002;
use constant HTTP_URL_SYNTAX                      => 2020;
use constant HTTP_USE_IP                          => 2021;
use constant HTTP_UNKNOWN_HOST			 => 2022;

1;
