/*!
 * @FILE: YYZJavascriptApplication.h
 * @PROJECT: YYZPlugin
 * @DESCRIPTION:
 * JSBridage用于javascript通向本地API的方法路径，通过该bridage，可以实现javascript对本地API的调用
 *
 *  Created by 颜 垣 on 13-02-04.
 *  Copyright (c) 2012年 一淘网. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "WindVaneJSBridgeCore.h"

@interface YYZJavascriptApplication : NSObject

@property (assign, nonatomic) UIWebView * webview;

/*!
 * 检测是否是JSBridge的Protocol协议
 */
+ (BOOL) isJSBridgeProtocol:(NSString *) request;

/*!
 * 初始化
 */
- (id) init;

/*!
 * 是否已经绑定webview
 */
- (BOOL) isBindedWebView;

/*!
 * 绑定webview
 */
- (void) bindWebView:(UIWebView * ) wv;

/*!
 * 解绑webview
 */
- (void) releaseWebView;

/*!
 * 注册服务
 */
- (void) registeHandler:(NSString *) name withClassName:(NSString *) className handler:(YYZJSBHandler) handler;

/*!
 * 注册JSB的别名 @{ "类别名:方法别名" : "类名:方法名" }
 * 注意别名为KEY，原始名为VALUE
 */
- (void) registeHandlerAlias:(NSDictionary *) alias;

/*!
 * 调用服务
 */
- (void) callHandler:(NSString *) handlerName withClassName:(NSString *) className withData:(id) data withReqId:(NSString *) ifid withNested:(BOOL) nested /*是否父子嵌套调用*/ withViewController:(UIViewController *) viewController withWebView:(UIWebView *) webVivew;

/*!
 * 拿到回调给js的response
 */
- (YYZJSBResponse) callBackResponeseForJSWithHandlerName:(NSString*)handlerName className:(NSString*) className;

/*!
 * 拿到回调给js的req
 */
- (NSString *) callbackSeqIdForJSWithHandlerName:(NSString*)handlerName className:(NSString*) className;

/*!
 * 打开日志
 */
- (void) openLog;

/*!
 * 执行脚本
 */
- (void) executeScript:(NSString *) script;

/*!
 * 重置JSBridge Context
 */
- (void) resetJSBridgeContext;

/*!
 * 执行SUCCESS回调
 */
+ (void) callBackForWebView:(UIWebView *) webView withIfId:(NSString *) ifid withMsg:(NSDictionary *) result;

/*!
 * 指定ret执行回调,SUCCESS or FAILED
 */
+ (void) callBackForWebView:(UIWebView *) webView withIfId:(NSString *) ifid withMsg:(NSDictionary *) result withRet:(NSString *) ret;

/*!
 * 指定方法执行回调
 */
+ (void) callBackForWebView:(UIWebView *) webView withIfId:(NSString *) ifid withMsg:(NSDictionary *) result withRet:(NSString *) ret withFuntion:(NSString *) callbackMethod;

/*!
 * 获取只带有结果码的结果JSON串
 */
+ (NSString *) getResultOnlyWithCode:(NSString *) code;

/*!
 * 从协议参数中获取参数哈希集合
 */
+ (NSDictionary *) getParaemeterFromProtocol:(NSString *) param;

/*!
 * 获取执行方法名称
 */
+ (NSString *) getMethod:(NSArray *) methods;

/*!
 * 自动注入JSBridge到页面，适用于非阿里系的外部页面使用，但会带来安全风险
 */
+ (BOOL) autoWiredJSBridgeIntoWebView:(UIWebView *) webView withJSBridgeFileName:(NSString *) jsFile;

#pragma mark- 全局App注册服务

/*!
 * 注册App服务 - 全局注册器专用, 请勿直接使用YYZJavascriptApplication对象调用该API
 */
- (void) registeAppHandler:(NSString *)name withClassName:(NSString *)className handler:(WVJSBHandler)handler withResetHandler:(WVJSBResetHandler) resetHandler;

/*!
 * 注册App服务 - 全局注册器专用, 请勿直接使用YYZJavascriptApplication对象调用该API
 */
- (void) registeHandler:(NSString *)name withClassName:(NSString *)className handler:(WVJSBHandler)handler withResetHandler:(WVJSBResetHandler)resetHandler withDeallocHandler:(WVJSBDeallocHandler) deallocHandler;

/*!
 * 重置App服务 - 全局注册器专用, 请勿直接使用YYZJavascriptApplication对象调用该API
 */
- (void) resetAppJSBHandler:(UIViewController *) sourceViewController withWebView:(UIWebView *) webView;

/*!
 * 销毁App服务 - 全局注册器专用, 请勿直接使用YYZJavascriptApplication对象调用该API
 */
- (void) deallocAppJSBHandler:(UIViewController *) sourceViewController withWebView:(UIWebView *) webView;

/*!
 * 获取App服务 - 全局注册器专用, 请勿直接使用YYZJavascriptApplication对象调用该API
 */
- (void) synAppJSBHandler:(NSDictionary *) appHandlers withRetHandler:(NSDictionary *) resetHandlers withDeallocHandler:(NSDictionary *) deallocHandlers;

/*!
 * 全局的处理器
 */
- (NSDictionary *) appWVJSBHandlers;

/*!
 * 全局的重置处理器
 */
- (NSDictionary *) appWVJSBResetHandlers;

/*!
 * 销毁的重置处理器
 */
- (NSDictionary *) appWVJSBDeallocHandlers;

/*!
 * Handler名称的内部调用解析方法 - 外部用不到 - 内部用
 */
+ (NSArray *) getHandlerName:(NSString *) handlerTargetName;

@end
