# MinkasuWallet_iOS_SDK

##Setup

- The minimum requirements for the SDK are:
   - iOS 8.0 and higher
   - Internet connection
- The following architectures are supported in the SDK:
   - armv7 and arm64 for devices
   - i386 and x86_64 for iOS simulator
- Make sure that the setting "Link Frameworks Automatically" is set to YES.
- Add the following linker flags to your Xcode Build Settings:
Note: Added automatically if using CocoaPods.
   - -lc++
   - -ObjC (recommended) or -all_load

- Your application must support at least Portrait-Orientation.
- Make sure to include UIInterfaceOrientationPortrait as supportedInterfaceOrientations in your application’s plist file.
- Set **Enable Bitcode** to **No** in Build Settings.
- Set **Allow Non-modular Includes in Framework Modules** to **Yes** in Build Settings.

##Integrations

1. Create a new iOS project in Xcode.
2. Open a terminal window, and **$ cd** into your project directory.
3. Create a Podfile. This can be done by running **$ pod init** .
4. Open your Podfile and add **pod 'MinkasuWallet_iOS_SDK', '~>0.0.1'** to your app.
5. Run pod install on the terminal.
6. Close the Xcode project created and open the Xcode Workspace from the project root directory.

##Initializing the SDK

- Import ```<MinkasuSDK/MinkasuSDK.h>``` at the prefix header so it is available through out the project.
- Create property of **MinkasuInit** and implement **MinkasuSDKDelegate** in each ViewController that you want to use MinkasuSDK in.
- Encapsulate the initialization code below as a function to initialize the Minkasu SDK.

```
-(void)initMinkasuSDK{
    MinkasuConfigs *config = [MinkasuConfigs new];
    config.partner_mk_access_token = @"";
    config.partner_id = @"";
    config.isSDKCall = true;
    config.netswipe_api_token = @"";
    config.netswipe_api_secret = @"";
    config.netverify_api_token = @"";
    config.netverify_api_secret = @"";
    
    minkasuInit = [[MinkasuInit alloc] initWithConfiguration:config];
}
``` 

- Make sure that your partner_mk_access_token and partner_id are correct.
- Add delegate functions to the viewcontroller's implementations (.m) to implement the **MinkasuSDKDelegate**

```
-(void) didCancelWithError:(NSError *)error{
    [self dismissViewControllerAnimated:YES completion:nil];
    //YOUR CODE TO HANDLE ERROR
}

-(void) didFinishPaymentSuccessfullyWithTnxInformation:(MinkasuTxnInformation *)txnInformation{
    (MinkasuTxnInformation *)txnInformation{
    NSLog(@"Transaction Complete with ID : %@",txnInformation.transactionId);
    double delayInSeconds = 0.5; //seconds to wait
    dispatch_time_t popTime = dispatch_time(DISPATCH_TIME_NOW, (int64_t)(delayInSeconds * NSEC_PER_SEC));
    dispatch_after(popTime, dispatch_get_main_queue(), ^(void){
        [self dismissViewControllerAnimated:NO completion:nil];
    });
    //YOUR CODE TO HANDLE SUCCESS
}
```

- Initialize the SDK by calling ```[self initMinkasuSDK];``` on viewDidAppear. Every controller has to implement its instance of the MinkasuSDK object.



##Displaying the SDK

- Use the following for the following SDK entry points
      - Scan Payment Screen **[minkasuInit getViewController:MK_START_VIEWCONTROLLER];**
      - Process Payment Code **[minkasuInit getViewController:MK_START_VIEWCONTROLLER]**
      - Payments History screen **[minkasuInit getViewController:MK_PAYMENT_HISTORY_VIEWCONTROLLER];**
      - Manage Payment Cards Screen **[minkasuInit getViewController:MK_MANAGE_CARD_VIEWCONTROLLER];**

```
    minkasuInit.stateManager.sdkConfigs.delegate = self;
    UINavigationController *minkasuStartViewController = [minkasuInit getViewController:MK_START_VIEWCONTROLLER];
    if (minkasuStartViewController==Nil){
       NSLog(@"Start Viewcontroller didnt initialize properly.");
    }
    else{
       [self presentViewController:minkasuStartViewController animated:YES completion:nil];
    }

```

- For sending a Payment Code to the SDK use the code below. Set the **view_controller.txn_code_string = @"";** with the payment code to be processed.

```
    minkasuInit.stateManager.sdkConfigs.delegate = self;
    UINavigationController *minkasuStartViewController = [minkasuInit getViewController:MK_START_VIEWCONTROLLER];
    if (minkasuStartViewController==Nil){
        NSLog(@"Start Viewcontroller didnt initialize properly.");
    }
    else{
         [self presentViewController:minkasuStartViewController animated:YES completion:^() {
            StartViewController *view_controller = (StartViewController *)minkasuStartViewController.topViewController;
            view_controller.new_txnid_available = TRUE;
            view_controller.txn_code_string = @"";
            view_controller.getTransactionInProgress = TRUE;
            view_controller.pmnt_request_is_local = TRUE;
            [view_controller processScannedCode:view_controller.txn_code_string];
        }];
    }

```

###Universal Links and iOS 8 App Handoff

**To handle universal links follow the steps below.**
- Enable **Associated Domains** under **Capabilities Tab** of the project settings.
- Add **applinks:dev.minkasu.com** and **applinks:d.mku.us**..
- Add the same **apprlPrefix** used to signup on the merchant dashboard to the **URL Schemes** in **URL Types** under **Info tab** of the project settings
- Use the **apprlPrefix** and the **app id** while signing up on the Minkasu Dashboard. Enter both in the respective fields.
- Encapsulate the initialization code below as a function to initialize the Minkasu SDK.

```
-(void)initMinkasuSDK{
    MinkasuConfigs *config = [MinkasuConfigs new];
    config.partner_mk_access_token = @"";
    config.partner_id = @"";
    config.isSDKCall = true;
    config.netswipe_api_token = @"";
    config.netswipe_api_secret = @"";
    config.netverify_api_token = @"";
    config.netverify_api_secret = @"";
    
    minkasuInit = [[MinkasuInit alloc] initWithConfiguration:config];
}
``` 
- Initialize the SDK by calling ```[self initMinkasuSDK];``` from ```- **(BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions```.
- Make sure that your partner_mk_access_token and partner_id are correct.
- Implement **MinkasuSDKDelegate** Appdelegate.m by adding the following delegate functions to the Appdelegate.m.

```
-(void) didCancelWithError:(NSError *)error{
   [minkasuInit.stateManager.universalLinkHandledFromViewController dismissViewControllerAnimated:NO completion:^{
           minkasuInit.stateManager.universalLinkHandledFromViewController = NULL;
           //YOUR CODE TO HANDLE ERROR
       }];
}

-(void) didFinishPaymentSuccessfullyWithTnxInformation:(MinkasuTxnInformation *)txnInformation{
    NSLog(@"Transaction Complete with ID : %@",txnInformation.transactionId);
    double delayInSeconds = 0.5; //seconds to wait
    dispatch_time_t popTime = dispatch_time(DISPATCH_TIME_NOW, (int64_t)(delayInSeconds * NSEC_PER_SEC));
    dispatch_after(popTime, dispatch_get_main_queue(), ^(void){
        [minkasuInit.stateManager.universalLinkHandledFromViewController dismissViewControllerAnimated:NO completion:^{
            minkasuInit.stateManager.universalLinkHandledFromViewController = NULL;
            //YOUR CODE TO HANDLE SUCCESS
        }];
    });
}
```

- Add the following code to handle the universal link(iOS 9 on Safari) app entry event

```
- (BOOL)application:(UIApplication *)application
continueUserActivity:(NSUserActivity *)userActivity
 restorationHandler:(void(^)(NSArray * __nullable restorableObjects))restorationHandler
{
    minkasuInit.stateManager.sdkConfigs.delegate = self;
    if(minkasuInit.stateManager.universalLinkHandledFromViewController != NULL){
        [minkasuInit.stateManager.universalLinkHandledFromViewController dismissViewControllerAnimated:YES completion:^{
            if ([userActivity.activityType isEqualToString:NSUserActivityTypeBrowsingWeb]) {
                NSURL *webpageURL = userActivity.webpageURL;
                [minkasuInit.stateManager topMostController];
                if (![minkasuInit.stateManager handleUniversalLink: webpageURL]) {
                    NSLog(@"Link will open in Safari");
                    [[UIApplication sharedApplication] openURL:webpageURL]; // Will open in Safari
                }
            }
        }];
    }
    else{
        if ([userActivity.activityType isEqualToString:NSUserActivityTypeBrowsingWeb]) {
            NSURL *webpageURL = userActivity.webpageURL;
            [minkasuInit.stateManager topMostController];
            if (![minkasuInit.stateManager handleUniversalLink: webpageURL]) {
                NSLog(@"Link will open in Safari");
                [[UIApplication sharedApplication] openURL:webpageURL]; // Will open in Safari
            }
        }
    }
    return YES;
}
```

- Add the following code to handle App Handoff (iOS 8 on Safari & Chrome) app entry event

```
- (BOOL)application:(UIApplication *)application
   continueUserActivity:(NSUserActivity *)userActivity
   restorationHandler:(void(^)(NSArray * __nullable restorableObjects))restorationHandler
{
    minkasuInit.stateManager.sdkConfigs.delegate = self;
    if(minkasuInit.stateManager.universalLinkHandledFromViewController != NULL){
        [minkasuInit.stateManager.universalLinkHandledFromViewController dismissViewControllerAnimated:YES completion:^{
            NSLog(@"Minkasu called with url query string %s, source application %@ annotation %@",
                  [[url query] cStringUsingEncoding: NSUTF8StringEncoding],
                  sourceApplication,
                  annotation);
            
            NSString *query_string = [url query];
            NSArray *qry_str_parts = [query_string componentsSeparatedByString:@"&"];
            NSMutableDictionary *arg_dict = [[NSMutableDictionary alloc] init];
            for (int i = 0; i < qry_str_parts.count; i++) {
                NSArray *arg_pair = [qry_str_parts[i] componentsSeparatedByString:@"="];
                if (arg_pair.count == 1) {
                    [arg_dict setObject:@"" forKey:arg_pair[0]];
                } else {
                    [arg_dict setObject:arg_pair[1] forKey:arg_pair[0]];
                }
            }
            
            NSString *txn_code_string;
            if ([arg_dict objectForKey:@"pmnt_code"]) {
                txn_code_string = (NSString *)[arg_dict objectForKey:@"pmnt_code"];
            } else {
                txn_code_string = qry_str_parts[0];
            }
            [minkasuInit.stateManager scheduleProcessingTransactionCodeString:txn_code_string FromApplication:sourceApplication WithArgs:arg_dict];
        }];
    }
    else{
        NSLog(@"Minkasu called with url query string %s, source application %@ annotation %@",
              [[url query] cStringUsingEncoding: NSUTF8StringEncoding],
              sourceApplication,
              annotation);
        
        NSString *query_string = [url query];
        NSArray *qry_str_parts = [query_string componentsSeparatedByString:@"&"];
        NSMutableDictionary *arg_dict = [[NSMutableDictionary alloc] init];
        for (int i = 0; i < qry_str_parts.count; i++) {
            NSArray *arg_pair = [qry_str_parts[i] componentsSeparatedByString:@"="];
            if (arg_pair.count == 1) {
                [arg_dict setObject:@"" forKey:arg_pair[0]];
            } else {
                [arg_dict setObject:arg_pair[1] forKey:arg_pair[0]];
            }
        }
        
        NSString *txn_code_string;
        if ([arg_dict objectForKey:@"pmnt_code"]) {
            txn_code_string = (NSString *)[arg_dict objectForKey:@"pmnt_code"];
        } else {
            txn_code_string = qry_str_parts[0];
        }
        [minkasuInit.stateManager scheduleProcessingTransactionCodeString:txn_code_string FromApplication:sourceApplication WithArgs:arg_dict];
    }
    
    return YES;

}
```

##Retrieving information

Implement the following delegate methods for scan attempts, successful scans and user
cancellation notifications. Dismiss the SDK view in your app once you received the result.

Upon success, the parameter cardInformation will be returned. Call clear after processing
the card information to make sure no sensitive data remains in the device's memory.

```
-(void) didFinishPaymentSuccessfullyWithTnxInformation:(MinkasuTxnInformation *)txnInformation{
    NSLog(@"Transaction Complete with ID : %@",txnInformation.transactionId);
    double delayInSeconds = 0.5; //seconds to wait
    dispatch_time_t popTime = dispatch_time(DISPATCH_TIME_NOW, (int64_t)(delayInSeconds * NSEC_PER_SEC));
    dispatch_after(popTime, dispatch_get_main_queue(), ^(void){
        [self dismissViewControllerAnimated:NO completion:nil];
    });
    // OBTAIN PARAMETERS HERE
    // YOURCODE
}
```

The parameter error contains the user cancellation reason.
Note: The error codes 200, 210, 220, 240, 250, 260 and 310 will be returned. Using the
custom scan view, the error codes 260 and 310 will be returned.

```
-(void) didCancelWithError:(NSError *)error{
    [self dismissViewControllerAnimated:YES completion:nil];
    // NSInteger errorCode = error.code;
    // NSString *errorMessage = error.localizedDescription;
    // YOURCODE
}
```

