//
//  WVMtopRequest.h
//  YYZPlugin
//
//  Created by 隐风 on 14-2-24.
//  Copyright (c) 2014年 颜 垣. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WVHTTPRequest.h"

@interface WVMtopRequest : WVHTTPRequest

// 是否由安全黑匣子代理
@property(nonatomic) BOOL isSafeBoxProxy;
// 是否是API2
@property(nonatomic, assign) BOOL isUseAPI2;
// 是否需要ecode
@property(nonatomic, assign) BOOL isNeedEcode;
// 是否返回所有的mtop返回字段
@property(nonatomic, assign) BOOL isResponseAllAttributes;

- (id)initWithMethod:(NSString*)method;

// 操作MTOP的data参数
- (void)addParam:(NSObject*)param forKey:(NSString*)key;
- (void)removeParam:(NSString*)key;


@end
