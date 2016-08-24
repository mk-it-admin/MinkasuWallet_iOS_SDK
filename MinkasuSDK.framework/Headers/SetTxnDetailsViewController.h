//
//  SetTxnDetailsViewController.h
//  PayNow
//
//  Created by Subramanian Lakshmanan on 5/14/15.
//  Copyright (c) 2015 Subramanian Lakshmanan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "StartViewController.h"

@interface SetTxnDetailsViewController : UIViewController <UITableViewDataSource, UITableViewDelegate,
                                                           UITextFieldDelegate,
                                                           UIPickerViewDelegate, UIPickerViewDataSource>

@property StartViewController *root_view_controller;

@property NSMutableDictionary *txn_details;
@property unsigned int amount_entered_in_cents;
@property unsigned int min_amount_in_cents;
@property unsigned int max_amount_in_cents;
@property unsigned int default_amount_in_cents;
@property NSArray *attr_metadata_list;
@property NSMutableDictionary *attr_list;
@property unsigned int selected_attr_index;
@property BOOL txn_is_donation;
@property BOOL txn_amount_is_determined_by_attributes;
@property BOOL txn_allow_zero_dollar;

@property (weak, nonatomic) IBOutlet UILabel *labelMerchantName;

@property (weak, nonatomic) IBOutlet UITableView *tableTxnAttributes;

@property (weak, nonatomic) IBOutlet UIButton *btnNext;

//@property (weak, nonatomic) IBOutlet UITextField *amountTextField;
@property unsigned int amount_index;

@property UIView *overlayView;

- (IBAction)NextButtonTapped:(id)sender;

- (IBAction)ReturnToPreviousScreen:(id)sender;

- (NSArray *) getAttrListWithAmountAttrInserted;

@property BOOL isTextFieldBeingEdited;

@end
