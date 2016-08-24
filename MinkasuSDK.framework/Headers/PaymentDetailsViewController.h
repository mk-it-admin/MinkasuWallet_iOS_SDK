//
//  PaymentDetailsViewController.h
//  PayNow
//
//  Created by Subramanian Lakshmanan on 3/25/14.
//  Copyright (c) 2014 Subramanian Lakshmanan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PaymentDetails.h"

@interface PaymentDetailsViewController : UIViewController

@property (weak, nonatomic) IBOutlet UILabel *merchantNameElement;

@property (weak, nonatomic) IBOutlet UILabel *lblbillNumberElement;

@property (weak, nonatomic) IBOutlet UILabel *billNumberElement;

@property (weak, nonatomic) IBOutlet UILabel *billAmountElement;

@property (weak, nonatomic) IBOutlet UILabel *timeOfPayElement;

@property (weak, nonatomic) IBOutlet UILabel *cardAliasElement;
@property (weak, nonatomic) IBOutlet UIImageView *cardTypeElement;

@property (weak, nonatomic) IBOutlet UILabel *addrLine1Element;
@property (weak, nonatomic) IBOutlet UILabel *addrLine2Element;

@property (weak, nonatomic) IBOutlet UILabel *transactionStateElement;

@property (weak, nonatomic) IBOutlet UILabel *transactionIdElement;

@property PaymentDetails *pmntDetailsObject;

@end
