/*!
 *  @FILE: WVRuleWebViewController.h
 *  @PROJECT: YYZPlugin
 *  @DESCRIPTION:
 *
 *  (ARC)
 *  带有与Native交互规则的Controller
 *
 *  Created by 颜 垣 on 13-2-20.
 *  Copyright (c) 2012年 颜 垣. All rights reserved.
 */

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import "YYZPluginCategory.h"
#import "YYZRuleProtocol.h"
#import "YYZJavascriptApplication.h"
#import "WindVaneJSBridgeCore.h"
#import "TBRuleResult.h"

#pragma mark-
#pragma mark-TBWebViewController

@interface WVRuleWebViewController : UIViewController <YYZRuleProtocol, WindVaneAPIAuthCheckProtocol>

/*!
 * 创建对象
 */
- (id)init;

/*!
 * 初始化Brigdage
 */
- (void)initBrigdage;

/*!
 * 注册服务
 */
- (void) registeHandler:(NSString *) name withClassName:(NSString *) className handler:(YYZJSBHandler) handler;

/*!
 * 拿到回调给js的response
 */
- (YYZJSBResponse) callBackResponeseForJSWithHandlerName:(NSString*)handlerName className:(NSString*) className;

/*!
 * 主动调用Handler - 该API仅允许在Handler中调用
 *
 * @ className  : 要调用的Handler的类名称
 * @ method     : 要调用的方法的名称
 * @ data       : 要调用的Handler的参数
 * @ fClassName : 调用Handler的父类名称，传入你当前的Handler的 className
 * @ fMethod    : 调用Handler的父方法名称，传入你当前的Handler的 method
 */
- (void) callRegistedHandler:(NSString *) className withMethod:(NSString *) method withData:(id) data withFatherClass:(NSString *) fClassName withFatherMethod:(NSString *) fMethod;

/*!
 * WebViewDelegate
 */
- (BOOL)webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)_request navigationType:(UIWebViewNavigationType)navigationType;

/*!
 * 打开useJSBridge日志
 */
- (void) useJSBridgeLog;

/*!
 * 获取UIWebView对象，子类必须重写该方法以传递自己的webview给本父类
 */
- (UIWebView *) getWebView;

/*!
 * 初始化JavascriptBridge
 */
- (void) initJavascriptBridge:(UIWebView *) webview;

/*!
 * 从请求体中读取参数串
 */
- (NSString *) getRequestBodyForPost:(NSURLRequest *) request;

/*!
 * 是否是POST方式的请求
 */
- (BOOL) isPostRequest:(NSURLRequest *) request;

/*!
 * 新旧版本兼容解析URL规则分析
 */
- (TBRuleResult *) analyzerRequest:(NSURLRequest *) request navigationType:(UIWebViewNavigationType) navigationType withWebView:(UIWebView *) webView;

/*!
 * 基于解析URL规则分析结果的分发
 */
- (BOOL) dispatch:(TBRuleResult *) type withRequestUrl:(NSURLRequest *) request;

/*!
 * 请求开始事件
 */
- (void) webViewDidStartLoad:(UIWebView *)webView;

/*!
 * 请求结束事件
 */
- (void)webViewDidFinishLoad:(UIWebView *)webView;

/*!
 * 请求结束错误
 */
- (void) webView:(UIWebView *)webView didFailLoadWithError:(NSError *)error;

/*!
 * 获取JSPath规则
 */
- (NSDictionary*) getJSPatchRule;

/*!
 * 设置JSPatch规则
 */
- (void) setJSPatchRule:(NSDictionary *) jsPatchRule;

/*!
 * 是否启动本地服务，本地服务基于本地功能封装的服务于Javascript的API
 * 具体的服务清单可以参见：http://gitlab.alibaba-inc.com/mtb/lib-windvane/blob/master/README.md
 */
- (void) openLocalService;

/*!
 * 关闭JSBridge服务
 */
- (void) closeLocalService;

/*!
 * 判断是否开启JSBridge服务
 */
- (BOOL) isOpenLocalService;

/*!
 * 重置JSBridge服务
 */
- (void) resetJSBridge;

/*!
 * 关闭URL拦截解析服务
 */
+ (void) closeURLInterruptedModule;

/*!
 * 开启URL拦截解析服务
 */
+ (void) openURLInterruptedModule;

/*!
 * URL拦截解析服务是否开启
 */
+ (BOOL) isOpenURLInterruptedModule;

/*!
 * 获取当前JSB上下文环境
 */
- (YYZJavascriptApplication *) currentJSBContext;

@end
