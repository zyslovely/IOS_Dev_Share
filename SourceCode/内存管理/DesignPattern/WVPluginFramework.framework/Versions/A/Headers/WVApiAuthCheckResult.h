//
//  WVApiAuthCheckResult.h
//  YYZPlugin
//
//  Created by 颜 垣 on 14-1-16.
//  Copyright (c) 2014年 颜 垣. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WVApiAuthCheckResult : NSObject

// 是否允许
@property (nonatomic, assign) BOOL isPermitted;

// 错误信息
@property (nonatomic, strong) NSDictionary * errorInfo;

@end
