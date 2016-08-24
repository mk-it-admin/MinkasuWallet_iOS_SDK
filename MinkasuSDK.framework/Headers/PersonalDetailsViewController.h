//
//  PersonalDetailsViewController.h
//  PayNow
//
//  Created by Subramanian Lakshmanan on 3/30/14.
//  Copyright (c) 2014 Subramanian Lakshmanan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CustomerDetails.h"
#import "StartViewController.h"
#import "MinkasuStateManager.h"

@interface PersonalDetailsViewController : UIViewController <UITextFieldDelegate, UIAlertViewDelegate>

@property (weak, nonatomic) IBOutlet UITextField *NameTextElement;

@property (weak, nonatomic) IBOutlet UITextField *PhoneNumberElement;

@property (weak, nonatomic) IBOutlet UITextField *EmailAddressElement;


@property (weak, nonatomic) IBOutlet UIBarButtonItem *SlideOutMenuButton;

@property (weak, nonatomic) IBOutlet UIBarButtonItem *DismissButton;


- (IBAction)DismissButtonClicked:(id)sender;

- (IBAction)TermsAndConditionsTapped:(id)sender;


@property StartViewController *root_view_controller;
@property MinkasuStateManager *mainAppDelegate;
@property BOOL presentAsModal;


- (IBAction)SaveButtonClicked:(id)sender;
- (IBAction)SlideOutMenuButtonClicked:(id)sender;

@property CustomerDetails *customer_details;

@end
