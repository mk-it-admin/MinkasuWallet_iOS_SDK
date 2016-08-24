//
//  ScanOverlayView.h
//  PayNow
//
//  Created by Subramanian Lakshmanan on 2/20/14.
//  Copyright (c) 2014 Subramanian Lakshmanan. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ScanOverlayView : UIView

@property UIView *guideView;
@property CGRect overlayFrame;
@property BOOL orientationIsVertical;

@end
