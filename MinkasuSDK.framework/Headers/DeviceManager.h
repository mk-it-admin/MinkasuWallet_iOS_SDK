//
//  DeviceManager.h
//  PayNow
//
//  Created by ashis poddar on 1/24/15.
//  Copyright (c) 2015 Subramanian Lakshmanan. All rights reserved.
//

#ifndef PayNow_DeviceManager_h
#define PayNow_DeviceManager_h


#import "MKObjectManager.h"

@class Device;

@interface DeviceManager : MKObjectManager

@property (assign, atomic) BOOL deviceRegistrationInProgress;
@property (strong, atomic) NSString *deviceId;

- (void) loadDevice:(void (^)(Device  *device))success failure:(void (^)(RKObjectRequestOperation *operation, NSError *error))failure;
- (void) createDevice:(NSString*)customerId withToken:(NSString*)notificationToken;
- (void) updateDevice:(NSString*)deviceId withToken:(NSString*)notifToken forCustomer:(NSString*)customerId;
- (void) confirmDevice:(NSString*)deviceId forCustomer:(NSString*)customerId withCode:(NSString*)code;

@end

#endif
