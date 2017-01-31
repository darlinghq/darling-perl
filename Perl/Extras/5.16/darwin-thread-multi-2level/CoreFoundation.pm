package CoreFoundation;

require Exporter;
require DynaLoader;

@ISA = qw(Exporter DynaLoader);
@EXPORT = qw( );
$VERSION = '1.0';
bootstrap CoreFoundation $VERSION;
    
use PerlObjCBridge;

package CFPDCFDataBuffer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package CFPDContainerSource;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package CFPDDataBuffer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package CFPDPurgeableBuffer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package CFPDSource;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package CFPrefsCompatibilitySource;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package CFPrefsDirectSource;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package CFPrefsManagedSource;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package CFPrefsPlistSource;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package CFPrefsSearchListSource;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package CFPrefsSource;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSArray;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSBlock;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSBlockInvocation;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSCache;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSCalendar;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSData;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSDate;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSDateComponents;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSDictionary;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSEnumerator;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSException;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFileSecurity;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSInputStream;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSInvocation;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSLocale;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSMethodSignature;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSMutableArray;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSMutableData;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSMutableDictionary;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSMutableOrderedSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSMutableSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSNull;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSOrderedSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSOutputStream;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSRunLoop;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSSharedKeyDictionary;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSSharedKeySet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSStream;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSTaggedPointerString;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSTaggedPointerStringCStringContainer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSTimeZone;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSTimer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSURL;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSUserDefaults;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _CFPrefsSynchronizer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _CFStreamDelegate;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _CFXNotificationDarwinTokenQueueRegistration;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _CFXNotificationDarwinTokenRegistration;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _CFXNotificationDistributedTokenQueueRegistration;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _CFXNotificationDistributedTokenRegistration;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _CFXNotificationNameRegistration;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _CFXNotificationNameWildcardObjectRegistration;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _CFXNotificationObjcObserverRegistration;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _CFXNotificationObjectRegistration;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _CFXNotificationObserverRegistration;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _CFXNotificationRegistrar;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _CFXNotificationRegistrationBase;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _CFXNotificationRegistrationContainer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _CFXNotificationTokenQueueRegistration;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _CFXNotificationTokenRegistration;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSChineseBigramKeySet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSChineseBigramKeySet_SKS;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSChineseBigramKeySet_SKS_SKS;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSCopyOnWriteCalendarWrapper;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSJapaneseBigramKeySet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSKoreanBigramKeySet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSKoreanBigramKeySet_SKS;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSMostCommonChineseCharsKeySet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSMostCommonJapaneseCharsKeySet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSMostCommonKoreanCharsKeySet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSPlaceholderLocale;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSRefcountedPthreadMutex;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSSharedKeySetS;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSZombie_;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __CFNotification;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSArray0;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSArrayI;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSArrayM;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSArrayReverseEnumerator;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSArrayReversed;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSAtom;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSAutoBlock;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSBlockVariable;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSCFArray;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSCFAttributedString;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSCFBoolean;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSCFCalendar;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSCFCharacterSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSCFConstantString;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSCFData;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSCFDictionary;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSCFError;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSCFInputStream;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSCFLocale;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSCFNumber;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSCFOutputStream;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSCFSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSCFString;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSCFTimer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSCFType;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSDate;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSDictionary0;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSDictionaryI;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSDictionaryM;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSDictionaryObjectEnumerator;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSFastEnumerationEnumerator;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSFileSecurity;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSFinalizingBlock;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSGenericDeallocHandler;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSGlobalBlock;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSISO885911TrigramKeySet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSISO88595TrigramKeySet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSISO88596TrigramKeySet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSISO88597TrigramKeySet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSISO88598TrigramKeySet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSISOLatin10TrigramKeySet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSISOLatin1TrigramKeySet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSISOLatin2TrigramKeySet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSISOLatin3TrigramKeySet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSISOLatin4TrigramKeySet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSISOLatin5TrigramKeySet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSISOLatin6TrigramKeySet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSISOLatin7TrigramKeySet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSISOLatin8TrigramKeySet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSISOLatin9TrigramKeySet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSLocalTimeZone;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSMallocBlock;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSMessageBuilder;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSOrderedSetArrayProxy;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSOrderedSetI;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSOrderedSetM;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSOrderedSetReverseEnumerator;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSOrderedSetReversed;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSOrderedSetSetProxy;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSPlaceholderArray;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSPlaceholderDate;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSPlaceholderDictionary;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSPlaceholderFileSecurity;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSPlaceholderOrderedSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSPlaceholderSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSPlaceholderTimeZone;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSSKGraph;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSSKGraphE;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSSetI;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSSetM;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSSingleObjectSetI;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSStackBlock;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSTaggedDate;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSTimeZone;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSWindows1250TrigramKeySet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSWindows1251TrigramKeySet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSWindows1252TrigramKeySet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSWindows1253TrigramKeySet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSWindows1254TrigramKeySet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSWindows1255TrigramKeySet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSWindows1256TrigramKeySet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSWindows1257TrigramKeySet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSWindows1258TrigramKeySet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSWindows874TrigramKeySet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

1;
