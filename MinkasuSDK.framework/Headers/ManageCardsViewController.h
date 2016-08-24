//
//  ManageCardsViewController.h
//  PayNow
//
//  Created by Naveen Doraiswamy on 7/18/14.
//  Copyright (c) 2014 Subramanian Lakshmanan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MinkasuStateManager.h"
#import "StartViewController.h"

@interface ManageCardsViewController : UIViewController <UITableViewDataSource, UITableViewDelegate, UIAlertViewDelegate>

@property MinkasuStateManager *mainAppDelegate;
@property StartViewController *root_view_controller;
@property NSInteger deleteCardIndex;
@property (weak, nonatomic) IBOutlet UITableView *cardsTableView;

- (NSMutableArray *)getCardList;
- (int) deleteCardFromServer:(NSString *)card_alias;

- (IBAction)addNewCardButtonTapped:(id)sender;
- (IBAction)SlideOutMenuButtonClicked:(id)sender;
- (IBAction)cancelSDKCall:(id)sender;

@end
