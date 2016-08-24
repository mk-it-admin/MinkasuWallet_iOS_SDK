//
//  SettingsViewController.h
//  PayNow
//
//  Created by Naveen Doraiswamy on 10/17/14.
//  Copyright (c) 2014 Subramanian Lakshmanan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "StartViewController.h"
#import "MinkasuStateManager.h"

@interface SettingsViewController : UIViewController <UITableViewDataSource, UITableViewDelegate>

@property MinkasuStateManager *mainAppDelegate;

@property StartViewController *root_view_controller;

@property int screen_mode_for_address_screen;
@property int address_index_for_address_screen;

@property NSMutableArray *settingsTableItems;
@property NSInteger pinRowInSettingsTable;

@property (weak, nonatomic) IBOutlet UITableView *addressesTableView;

@property (weak, nonatomic) IBOutlet UITableView *settingsTableView;

@property (weak, nonatomic) IBOutlet UIBarButtonItem *SlideOutMenuButton;

- (IBAction)SlideOutMenuButtonClicked:(id)sender;

- (IBAction)addNewAddressButtonClicked:(id)sender;

- (IBAction)onCloseButtonTapped:(id)sender;

@end
