//
//  WVJSPatch.h
//  YYZPlugin
//
//  Created by 颜 垣 on 13-11-10.
//  Copyright (c) 2013年 颜 垣. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface WVJSPatch : NSObject

/*
 * 执行JSPatch，必须在主线程执行
 */
+ (void) executeJSPatch:(UIWebView *) webview withJSPatchRule:(NSDictionary *) rule;

@end
