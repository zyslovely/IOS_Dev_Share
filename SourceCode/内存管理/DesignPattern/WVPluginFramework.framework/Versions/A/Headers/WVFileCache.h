//
//  WVCache.h
//  YYZPlugin
//
//  Created by christ.yuj on 13-5-17.
//  Copyright (c) 2013年 颜 垣. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WVFileCache : NSObject {
	NSString* _cachePath;
	NSRecursiveLock* _cacheLock;
}

@property (nonatomic, readonly) NSString* cachePath;

- (id)initWithPath:(NSString*)cachePath subDirectories:(NSArray*)subDirectories;
- (BOOL)hasEntry:(NSString*)cacheKey;
- (void)invalidateEntry:(NSString*)cacheKey;
- (void)invalidateSubDirectory:(NSString*)subDirectory;
- (void)invalidateAll;
- (void)writeDictionary:(NSDictionary*)dictionary withCacheKey:(NSString*)cacheKey;
- (void)writeData:(NSData*)data withCacheKey:(NSString*)cacheKey;
- (NSDictionary*)dictionaryForCacheKey:(NSString*)cacheKey ;
- (NSData*)dataForCacheKey:(NSString*)cacheKey;
- (NSDate*)cacheDateForCacheKey:(NSString*)cacheKey;
@end
