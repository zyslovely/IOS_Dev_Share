//
//  WVNativeURLCache.h
//  YYZPlugin
//
//  专门服务于本地zip化webapp的缓存处理器
//
//  Created by 颜 垣 on 13-9-5.
//  Copyright (c) 2013年 颜 垣. All rights reserved.
//

#import "YYZURLCache.h"

/*@
 * WVNativeURLCache
 */
@interface WVNativeURLCache : YYZURLCache <WebViewNSURLCacheProtocol>

/*!
 * instance
 */
+ (id) instance;

/*!
 * cachedResponseForRequest
 */
- (NSCachedURLResponse *) cachedResponseForRequest:(NSURLRequest *)request;

/*!
 * 将缓存模块热切换到基础版本 - 无本地APP服务
 */
- (void) switchURLCacheToBaseWithoutNativeApp;

/*!
 * 校验请求是否是缓存模块会处理的地址
 */
- (URLCacheRuleCheckResult *) checkURLCacheRule:(NSURLRequest *) request;

@end
