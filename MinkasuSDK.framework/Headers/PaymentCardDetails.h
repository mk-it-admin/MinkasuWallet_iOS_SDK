//
//  PaymentCardDetails.h
//  PayNow
//
//  Created by Subramanian Lakshmanan on 3/3/14.
//  Copyright (c) 2014 Subramanian Lakshmanan. All rights reserved.
//

#import <Foundation/Foundation.h>

// This is the container data structure holding phone side information about a credit card
// The card number or cvc is not held in particular.
// The phone side half after the card data is split is stored
// along with other meta data like card type, last 4 etc.


@interface PaymentCardDetails : NSObject

@property NSString *card_type;
@property NSString *card_alias;
@property NSString *encoded_card_data;
@property unsigned int card_exp_month;
@property unsigned int card_exp_year;
@property NSString *last_4digs;
@property NSString *card_holder_name;

- (NSString *) ToString;
- (NSString *) getCardTypeForDisplay;

+ (PaymentCardDetails *) FromString: (NSString *)in_str;

@end
