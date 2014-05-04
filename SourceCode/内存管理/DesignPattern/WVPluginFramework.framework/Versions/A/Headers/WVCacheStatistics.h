//
//  WVCacheStatistics.h
//  YYZPlugin
//
//  Created by 颜 垣 on 14-2-27.
//  Copyright (c) 2014年 颜 垣. All rights reserved.
//

#import <Foundation/Foundation.h>

// 类型定义 - 资源读取来源
typedef enum {
    WV_READ_FROM_DEFAULT    =   0,
    WV_READ_FROM_BROWSER    =   1,
    WV_READ_FROM_MEMORY     =   2,
    WV_READ_FROM_FILE       =   3,
    WV_READ_FROM_NETWORK    =   4,
    WV_READ_FROM_CUSTOME    =   5
} WVRESOURCE_READ_FROM ;

@interface WVCacheStatistics : NSObject

// 总请求数量
@property (nonatomic, assign) long      requestTotalCount;
// 总处理
@property (nonatomic, assign) long      processCount;
// 浏览器处理
@property (nonatomic, assign) long      browserCount;
// 内存处理
@property (nonatomic, assign) long      memoryCount;
// 磁盘处理
@property (nonatomic, assign) long      fileCount;
// 网络处理
@property (nonatomic, assign) long      networkCount;
// 浏览器容量
@property (nonatomic, assign) double    browserCacheSize;
// 内存容量
@property (nonatomic, assign) double    memoryCacheSize;
// 磁盘容量
@property (nonatomic, assign) double    fileCacheSize;
// 网络容量
@property (nonatomic, assign) double    networkCacheSize;
// 插件启动
@property (nonatomic, assign) int       h5pluginCount;
// 创建时间
@property (nonatomic, assign) double    gmtCreate;
// 清理任务
@property (nonatomic, assign) BOOL      isClearTaskDone;
// 命中缓存率
@property (nonatomic, assign) double    firedCachePercent;

/*!
 * markClearTaskDone
 */
+ (void) markClearTaskDone;

/*!
 * markClearTaskDone
 */
+ (void) addRequestTotalCount;

/*!
 * fetchCurrentStaticsticsContext
 */
+ (WVCacheStatistics *) fetchCurrentStaticsticsContext;

/*!
 * addCacheStatistics
 */
+ (void) addCacheStatistics:(float) size withRequestURL:(NSString *) requestURL withReadFrom:(WVRESOURCE_READ_FROM) readFrom;

/*!
 * addWVPluginOpenStaticstics
 */
+ (void) addWVPluginOpenStaticstics:(NSString *) pluginName;

/*!
 * sendCacheStaticstics
 */
+ (void) sendCacheStaticstics;

@end
