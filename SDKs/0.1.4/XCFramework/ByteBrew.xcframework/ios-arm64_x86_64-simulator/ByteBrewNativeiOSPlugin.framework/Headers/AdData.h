//
//  AdData.h
//  bytebrew-cross-promo
//
//  Created by Max Wilk on 3/28/25.
//

#ifndef AdData_h
#define AdData_h

#import <Foundation/Foundation.h>
#import <ByteBrewNativeiOSPlugin/AdData.h>
#import <ByteBrewNativeiOSPlugin/AdUnit.h>

NS_ASSUME_NONNULL_BEGIN

@interface AdData : NSObject

@property (nonatomic, strong, readonly) NSString *adUnitID;
@property (nonatomic, assign) BOOL isCTRLOnly;

- (instancetype)initWithAdID:(NSString *)adUnitID
                  isCTRLOnly:(BOOL)isCTRLOnly NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithOnlyAdUnitId:(NSString *)adUnitID;

- (instancetype)initWithAdUnit:(AdUnit * _Nullable)adUnit;

- (NSString *)getInfoString;

@end

NS_ASSUME_NONNULL_END

#endif /* AdData_h */
