//
//  ByteBrewAds.h
//  bytebrew-cross-promo
//
//  Created by Max Wilk on 2/23/25.
//

#ifndef ByteBrewAds_h
#define ByteBrewAds_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <ByteBrewNativeiOSPlugin/AdData.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AdInitEventListener <NSObject>
@optional
- (void)onAdsInitSuccess;
- (void)onAdsInitFailure;
@end

@protocol AdEventListener <NSObject>
@optional
- (void)onAdStarted:(AdData *)adData;
- (void)onAdClicked:(AdData *)adData;
- (void)onAdCompleted:(AdData *)adData;
- (void)onAdDismissed:(AdData *)adData;
- (void)onAdError:(NSString *)error adData:(nullable AdData *)adData;
@end

@protocol RewardedAdEventListener <AdEventListener>
@optional
- (void)onAdRewarded:(AdData *)adData;
@end

@protocol InterstitialAdEventListener <AdEventListener>
@optional
@end

@protocol AdLoadEventListener <NSObject>
@optional
- (void)onAdLoaded:(AdData *)adData;
- (void)onAdLoadError:(NSString *)error adData:(nullable AdData *)adData;
@end

@interface ByteBrewAds : NSObject

+ (void)initAdsWithContext:(id)context;
+ (void)initAdsWithContext:(id)context listener:(nullable id<AdInitEventListener>)listener;
+ (void)tryInitWithContext:(id)context;
+ (void)failInit;

+ (void)loadInterstitialCrossPromoAd:(NSString *)adUnitID;
+ (void)loadInterstitialCrossPromoAd:(NSString *)adUnitID ctrlOnly:(BOOL)ctrlOnly;
+ (void)loadInterstitialCrossPromoAdWithListener:(nullable id<AdLoadEventListener>)listener adUnitID:(NSString *)adUnitID ctrlOnly:(BOOL)ctrlOnly;

+ (void)loadRewardedCrossPromoAd:(NSString *)adUnitID;
+ (void)loadRewardedCrossPromoAd:(NSString *)adUnitID ctrlOnly:(BOOL)ctrlOnly;
+ (void)loadRewardedCrossPromoAdWithListener:(nullable id<AdLoadEventListener>)listener adUnitID:(NSString *)adUnitID ctrlOnly:(BOOL)ctrlOnly;

+ (void)showInterstitialCrossPromoAd:(NSString *)adUnitID;
+ (void)showInterstitialCrossPromoAd:(nullable UIViewController *)context adUnitID:(NSString *)adUnitID;
+ (void)showInterstitialCrossPromoAd:(NSString *)adUnitID ctrlOnly:(BOOL)ctrlOnly;
+ (void)showInterstitialCrossPromoAdWithContext:(nullable UIViewController *)context adUnitID:(NSString *)adUnitID ctrlOnly:(BOOL)ctrlOnly;
+ (void)showInterstitialCrossPromoAdWithContext:(nullable UIViewController *)context adUnitID:(NSString *)adUnitID ctrlOnly:(BOOL)ctrlOnly listener:(nullable id<AdEventListener>)listener;

+ (void)showRewardedCrossPromoAd:(NSString *)adUnitID;
+ (void)showRewardedCrossPromoAd:(nullable UIViewController *)context adUnitID:(NSString *)adUnitID;
+ (void)showRewardedCrossPromoAd:(NSString *)adUnitID ctrlOnly:(BOOL)ctrlOnly;
+ (void)showRewardedCrossPromoAdWithContext:(nullable UIViewController *)context adUnitID:(NSString *)adUnitID ctrlOnly:(BOOL)ctrlOnly;
+ (void)showRewardedCrossPromoAdWithContext:(nullable UIViewController *)context adUnitID:(NSString *)adUnitID ctrlOnly:(BOOL)ctrlOnly listener:(nullable id<AdEventListener>)listener;

+ (void)flushAllAds;
+ (BOOL)isInitialized;
+ (BOOL)isAdShowing;
+ (BOOL)isCrossPromoAdLoaded:(NSString *)adUnitID;
+ (BOOL)isCrossPromoAdLoaded:(NSString *)adUnitID ctrlOnly:(BOOL)ctrlOnly;

+ (NSString*)adsAPIBaseURL;
+ (NSString*)measurementAPIBaseURL;
+ (BOOL)preDownloadAdVideo;
+ (BOOL)preDownloadAdIcon;

+ (NSString*)sdkKey;

+ (void)setSettingsDict:(NSDictionary *)settingsDict;
+ (NSString*)getSettingFromDict:(NSString *)settingKey;

+ (NSString*)fallbackVideoAdUnitID;
+ (void)setFallbackVideoAdUnitID:(NSString *)adUnitID;

+ (id<AdInitEventListener>)adInitEventListener;
+ (void)setAdInitEventListener:(id<AdInitEventListener>)listener;

+ (id<AdEventListener>)getAppropriateAdEventListener:(AdUnit *)adUnit;
+ (id<AdLoadEventListener>)getAppropriateAdLoadEventListener:(AdUnit *)adUnit;

+ (id<InterstitialAdEventListener>)interstitialAdEventListener;
+ (void)setInterstitialAdEventListener:(id<InterstitialAdEventListener>)listener;

+ (id<AdLoadEventListener>)interstitialAdLoadEventListener;
+ (void)setInterstitialAdLoadEventListener:(id<AdLoadEventListener>)listener;

+ (id<RewardedAdEventListener>)rewardedAdEventListener;
+ (void)setRewardedAdEventListener:(id<RewardedAdEventListener>)listener;

+ (id<AdLoadEventListener>)rewardedAdLoadEventListener;
+ (void)setRewardedAdLoadEventListener:(id<AdLoadEventListener>)listener;

+ (nullable UIViewController *)getTopViewController;

+ (void)reportAdDismissed;

@end

NS_ASSUME_NONNULL_END

#endif /* ByteBrewAds_h */
