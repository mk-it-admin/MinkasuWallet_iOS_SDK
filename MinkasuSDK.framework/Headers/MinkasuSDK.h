//
//  MinkasuSDK.h
//  MinkasuSDK
//
//  Created by Sachin Selvaraj on 2/16/16.
//  Copyright © 2016 Sachin Selvaraj. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for MinkasuSDK.
FOUNDATION_EXPORT double MinkasuSDKVersionNumber;

//! Project version string for MinkasuSDK.
FOUNDATION_EXPORT const unsigned char MinkasuSDKVersionString[];

#define MK_START_VIEWCONTROLLER 0
#define MK_PAYMENT_HISTORY_VIEWCONTROLLER 2
#define MK_MANAGE_CARD_VIEWCONTROLLER 3

// In this header, you should import all the public headers of your framework using statements like #import <MinkasuSDK/PublicHeader.h>

#import <MinkasuSDK/AddNewCardViewController.h>
#import <MinkasuSDK/Address.h>
#import <MinkasuSDK/AddressDetailsViewController.h>
#import <MinkasuSDK/CardDetails.h>
#import <MinkasuSDK/ChangePINViewController.h>
#import <MinkasuSDK/CreatePINViewController.h>
#import <MinkasuSDK/CustomerDetails.h>
#import <MinkasuSDK/CustomerInfo.h>
#import <MinkasuSDK/CustomPayNowViewController.h>
#import <MinkasuSDK/FeedbackViewController.h>
#import <MinkasuSDK/FTUSetupPaymentInfoViewController.h>
#import <MinkasuSDK/HelpViewController.h>
#import <MinkasuSDK/InviteFriendsViewController.h>
#import <MinkasuSDK/KeyChainItemWrapper.h>
#import <MinkasuSDK/ManageAddressViewController.h>
#import <MinkasuSDK/ManageCardsViewController.h>
#import <MinkasuSDK/NumberPadDoneBtn.h>
#import <MinkasuSDK/NumberToolBar.h>
#import <MinkasuSDK/PastPaymentsViewController.h>
#import <MinkasuSDK/PaymentCardDetails.h>
#import <MinkasuSDK/PaymentDetails.h>
#import <MinkasuSDK/PaymentDetailsViewController.h>
#import <MinkasuSDK/PaymentSuccessViewController.h>
#import <MinkasuSDK/PersonalDetailsViewController.h>
#import <MinkasuSDK/QuestionsViewController.h>
#import <MinkasuSDK/ScanOverlayView.h>
#import <MinkasuSDK/SecKeyWrapper.h>
#import <MinkasuSDK/SettingsViewController.h>
#import <MinkasuSDK/SetTxnDetailsViewController.h>
#import <MinkasuSDK/ShowQuestionsViewController.h>
//#import <MinkasuSDK/SlideOutMenuViewController.h>
#import <MinkasuSDK/TermsViewController.h>
#import <MinkasuSDK/VerifyIdentityViewController.h>
#import <MinkasuSDK/VerifyPhoneViewController.h>
#import <MinkasuSDK/MinkasuInit.h>
#import <MinkasuSDK/MinkasuStateManager.h>
#import <MinkasuSDK/MinkasuConfigs.h>
#import <MinkasuSDK/MinkasuTxnInformation.h>
#import <MinkasuSDK/MinkasuSDKDelegate.h>

