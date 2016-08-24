//
//  VerifyIdentityViewController.h
//  PayNow
//
//  Created by Naveen Doraiswamy on 6/18/14.
//  Copyright (c) 2014 Subramanian Lakshmanan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MinkasuStateManager.h"
#import "CustomerDetails.h"
#import "Address.h"

@interface VerifyIdentityViewController : UIViewController <UITableViewDataSource, UITableViewDelegate>

@property MinkasuStateManager *mainAppDelegate;
@property CustomerDetails *customer_details;
@property Address *customer_address;

@property (weak, nonatomic) IBOutlet UILabel *verifiedStatus;
@property (weak, nonatomic) IBOutlet UITableView *vmTableView;

- (NSString *)retrieveVerifiedStatus;
- (BOOL)validate:(CustomerDetails*)customerDetails AndAddress: (Address *)customerAddress;

- (IBAction)SlideOutMenuButtonClicked:(id)sender;

@end
