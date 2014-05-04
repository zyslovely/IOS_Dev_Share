/*!
 * @FILE: YYZFileUtil.h
 * @PROJECT: YYZPlugin
 * @DESCRIPTION:
 * 本地文件路径工具类
 *
 *  Created by 颜 垣 on 12-10-18.
 *  Copyright (c) 2012年 一淘网. All rights reserved.
 */
#import <Foundation/Foundation.h>

@interface YYZFileUtil : NSObject

/*!
 * 获取APP运行目录
 */
+ (NSBundle *) mainBunddle;

/*!
 * 获取IOS的主目录
 */
+ (NSString *) getBunddlePath;

/*!
 * 获取文件名字符串的md5后的值
 */
+ (NSString *) md5:(NSString*)str;

/*!
 * 获取文件本地文件名称
 */
+ (NSString *) getFileLocalName:(NSString *) f;

/*!
 * 获取配置文件路径
 */
+ (NSString *) getConfigurationFilePath:(NSString *) bunddlePath;

/*!
 * 获取配置文件在APP内置的路径
 */
+ (NSString *) getConfigurationFileInAPP:(NSBundle *) mainBunddle;

/*!
 * 获取资源文件文件夹路径
 */
+ (NSString *) getConfigurationFolder:(NSString *) bunddlePath;

/*!
 * 传入原始URL，获取本地的资源文件文件路径
 */
+ (NSString *) getFilePath:(NSString *) bunddlePath withFileName:(NSString *) fileName;

/*!
 * 传入原始URL和版本号，获取本地的资源文件文件路径
 */
+ (NSString *) getCommonFilePath:(NSString *) bunddlePath withResourceName:(NSString *) src withVersion:(NSString *) v;

/*!
 * 获取通用资源存储路径
 */
+ (NSString *) getCommonFilePath:(NSString *) bunddlePath withResourceName:(NSString *) src;

/*!
 * 获取通用资源存储路径
 */
+ (NSString *) getCommonFilePath:(NSString *) bunddlePath withMD5Name:(NSString *) name;

/*!
 * 获取通用资源存储目录
 */
+ (NSString *) getCommonFolder:(NSString *) bunddlePath;

/*!
 * 获取大碎片类型资源存储目录
 */
+ (NSString *) getMuchFolder:(NSString *) bunddlePath;

/*!
 * 获取大碎片类型资源存储路径
 */
+ (NSString *) getMuchFilePath:(NSString *) bunddlePath withResourceName:(NSString *) src;

/*!
 * 获取大碎片类型资源存储路径
 */
+ (NSString *) getMuchFilePath:(NSString *) bunddlePath withMD5Name:(NSString *) src;

/*!
 * 获取文件创建时间长度
 */
+ (NSTimeInterval) getFileLastModifiedTime:(NSDictionary *) fileAttr;

/*!
 * 检查文件是否是保留文件
 */
+ (BOOL) checkIsStopWordFile:(NSString *) fileName;

/*!
 * 更新文件最后修改时间
 */
+ (void) updateLstModifiedTime:(NSString *) filePath;

/*!
 * 获取Documents目录
 */
+ (NSString *) getDocumentPath;

/*!
 * 设置文件的属性，拒绝被iCloud同步
 */
+ (BOOL) addSkipBackupAttributesToFile:(NSURL *) filePath;

@end
