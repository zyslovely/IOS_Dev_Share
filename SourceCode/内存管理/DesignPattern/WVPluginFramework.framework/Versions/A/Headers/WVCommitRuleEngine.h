//
//  WVCommitRuleEngine.h
//  YYZPlugin
//
//  通信规则模块
//
//  Created by 颜 垣 on 13-5-23.
//  Copyright (c) 2013年 颜 垣. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBWVRuleCoreData.h"
#import "TBWVRule.h"
#import "TBRuleResult.h"

@interface WVCommitRuleEngine : NSObject

// 是否正在执行初始化行为
@property (assign, atomic) BOOL initing;

/*!
 * 单例
 */
+ (id) instance;

/*!
 * 初始化
 */
- (void) initRuleEngine;

/*!
 * 更新
 */
- (void) updateRuleEngine;

@end
