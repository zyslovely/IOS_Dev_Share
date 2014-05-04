/*!
 * @FILE: YYZPluginFactory.h
 * @PROJECT: YYZPlugin
 * @DESCRIPTION:
 * YYZ组件工具
 *
 *  Created by 颜 垣 on 13-1-21.
 *  Copyright (c) 2012年 一淘网. All rights reserved.
 */

#import <Foundation/Foundation.h>

@interface YYZPluginFactory : NSObject

/*!
 * [不允许直接调用] 单例
 */
+ (id) instance __attribute__((deprecated));

/*!
 * 判断是否因为NSURLProtocol挂掉
 */
+ (BOOL) checkIsURLProtocolCrashedToday;

/*!
 * [不允许直接调用] 安装WindVane插件
 */
- (void) installYYZPlugin __attribute__((deprecated));

/*!
 * [不允许直接调用] 安装WindVane插件但是不包括缓存协议部分 - 通常需要额外的再安装缓存协议
 */
- (void) installWindVanePluginWithoutRegisteCacheProtocol __attribute__((deprecated));

/*!
 * [不允许直接调用] 安装WindVane插件的缓存协议部分
 */
- (void) installWindVaneRegisteCacheProtocl __attribute__((deprecated));

/*!
 * [不允许直接调用] 注册自定义URLCache，需要在installYYZPlugin方法前执行
 */
+ (void) registeCustomURLCache:(id) instance __attribute__((deprecated));

@end
