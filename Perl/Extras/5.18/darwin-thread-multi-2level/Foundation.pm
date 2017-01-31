package Foundation;

require Exporter;
require DynaLoader;

@ISA = qw(Exporter DynaLoader);
@EXPORT = qw( );
$VERSION = '1.0';
bootstrap Foundation $VERSION;
    
use PerlObjCBridge;
use CoreFoundation;

package NSAEDescriptorTranslator;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSAKDeserializer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSAKDeserializerStream;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSAKSerializer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSAKSerializerStream;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSASCIIEncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSAbstractLayoutGuide;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSAddressCheckingResult;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSAffineTransform;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSAggregateExpression;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSAllDescendantPathsEnumerator;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSAnyKeyExpression;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSAppleEventDescriptor;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSAppleEventHandling;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSAppleEventManager;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSAppleScript;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSArchiver;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSArrayChange;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSArrayChanges;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSAssertionHandler;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSAttributedString;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSAutoCalendar;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSAutoContentAccessingProxy;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSAutoLocale;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSAutoreleasePool;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSAutoresizingMaskLayoutConstraint;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSBackgroundActivityScheduler;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSBetweenPredicateOperator;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSBig5EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSBig5HKSCSEncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSBigEEncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSBigMutableString;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSBlockExpression;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSBlockObservationSink;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSBlockOperation;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSBlockPredicate;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSBoundKeyPath;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSBuiltinCharacterSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSBundle;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSByteCountFormatter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSCFArray;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSCFAttributedString;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSCFCharacterSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSCFData;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSCFDictionary;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSCFError;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSCFInputStream;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSCFOutputStream;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSCFSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSCFTimer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSCFType;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSCalendarDate;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSCharacterSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSCheapMutableString;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSClassDescription;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSClassicHashTable;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSClassicMapTable;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSCloneCommand;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSCloseCommand;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSCoder;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSCoercionHandler;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSComparisonPredicate;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSComparisonPredicateOperator;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSComplexOrthography;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSComplexRegularExpressionCheckingResult;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSCompoundPredicate;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSCompoundPredicateOperator;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSConcreteArrayChange;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSConcreteArrayChanges;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSConcreteAttributedString;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSConcreteData;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSConcreteDistantObjectRequest;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSConcreteFileHandle;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSConcreteFileHandleARCWeakRef;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSConcreteHashTable;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSConcreteMapTable;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSConcreteMapTableValueEnumerator;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSConcreteMutableAttributedString;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSConcreteMutableData;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSConcreteNotification;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSConcreteObservationBuffer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSConcreteOrderedSetChange;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSConcreteOrderedSetChanges;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSConcretePipe;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSConcretePointerArray;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSConcretePointerFunctions;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSConcretePortCoder;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSConcreteProtocolChecker;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSConcreteScanner;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSConcreteSetChange;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSConcreteSetChanges;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSConcreteTask;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSConcreteValue;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSCondition;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSConditionLock;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSConnection;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSConnectionHelper;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSConstantString;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSConstantValueExpression;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSContentSizeLayoutConstraint;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSCorrectionCheckingResult;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSCountCommand;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSCountedSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSCreateCommand;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSCreateCommandMoreIVars;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSCustomPredicateOperator;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSDOStreamData;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSDashCheckingResult;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSDataDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSDateCheckingResult;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSDateComponentsFormatter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSDateFormatter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSDateIntervalFormatter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSDebugString;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSDecimalNumber;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSDecimalNumberHandler;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSDecimalNumberPlaceholder;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSDeleteCommand;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSDeserializer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSDictionaryEntry;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSDirInfo;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSDirInfoDeserializer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSDirInfoSerializer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSDirectoryEnumerator;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSDirectorySubpathsOperation;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSDirectoryTraversalOperation;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSDistantObject;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSDistantObjectRequest;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSDistantObjectTableEntry;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSDistributedLock;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSDistributedNotificationCenter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSDistributedObjectsStatistics;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSDocInfo;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSDocumentDeserializer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSDocumentSerializer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSEUCGB2312EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSEUCJPEncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSEUCKREncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSEUCTWEncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSEncodingDetectionBuffer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSEncodingDetectionPlaceholder;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSEncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSEnergyFormatter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSEqualityPredicateOperator;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSError;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSExistsCommand;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSExpression;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSExtendedRegularExpressionCheckingResult;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFTPURLHandle;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFalsePredicate;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFileAccessArbiter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFileAccessArbiterProxy;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFileAccessClaim;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFileAccessIntent;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFileAccessNode;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFileAccessProcessManager;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFileAttributes;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFileCoordinator;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFileCoordinatorAccessorBlockCompletion;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFileHandle;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFileManager;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFileMultipleAccessClaim;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFilePresenterAsynchronousOperation;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFilePresenterOperationRecord;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFilePresenterProxy;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFilePresenterRelinquishment;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFilePromiseWriteToken;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFileProviderProxy;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFileReactorProxy;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFileReadingClaim;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFileReadingWritingClaim;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFileSubarbitrationClaim;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFileURLHandle;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFileVersion;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFileWatcher;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFileWatcherObservations;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFileWrapper;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFileWrapperMoreIVars;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFileWritingClaim;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFileWritingWritingClaim;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFilesystemItemCopyOperation;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFilesystemItemLinkOperation;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFilesystemItemMoveOperation;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFilesystemItemRemoveOperation;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFilterObservationTransformer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFormatter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSFunctionExpression;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSGB18030EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSGBKEncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSGarbageCollector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSGetCommand;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSGrammarCheckingResult;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSHTTPURLHandle;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSHZGB2312EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSHashTable;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSIBPrototypingLayoutConstraint;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISEngine;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISInlineStorageVariable;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISLinearExpression;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISO2022CNEncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISO2022EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISO2022JP1EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISO2022JP2EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISO2022JPEncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISO2022KREncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISO885911EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISO88595EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISO88596EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISO88597EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISO88598EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISOLATIN10EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISOLATIN1EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISOLATIN2EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISOLATIN3EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISOLATIN4EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISOLATIN5EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISOLATIN6EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISOLATIN7EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISOLATIN8EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISOLATIN9EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISObjectiveLinearExpression;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISPlaybackOperation;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISRestrictedToNonNegativeMarkerVariable;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISRestrictedToNonNegativeMarkerVariableToBeMinimized;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISRestrictedToNonNegativeVariable;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISRestrictedToNonNegativeVariableToBeMinimized;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISRestrictedToZeroMarkerVariable;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISUnrestrictedVariable;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSISVariable;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSInPredicateOperator;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSIndexPath;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSIndexSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSIndexSpecifier;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSInvocationOperation;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSJSONSerialization;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyBinding;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyGetBinding;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyPathExpression;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyPathSpecifierExpression;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeySetBinding;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueAccessor;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueArray;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueChangeDictionary;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueCollectionGetter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueComputedProperty;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueContainerClass;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueFastMutableArray;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueFastMutableArray1;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueFastMutableArray2;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueFastMutableCollection1Getter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueFastMutableCollection2Getter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueFastMutableOrderedSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueFastMutableOrderedSet1;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueFastMutableOrderedSet2;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueFastMutableSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueFastMutableSet1;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueFastMutableSet2;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueGetter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueIvarGetter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueIvarMutableArray;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueIvarMutableCollectionGetter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueIvarMutableOrderedSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueIvarMutableSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueIvarSetter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueMethodGetter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueMethodSetter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueMutableArray;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueMutableOrderedSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueMutableSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueMutatingArrayMethodSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueMutatingCollectionMethodSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueMutatingOrderedSetMethodSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueMutatingSetMethodSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueNestedProperty;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueNilOrderedSetEnumerator;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueNilSetEnumerator;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueNonmutatingArrayMethodSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueNonmutatingCollectionMethodSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueNonmutatingOrderedSetMethodSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueNonmutatingSetMethodSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueNotifyingMutableArray;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueNotifyingMutableCollectionGetter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueNotifyingMutableOrderedSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueNotifyingMutableSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueObservance;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueObservationInfo;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueOrderedSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueProperty;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueProxyGetter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueProxyShareKey;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueSetter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueShareableObservanceKey;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueShareableObservationInfoKey;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueSlowGetter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueSlowMutableArray;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueSlowMutableCollectionGetter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueSlowMutableOrderedSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueSlowMutableSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueSlowSetter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueUndefinedGetter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueUndefinedSetter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyValueUnnestedProperty;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyedArchiver;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyedPortCoder;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSKeyedUnarchiver;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSLanguageContext;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSLayoutAnchor;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSLayoutConstraint;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSLayoutConstraintParser;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSLayoutDimension;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSLayoutXAxisAnchor;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSLayoutYAxisAnchor;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSLeafProxy;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSLengthFormatter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSLikePredicateOperator;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSLinguisticTagger;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSLinkCheckingResult;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSLocalizableString;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSLock;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSLogicalTest;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSLookupMatch;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSMachBootstrapServer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSMachPort;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSMapObservationTransformer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSMapTable;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSMassFormatter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSMatchingPredicateOperator;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSMessagePort;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSMessagePortNameServer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSMetadataItem;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSMetadataQuery;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSMetadataQueryAttributeValueTuple;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSMetadataQueryResultGroup;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSMiddleSpecifier;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSMoveCommand;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSMultiReadUniWriteLock;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSMutableAttributedString;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSMutableCharacterSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSMutableIndexSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSMutableRLEArray;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSMutableString;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSMutableStringProxy;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSMutableStringProxyForMutableAttributedString;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSNameSpecifier;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSNotification;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSNotificationCenter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSNotificationObservable;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSNotificationQueue;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSNullFileHandle;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSNumber;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSNumberFormatter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSObjectSpecifier;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSObservableKeyPath;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSObservation;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSObservationBuffer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSObservationSink;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSObservationSource;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSObservationTransformer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSObservedValue;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSObserverKeyPath;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSOldValueObservationTransformer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSOperation;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSOperationQueue;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSOrderedSetChange;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSOrderedSetChanges;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSOrthography;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSOrthographyCheckingResult;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSOwnedDictionaryProxy;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSPageData;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSPathStore2;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSPersonNameComponents;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSPersonNameComponentsFormatter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSPhoneNumberCheckingResult;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSPinyinString;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSPipe;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSPlaceholderMutableString;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSPlaceholderNumber;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSPlaceholderString;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSPlaceholderValue;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSPointerArray;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSPointerFunctions;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSPort;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSPortCoder;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSPortMessage;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSPortNameServer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSPositionalSpecifier;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSPositionalSpecifierMoreIVars;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSPredicate;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSPredicateOperator;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSProcessInfo;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSProgress;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSProgressValues;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSPropertyListSerialization;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSPropertySpecifier;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSProtocolChecker;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSProxy;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSPurgeableData;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSQuitCommand;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSQuoteCheckingResult;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSRLEArray;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSRTFD;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSRandomSpecifier;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSRangeSpecifier;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSRecursiveLock;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSReduceObservationTransformer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSRegularExpression;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSRegularExpressionCheckingResult;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSRelativeSpecifier;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSReplacementCheckingResult;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSSHIFTJISX0213EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScanner;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptArgumentDescription;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptAttributeDescription;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptClassDescription;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptClassDescriptionMoreIVars;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptCoercionHandler;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptCommand;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptCommandConstructionContext;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptCommandDescription;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptCommandDescriptionMoreIVars;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptCommandMoreIVars;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptComplexTypeDescription;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptDeclaredRecordTypeDescription;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptEnumerationDescription;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptEnumeratorDescription;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptExecutionContext;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptExecutionContextMoreIVars;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptFakeObjectTypeDescription;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptListTypeDescription;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptObjectSpecifier;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptObjectTypeDescription;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptPropertiesRecordTypeDescription;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptPropertyDescription;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptRecordFieldDescription;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptRecordTypeDescription;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptSDEFElement;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptSDEFParser;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptSuiteDescription;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptSuiteRegistry;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptSynonymDescription;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptToManyRelationshipDescription;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptToOneRelationshipDescription;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptTypeDescription;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptValueTypeDescription;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptWhoseTest;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSScriptingAppleEventHandler;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSSearchPathEnumerator;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSSelfExpression;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSSerializer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSSetChange;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSSetChanges;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSSetCommand;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSSetExpression;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSSimpleAttributeDictionary;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSSimpleAttributeDictionaryEnumerator;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSSimpleCString;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSSimpleOrthography;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSSimpleRegularExpressionCheckingResult;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSSingleByteEncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSSocketPort;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSSocketPortNameServer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSSortDescriptor;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSSpecifierTest;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSSpellCheckingResult;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSSpellServer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSSpellingSubstring;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSStackObservedValue;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSString;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSStringPredicateOperator;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSSubqueryExpression;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSSubrangeData;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSSubstitutionCheckingResult;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSSubstringPredicateOperator;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSSymbolicExpression;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSTask;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSTernaryExpression;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSTextCheckingResult;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSThread;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSTokenMatchingPredicateOperator;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSTransitInformationCheckingResult;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSTruePredicate;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSURLComponents;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSURLConnectionDelegateProxy;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSURLConnectionHandle;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSURLDirectoryEnumerator;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSURLError;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSURLFileTypeMappings;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSURLFileTypeMappingsInternal;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSURLHandle;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSURLHostNameAddressInfo;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSURLKeyValuePair;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSURLQueryItem;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSURLQueue;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSURLQueueNode;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSUTF16BEEncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSUTF16BaseEncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSUTF16EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSUTF16LEEncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSUTF32BEEncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSUTF32EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSUTF32LEEncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSUTF7EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSUTF8EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSUTIPredicateOperator;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSUUID;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSUbiquitousKeyValueStore;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSUnarchiver;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSUndoManager;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSUndoManagerProxy;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSUniqueIDSpecifier;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSUnitFormatter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSUnkeyedPortCoder;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSUserActivity;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSUserAppleScriptTask;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSUserAutomatorTask;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSUserNotification;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSUserNotificationAction;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSUserNotificationCenter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSUserScriptTask;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSUserScriptTaskRunner;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSUserScriptTaskServiceDelegate;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSUserUnixTask;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSValue;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSValueTransformer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSVariableAssignmentExpression;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSVariableExpression;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSWINDOWS1250EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSWINDOWS1251EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSWINDOWS1252EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSWINDOWS1253EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSWINDOWS1254EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSWINDOWS1255EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSWINDOWS1256EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSWINDOWS1257EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSWINDOWS1258EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSWINDOWS874EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSWINDOWS932EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSWINDOWS936EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSWINDOWS949EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSWINDOWS950EncodingDetector;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSWeakCallback;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSWeakObjectValue;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSWeakPointerValue;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSWhoseSpecifier;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSWhoseTest;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSXMLAttributeDeclaration;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSXMLChildren;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSXMLContext;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSXMLDTD;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSXMLDTDNode;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSXMLDocument;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSXMLElement;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSXMLElementDeclarationContent;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSXMLFidelityElement;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSXMLFidelityNode;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSXMLNSArrayTransformerName;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSXMLNSDataTransformerName;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSXMLNSDateTransformerName;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSXMLNSNumberTransformerName;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSXMLNSURLTransformerName;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSXMLNamedFidelityNode;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSXMLNamedNode;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSXMLNode;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSXMLParser;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSXMLSAXParser;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSXMLSchemaType;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSXMLTidy;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSXMLTreeReader;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSXPCCoder;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSXPCConnection;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSXPCDecoder;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSXPCEncoder;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSXPCInterface;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSXPCListener;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSXPCListenerEndpoint;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package NSZipFileArchive;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSAECoercerData;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSAETranslatorData;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSActivityAssertion;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSBackgroundActivityInternal;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSCachedIndexSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSCallStackArray;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSConcreteObservation;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSConcreteUserNotification;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSConcreteUserNotificationAction;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSConcreteUserNotificationCenter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSDOConversationInfo;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSDiskOperation;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSDispatchData;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSFileManagerInfo;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSFileWatcherDirectoryFileHandleInfo;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSFileWatcherFileHandleInfo;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSIndexSetEnumerator;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSInlineData;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSIsNilTransformer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSIsNotNilTransformer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSJSONReader;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSJSONWriter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSKVCPIvarGetBinding;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSKVCPIvarSetBinding;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSKVO1Adaptor;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSKeyForwardingGetBinding;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSKeyForwardingSetBinding;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSKeyedCoderOldStyleArray;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSKeyedUnarchiveFromDataTransformer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSKeyedUnarchiverHelper;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSLocalNotificationCenter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSMappingObservation;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSMetadataItemPrivateIvars;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSMetadataQueryPrivateIvars;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSMetadataQueryResultArray;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSMetadataQueryResultGroupArray;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSMetadataQuerySortingPseudoItem;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSNegateBooleanTransformer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSNestedDictionary;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSObservableKVO1Adaptor;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSObservableKeyPathChangeAdaptor;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSObservableObservation;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSObserverList;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSObservingObservation;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSOwningMappingObservation;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSOwningObservingObservation;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSPersonNameComponentsData;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSPersonNameComponentsFormatterData;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSPersonNameComponentsStyleFormatter;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSPersonNameComponentsStyleFormatterAbbreviated;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSPersonNameComponentsStyleFormatterAvatar;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSPersonNameComponentsStyleFormatterFamilyInitialVariant;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSPersonNameComponentsStyleFormatterFamilyOnlyVariant;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSPersonNameComponentsStyleFormatterGivenInitialVariant;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSPersonNameComponentsStyleFormatterGivenOnlyVariant;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSPersonNameComponentsStyleFormatterLong;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSPersonNameComponentsStyleFormatterMedium;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSPersonNameComponentsStyleFormatterNicknameVariant;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSPersonNameComponentsStyleFormatterShort;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSPersonNameComponentsStyleFormatterShortNameSimpleFallback;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSPersonNameComponentsStyleFormatterShortVariantGeneral;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSPlaceholderCharacterSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSPlaceholderData;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSPlaceholderIndexSet;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSPlaceholderObservation;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSPredicateOperatorUtilities;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSPredicateUtilities;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSProgressFraction;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSProgressFractionTuple;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSProgressProxy;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSProgressSubscriber;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSProgressWithRemoteParent;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSSelectorGetBinding;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSSelectorSetBinding;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSSharedValueTransformer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSStdIOFileHandle;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSStringProxyForContext;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSThreadData;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSThreadPerformInfo;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSUnarchiveFromDataTransformer;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSUndoBeginMark;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSUndoBlockInvocation;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSUndoEndMark;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSUndoInvocation;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSUndoLightInvocation;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSUndoObject;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSUndoStack;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSXMLDocumentExtraIvars;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSXMLPlaceholderNode;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSXPCBoost;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSXPCConnectionClassCache;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSXPCConnectionExpectedReplies;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSXPCConnectionExpectedReplyInfo;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSXPCConnectionExportInfo;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSXPCConnectionExportedObjectTable;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSXPCConnectionImportInfo;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSXPCConnectionRequestedReplies;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSXPCConnectionRequestedReplyInfo;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSXPCDistantObject;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSXPCDistantObjectSynchronousWithError;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSXPCDistantObjectTimeoutWithError;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSXPCDistantObjectWithError;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSXPCDistantObjectWithUserInfoAndError;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSXPCInterfaceMethodInfo;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package _NSZeroData;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSBundleTables;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSConcreteURLComponents;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSConcreteUUID;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSLocalizedString;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSObserver;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSOperationInternal;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSOperationQueueInternal;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

package __NSVariableWidthString;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );

###############################

package Foundation;

use warnings::register;
use Carp qw(cluck);

# save some trips over the bridge
our $nsstringClass      = NSString->class();
our $nsnumberClass      = NSNumber->class();
our $nsdataClass        = NSData->class();
our $nsdateClass        = NSDate->class();
our $nsarrayClass       = NSArray->class();
our $nsdictionaryClass  = NSDictionary->class();
our $nsnullClass        = NSNull->class();
our $nsnull             = NSNull->null();

# convert a list of Perl strings to an NSArray of NSStrings
sub NSArrayOfNSStringsFromListOfPerlStrings {
    my $array = NSMutableArray->arrayWithCapacity_( int( @_ ) );
    unless ( $array and $$array ) {
        die "**** ERROR **** Foundation::NSArrayOfNSStringsFromListOfPerlStrings: can't allocate NSMutableArray with capacity ", int( @_ );
    }
        
    # loop over the arguments, converting each string to an NSString and adding to return NSArray    
    foreach my $string ( @_ ) {
        if ( not defined( $string ) ) {
            $array->addObject_( $nsnull );
        }
        elsif ( ref( $string ) eq '' ) {
            $array->addObject_( NSString->stringWithUTF8String_( "$string" ) )
        }
        elsif ( ref( $string ) eq 'SCALAR' ) {
            $array->addObject_( NSString->stringWithUTF8String_( "$$string" ) )
        }
        else {
            if ( warnings::enabled() ) {
                cluck( "**** WARNING **** Foundation::NSArrayOfNSStringsFromListOfPerlStrings: argument is not a SCALAR, it's a reference to a ", ref( $string ) );
            }
        }
    }
    
    return $array;
}

# convert an NSArray of NSStrings to a list of Perl strings 
sub listOfPerlStringsFromNSArrayOfNSStrings {
    my $array = shift @_;
    
    # check argument
    unless ( defined( $array ) ) {
        return;
    }
    unless ( ref( $array ) ) {
        if ( warnings::enabled() ) {
            cluck( "**** WARNING **** Foundation::listOfPerlStringsFromNSArrayOfNSStrings: argument is not a reference" );
        }
        return;
    }
    if ( ref( $array ) =~ m{^(REF|SCALAR|ARRAY|HASH|CODE|GLOB)$} ) {
        if ( warnings::enabled() ) {
            cluck( "**** WARNING **** Foundation::listOfPerlStringsFromNSArrayOfNSStrings: argument is an unblessed reference" );
        }
        return;
    }
    unless ( $$array ) {
        return;
    }
    unless ( $array->isKindOfClass_( $nsarrayClass ) ) {
        if ( warnings::enabled() ) {
            cluck( "**** WARNING **** Foundation::listOfPerlStringsFromNSArrayOfNSStrings: argument is not an NSArray" );
        }
        return;
    }
    
    # create an NSEnumerator for the NSArray
    my $enumerator = $array->objectEnumerator();
    unless ( $enumerator and $$enumerator ) {
        die "**** ERROR **** Foundation::listOfPerlStringsFromNSArrayOfNSStrings: can't create enumerator for argument";
    }

    # loop over the NSArray, converting each element to a Perl string and pushing onto return list
    my @list = ( );
    my $string;
    while ( $string = $enumerator->nextObject() and $$string ) {
        if ( $string->isEqual_( $nsnull ) ) {
            push( @list, undef );
        }
        elsif ( $string->isKindOfClass_( $nsstringClass ) ) {
            push( @list, $string->UTF8String() );
        }
        else {
            if ( warnings::enabled() ) {
                cluck( "**** WARNING **** Foundation::listOfPerlStringsFromNSArrayOfNSStrings: array element is not an NSString" );
            }
        }
    }
    
    return @list;
}

# convert a Perl data structure to a Foundation property list (more or less)
sub objectRefFromPerlRef
{
    my $perlRef = shift @_;
    
    # can't do much with undef
    return unless defined( $perlRef );
    
    # switch based on the type of the referent
    my $refType = ref( $perlRef );
    if ( $refType eq '' ) {                                                     # argument is a scalar
        my $nsstring = NSString->stringWithUTF8String_( "$perlRef" );
        unless ( $nsstring and $$nsstring ) {
            die "**** ERROR **** Foundation::objectRefFromPerlRef: couldn't create NSString from Perl string \"$perlRef\"";
        }
        return $nsstring;
    }
    elsif ( $refType eq 'SCALAR' ) {                                            # argument is a reference to a scalar
        my $nsstring = NSString->stringWithUTF8String_( "$$perlRef" );
        unless ( $nsstring and $$nsstring ) {
            die "**** ERROR **** Foundation::objectRefFromPerlRef: couldn't create NSString from Perl string \"$$perlRef\"";
        }
        return $nsstring;
    }
    elsif ( $refType eq 'ARRAY' ) {                                             # argument is a reference to a array
        my $nsarray = NSMutableArray->arrayWithCapacity_( int( @$perlRef ) );
        unless ( $nsarray and $$nsarray ) {
            die "**** ERROR **** Foundation::objectRefFromPerlRef: couldn't create NSMutableArray with capacity ", int( @$perlRef );
        }
        foreach $item ( @$perlRef ) {
            my $nsobject = objectRefFromPerlRef( $item );
            if ( not defined( $nsobject ) ) {
                $nsobject = $nsnull;
            }
            $nsarray->addObject_( $nsobject );
        }
        return $nsarray;
    }
    elsif ( $refType eq 'HASH' ) {                                              # argument is a reference to a hash
        my @keys = keys( %$perlRef );
        my $nsdict = NSMutableDictionary->dictionaryWithCapacity_( int( @keys ) );
        unless ( $nsdict and $$nsdict ) {
            die "**** ERROR **** Foundation::objectRefFromPerlRef: couldn't create NSMutableDictionary with capacity ", int( @keys );
        }
        foreach my $key ( @keys ) {
            my $keyObject = NSString->stringWithUTF8String_( "$key" );
            unless ( $keyObject and $$keyObject ) {
                die "**** ERROR **** Foundation::objectRefFromPerlRef: couldn't convert key \"$key\" to NSString";
            }
            my $valueObject = objectRefFromPerlRef( $perlRef->{$key} );
            if ( not defined( $valueObject ) ) {
                $valueObject = $nsnull;
            }
            $nsdict->setObject_forKey_( $valueObject, $keyObject );
        }
        return $nsdict;
    }
    else {
        return;                                                                 # don't know how to handle other ref types
    }
}

# convert a Foundation property list to a Perl data structure (more or less)
sub perlRefFromObjectRef {
    my $nsobject = shift @_;
        
    # check argument
    unless ( defined( $nsobject ) ) {
        return;
    }
    unless ( ref( $nsobject ) ) {
        if ( warnings::enabled() ) {
            cluck( "**** WARNING **** Foundation::perlRefFromObjectRef: argument is not a reference" );
        }
        return;
    }
    if ( ref( $nsobject ) =~ m{^(REF|SCALAR|ARRAY|HASH|CODE|GLOB)$} ) {
        if ( warnings::enabled() ) {
            cluck( "**** WARNING **** Foundation::perlRefFromObjectRef: argument is an unblessed reference" );
        }
        return;
    }
    unless ( $$nsobject ) {
        return;
    } 

    # switch based on kind of object
    if ( $nsobject->isKindOfClass_( $nsstringClass ) ) {                    # argument is an NSString
        return $nsobject->UTF8String();
    }
    elsif ( $nsobject->isKindOfClass_( $nsnumberClass ) ) {                 # argument is an NSNumber
        return $nsobject->stringValue()->UTF8String();                          ## ugh, convert to string
    }
    elsif ( $nsobject->isKindOfClass_( $nsdateClass) ) {                    # argument is an NSDate
        return $nsobject->description()->UTF8String();                          ## ugh, convert to string
    }
    elsif ( $nsobject->isKindOfClass_( $nsnullClass) ) {                    # argument is an NSNull
        return undef;                                                           ## return undef
    }
    elsif ( $nsobject->isKindOfClass_( $nsdataClass) ) {                    # argument is an NSData
        return $nsobject->bytes();                                              ## returns a scalar containing a pointer(!)
    }
    elsif ( $nsobject->isKindOfClass_( $nsarrayClass ) ) {                  # argument is an NSArray
        my $enumerator = $nsobject->objectEnumerator();
        unless ( $enumerator and $$enumerator ) {
            die "**** ERROR **** Foundation::perlRefFromObjectRef: can't create enumerator for NSArray";
        }
        my @array;
        my $nsobject2;
        while ( $nsobject2 = $enumerator->nextObject() and $$nsobject2 ) {
            push( @array, perlRefFromObjectRef( $nsobject2 ) );
        }
        return \@array;
    }
    elsif ( $nsobject->isKindOfClass_( $nsdictionaryClass ) ) {             # argument is an NSDictionary
        my $enumerator = $nsobject->keyEnumerator();
        unless ( $enumerator and $$enumerator ) {
            die "**** ERROR **** Foundation::perlRefFromObjectRef: can't create enumerator for NSDictionary";
        }
        my %hash;
        my $keyObject;
        while ( $keyObject = $enumerator->nextObject() and $$keyObject ) {
            my $key = $keyObject->UTF8String();
            unless ( defined( $key ) ) {
                die "**** ERROR **** Foundation::perlRefFromObjectRef: can't convert NSDictionary key to Perl string";
            }
            my $valueObject = $nsobject->objectForKey_( $keyObject );
            unless ( $valueObject and $$valueObject ) {
                die "**** ERROR **** Foundation::perlRefFromObjectRef: can't get NSDictionary value for key \"$key\"";
            }
            $hash{$key} = perlRefFromObjectRef( $valueObject );
        }
        return \%hash;
    }
    else {
        return;                                                             # argument class is unsupported
    }
}

# Splice this in here to avoid problems where NSObject doesn't have a Class reference in Perl. See:
#   <rdar://problem/10678884> CrashTracer: [USER] 46 crashes in perl5.12 at libperl.dylib: Perl_Gv_AMupdate + 65
# We splice it in here so that the resultant Foundation.pm will have this without needing to modify the logic
# in createBridgeModules or PerlObjCBridge's convoluted Makefile
package NSObject;
@ISA = qw(PerlObjCBridge);
@EXPORT = qw( );


1;
