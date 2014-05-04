/*!
 *  @FILE: YYZWebViewController.h
 *  @PROJECT: YYZPlugin
 *  @DESCRIPTION:
 *
 *  (ARC)
 *  带有顶部下拉刷新以及带有URL跳转拦截回调通知的Controller
 *
 *  Created by 颜 垣 on 12-12-3.
 *  Copyright (c) 2012年 颜 垣. All rights reserved.
 */

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import "YYZUIWebViewController.h"
#import "WVApiAuthCheckResult.h"

#pragma mark-
#pragma mark-TBWebViewController

@interface WVWebViewController : YYZUIWebViewController

/*!
 * 单例
 */
+ (id) sharedInstance;

/*!
 * 自动注入JSBridge服务，如果采用默认名称：jsbridge.js则jsFile可以传递nil，否则请指定以APP mainBunddle为基础路径的内部的文件路径
 * 该方法建议使用在webview webViewDidFinishLoad delegate方法中，用于目标页面加载完成后使用
 *
 * [Attention:自动注入服务将带来安全隐患，请慎重考虑！！！]
 *
 */
- (void) autoWiredJSBridgeWithTargetJSFile:(NSString *) jsFile;

/*!
 * API 鉴权
 * 返回值:
 * @(WVApiAuthCheckResult *) 判断结果 
 *      - 如果返回不为nil并且指定其中的是否允许参数为NO，则认定不允许执行API；如果返回nil则认为可以执行该API
 */
- (WVApiAuthCheckResult *) apiAuthCheck:(NSString *) className withMethod:(NSString *) method withParam:(id) data;

/*!
 * 注册通用API
 * 该注册方法会将API统一注册，并且具有上述的 apiAuthCheck 提供的权限AOP控制
 * 该方法与普通registeHandler的区别是registeHandler的注册方式不会具有权限AOP控制，即不会使用进入上述的apiAuthCheck方法
 *
 * @ className  : 类名 - 提供给JS使用的类名称
 * @ method     : 方法名 - 提供给JS使用的方法名
 * @ handler    : 处理器 - 即响应JS调用的函数执行体
 */
- (void) registeCommonHandler:(NSString *) className withMethodName:(NSString *) method withHandler:(YYZJSBHandler) handler;

#pragma mark-
#pragma mark- API - 以下API均采用权限AOP控制层的方式注册 - 可以在apiAuthCheck方法进行统一鉴权

// 注册行为服务
- (void) registeWVMotionService;
// 注册震动服务
- (void) registeWVMotionVibrateService;
// 注册监听摇动服务
- (void) registeWVMotionListeningShakeService;
// 注册监听吹气服务
- (void) registeWVMotionListeningBlowService;
// 注册停止监听吹气服务
- (void) registeWVMotionStopListeningBlowService;

// 注册导航类服务
- (void) registeNavigatorService;
// 注册导航PUSH服务
- (void) registeWVNavigitorPushService;
// 注册导航POP服务
- (void) registeWVNavigitorPopService;

@end
