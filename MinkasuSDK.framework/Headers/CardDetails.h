//
//  CardDetails.h
//  PayNow
//
//  Created by Subramanian Lakshmanan on 2/15/15.
//  Copyright (c) 2015 Subramanian Lakshmanan. All rights reserved.
//

#import <Foundation/Foundation.h>

// Captures all information entered about a credit card in the setup or add card screen.
// Also supports methods to split card data and register the card with the server
// by splittng the card data and sending the phone side half.

@interface CardDetails : NSObject

@property NSString *card_num;
@property NSString *card_exp;
@property NSString *cvc;

@property NSString *card_holder_name;

@property NSString *address_line_1;
@property NSString *address_line_2;
@property NSString *city;
@property NSString *state;
@property NSString *zip;

@property NSString *card_type;
@property NSString *card_alias;
@property unsigned int card_exp_month;
@property unsigned int card_exp_year;
@property NSString *last_4digs;

@property NSString *local_card_data;
@property NSString *svr_card_data;



+ (CardDetails *) cardDetailsUsingCardNum: (NSString *)card_num_str WithExp: (NSString *)card_exp_str Cvc: (NSString *)cvc_str Name: (NSString *)name_str AddressLine1: (NSString *)addr_line1_str Line2: (NSString *)addr_line2_str City: (NSString *)city_str State: (NSString *)state_str Zip: (NSString *)zip_str;

- (void) splitCardDetails;

- (void) registerCardWithServerWithCompletion:(void (^)(int error, NSString *error_message))completion;

@end
