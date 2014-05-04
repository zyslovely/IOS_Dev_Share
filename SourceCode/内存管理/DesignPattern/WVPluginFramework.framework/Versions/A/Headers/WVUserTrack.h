/**
*  WVUserTrack.h
*  YYZPlugin
*
*   数据埋点服务，专门针对于加载错误的埋点，用于计算webview的可用性
*
*  Created by 颜 垣 on 13-6-6.
*  Modified by 颜 垣 on 13-9-4.
*  Copyright (c) 2013年 颜 垣. All rights reserved.
*/

#import <Foundation/Foundation.h>

@interface WVUserTrack : NSObject

/*!
 * 单例模式
 */
+ (id) instance;

/*!
 * 初始化本地模块
 */
- (void) buildUserTrack;

/*!
 * 记录ERROR，调用之前，请确保客户端已经初始化过UserTrack
 */
- (void) notifyPageLoadError:(NSError *) error;

/*!
 * 主动数据埋点，调用之前，请确保客户端已经初始化过UserTrack
 */
- (void) notifyDataTrack:(NSString *) arg1 withArg2:(NSString *) arg2 withArg3:(NSString *) arg3;

/*!
 * 主动数据埋点，调用之前，请确保客户端已经初始化过UserTrack
 */
- (void) notifyDataTrackWithEventId:(int)eventId withArg1:(NSString *)arg1 withArg2:(NSString *)arg2 withArg3:(NSString *)arg3;

/*!
 * 主动数据埋点，调用之前，请确保客户端已经初始化过UserTrack
 */
- (void) notifyDataTrackWithEventId:(int)eventId arg1:(NSString *)arg1 arg2:(NSString *)arg2 arg3:(NSString *)arg3 args:(NSDictionary *) dict;

/*!
 * 主动数据埋点，调用之前，请确保客户端已经初始化过UserTrack
 */
- (void) notifyDataTrackWithEventId:(NSObject *)page eventID:(int)eventId arg1:(NSString *)arg1 arg2:(NSString *)arg2 arg3:(NSString *)arg3 args:(NSDictionary *) dict;

@end

/*
 * 数据提交API 协议
 */
@protocol UTProcol <NSObject>

/*
 * 数据提交协议方法
 */
+ (void)commitEvent:(int)eventId arg1:(NSString *)arg1 arg2:(NSString *)arg2 arg3:(NSString *)arg3;

/*
 * 数据提交协议方法 - II
 */
+ (void)commitEvent:(int)eventId arg1:(NSString *)arg1 arg2:(NSString *)arg2 arg3:(NSString *)arg3 args:(NSDictionary *) dict;

/*
 * 数据提交协议方法 - III
 */
+ (void)commitEvent:(NSObject *)page eventID:(int)eventID arg1:(NSString *)arg1 arg2:(NSString *)arg2 arg3:(NSString *)arg3 args:(NSDictionary *) dict;

@end
