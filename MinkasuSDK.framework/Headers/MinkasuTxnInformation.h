//
//  MinkasuTxnInformation.h
//  MinkasuSDK
//
//  Created by Sachin Selvaraj on 3/8/16.
//  Copyright © 2016 Sachin Selvaraj. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MinkasuTxnInformation : NSObject

@property NSString *merchant_name;
@property NSString *amount;
@property NSString *transactionId;
@property NSString *billno;
@property BOOL txn_is_donation;
@property BOOL isRedirect;
@property BOOL noRedirect;

@end
