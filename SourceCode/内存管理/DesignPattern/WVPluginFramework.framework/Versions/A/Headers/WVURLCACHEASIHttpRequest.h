//
//  WVURLCACHEASIHttpRequest.h
//  YYZPlugin
//
//  定制服务于NSURLCache的WVRequest 类型
//
//  Created by 颜 垣 on 13-5-23.
//  Copyright (c) 2013年 颜 垣. All rights reserved.
//
#import "WVRequest.h"
#import "URLCacheRuleCheckResult.h"

// 网络下载资源后的回调
typedef void (^WVCacheDownloadComplete)(int statusCode, NSData * responseData, NSDictionary * responseHeader, WVRequest * downloadRequest);
typedef void (^WVCacheDownloadFailed)(int statusCode, NSData * responseData, NSDictionary * responseHeader, NSError * error, WVRequest * downloadRequest);

// WVURLCACHEASIHttpRequest
@interface WVURLCACHEASIHttpRequest : WVRequest
// 文件本地存储路径
@property (copy, nonatomic)     NSString        * fileLocalPath;
// 文件请求地址
@property (copy, nonatomic)     NSString        * fileUrl;
// 文件长度
@property (assign, nonatomic)   NSInteger       fileLength;
// 匹配中的配置
@property (copy, nonatomic)     NSDictionary    * config;
// 原始请求
@property (strong, nonatomic)   NSURLRequest    * sourceRequest;
// 是否打点
@property (assign, nonatomic)   BOOL            isTrack;
// 是否Cache
@property (assign, nonatomic)   BOOL            isCache;
// 是否是碎片资源
@property (assign, nonatomic)   BOOL            isMuchResource;
// 规则检查结果
@property (strong, nonatomic)   URLCacheRuleCheckResult * checkResult;
// 成功回调方法
@property (nonatomic, copy)     WVCacheDownloadComplete successCallback;
// 失败回调方法
@property (nonatomic, copy)     WVCacheDownloadFailed   failedCallback;

// 是否是页面请求
- (BOOL) isPageRequest;

@end
