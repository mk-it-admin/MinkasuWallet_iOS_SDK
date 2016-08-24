//
//  CustomerInfo.h
//  PayNow
//
//  Created by Subramanian Lakshmanan on 3/5/14.
//  Copyright (c) 2014 Subramanian Lakshmanan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>


@interface CustomerInfo : NSManagedObject

@property (nonatomic, retain) NSString * device_id;
@property (nonatomic, retain) NSString * customer_id;
@property (nonatomic, retain) NSString * customer_login;
@property (nonatomic, retain) NSString * customer_name;
@property (nonatomic, retain) NSNumber * app_version;
@property (nonatomic, retain) NSString * pin_salt;
@property (nonatomic, retain) NSString * pin_hash;
@property BOOL ftu_setup_complete;
@property int16_t incorrect_pin_count;
@property (nonatomic, retain) NSDate *incorrect_pin_time;
@property int32_t account_status;

@end
