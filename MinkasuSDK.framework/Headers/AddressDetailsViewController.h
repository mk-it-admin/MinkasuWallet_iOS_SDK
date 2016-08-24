//
//  AddressDetailsViewController.h
//  PayNow
//
//  Created by Praveena Khanna on 2/3/15.
//  Copyright (c) 2015 Subramanian Lakshmanan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Address.h"
#import "StartViewController.h"
#import "MinkasuStateManager.h"

#define SCREEN_MODE_VIEW 0
#define SCREEN_MODE_EDIT 1
#define SCREEN_MODE_NEW 2

@interface AddressDetailsViewController : UIViewController <UITextFieldDelegate, UIAlertViewDelegate>

@property BOOL adddress_reqd;
@property BOOL email_reqd;
@property BOOL phone_reqd;


@property (weak, nonatomic) IBOutlet UITextField *NameTextElement;

@property (weak, nonatomic) IBOutlet UITextField *AddrLine1Element;

@property (weak, nonatomic) IBOutlet UITextField *AddrLine2Element;

@property (weak, nonatomic) IBOutlet UITextField *CityElement;

@property (weak, nonatomic) IBOutlet UITextField *StateElement;

@property (weak, nonatomic) IBOutlet UITextField *ZipElement;

@property (weak, nonatomic) IBOutlet UIBarButtonItem *SlideOutMenuButton;

@property (weak, nonatomic) IBOutlet UIBarButtonItem *SaveButton;

@property (weak, nonatomic) IBOutlet UIButton *RemoveButton;



- (IBAction)SaveButtonClicked:(id)sender;

- (IBAction)RemoveButtonClicked:(id)sender;


@property StartViewController *root_view_controller;
@property MinkasuStateManager *mainAppDelegate;
@property BOOL presentAsModal;
@property int screen_mode;


- (IBAction)SlideOutMenuButtonClicked:(id)sender;

@property Address *address;
@property int address_index;

@end
