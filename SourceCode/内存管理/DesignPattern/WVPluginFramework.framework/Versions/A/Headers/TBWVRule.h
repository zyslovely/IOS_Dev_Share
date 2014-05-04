//
//  TBWVRule.h
//  YYZPlugin
//
//  通信规则类型
//  Created by 颜 垣 on 13-5-23.
//  Copyright (c) 2013年 颜 垣. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBWVRuleCoreData.h"

@interface TBWVRule : NSObject

// 目标
@property NSInteger target;
// 方式
@property TBWVRuleType ruleType;
// 适用于正则：总匹配数字
@property int totalMatchCount;
// 适用于正则：目标参数下标 
@property (retain, nonatomic) NSString * indexOfPattern;
// 适用于参数：参数名称
@property (retain, nonatomic) NSString * nameOfParam;
// 适用于正则：正则表达式
@property (retain, nonatomic) NSRegularExpression * pattern;
// 是否decode参数
@property int isNeedDecode;

@end
