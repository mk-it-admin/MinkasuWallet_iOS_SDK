//
//  ChangePINViewController.h
//  PayNow
//
//  Created by ashis poddar on 2/18/15.
//  Copyright (c) 2015 Subramanian Lakshmanan. All rights reserved.
//

#ifndef PayNow_ChangePINViewController_h
#define PayNow_ChangePINViewController_h

@interface CreatePINViewController : UIViewController < UITextFieldDelegate >
@property (strong, nonatomic) IBOutlet UITextField *Pin1;
@property (strong, nonatomic) IBOutlet UITextField *Pin2;
@property (strong, nonatomic) IBOutlet UITextField *Pin3;
@property (strong, nonatomic) IBOutlet UITextField *Pin4;

@property (strong, nonatomic) IBOutlet UITextField *RePin1;
@property (strong, nonatomic) IBOutlet UITextField *RePin2;
@property (strong, nonatomic) IBOutlet UITextField *RePin3;
@property (strong, nonatomic) IBOutlet UITextField *RePin4;

@property (strong, nonatomic) IBOutlet UILabel *error;
@property (strong, nonatomic) IBOutlet UILabel *header;


@property BOOL reEnterPINMode;
@property NSString *pinValue1;
@property NSString *pinValue2;

@property BOOL text_field_moved_up;
@property BOOL moveUP;

@end
#endif
