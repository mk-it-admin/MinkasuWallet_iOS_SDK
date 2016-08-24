//
//  ManageAddressViewController.h
//  PayNow
//
//  Created by Praveena Khanna on 2/2/15.
//  Copyright (c) 2015 Subramanian Lakshmanan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MinkasuStateManager.h"
#import "StartViewController.h"

@interface ManageAddressViewController : UIViewController <UITableViewDataSource, UITableViewDelegate>

@property MinkasuStateManager *mainAppDelegate;
@property StartViewController *root_view_controller;

@property (weak, nonatomic) IBOutlet UITableView *addressesTableView;

- (NSMutableArray *)getAddressList;
//- (int) deleteAddress:(int )deleterow;
- (IBAction)addNewAddressButtonTapped:(id)sender;
- (IBAction)SlideOutMenuButtonClicked:(id)sender;

@end
