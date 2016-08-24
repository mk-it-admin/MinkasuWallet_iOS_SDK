//
//  FeedbackViewController.h
//  PayNow
//
//  Created by ashis poddar on 2/18/15.
//  Copyright (c) 2015 Subramanian Lakshmanan. All rights reserved.
//

#ifndef PayNow_FeedbackViewController_h
#define PayNow_FeedbackViewController_h

#import "MinkasuStateManager.h"
#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>

@interface FeedbackViewController : UIViewController <MFMailComposeViewControllerDelegate>

@property MinkasuStateManager *mainAppDelegate;

@property (strong, nonatomic) IBOutlet UIButton *contact;

- (IBAction)contactTapped:(id)sender;

- (IBAction)reviewButtonTapped:(id)sender;
- (IBAction)onCloseButtonTapped:(id)sender;

@end

#endif
