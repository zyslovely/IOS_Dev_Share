//
//  WVRequestCache.h
//  YYZPlugin
//
//  Created by christ.yuj on 13-5-19.
//  Copyright (c) 2013年 颜 垣. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WVFileCache.h"
#import "WVMemCache.h"

@class WVHTTPRequest;

typedef enum {
    WVRequestCacheStoragePolicyDisabled,
    WVRequestCacheStoragePolicyEnabled
} WVRequestCacheStoragePolicy;

extern NSString * const WVRequestCachePermanentCacheDirectory;

@interface WVRequestCache : NSObject {
    WVRequestCacheStoragePolicy _storagePolicy;
    WVFileCache *_cache;
    WVMemCache * _memCache;
}

- (id)initWithPath:(NSString *)cachePath storagePolicy:(WVRequestCacheStoragePolicy)storagePolicy;

@property (nonatomic, readonly) NSString *path;
@property (nonatomic, assign)   WVRequestCacheStoragePolicy storagePolicy;

- (NSString *)pathForRequest:(WVHTTPRequest *)request;

- (BOOL)hasResponseForRequest:(WVHTTPRequest *)request;

- (void)storeResponse:(NSDictionary*)response forRequest:(WVHTTPRequest *)request;

- (NSDate *)cacheDateForRequest:(WVHTTPRequest *)request;

- (NSDictionary*)responseForRequest:(WVHTTPRequest *)request;

- (void)invalidateRequest:(WVHTTPRequest *)request;

- (void)invalidateWithStoragePolicy:(WVRequestCacheStoragePolicy)storagePolicy;

- (void)invalidateAll;

@end
