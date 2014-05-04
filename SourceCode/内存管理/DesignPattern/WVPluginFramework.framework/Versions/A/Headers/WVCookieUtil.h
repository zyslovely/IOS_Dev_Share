//
//  WVCookieUtil.h
//  YYZPlugin
//
//  Created by christ.yuj on 13-7-10.
//  Copyright (c) 2013年 颜 垣. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WVCookieUtil : NSObject

/*!
 将Set Cookie对应的cookie字符串解析成一个字典数据结构
 example:
 "imewweoriw=i0syJl1Vo8MrJrrOh%2B24JA%3D%3D; Domain=.waptest.taobao.com; Expires=Sat, 30-Mar-2013 09:32:18 GMT; Path=/"
 转换成
 {
 imewweoriw = i0syJl1Vo8MrJrrOh%2B24JA%3D%3D;
 Domain = .waptest.taobao.com;
 Expires = Sat, 30-Mar-2013 09:32:18 GMT;
 Path = /
 }
 */
+ (NSDictionary *)cookieMapWithCookieString:(NSString *)cookieString;


/*!
 将一个普通的CookieMap转换成标准的Cookie Properties
 此CookieMap可能是从CookieString转换而来的map，也可能是api返回的一个cookie map
 */
+ (NSDictionary *)cookiePropertiesWithCookieMap:(NSDictionary *)cookieMap;

//单个cookie的设置操作
+ (void)setCookieWithCookieString:(NSString *)cookieString;
+ (void)setCookieWithCookieMap:(NSDictionary *)cookieMap;

+ (void)setCookiesWithCookieMaps:(NSArray *)cookieMaps;
+ (void)setCookiesWithCookieStrings:(NSArray *)cookieStrings;

+ (void)deleteAllCookies;

@end
