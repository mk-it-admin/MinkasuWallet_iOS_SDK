//
//  TermsViewController.h
//  PayNow
//
//  Created by ashis poddar on 2/21/15.
//  Copyright (c) 2015 Subramanian Lakshmanan. All rights reserved.
//

#ifndef PayNow_TermsViewController_h
#define PayNow_TermsViewController_h

@interface TermsViewController : UIViewController
@property (strong, nonatomic) IBOutlet UIButton *CancelView;
@property (strong, nonatomic) IBOutlet UIWebView *termsWebView;
@property (strong, nonatomic) IBOutlet UIButton *CancelTerms;
- (IBAction)cancelTerms:(id)sender;

@end

#endif
