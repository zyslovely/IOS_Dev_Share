//
//  WVURLProtocol.h
//  YYZPlugin
//
//  Created by 颜 垣 on 13-10-22.
//  Copyright (c) 2013年 颜 垣. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WVURLProtocol : NSURLProtocol

    /**********************************************************************
     *          基于URLProtocol和NSURLCache的统一缓存处理模块                 *
     **********************************************************************
     *                                                                    *
     *   + 目前支持特性:
     *      - 多线程触发资源拦截，任务队列下载资源
     *      - 基于动态规则的资源规则处理
     *      - 支持离线/reload的本地读取
     *
     *   + 注意:
     *      - 本interface禁止任何场景的实例化
     *      - NSURLCache 为自定义策略实现(YYZURLCache),挂在于本Protocol中使用
     *        ,如果你要实现自己的NSURLCache,则需要遵循规范，详见:YYZURLCache
     *                                                                    *
     **********************************************************************/


/*!
 * 关闭HTML5的AppCache，仅支持manifest请求为.manifest的页面
 */
+ (void) closeHTML5ApplicationCache;

/*!
 * 开启HTML5的AppCache，仅支持manifest请求为.manifest的页面
 */
+ (BOOL) openHTML5ApplicationCache;

/*!
 * 关闭应用程序的缓存功能
 */
+ (void) closeApplicationCache;

/*!
 * 打开应用程序的缓存功能
 */
+ (void) openApplicationCache;

/*!
 * 应用程序的缓存功能是否打开
 */
+ (BOOL) isOpenApplicationCache;

@end
