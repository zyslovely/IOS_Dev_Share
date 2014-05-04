//
//  WVHTTPRequest.h
//  YYZPlugin
//
//  Created by 隐风 on 14-2-24.
//  Copyright (c) 2014年 颜 垣. All rights reserved.
//
//  A wrapper class of ASIHTTPRequest used by WindVane.
//  @see ASIHTTPRequest
//

#import <Foundation/Foundation.h>
#import "WVRequestCache.h"
@class ASIFormDataRequest;

typedef enum {
    WVRequestCachePolicyNone = 0,
    WVRequestCachePolicyTimeout = 1
} WVRequestCachePolicy;

@interface WVHTTPRequest : NSObject

//回调delegate对象
@property (nonatomic, assign) id delegate;

//请求开始、失败、成功的回调方法
@property (nonatomic, assign) SEL requestDidStartSelector;
@property (nonatomic, assign) SEL requestDidFailedSelector;
@property (nonatomic, assign) SEL requestDidFinishSelector;

// 发送请求的url
@property (nonatomic, retain) NSString* requestUrl;

// 请求的参数
@property (nonatomic, retain) NSMutableDictionary* params;

// 请求时发生的错误
@property (nonatomic, retain) NSError* error;

// 响应码以及三种形式的响应数据
@property (nonatomic) int responseStatusCode;
@property (nonatomic, retain) NSString* responseString;
@property (nonatomic, retain) NSData* responseData;
@property (nonatomic, strong) NSDictionary* responseJSON;

// 是否使用 POST 方式发送请求
@property (nonatomic, assign) BOOL usePOST;

// 使用上传模式
@property (nonatomic, assign) BOOL usedForUpload;
@property (nonatomic, assign) NSString* filePath;

// 缓存策略
@property (nonatomic, assign) WVRequestCachePolicy cachePolicy;
@property (nonatomic, strong) WVRequestCache* cache;
@property (nonatomic, assign) NSTimeInterval cacheTimeoutInterval;
@property (nonatomic, assign) BOOL isLoadFromCache;

@property (nonatomic, strong) NSDictionary* userInfo;

// ASIHTTPRequst回调函数
- (void)requestStarted:(ASIFormDataRequest*)request;
- (void)requestFinished:(ASIFormDataRequest*)request;
- (void)requestFailed:(ASIFormDataRequest*)request;

// 获取请求的URL和参数
- (NSString*)urlForRequest;
- (NSDictionary*)parametersForRequest;

// 操作请求参数
- (void)addTopParam:(NSObject*)param forKey:(NSString*)key;
- (void)removeTopParam:(NSString*)key;

// 发送请求
- (void)sendRequest;
- (void)loadFromRemote;

// 取消
- (void)cancel;
// 是否在请求中
- (BOOL)isRequesting;

// 是否要缓存
- (BOOL)isCacheable;
// 缓存的key
- (NSString*)cacheKey;
// 使缓存失效
- (void)invalidateCache;
// 取得md5值
- (NSString*)md5:(NSData*)data;

- (void)addParam:(NSObject*)param forKey:(NSString*)key;

@end
