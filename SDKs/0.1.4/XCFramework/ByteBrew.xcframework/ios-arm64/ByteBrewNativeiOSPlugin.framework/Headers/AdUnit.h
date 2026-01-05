//
//  AdUnit.h
//  bytebrew-cross-promo
//
//  Created by Max Wilk on 2/23/25.
//

#ifndef AdUnit_h
#define AdUnit_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const INTERSTITIAL_STRING;
extern NSString * const REWARDED_STRING;

@interface AdUnit : NSObject

@property (nonatomic, strong, readonly) NSString *adID;
@property (nonatomic, strong, readonly) NSString *adUnitID;
@property (nonatomic, strong, readonly) NSString *mediaURL;
@property (nonatomic, strong, readonly) NSString *platform;
@property (nonatomic, strong, readonly) NSString *bbAppID;
@property (nonatomic, strong, readonly) NSString *appName;
@property (nonatomic, strong, readonly) NSString *appIcon;
@property (nonatomic, strong, readonly) NSString *appStore;
@property (nonatomic, strong, readonly) NSString *bundle;
@property (nonatomic, strong, readonly) NSString *timestamp;
@property (nonatomic, strong, readonly) NSString *appSubtitle;
@property (nonatomic, strong, readonly) NSString *cta;
@property (nonatomic, strong, readonly) NSString *orientation;
@property (nonatomic, strong, readonly) NSString *adType;
@property (nonatomic, assign) BOOL isCTRLOnly;
@property (nonatomic, strong, readonly) NSString *adTemplate;

- (instancetype)initWithId:(NSString *)adID
                  adUnitID:(NSString *)adUnitID
                  mediaURL:(NSString *)mediaURL
                  platform:(NSString *)platform
                   bbAppID:(NSString *)bbAppID
                   appName:(NSString *)appName
                   appIcon:(NSString *)appIcon
                  appStore:(NSString *)appStore
                    bundle:(NSString *)bundle
                 timestamp:(NSString *)timestamp
               appSubtitle:(NSString *)appSubtitle
                       cta:(NSString *)cta
               orientation:(NSString *)orientation
                    adType:(NSString *)adType
                isCTRLOnly:(BOOL)isCTRLOnly
                adTemplate:(NSString *)adTemplate NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithAdUnitId:(NSString *)adUnitID
                          adType:(NSString *)adType
                      isCTRLOnly:(BOOL)isCTRLOnly;

- (instancetype)init NS_UNAVAILABLE;

- (NSString *)getCacheKey;
- (BOOL)isInterstitialAd;
- (BOOL)isRewardedAd;

@end

NS_ASSUME_NONNULL_END

#endif /* AdUnit_h */
