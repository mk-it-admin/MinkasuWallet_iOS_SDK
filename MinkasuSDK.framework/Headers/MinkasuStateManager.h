//
//  MinkasuStateManager.h
//  MinkasuSDK
//
//  Created by Sachin Selvaraj on 2/17/16.
//  Copyright © 2016 Sachin Selvaraj. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MinkasuConfigs.h"

@interface MinkasuStateManager : NSObject{
    
}

@property (nonatomic, retain) NSManagedObjectModel *managedObjectModel;
@property (nonatomic, retain) NSManagedObjectContext *managedObjectContext;
@property (nonatomic, retain) NSPersistentStoreCoordinator *persistentStoreCoordinator;
@property NSMutableArray *centerViewControllers;
@property UIViewController *root_view_controller;
@property UINavigationController *current_nav_controller;
@property BOOL isSDKCall;
@property BOOL netswipeKeyPresent;
@property BOOL netverifyKeyPresent;
@property NSString *paymentCode;
@property MinkasuConfigs *sdkConfigs;
@property BOOL sdkTxnComplete;
@property BOOL sdkInitComplete;
@property UIViewController *universalLinkHandledFromViewController;

+ (id)sharedManager;
- (void) initPushNotification:(UIApplication *)application forCustomer:(NSString *)customerId;
- (NSString*) getCustomerId;
- (void) attachDeviceIdForCustomer:(NSString*)deviceId forCustomer:(NSString*)customerId;
- (UIActivityIndicatorView *) getNWActivitySpinnerForView: (UIViewController *) view_controller;
- (void) checkConnectivityToServer:(void (^)(BOOL keys_retrieved)) completionHandler;
- (BOOL) handleUniversalLink:(NSURL *)url;
- (void)scheduleProcessingTransactionCodeString: (NSString *)txn_code_string FromApplication: (NSString *)sourceApplication WithArgs: (NSDictionary *)argDict;
+ (void) configureNavigationBar:(UINavigationBar *)navigationBar;
- (UIViewController*) topMostController;

- (int) savePIN:(NSString *)pin;
- (BOOL) matchPIN:(NSString*)pin2;
- (BOOL) hasPIN;
- (int16_t) getIncorrectPINCount;
- (void) incrementIncorrectPINCount;
- (void) resetIncorrectPINCount;
- (double) timeSinceIncorrectPIN;
- (BOOL) isPINLockoutInEffect;

- (void) upgradeCheck:(BOOL)forceUpgrade withTargetVersion:(NSString *)version;

- (void) setAccountDeviceVerificationStatus: (BOOL)verified;
- (void) setAccountPhoneVerificationStatus: (BOOL)verified;
- (void) setAccountIdVerificationStatus: (BOOL)verified;
- (void) setAccountIdVerificationRequired: (BOOL)reqd;
- (BOOL) phoneVerificationIsPending;
- (BOOL) deviceVerificationIsPending;
- (BOOL) idVerificationIsPending;
- (BOOL) idVerificationIsRequired;



@end
