//
//  VerifyPhoneViewController.h
//  PayNow
//
//  Created by ashis poddar on 2/16/15.
//  Copyright (c) 2015 Subramanian Lakshmanan. All rights reserved.
//

#ifndef PayNow_VerifyPhoneViewController_h
#define PayNow_VerifyPhoneViewController_h

#import "StartViewController.h"

@interface VerifyPhoneViewController : UIViewController <UIAlertViewDelegate>

@property StartViewController *root_view_controller;

@property (nonatomic,weak) IBOutlet UIButton *successMark;
@property (nonatomic,weak) IBOutlet UIButton *successMsg;

@property (weak, nonatomic) IBOutlet UIImageView *verifySMSImage;



@property (nonatomic,strong)NSTimer *timer;
@property (nonatomic, retain) NSDate *startTime;
@property (nonatomic,strong)UIActivityIndicatorView *spinnerForTimer;

@property (nonatomic,weak) IBOutlet UIButton *verifyButton;
@property (nonatomic,weak)IBOutlet UILabel *header;
@property (nonatomic,weak)IBOutlet UILabel *headersuccess;

@property (nonatomic,weak)IBOutlet UILabel *detailbody;
@property (nonatomic,weak)IBOutlet UILabel *detailbodysuccess;

@property (strong, nonatomic) IBOutlet UILabel *footer;

- (IBAction)VerifyPhoneButtonTapped:(id)sender;

//user customer data
@property (nonatomic, strong) NSString *customerId;
@property (nonatomic, strong) NSString *phone;

@property BOOL back_button_should_be_hidden;

@property (strong, nonatomic) IBOutlet UIBarButtonItem *verifyDone;
- (IBAction)verifyDoneTapped:(id)sender;

@end

#endif
