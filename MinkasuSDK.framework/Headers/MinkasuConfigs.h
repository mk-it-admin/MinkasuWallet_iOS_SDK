//
//  MinkasuConfigs.h
//  MinkasuSDK
//
//  Created by Sachin Selvaraj on 2/16/16.
//  Copyright © 2016 Sachin Selvaraj. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import <UIKit/UIKit.h>
#import "MinkasuTxnInformation.h"
#import "MinkasuSDKDelegate.h"

@interface MinkasuConfigs : NSObject

@property NSString *partner_id;
@property NSString *partner_mk_access_token;
@property NSString *txn_code_string;
@property (nonatomic, weak) id<MinkasuSDKDelegate> delegate;
@property int pageToCall;
@property BOOL isSDKCall;
@property NSString *netswipe_api_token;
@property NSString *netswipe_api_secret;
@property NSString *netverify_api_token;
@property NSString *netverify_api_secret;


@end

