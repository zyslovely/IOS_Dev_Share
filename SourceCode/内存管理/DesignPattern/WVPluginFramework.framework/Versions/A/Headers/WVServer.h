//
//  WVServer.h
//  YYZPlugin
//
//  Created by 颜 垣 on 13-12-20.
//  Copyright (c) 2013年 颜 垣. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WVWebViewController.h"
#import "WVAPIBase.h"
#import "WVMtopRequest.h"

#define WV_SERVER_CLASS                     @"WVServer"
#define WV_SERVER_METHOD_SEND               @"send"

typedef void (^WVServerFailed)(WVMtopRequest * request, YYZJSBResponse callback);

@interface WVServer : WVAPIBase

#pragma mark-全局注册方法

/*!
 * 将API注册给APP全局JSB容器
 */
+ (void) registeServiceToApp;

/*!
 * 注册给WVServer方法的失败处理器
 */
+ (void) registeFailedBlock:(WVServerFailed) failedBlock;

#pragma mark-独立注册方法

/*!
 * 发送数据请求
 */
- (void) sendData:(id) data withCallBack:(YYZJSBResponse) yyzJSBResponseCallback;

@end
