//
//  AddNewCardViewController.h
//  PayNow
//
//  Created by Subramanian Lakshmanan on 3/3/14.
//  Copyright (c) 2014 Subramanian Lakshmanan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "StartViewController.h"
#import <Netswipe/NetswipeViewController.h>
#import "CardDetails.h"

@interface AddNewCardViewController : UIViewController<UITextFieldDelegate,NetswipeViewControllerDelegate>

@property StartViewController *root_view_controller;

- (BOOL) textFieldShouldReturn: (UITextField *) textField;

- (IBAction)cancelAddCard:(id)sender;

- (IBAction)RegisterButtonTapped:(id)sender;

@property (weak, nonatomic) IBOutlet UITextField *card_num_text;

@property (weak, nonatomic) IBOutlet UITextField *card_exp_text;

@property (weak, nonatomic) IBOutlet UITextField *card_holder_text;

@property (weak, nonatomic) IBOutlet UITextField *zip_text;

@property (weak, nonatomic) IBOutlet UITextField *cvc_text;


@property (weak, nonatomic) IBOutlet UITextField *addr_line1;

@property (weak, nonatomic) IBOutlet UITextField *addr_line2;

@property (weak, nonatomic) IBOutlet UITextField *city;


@property (weak, nonatomic) IBOutlet UITextField *state;
@property (weak, nonatomic) IBOutlet UIButton *netswipeButton;

@property BOOL cardRegistrationInProgress;

-(void) handleRegisterCardResponse: (int)error WithErrorMessage: (NSString *)errorMsg ForCard: (CardDetails *)cardDetails;

- (BOOL) cardFieldsAreValid: (NSString **) errorString;


- (NSString *) cardTypeFromNumber: (NSString *) cardNumber;

@property (nonatomic, strong) NetswipeViewController *netswipeViewController;

- (IBAction)startNetswipeSDK:(id)sender;

@end
