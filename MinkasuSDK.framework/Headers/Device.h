//
//  Device.h
//  PayNow
//
//  Created by ashis poddar on 1/24/15.
//  Copyright (c) 2015 Subramanian Lakshmanan. All rights reserved.
//

#ifndef PayNow_Device_h
#define PayNow_Device_h

@interface Device : NSObject

@property (nonatomic, strong) NSString * name;
@property (nonatomic, strong) NSString * os;
@property (nonatomic, strong) NSString * platform;
@property (nonatomic, strong) NSString * id;
@property (nonatomic, strong) NSString * notificationToken;
@property (nonatomic, strong) NSString * status;
@property (nonatomic, strong) NSString * uuid;
@property (nonatomic, assign) NSNumber * confirmed ;
@property (nonatomic, assign) BOOL * disabled ;
@property (nonatomic, strong) NSString * customerId;
@property (nonatomic, strong) NSDate * timeCreated;
@property (nonatomic, strong) NSDate * timeUpdated;

@end

#endif
