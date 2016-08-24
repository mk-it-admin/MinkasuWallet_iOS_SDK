//
//  PastPaymentsViewController.h
//  PayNow
//
//  Created by Subramanian Lakshmanan on 3/24/14.
//  Copyright (c) 2014 Subramanian Lakshmanan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PaymentDetails.h"
#import "MinkasuStateManager.h"
#import "StartViewController.h"

@interface PastPaymentsViewController : UIViewController <UISearchBarDelegate, UISearchDisplayDelegate>

@property (weak, nonatomic) IBOutlet UITableView *pastPaymentsTableView;
@property (strong,nonatomic) NSMutableArray *pastPaymentsList;
@property BOOL list_retrieved;
@property unsigned int rowSelectedForDetails;
@property MinkasuStateManager *mainAppDelegate;
@property BOOL listRetrievalInProgress;
@property (nonatomic,strong) UIActivityIndicatorView *spinner;
@property StartViewController *root_view_controller;


- (IBAction)SlideOutMenuButtonClicked:(id)sender;
@property (strong,nonatomic) NSMutableArray *filteredPaymentsArray;
@property IBOutlet UISearchBar *paymentsSearchBar;
- (IBAction)cancelSDKCall:(id)sender;


- (void) retrievePastPayments;
//- (void) addNewPayment: (PaymentDetails *)new_pmnt;

@end
