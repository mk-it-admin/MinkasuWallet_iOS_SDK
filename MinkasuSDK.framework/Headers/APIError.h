//
//  APIError.h
//  PayNow
//
//  Created by ashis poddar on 1/25/15.
//  Copyright (c) 2015 Subramanian Lakshmanan. All rights reserved.
//

#ifndef PayNow_APIError_h
#define PayNow_APIError_h



@interface APIError : NSObject

@property(nonatomic,strong) NSNumber *errNum;
@property(nonatomic,strong) NSString* message;
@property(nonatomic,strong) NSString* details;

@end

#endif
