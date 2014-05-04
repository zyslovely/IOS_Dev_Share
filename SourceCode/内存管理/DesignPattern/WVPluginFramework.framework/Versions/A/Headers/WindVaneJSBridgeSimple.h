//
//  WindVaneJSBridgeSimple.h
//  YYZPlugin
//
//  Created by 颜 垣 on 14-2-26.
//  Copyright (c) 2014年 颜 垣. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NSObject+WVJSBridgeInterface.h"
#import "WindVaneJSBridgeCore.h"
#import <UIKit/UIKit.h>

/*
 * NEW JSBridge API Simple
 */
@interface WindVaneJSBridgeSimple : NSObject

+ (id) instance;

// 输出方法
+ (void) iLoveUAndGiveUWhatIHave:(NSDictionary *) wealth withCallback:(YYZJSBResponse) callback withWebView:(UIWebView *) webview;

// 输出方法
- (void) iLoveUAndTakeOffMyHeart:(NSString *) heart withCallback:(YYZJSBResponse) callback withWebView:(UIWebView *) webview;

@end
