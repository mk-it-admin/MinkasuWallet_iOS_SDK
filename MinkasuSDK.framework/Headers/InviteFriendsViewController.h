//
//  InviteFriendsViewController.h
//  PayNow
//
//  Created by ashis poddar on 2/18/15.
//  Copyright (c) 2015 Subramanian Lakshmanan. All rights reserved.
//

#ifndef PayNow_InviteFriendsViewController_h
#define PayNow_InviteFriendsViewController_h

#import "MinkasuStateManager.h"
#import "StartViewController.h"

@interface InviteFriendsViewController : UIViewController

@property MinkasuStateManager *mainAppDelegate;
@property StartViewController *root_view_controller;

- (IBAction)onCloseButtonTapped:(id)sender;


- (IBAction)shareViaEmail:(id)sender;

- (IBAction)shareViaText:(id)sender;

@end

#endif
