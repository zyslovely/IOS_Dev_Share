//
//  WindVaneUIWebView.h
//  YYZPlugin
//
//  Created by 颜 垣 on 14-3-11.
//  Copyright (c) 2014年 颜 垣. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "WindVaneJSBridgeCore.h"

@class YYZJavascriptApplication;
#pragma mark-
#pragma mark-WindVaneUIWbeViewDelegate

@protocol WindVaneUIWbeViewDelegate <UIWebViewDelegate>
@optional
- (BOOL) webView:(UIWebView *) webView shouldStartLoadWithRequest:(NSURLRequest *) request navigationType:(UIWebViewNavigationType) navigationType;
- (void) webViewDidStartLoad:(UIWebView *) webView;
- (void) webViewDidFinishLoad:(UIWebView *) webView;
- (void) webView:(UIWebView *) webView didFailLoadWithError:(NSError *) error;
@end

#pragma mark-
#pragma mark-WindVaneUIWebView

/*
 * WindVaneUIWebView
 *
 * SUPPORTS:
 * - JSBridge & API
 * - URL Interrupted
 * - JSPatch
 * - Cache
 */
@interface WindVaneUIWebView : UIWebView <WindVaneAPIAuthCheckProtocol>

// 是否禁止拖拽效果
@property (nonatomic, assign) BOOL                              forbiddenPullScroll;
// 代理
@property (nonatomic, assign) id<WindVaneUIWbeViewDelegate>     windVaneDelegate;
// 挂载的归属源VC
@property (nonatomic, assign) UIViewController *                sourceViewController;
// 是否开启JSBridge服务
@property (nonatomic, assign) BOOL                              isOpenLocalService;
// 是否响应点击status bar自动滚动到顶端
@property (nonatomic, assign) BOOL                              scrollsToTop;

#pragma mark- Public API

/*
 * 加载地址
 */
- (void) loadURL:(NSString *) requestURL;

/*
 * [ATTENTION::必须在VC的ViewWillDisappear中调用!!!] 释放WebView的服务,外部VC需要在disappear中使用
 */
- (void) releaseWebViewService;

/*
 * [ATTENTION::必须在VC的Dealloc中调用!!!] 销毁WebView的服务,外部VC需要在dealloc中使用
 */
- (void) deallocWebViewService;

/*
 * 注册私有JSB服务
 */
- (void) registeHandler:(NSString *) name withClassName:(NSString *) className handler:(YYZJSBHandler) handler;

#pragma mark- Protected API

/*
 * 获取当前WebView的JSB的上下文容器
 */
- (YYZJavascriptApplication *) webviewJSBContext;

/*
 * 获取JSB的响应处理器
 */
- (YYZJSBResponse) callBackResponeseForJSWithHandlerName:(NSString*)handlerName className:(NSString*) className;

@end