/*
 * WindVane SDK Interface
 *
 * @FILE:WindVane.h
 * @PROJECT:YYZPlugin
 *
 * Created by 颜 垣 on 13-10-28.
 * Copyright (c) 2013年 颜 垣. All rights reserved.
*/

/************************************************************
 *                                                          *
 *                  - WindVane INIT API -                   *
 *                                                          *
 ************************************************************/

#import <Foundation/Foundation.h>

@interface WindVane : NSObject

#pragma mark-
#pragma mark- 默认API

/*!
 * [推荐使用 - 适用于默认无特殊需求场景] 初始化WindVane
 * [必选]
 */
+ (void) initWindVanePlugin;

/*!
 * [必须初始化前调用] 开启WindVane的安全模式 - 如果你开启了这个安全模式，则不需要再通过WVUserConfig来设置appkey和appSecret
 *
 * !!!! 但是这要求你的APP必须引入了安全黑匣子 !!!!
 * [可选]
 */
+ (void) setWindVaneSecurityModal;

/*!
 * [必须初始化前调用] 设置WindVane的TTID
 * [必选]
 */
+ (void) setWindVaneTTID:(NSString *) ttid;

#pragma mark-
#pragma mark- 高级API

/*!
 * [适用需要自己定制缓存处理器的场景] 初始化WindVane，并且指定URLCache处理器
 */
+ (void) initWindVanePluginWithCustomURLCache:(id) cacheInstance;

/*!
 * [适用于对NSURLProcol要额外定制注册过程的场景] 初始化WindVane 
 *  - 但是不包含缓存协议模块部分的初始化,通常需要额外的再调用初始化WindVane的协议模块部分
 */
+ (void) installWindVanePluginWithoutRegisteCacheProtocol;

/*!
 * [适用于手动调用注册NSURLProtocl来注入WindVane缓存处理模块的场景] 初始化WindVane 的缓存协议模块部分
 *  - 该部分内部自带了对iOS系统bug的自动处理
 */
+ (void) installWindVaneRegisteCacheProtocl;

@end
