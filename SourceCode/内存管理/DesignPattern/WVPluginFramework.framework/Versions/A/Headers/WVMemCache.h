//
//  WVMemCache.h
//  YYZPlugin
//
//  Created by christ.yuj on 13-5-20.
//  Copyright (c) 2013年 颜 垣. All rights reserved.
//

#import <Foundation/Foundation.h>
#define WapluginMemCachePath @"WapluginMemCache"

@interface WVMemCache : NSObject{
    NSString* _cachePath;
    NSRecursiveLock* _cacheLock;
    NSUInteger _cacheArrayCapacity;
    NSMutableArray* _cacheArray;
}

@property (nonatomic, readonly) NSString* cachePath;

- (id)initWithPath:(NSString*)cachePath capacity:(NSUInteger)numItems;
- (BOOL)hasEntry:(NSString*)cacheKey;
- (void)invalidateEntry:(NSString*)cacheKey;
- (void)invalidateAll;
- (void)writeDictionary:(NSDictionary*)dictionary withCacheKey:(NSString*)cacheKey;
- (NSDictionary*)dictionaryForCacheKey:(NSString*)cacheKey ;
- (NSDate*)cacheDateForCacheKey:(NSString*)cacheKey;

@end
