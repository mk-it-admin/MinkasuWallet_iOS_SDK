//
//  FTUSetupPaymentInfoViewController.h
//  PayNow
//
//  Created by Subramanian Lakshmanan on 2/14/15.
//  Copyright (c) 2015 Subramanian Lakshmanan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "StartViewController.h"
#import <Netswipe/NetswipeViewController.h>
#import "MinkasuStateManager.h"

#define FTU_NEXT_STEP_NONE 0
#define FTU_NEXT_STEP_SAVE_PMNT_INFO_PROCEED_TO_PHONE_VERIFY 1
#define FTU_NEXT_STEP_DISMISS_VIEW 2


@interface FTUSetupPaymentInfoViewController : UIViewController<UITextFieldDelegate, UIScrollViewDelegate,NetswipeViewControllerDelegate>

@property StartViewController *root_view_controller;
@property NSString *screen_title;
@property BOOL getApiKeysInProgress;
@property BOOL ftuSetupCallInProgress;

@property (weak, nonatomic) IBOutlet UITextField *CardNumTextField;
@property (weak, nonatomic) IBOutlet UITextField *CardExpiryTextField;
@property (weak, nonatomic) IBOutlet UITextField *CardCvcTextField;

@property (weak, nonatomic) IBOutlet UITextField *FirstNameTextField;
@property (weak, nonatomic) IBOutlet UITextField *LastNameTextField;
@property (weak, nonatomic) IBOutlet UITextField *AddrLine1TextField;
@property (weak, nonatomic) IBOutlet UITextField *AddrLine2TextField;
@property (weak, nonatomic) IBOutlet UITextField *CityTextField;
@property (weak, nonatomic) IBOutlet UITextField *StateTextField;
@property (weak, nonatomic) IBOutlet UITextField *ZipTextField;

@property (weak, nonatomic) IBOutlet UITextField *SAFirstNameTextField;
@property (weak, nonatomic) IBOutlet UITextField *SALastNameTextField;
@property (weak, nonatomic) IBOutlet UITextField *SAAddrLine1TextField;
@property (weak, nonatomic) IBOutlet UITextField *SAAddrLine2TextField;
@property (weak, nonatomic) IBOutlet UITextField *SACityTextField;
@property (weak, nonatomic) IBOutlet UITextField *SAStateTextField;
@property (weak, nonatomic) IBOutlet UITextField *SAZipTextField;


@property (weak, nonatomic) IBOutlet UISwitch *ShippingAndBillingSameSwitch;
@property (weak, nonatomic) IBOutlet UIView *ShippingAddressView;
@property (weak, nonatomic) IBOutlet UIView *ContactandTermsAndCondView;

@property (weak, nonatomic) IBOutlet UITextField *EmailTextField;
@property (weak, nonatomic) IBOutlet UITextField *PhoneTextField;
@property (weak, nonatomic) IBOutlet UIScrollView *ScrollViewContainer;
@property (nonatomic,strong) UIActivityIndicatorView *spinner;
@property (weak, nonatomic) IBOutlet UIView *ShippingAddressHeaderView;
@property (weak, nonatomic) IBOutlet UIButton *netswipeButton;

@property int next_step_when_view_appears;

- (IBAction)BackButtonTapped:(id)sender;

- (IBAction)NextButtonTapped:(id)sender;

- (IBAction)ShippingSameAsBillingSwitchValueChanged:(id)sender;

- (BOOL) textFieldShouldReturn: (UITextField *) textField;

@property (nonatomic, strong) NetswipeViewController *netswipeViewController;

- (IBAction)startNetswipeSDK:(id)sender;

@property (strong, nonatomic) IBOutlet UIButton *TermsAndConditions;

- (IBAction)TermsAndConditionsTapped:(id)sender;

@end
