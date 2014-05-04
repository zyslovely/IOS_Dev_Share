//
//  URLCacheRuleCheckResult.h
//  YYZPlugin
//
//  Created by 颜 垣 on 13-10-22.
//  Copyright (c) 2013年 颜 垣. All rights reserved.
//

#import <Foundation/Foundation.h>

// 资源读取来源
typedef enum {
    WV_RESOURCE_READ_FROM_LOCAL     = 100, // 需要检查更新
    WV_RESOURCE_READ_FROM_WEBKIT    = 200  // 需要下载缓存
} WVResourceReadFromType;

@interface URLCacheRuleCheckResult : NSObject
// 是否命中
@property (nonatomic, assign) BOOL isFired;
// 是否性能监控
@property (nonatomic, assign) BOOL isTrack;
// 是否需要处理
@property (nonatomic, assign) BOOL isNeedProcess;
// 是否是碎片型资源
@property (nonatomic, assign) BOOL isMuchResource;
// 命中的规则内容
@property (nonatomic, strong) NSDictionary * configItem;

/*!
 * 该规则是否是页面规则
 */
- (BOOL) isHTMLRule;

@end
