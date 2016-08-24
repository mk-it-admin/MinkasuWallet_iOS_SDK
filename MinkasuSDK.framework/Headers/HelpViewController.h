//
//  HelpViewController.h
//  PayNow
//
//  Created by ashis poddar on 2/17/15.
//  Copyright (c) 2015 Subramanian Lakshmanan. All rights reserved.
//

#ifndef PayNow_HelpViewController_h
#define PayNow_HelpViewController_h
#import "MinkasuStateManager.h"


@interface HelpViewController : UIViewController<UIWebViewDelegate>

@property MinkasuStateManager *mainAppDelegate;
@property NSString *helpUrl;
@property (nonatomic,strong) UIActivityIndicatorView *spinner;

@property (strong, nonatomic) IBOutlet UIWebView *helpWebView;

- (IBAction)onBackButtonTapped:(id)sender;
- (IBAction)onCloseButtonTapped:(id)sender;

@end

#endif
