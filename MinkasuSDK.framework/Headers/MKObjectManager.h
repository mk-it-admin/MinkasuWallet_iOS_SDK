//
//  MKObjectManager.h
//  PayNow
//
//  Created by ashis poddar on 1/24/15.
//  Copyright (c) 2015 Subramanian Lakshmanan. All rights reserved.
//

#ifndef PayNow_MKObjectManager_h
#define PayNow_MKObjectManager_h

#import <RestKit/Network/RKObjectManager.h>

@interface MKObjectManager : RKObjectManager

+ (instancetype) sharedManager;

- (void) setupRequestDescriptors;
- (void) setupResponseDescriptors;

@end


#endif
