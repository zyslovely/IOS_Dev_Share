/*!
 *  @FILE: WVMultiWebViewController.h
 *  @PROJECT: YYZPlugin
 *  @DESCRIPTION:
 *
 *  (ARC)
 *  带有顶部下拉刷新以及带有URL跳转拦截回调通知、
 *  并且每一次的页面跳转都讲会主动新开创建一个Controller
 *
 *  Created by 颜 垣 on 13-08-05.
 *  Copyright (c) 2012年 颜 垣. All rights reserved.
 */

#import "WVWebViewController.h"

// 默认的协议和协议值
#define WV_DEF_PRO_TARGET_NAME  @"_target"
#define WV_DEF_PRO_TARGET_VALUE @"blank"

@interface WVMultiWebViewController : WVWebViewController
/*!
 * 根据URL中是否带有协议参数和协议参数值来决定是否要跳转到新的Controller
 * URL?@protocolParamName=@protocolParamValue
 */
// 跳转协议参数名
@property (retain, nonatomic) NSString * protocolParamName;
// 跳转协议参数值
@property (retain, nonatomic) NSString * protocolParamValue;
// 是否使用Native自带导航栏
@property (nonatomic) BOOL useNavigationBar;
@end
