//
//  CustomerDetails.h
//  PayNow
//
//  Created by Subramanian Lakshmanan on 3/30/14.
//  Copyright (c) 2014 Subramanian Lakshmanan. All rights reserved.
//

#import <Foundation/Foundation.h>

#define MASK_BIT_ADDRESS 0x1
#define MASK_BIT_EMAIL 0x2
#define MASK_BIT_PHONE 0x4

// This is the container data structure holding information about the User from the profile screen
// namely Phone and Email.

@interface CustomerDetails : NSObject

@property NSString *customerName;
@property NSString *phone;
@property NSString *email;

- (CustomerDetails *) init;

- (NSString *) toString;

+ (CustomerDetails *) fromString: (NSString *)string_rep;

+ (CustomerDetails *) customerDetailsWithCustomerName: (NSString *)name_str Phone: (NSString *)phone_str Email: (NSString *)email_str;

@end
