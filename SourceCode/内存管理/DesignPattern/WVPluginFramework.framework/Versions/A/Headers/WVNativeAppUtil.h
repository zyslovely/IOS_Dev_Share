//
//  WVNativeAppUtil.h
//  YYZPlugin
//
//  Created by 颜 垣 on 13-9-5.
//  Copyright (c) 2013年 颜 垣. All rights reserved.
//
#import "YYZFileUtil.h"

@interface WVNativeAppUtil : YYZFileUtil

/*!
 * 获取安装基础路径
 */
+ (NSString *) getWVNativeAppBasePath;

/*!
 * 获取APP安装路径
 */
+ (NSString *) getWVNativeAppInstallPath : (NSString *) appName withSeqId:(NSString *) seqId;

/*!
 * 获取APP配置文件路径
 */
+ (NSString *) getWVNativeAppConfigFilePath : (NSString *) appInstallPath;

/*!
 * 获取安装文件夹名称
 */
+ (NSString *) getWVNativeAppFolderName : (NSString *) appName withSeqId:(NSString *) seqId;

/*!
 * 检测当前APP是否正在下载
 */
+ (BOOL) isWVNativeUpdateDownLoading:(NSString *) seqId;

/*!
 * 标记当前APP正在下载
 */
+ (void) wvNativeStartUpdateDownLoad:(NSString *) seqId;

/*!
 * 标记当前APP完成下载
 */
+ (void) wvNativeEndUpdateDownLoad:(NSString *) seqId;

/*!
 * 获取当前APP的配置文件的KEY对应的项目值
 */
+ (NSDictionary *) currentWVNativeAppConfig:(NSString *) requestURL;

/*!
 * 获取指定APP上下中KEY对应的项目值
 */
+ (NSString *) getWVnativeAppConfigForKey:(NSString *) key withContext:(NSDictionary *) context;

@end
