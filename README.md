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

##Integrations

1. Create a new iOS project in Xcode.
2. Open a terminal window, and **$ cd** into your project directory.
3. Create a Podfile. This can be done by running **$ pod init** .
4. Open your Podfile and add **pod 'MinkasuWallet_iOS_SDK', '~>0.0.1'** to your app.
5. Run pod install on the terminal.
6. Close the Xcode project created and open the Xcode Workspace from the project root directory.

##Initializing the SDK

- Use the code below to initialize the Minkasu SDK.
- Make sure that your merchant API token and API secret are correct, specify your delegate
object that implements the MinkasuSDKDelegate protocol.
- Initialization to be done in the AppDelegate if the Universal links are to be handled. An instance of the MinkasuSDK object that is returned can be stored in the AppDelegate to be used in other ViewControllers depending on the functionality.

```
MinkasuConfigs *config = [MinkasuConfigs new];
config.minkasu_api_token = @"";
config.minkasu_api_secret = @"";
config.delegate = self;
config.isSDKCall = true;
config.netswipe_api_token = @"";
config.netswipe_api_secret = @"";
config.netverify_api_token = @"";
config.netverify_api_secret = @"";
    
minkasuInit = [[MinkasuInit alloc] initWithConfiguration:config];

```

##Displaying the SDK

- Use the following for the following SDK entry points
      - Scan Payment Screen **[minkasuInit getViewController:0];**
      - Payments History screen **[minkasuInit getViewController:1];**
      - Manage Payment Cards Screen **[minkasuInit getViewController:2];**

```
UINavigationController *minkasuStartViewController = [minkasuInit getViewController:0];
    if (minkasuStartViewController==Nil){
        NSLog(@"Start Viewcontroller didnt initialize properly.");
    }
    else{
        [self presentViewController:minkasuStartViewController animated:YES completion:nil];
    }

```

- For sending a Payment Code to the SDK use the code below. Set the **view_controller.txn_code_string = @"";** with the payment code to be processed.

```
    UINavigationController *minkasuStartViewController = [minkasuInit getViewController:0];
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
            //view_controller.requesting_application = sourceApplication;
            //view_controller.local_req_args = argDict;
            [view_controller processScannedCode:view_controller.txn_code_string];
        }];
    }

```
- To handle universal links follow the steps below.
    - Enable **Associated Domains** under **Capabilities Tab** of the project settings.
    - Add **applinks:dev.minkasu.com/prefix**.
    - Add the same **<prefix>** to the **URL Schemes** in **URL Types** under **Info tab** of the project settings
    - Use the **prefix** and the **app id** while signing up on the Minkasu Dashboard. Enter both in the respective fields.
    - Implement the Minkasu delegate object and set it in the Minkasu Config.
    - Add the following code to handle the universal link app entry event 
```
         - (BOOL)application:(UIApplication *)application
            continueUserActivity:(NSUserActivity *)userActivity
            restorationHandler:(void(^)(NSArray * __nullable restorableObjects))restorationHandler
         {
            if ([userActivity.activityType isEqualToString:NSUserActivityTypeBrowsingWeb]) {
               NSURL *webpageURL = userActivity.webpageURL;
               [minkasuInit.stateManager topMostController];
               if (![minkasuInit.stateManager handleUniversalLink: webpageURL]) {
                  [[UIApplication sharedApplication] openURL:webpageURL]; // Will open in Safari
               }
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
