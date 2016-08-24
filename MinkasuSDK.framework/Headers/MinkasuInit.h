//
//  MinkasuInit.h
//  MinkasuSDK
//
//  Created by Sachin Selvaraj on 2/16/16.
//  Copyright © 2016 Sachin Selvaraj. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MinkasuStateManager.h"
#import "MinkasuConfigs.h"
#import "StartViewController.h"
#import "PastPaymentsViewController.h"
#import "ManageCardsViewController.h"


@interface MinkasuInit : NSObject

@property MinkasuStateManager *stateManager;

-(id) initWithConfiguration:(MinkasuConfigs*)configuration;
-(UINavigationController*) getViewController:(int)pageToCall;

@end
