/*!
 *  @FILE: YYZUIWebViewController.h
 *  @PROJECT: YYZPlugin
 *  @DESCRIPTION:
 *
 *  协议定义
 *
 *  Created by 颜 垣 on 13-1-7.
 *  Copyright (c) 2012年 颜 垣. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "TBWVRuleCoreData.h"

#pragma mark-
#pragma mark-Enum

/*!
 * 协议定义的参数KEY 
 */
#define HY_PROTOCOL_PRE @"HY_"

@protocol YYZRuleProtocol <NSObject>

#pragma mark-
#pragma mark-Methods_protected

/*!
 * 本地跳转方法
 * @target   : 跳转解析后的判别目标
 * @allPara  : 请求附带的所有参数
 * @request  : 请求体对象
 *
 * return    : 如果客户端响应了该target，则请返回NO，否则，请返回YES； 
 */
@required
- (BOOL) interruptJumpToLocalPage:(NSInteger) target withParam:(NSDictionary *) allParam withRequest:(NSURLRequest *) request;

@end
