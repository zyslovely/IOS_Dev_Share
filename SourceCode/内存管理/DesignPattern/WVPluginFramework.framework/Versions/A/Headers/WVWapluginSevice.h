//
//  WVWapPluginSevice.h
//  YYZPlugin
//
//  Created by christ.yuj on 13-5-14.
//  Copyright (c) 2013年 颜 垣. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface WVWapluginSevice : NSObject

+(BOOL)isWapPluginProtocol:(NSString*)urlString;

+(void)openWapluginUrl:(NSString*)urlString sourceViewController:(UIViewController*)sourceViewController;

+(void)cleanSourceViewController;

+(NSDictionary *) currentPluginResRuleInContext;

@end
