//
//  MappingProvider.h
//  PayNow
//
//  Created by ashis poddar on 1/24/15.
//  Copyright (c) 2015 Subramanian Lakshmanan. All rights reserved.
//

#ifndef PayNow_MappingProvider_h
#define PayNow_MappingProvider_h

#import <Foundation/Foundation.h>

@class RKObjectMapping;

@interface MappingProvider : NSObject

+ (RKObjectMapping *) deviceMapping;
+ (RKObjectMapping *) phoneConfirmMapping;

@end

#endif
