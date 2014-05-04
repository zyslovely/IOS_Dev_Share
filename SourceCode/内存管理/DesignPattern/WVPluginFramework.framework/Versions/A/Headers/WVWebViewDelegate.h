/*!
 *  @FILE: WVWebViewDelegate.h
 *  @PROJECT: YYZPlugin
 *  @DESCRIPTION:
 *
 *  提供给子类使用的WVWebViewDelegate，可以参与到页面的加载开始和结束动作
 *
 *  Created by 颜 垣 on 13-2-5.
 *  Copyright (c) 2012年 颜 垣. All rights reserved.
 */

#import <Foundation/Foundation.h>

@protocol WVWebViewDelegate <NSObject>

/*!
 * 加载开始
 */
@optional
- (void)tbWebViewDidStartLoad:(UIWebView *)webView;

/*!
 * 加载结束
 */
@optional
- (void)tbWebViewDidFinishLoad:(UIWebView *)webView;

/*!
 * 请求事件
 */
- (BOOL)tbWebView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)_request navigationType:(UIWebViewNavigationType)navigationType;

@end
