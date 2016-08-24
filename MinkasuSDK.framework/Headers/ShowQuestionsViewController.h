//
//  ShowQuestionsViewController.h
//  PayNow
//
//  Created by Naveen Doraiswamy on 6/24/14.
//  Copyright (c) 2014 Subramanian Lakshmanan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CustomerDetails.h"
#import "VerifyIdentityViewController.h"
#import "Address.h"

@interface ShowQuestionsViewController : UIViewController

@property CustomerDetails *customer_details;
@property Address *customer_address;
@property NSDictionary *question_details;
@property VerifyIdentityViewController *root_view_controller;

@property (weak, nonatomic) IBOutlet UITextField *dateOfBirth;
@property (weak, nonatomic) IBOutlet UITextField *last4SSN;
@property (weak, nonatomic) IBOutlet UIButton *questionsButton;
@property (weak, nonatomic) IBOutlet UIView *resultTopDivider;
@property (weak, nonatomic) IBOutlet UILabel *resultTitle;
@property (weak, nonatomic) IBOutlet UILabel *result;
@property (weak, nonatomic) IBOutlet UIView *resultBottomDivider;

- (void)hideResult;
- (void)showResult:(NSString *)resultText;

- (IBAction)retrieveQuestions:(id)sender;

@end
