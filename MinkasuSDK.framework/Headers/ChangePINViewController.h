//
//  CreatePINViewController.h
//  PayNow
//
//  Created by Subramanian Lakshmanan on 2/14/15.
//  Copyright (c) 2015 Subramanian Lakshmanan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MinkasuStateManager.h"

@interface ChangePINViewController : UIViewController<UITextFieldDelegate>  

@property (strong, nonatomic) IBOutlet UILabel *message;
@property (strong, nonatomic) IBOutlet UITextField *Pin1;
@property (strong, nonatomic) IBOutlet UITextField *Pin2;
@property (strong, nonatomic) IBOutlet UITextField *Pin3;
@property (strong, nonatomic) IBOutlet UITextField *Pin4;

@property MinkasuStateManager *mainAppDelegate;

@end
