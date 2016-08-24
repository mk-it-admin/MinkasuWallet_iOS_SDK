//
//  Address.h
//  PayNow
//
//  Created by Praveena Khanna on 2/4/15.
//  Copyright (c) 2015 Subramanian Lakshmanan. All rights reserved.
//

#import <Foundation/Foundation.h>

#define MASK_BIT_ADDRESS 0x1
#define MASK_BIT_EMAIL 0x2
#define MASK_BIT_PHONE 0x4

@interface Address : NSObject

@property NSString *customerName;
@property NSString *addrLine1;
@property NSString *addrLine2;
@property NSString *city;
@property NSString *state;
@property NSString *zip;

- (Address *) init;

- (NSString *) toString;

- (NSString *) getEncodedStringWithMask: (unsigned int)details_mask;

- (BOOL) hasValidAddress;

+ (Address *) fromString: (NSString *)string_rep;


+ (Address *) addressWithName: (NSString *)name_str Line1: (NSString *)addr_line1 Line2: (NSString *)addr_line2 City: (NSString *)city_str State: (NSString *)state_str Zip: (NSString *)zip_str;

+ (NSString *) getEncodedStringWithName: (NSString *)name AddrLine1: (NSString *)addr_line1 Line2: (NSString *)addr_line2 City: (NSString *)city State: (NSString *)state Zip: (NSString *)zip;

+ (BOOL) stateCodeIsValid: (NSString *)state_code;

@end

