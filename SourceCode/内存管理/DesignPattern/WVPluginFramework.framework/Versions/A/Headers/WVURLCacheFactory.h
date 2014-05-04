//
//  WVURLCacheFactory.h
//  YYZPlugin
//
//  Created by 颜 垣 on 13-7-8.
//  Copyright (c) 2013年 颜 垣. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YYZURLCache.h"

@interface WVURLCacheFactory : NSObject

/*!
 * 获得 sharedCacheInstance
 */
+ (YYZURLCache *) sharedCacheInstance;

/*!
 * 注册 sharedCacheInstance
 */
+ (void) registeSharedCache:(YYZURLCache *) instance;

@end
