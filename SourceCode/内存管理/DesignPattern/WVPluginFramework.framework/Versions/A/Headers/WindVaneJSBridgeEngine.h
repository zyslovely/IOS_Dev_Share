//
//  WindVaneJSBridgeEngine.h
//  YYZPlugin
//
//  Created by 颜 垣 on 14-3-4.
//  Copyright (c) 2014年 颜 垣. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "YYZJavascriptApplication.h"

// 此处注册全局的JSBridge服务
@interface WindVaneJSBridgeEngine : NSObject

/*!
 * 注册服务
 * name         ：方法名
 * className    ：类名
 * handler      ：方法处理逻辑
 * resetHandler ：重置服务处理逻辑,比如停止播放音乐等操作
 *               [特别注意!!!] 该重置服务的逻辑会在ViewController willDisappear时候会执行
 */
+ (void) registeHandler:(NSString *)name withClassName:(NSString *)className handler:(WVJSBHandler)handler withResetHandler:(WVJSBResetHandler) resetHandler;

/*!
 * 注册服务
 * name          ：方法名
 * className     ：类名
 * handler       ：方法处理逻辑
 * resetHandler  ：重置服务处理逻辑,比如停止播放音乐等操作
 *               [特别注意!!!] 该重置服务的逻辑会在ViewController willDisappear时候会执行
 * deallocHandler：销毁服务处理逻辑,用于释放等行为
 *               [特别注意!!!] 该销毁服务的逻辑会在viewController dealloc时候执行
 */
+ (void) registeHandler:(NSString *)name withClassName:(NSString *)className handler:(WVJSBHandler)handler withResetHandler:(WVJSBResetHandler)resetHandler withDeallocHandler:(WVJSBDeallocHandler) deallocHandler;

/*!
 * 注册JSB的别名 @{ "类别名:方法别名" : "类名:方法名" }
 * 注意别名为KEY，原始名为VALUE
 */
+ (void) registeHandlerAlias:(NSDictionary *) alias;

/*!
 * 全局JSB上下文
 */
+ (YYZJavascriptApplication *) appWindVaneJSBContext;

/*!
 * 全局的处理器
 */
+ (NSDictionary *) appWVJSBHandlers;

/*!
 * 全局的重置处理器
 */
+ (NSDictionary *) appWVJSBResetHandlers;

/*!
 * 全局的销毁处理器
 */
+ (NSDictionary *) appDeallocHandlers;

/*!
 * 注册全局处理器到局部处理器
 */
+ (void) regiteAppHandlerForThisJSBContext:(YYZJavascriptApplication *) javascriptApplication;

/*!
 * 执行处理器
 */
+ (BOOL) executeJSBApplication:(NSURLRequest *) _request withJSBContext:(YYZJavascriptApplication *) javascriptBridage withWebView:(UIWebView *) webView withViewController:(UIViewController *) viewController  withLock:(BOOL) sourceControlNotLock;

@end
