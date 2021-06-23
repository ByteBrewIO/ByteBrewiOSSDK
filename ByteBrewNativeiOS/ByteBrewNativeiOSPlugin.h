//
//  ByteBrewNativeiOSPlugin.h
//  ByteBrewNativeiOSPlugin
//
//  Created by Cameron Hozouri on 4/23/21.
//

#ifndef ByteBrewProgressionType_h
#define ByteBrewProgressionType_h
typedef enum {
    Started,
    Completed,
    Failed
} ByteBrewProgressionType;

#endif /* ByteBrewProgressionType_h */

#import <Foundation/Foundation.h>

@interface ByteBrewNativeiOSPlugin : NSObject
+(void)InitialzeWithSettings:(NSString*) gameID SecretKey:(NSString*) secretKey EngineVersion:(NSString*) engineV BuildVersion:(NSString*) buildV;
+(void) AddNewCustomEvent:(NSString*) eventName;
+(void) AddNewCustomEventWithNumericValue:(NSString *)eventName Value:(Float64) value;
+(void) AddNewCustomEventWithStringValue:(NSString *)eventName Value:(NSString*) value;
+(void) AddProgressionEvent:(ByteBrewProgressionType) progressionStatus Environment:(NSString*) environment Stage:(NSString*) stage;
+(void) AddProgressionEventWithNumericValue:(ByteBrewProgressionType) progressionStatus Environment:(NSString*) environment Stage:(NSString*) stage Value:(Float64) value;
+(void) AddProgressionEventWithStringValue:(ByteBrewProgressionType) progressionStatus Environment:(NSString*) environment Stage:(NSString*) stage Value:(NSString*) value;
+(void) NewTrackedAdEvent:(NSString*) placementType AdLocation:(NSString*) adLoaction;
+(void) NewTrackedAdEvent:(NSString*) placementType AdLocation:(NSString*) adLocation AdID:(NSString*) adID;
+(void) NewTrackedAdEvent:(NSString*) placementType AdLocation:(NSString*) adLocation AdID:(NSString*) adID AdProvider:(NSString*) adProvider;
+(void) AddTrackedInAppPurchaseEvent:(NSString*) store Currency:(NSString*) currency Amount:(Float64) amount ItemID:(NSString*) itemID Category:(NSString*) category;
+(void) AddTrackediOSInAppPurchaseEvent:(NSString*) store Currency:(NSString*) currency Amount:(Float64) amount ItemID:(NSString*) itemID Category:(NSString*) category Receipt:(NSString*) receipt;
typedef void (^FinishedRetrieval)(BOOL status);
+(void) LoadRemoteConfigs:(FinishedRetrieval) finished;
+(NSString*) RetrieveRemoteConfigs:(NSString*) key DefaultValue:(NSString*) defaultValue;
+(void) RestartTracking;
+(void) StopTracking;
@end
