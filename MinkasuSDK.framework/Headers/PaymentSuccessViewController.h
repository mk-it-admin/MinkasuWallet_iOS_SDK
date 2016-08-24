//
//  PaymentSuccessViewController.h
//  PayNow
//
//  Created by ashis poddar on 2/20/15.
//  Copyright (c) 2015 Subramanian Lakshmanan. All rights reserved.
//

#ifndef PayNow_PaymentSuccessViewController_h
#define PayNow_PaymentSuccessViewController_h
#import "MinkasuStateManager.h"
#import "StartViewController.h"
#import "MinkasuTxnInformation.h"

@interface PaymentSuccessViewController : UIViewController

@property (strong, nonatomic) IBOutlet UILabel *paidAmount;
@property (strong, nonatomic) IBOutlet UILabel *merchant;
@property (strong, nonatomic) IBOutlet UILabel *confirmationId;
@property (strong, nonatomic) IBOutlet UILabel *confirmationlbl;
@property (strong, nonatomic) IBOutlet UILabel *redirectMsg;
@property (strong, nonatomic) IBOutlet UIButton *donebtn;

@property (weak, nonatomic) IBOutlet UILabel *paymentSentLbl;


//@property (strong, nonatomic) IBOutlet UILabel *orderId_lbl;
//@property (strong, nonatomic) IBOutlet UILabel *orderId;

@property NSString *merchant_name;
@property NSString *amount;
@property StartViewController *root_view_controller;

@property NSString *transactionId;
@property NSString *billno;
@property BOOL txn_is_donation;
@property BOOL isRedirect;
@property BOOL noRedirect;
@property MinkasuStateManager *stateManager;
@property MinkasuTxnInformation *txnInfo;
- (IBAction)paymentSuccessDoneTapped:(id)sender;

@end

#endif
