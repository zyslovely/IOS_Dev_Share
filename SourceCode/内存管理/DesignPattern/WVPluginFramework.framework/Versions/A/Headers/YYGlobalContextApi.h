/*!
 * @FILE: YYGlobalContextApi.h
 * @PROJECT: YYZPlugin
 * @DESCRIPTION:
 * Hybrid插件运行全局上下文API协议，如果要实现自己的运行上下文类，需要实现此处的协议
 *
 *  Created by 颜 垣 on 12-10-18.
 *  Copyright (c) 2012年 一淘网. All rights reserved.
 */

#import <Foundation/Foundation.h>

@protocol YYGlobalContextApi <NSObject>

/*!
 * 初始化
 */
@required
+ (void) init;

/*!
 * 设置值
 */
@required
+ (void) putContext:(NSString*)key setResource:(NSObject*)resource;

/*!
 * 获取值
 */
@required
+ (id) getContextValue:(NSString*)key;

/*!
 * 删除值
 */
@required
+ (void) removeContext:(NSString*)key;

/*!
 * 释放全部内存
 */
@required
+ (void) releaseContext;

@end
