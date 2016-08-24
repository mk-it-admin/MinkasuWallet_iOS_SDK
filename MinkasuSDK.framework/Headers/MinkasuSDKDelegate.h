//
//  MinkasuSDKDelegate.h
//  MinkasuSDK
//
//  Created by Sachin Selvaraj on 3/8/16.
//  Copyright © 2016 Sachin Selvaraj. All rights reserved.
//

#ifndef MinkasuSDKDelegate_h
#define MinkasuSDKDelegate_h


#endif /* MinkasuSDKDelegate_h */
#import "MinkasuTxnInformation.h"

@protocol MinkasuSDKDelegate <NSObject>

- (void) didCancelWithError:(NSError *) error;
- (void) didFinishPaymentSuccessfullyWithTnxInformation: (MinkasuTxnInformation *)txnInformation;

//@optional
//- (void) netswipeViewController:(NetswipeViewController *) controller didStartScanAttemptWithScanReference:(NSString *) scanReference;

@end