//
//  TBRuleResult.h
//  YYZPlugin
//
//  通信规则解析结果类型
//  Created by 颜 垣 on 13-5-23.
//  Copyright (c) 2013年 颜 垣. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBWVRuleCoreData.h"

@interface TBRuleResult : NSObject

// 目标
@property NSInteger target;
// 参数
@property (retain, nonatomic) NSDictionary * param;

@end
