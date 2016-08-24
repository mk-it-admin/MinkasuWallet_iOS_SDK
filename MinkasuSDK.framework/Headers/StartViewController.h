//
//  ViewController.h
//  PayNow
//
//  Created by Subramanian Lakshmanan on 2/10/14.
//  Copyright (c) 2014 Subramanian Lakshmanan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import <MediaPlayer/MediaPlayer.h>
#import "PaymentCardDetails.h"
//#import "CardData.h"
#import "CustomerInfo.h"
#import "CustomerDetails.h"
#import "SecKeyWrapper.h"
#import "KeyChainItemWrapper.h"
#import "PaymentDetails.h"
//#import "MMDrawerBarButtonItem.h"
#import "MinkasuStateManager.h"
#import "Address.h"
#import "CardDetails.h"
#import "ZBarSDK.h"


@interface StartViewController : UIViewController <UITextFieldDelegate, ZBarReaderDelegate, CLLocationManagerDelegate, UIAlertViewDelegate, UIScrollViewDelegate,UITableViewDataSource,UITableViewDelegate>
// ADD: delegate protocol for ZBarReader
//< ZBarReaderDelegate >
{
   // UIImageView *resultImage;
   // UITextView *resultText;
}
// @property (nonatomic, retain) IBOutlet UIImageView *resultImage;

@property (weak, nonatomic) IBOutlet UITextField *paymentCodeText;

@property (weak, nonatomic) IBOutlet UITableView *navTableView;
@property (weak, nonatomic) IBOutlet UIScrollView *mainScrollView;

@property BOOL viewIsCurrentlyVisible;

@property (weak, nonatomic) IBOutlet UIView *coverView;

@property NSDictionary *txn_details;
@property BOOL new_txnid_available;
@property NSString *txn_code_string;
@property BOOL pmnt_request_is_local;
@property NSString *requesting_application;
@property NSDictionary *local_req_args;

@property MinkasuStateManager *mainAppDelegate;

@property (nonatomic, retain) NSManagedObjectContext *managedObjectContext;
@property (nonatomic, retain) SecKeyWrapper *keyMgmtWrapper;
@property (nonatomic, retain) KeyChainItemWrapper *cardDataItemWrapper;
@property (nonatomic, retain) KeyChainItemWrapper *addressDataItemWrapper;
@property (nonatomic, retain) KeyChainItemWrapper *customerDetailsWrapper;
@property (nonatomic, retain) KeyChainItemWrapper *minkasuAccessTokenItemWrapper;
@property NSString *card_data_item_string;
@property NSString *address_data_item_string;

@property NSMutableArray *card_list;
@property NSMutableArray *address_list;
@property CustomerInfo *customer_info;
@property CustomerDetails *customer_details;
@property NSString *minkasu_access_token;
@property BOOL getTransactionInProgress;
@property BOOL deviceInitializationInProgress;
@property CLLocationManager *locationManager;
@property NSMutableDictionary *ftuSetupInfo;
@property int ftuSetupStatus;
@property BOOL text_field_moved_up;
@property BOOL show_explicit_new_user_regn_confirmation;


- (IBAction)touchGestureCloseNavTable:(id)sender;

- (IBAction)buttonNavViewToggle:(id)sender;
- (void) initFirstTimeDevice;

- (void)didBecomeActive:(NSNotification *)notification;

- (void) paymentCodeEntered;
- (void)keyboardWasHidden:(NSNotification*)aNotification;
- (IBAction) scanButtonTapped;
//Sachin
//- (IBAction)SlideMenuButtonTapped:(MMDrawerBarButtonItem *)sender;
- (IBAction)cancelSDKCall:(id)sender;

- (IBAction)FTUSetupButtonTapped:(id)sender;


@property (weak, nonatomic) IBOutlet UIButton *ftuSetupButton;

@property (weak, nonatomic) IBOutlet UIButton *ftuSetupArrow;

// Animation
@property (strong, nonatomic) MPMoviePlayerController *playerController;
@property (strong, nonatomic) UIImageView *splashImageView;
@property (strong, nonatomic) IBOutlet UILabel *howMkWorksLabel;
@property (strong, nonatomic) IBOutlet UIButton *replayButton;
@property (strong, nonatomic) IBOutlet UIButton *getStartedButton;
@property (strong, nonatomic) IBOutlet UIButton *skipButton;
@property (nonatomic,strong)UIActivityIndicatorView *spinner;
@property MinkasuStateManager *stateManager;


- (IBAction)replayButtonTapped:(id)sender;
- (IBAction)getStartedButtonTapped:(id)sender;
- (IBAction)skipButtonTapped:(id)sender;


- (void) processScannedCode: (NSString *)scanned_text;
- (void) getTransactionDetails: (NSString *) transaction_code;
- (void) handleGetTransactionResponse;
- (void) getNewCustomerIdForDevice: (NSString *) device_id WithPublicKey: (NSData *)public_key;
- (void) handleDeviceRegistrationResponseWithCustomerId: (NSString *) customer_id AndAccessToken: (NSString *)access_token;

- (void) loadMinkasuAccessToken;
- (void) loadCustomerInfo;
- (void) loadCustomerDetails;
- (void) loadAllCards;
- (void) loadAllAddresses;
- (void) saveAddress: (Address *) newAddress;
- (void) saveAddress: (Address *)upd_addr AtIndex: (int)addr_idx;
- (void) removeAddressAtIndex: (int) addr_idx;

- (void) saveMinkasuAccessToken: (NSString *)access_token;
- (void) addNewCard: (CardDetails *)cardDetails;
- (void) saveAllCards;
- (void) saveAllAddresses;
- (void) updateCustomerDetails: (CustomerDetails *) cust_details;

//- (void) paymentCompleted: (PaymentDetails *) newPayment;
- (void) getApiKeys:(void (^)(BOOL keys_retrieved)) completionHandler;
- (void) getCurrentLocation;

- (void) saveFtuSetupInfoWithCompletion:(void (^)(int error, NSString *error_message))completion;

- (BOOL) deviceHasTouchId: (BOOL *)touch_id_not_setup;

- (void) clearBeforeAppGoesBackground;
- (NSString *) cardTypeFromNumber: (NSString *) cardNumber;

@property (weak, nonatomic) IBOutlet UIScrollView *scrollView;
@property (nonatomic, strong) IBOutlet UIPageControl *pageControl;

@property (nonatomic, strong) NSArray *pageImages;
@property (nonatomic, strong) NSMutableArray *pageViews;

- (void)loadVisiblePages;
- (void)loadPage:(NSInteger)page;
- (void)purgePage:(NSInteger)page;

@property (strong, nonatomic) IBOutlet UIButton *scanQRButton;

@end
