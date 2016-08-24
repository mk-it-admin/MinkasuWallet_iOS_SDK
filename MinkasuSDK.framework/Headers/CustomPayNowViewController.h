//
//  CustomPayNowViewController.h
//  PayNow
//
//  Created by Subramanian Lakshmanan on 2/13/14.
//  Copyright (c) 2014 Subramanian Lakshmanan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "StartViewController.h"
#import "PaymentCardDetails.h"
#import "Address.h"

@interface CustomPayNowViewController : UIViewController <UIAlertViewDelegate>

@property NSMutableArray *card_list;
@property NSMutableArray *address_list;
@property BOOL shouldReinitWhenViewAppearsBack;
@property BOOL paymentInProgress;
@property BOOL paymentCompleted;
@property NSString *redirectUrl;
@property BOOL noRedirect;
@property NSString *customerDetailsString;

// Output - user selection
@property unsigned int selected_card_idx;
@property PaymentCardDetails *selected_card_data;
@property unsigned int selected_address_idx;
@property Address *selected_address_data;

// Input to the view - txn details
@property NSString *merchant_name;
@property unsigned int merchant_flags;
@property unsigned int min_amount_in_cents;
@property unsigned int amount_in_cents;
@property unsigned int max_amount_in_cents;
@property NSString *transaction_id;
@property unsigned int bill_number;
@property unsigned int txn_state;
@property BOOL address_reqd;
@property BOOL email_reqd;
@property BOOL phone_reqd;
@property BOOL txn_is_donation;
@property BOOL txn_req_location;
@property NSString *exp_ship_state;
@property NSString *exp_ship_zip;
@property NSDictionary *attr_val_list;
@property StartViewController *root_view_controller;
@property unsigned int retryCount;

@property NSString *payBtnTitleWhenReady;

@property (weak, nonatomic) IBOutlet UIImageView *merchantLogo;
@property (weak, nonatomic) IBOutlet UILabel *merchantName;
@property (weak, nonatomic) IBOutlet UILabel *billAmount;
@property (weak, nonatomic) IBOutlet UILabel *cardName;
@property (weak, nonatomic) IBOutlet UIView *nameSeparator;
@property (weak, nonatomic) IBOutlet UILabel *cardAlias;
@property (weak, nonatomic) IBOutlet UILabel *cardExpDate;
@property (weak, nonatomic) IBOutlet UIImageView *cardLogo;
@property (weak, nonatomic) IBOutlet UIButton *addCardButton;
@property (weak, nonatomic) IBOutlet UILabel *addCardLabel;
@property (weak, nonatomic) IBOutlet UIButton *PrevCardButton;
@property (weak, nonatomic) IBOutlet UIButton *NextCardButton;
@property (weak, nonatomic) IBOutlet UILabel *shipTo;
@property (weak, nonatomic) IBOutlet UILabel *shipName;
@property (weak, nonatomic) IBOutlet UILabel *shipAddress1;
@property (weak, nonatomic) IBOutlet UILabel *shipAddress2;
@property (weak, nonatomic) IBOutlet UIButton *addAddressIconButton;
@property (weak, nonatomic) IBOutlet UIButton *addAddressLabelButton;
@property (weak, nonatomic) IBOutlet UILabel *addAddressHint;
@property (weak, nonatomic) IBOutlet UIButton *PrevAddressButton;
@property (weak, nonatomic) IBOutlet UIButton *NextAddressButton;
@property (weak, nonatomic) IBOutlet UIButton *PayNowButton;
@property (weak, nonatomic) IBOutlet UIImageView *cardView;
@property (weak, nonatomic) IBOutlet UIView *addressView;

- (void)setCardDetails:(PaymentCardDetails *)card;
- (void)showCard:(BOOL)show;
- (BOOL)doesMerchantAcceptCard:(PaymentCardDetails *)card;
- (void)cardSelectorValueChanged;
- (void)setAddress:(Address *)address;
- (void)showAddress:(BOOL)show;
- (void)showAddressSection:(BOOL)show;
- (void)findMatchingAddress;
- (void)addressSelectorValueChanged;
- (void)setPayNowButtonState;
- (NSString *)localTimeStringFromDate:(NSDate *)date;
- (void)makePaymentForTransaction:(NSString *)txn_id;
- (void)handleMakePaymentResponse:(int)error WithReason:(NSString *)rsn AndData:(NSDictionary *) resp AndErrorCode: (int) error_code;
- (void)showPinRequestAlert;
- (void)transitionToProfileScreenWithAlertMessage: (NSString *)alert_msg;
- (void)waitUntilLocationInfoIsAvailable;

- (IBAction)ReturnToPrevScreen;
- (IBAction)addCardButtonTapped:(id)sender;
- (IBAction)PrevCardButtonTapped:(id)sender;
- (IBAction)NextCardButtonTapped:(id)sender;
- (IBAction)addAddressTapped:(id)sender;
- (IBAction)PrevAddressButtonTapped:(id)sender;
- (IBAction)NextAddressButtonTapped:(id)sender;
- (IBAction)PayButtonTapped;

@property (nonatomic,strong)UIActivityIndicatorView *spinner;

@end
