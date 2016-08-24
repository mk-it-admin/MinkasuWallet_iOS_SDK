//
//  PhoneConfirmManager.h
//  PayNow
//
//  Created by ashis poddar on 2/16/15.
//  Copyright (c) 2015 Subramanian Lakshmanan. All rights reserved.
//

#ifndef PayNow_PhoneConfirmManager_h
#define PayNow_PhoneConfirmManager_h


#import "MKObjectManager.h"

@class PhoneConfirm;

@interface PhoneConfirmManager : MKObjectManager

@property (nonatomic, strong) NSString * currentConfirmRequestId; //ensure tou set to null before stating the process


- (void) startConfirmationProcess:(NSString*)customerId
                        withPhone:(NSString*)phone
                        success:(void(^)(PhoneConfirm *confirmReq))success
                        failure: (void (^)(RKObjectRequestOperation *operation, NSError *error))failure;

- (void) getConfirmationStatus:(NSString*)requestId
                       success:(void(^)(PhoneConfirm *confirmReq))success
                       failure: (void (^)(RKObjectRequestOperation *operation, NSError *error))failure;

@end

#endif
