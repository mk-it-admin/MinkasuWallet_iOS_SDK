//
//  PaymentDetails.h
//  PayNow
//
//  Created by Subramanian Lakshmanan on 3/25/14.
//  Copyright (c) 2014 Subramanian Lakshmanan. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PaymentDetails : NSObject

@property NSString *transactionId;
@property NSString *merchantName;
@property unsigned int merchantBillNumber;
@property unsigned int billAmountInCents;
@property NSString *billAmountInDollars;
@property NSDate *timePaid;
@property NSString *timePaidString;
@property NSString *card_alias;
@property NSString *receiptString;
@property NSString *paymentCertificate;
@property NSString *customerDetailsString;
@property unsigned int transactionState;

@end
