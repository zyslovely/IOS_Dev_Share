/*!
 *  WVUserConfig.h
 *  YYZPlugin
 *  需要使用方自己配置的项目
 *
 *  Created by 颜 垣 on 13-5-22.
 *  Copyright (c) 2013年 颜 垣. All rights reserved.
 */

#import "YYZGlobalContext.h"

// 默认的TTID值
#define YYZ_DEFAULT_TTID    [NSString stringWithFormat:@"windvane@ios_%@", WINDVANE_VERSION]

//通过reachablity的网络状态设定延时，针对UI的延时应该统一用一个，不然其实还是在加载。另外下拉刷新不影响滑动和点击。
#define LOADING_TIMEOUT_WWAN 40.0f
#define LOADING_TIMEOUT_WIFI 20.0f

/** 环境设置 */
typedef enum {
    WVEnvironmentDebug =  0,     /**< 枚举，预发环境 */
    WVEnvironmentDaily,          /**< 枚举，日常环境 */
    WVEnvironmentRelease         /**< 枚举，正式环境 */
} WVEnvironment;

#import <Foundation/Foundation.h>

@interface WVUserConfig:NSObject

/*!
 * 设置APP Secret 和 APP Key
 */
+(void)setAppKey:(NSString*)key secrect:(NSString*)secrect;

/*!
 * 读取APP Key
 */
+ (NSString *)appKey;

/*!
 * 读取APP Secret
 */
+ (NSString *)appSecrect;

/*!
 * 设置TTID
 */
+ (void) setTTid:(NSString *) ttid;

/*!
 * 读取TTID
 */
+ (NSString *) ttid;

/*!
 * 是否使用黑匣子
 */
+ (void)useSafeSecert:(BOOL)isUse;

/*!
 * 判断是否使用黑匣子
 */
+ (BOOL)isUseSafeSecert;

/*!
 * 设置环境类型
 */
+ (void)setEnvironment:(WVEnvironment)environment;

/*!
 * 获取环境类型
 */
+ (WVEnvironment)environment;

/*!
 * 读取sid
 */
+ (NSString *) sid;

/*!
 * 设置sid，当客户端登陆成功后，请设置该sid
 */
+ (void)setSid:(NSString *) sid;

/*!
 * 读取eCode，用于mtop的eCode签名过程
 */
+ (NSString *) eCode;

/*!
 * 设置eCode，当客户端登陆成功后，请设置该eCode
 */
+ (void) setEcode:(NSString *) eCode;

/*!
 * 打开日志输出
 */
+ (void) openWindVaneLog;

/*!
 * 判断日志输出开关
 */
+ (BOOL) isOpenWindVaneLog;

/*!
 * 读取nickName
 */
+ (NSString *) nickName;

/*!
 * 设置nickName，当客户端登陆成功后，请设置该nickName
 */
+ (void)setNickName:(NSString *) nickName;

/*!
 * 设置客户端的名称
 */
+ (void) setAppName:(NSString *) appName;

/*!
 * 设置客户端的版本号
 */
+ (void) setAppVersion:(NSString *) appVersion;

/*!
 * 客户端的名称
 */
+ (NSString *) appName;

/*!
 * 客户端的版本号
 */
+ (NSString *) appVersion;

/*!
 * 设置客户端的补充UA,会跟在windvane UA的后面
 */
+ (void) setAppUA:(NSString *) appUA;

/*!
 * 客户端的UA
 */
+ (NSString *) appUA;

@end