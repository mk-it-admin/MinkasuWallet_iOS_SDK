//
//  PhoneConfirm.h
//  PayNow
//
//  Created by ashis poddar on 2/16/15.
//  Copyright (c) 2015 Subramanian Lakshmanan. All rights reserved.
//

#ifndef PayNow_PhoneConfirm_h
#define PayNow_PhoneConfirm_h

@interface PhoneConfirm : NSObject

@property (nonatomic, strong) NSString * id;
@property (nonatomic, strong) NSString * deviceId;
@property (nonatomic, strong) NSString * carrier;
@property (nonatomic, strong) NSString * phone;
@property (nonatomic, strong) NSString * token;
@property (nonatomic, strong) NSString * status ;


@end

#endif
