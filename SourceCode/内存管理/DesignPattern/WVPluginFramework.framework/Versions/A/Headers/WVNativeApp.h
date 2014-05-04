/*********************************************************************************
 *#.......#.......#..###...#....#...#.#.#....#.......#.....#......#....#...#.#.#.*
 *.#.....#.#.....#....#....#.#..#...#.....#...#.....#.....#.#.....#.#..#...#.....*
 *..#...#...#...#.....#....#..#.#...#.....#....#...#.....#...#....#..#.#...#.#.#.*
 *...#.#.....#.#......#....#...##...#.....#.....#.#.....#.#.#.#...#...##...#.....*
 *....#.......#......###...#....#...#.#.#........#.....#.......#..#....#...#.#.#.*
 *-------------------------------------------------------------------------------*
 *
 * WVNativeApp.h
 *
 * 用户处理文件都存放在本地的App管理器, 提供的皆为原子方法。向上层提供安装、下载、启动、关闭功能.
 *
 * 代码执行推荐逻辑：
 *  IF 已经安装过APP
 *      THEN 执行APP;
 *  ELSE
 *      动态下载安装APP;
 *  END
 *  检查APP更新;
 *
 *  [特别的]当前版本不支持多APP同时运行，请分别调用Start和Stop进行APP的运行环境切换.
 *
 * Created by 颜 垣 on 13-9-5.
 * Copyright (c) 2013年 颜 垣. All rights reserved.
 ******************************************************/

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#pragma mark -
#pragma mark -Enum-Define

// 安装结果返回值类型
typedef enum {
    // 安装成功
    WV_NP_SUCCESS,
    // 已经安装过，无需安装
    WV_NP_ALREADY_INSTALLED,
    // 安装失败
    WV_NP_FAILED,
    
    // 更新成功
    WV_NP_UP_SUCCESS,
    // 更新失败
    WV_NP_UP_FAILED
} WV_INSTALL_RESULT;

// 检查更新结果返回值类型
typedef enum {
    // 需要升级
    WV_NEED_UPDATE,
    // 需要升级，并且是因为本地文件损坏导致的需要升级
    WV_NEED_UPDATE_LOCAL_BROKEN,
    // 需要升级Native客户端
    WV_NEED_UPDATE_NATIVE,
    // 不需要升级
    WV_NO_NEED_UPDATE
} WV_UPDATE_CHECK_RESULT;

#pragma mark -
#pragma mark -WVAppInstallCallback

// 下载完成后的回调处理
typedef void (^WVAppInstallCallback) (WV_INSTALL_RESULT result);
// 检查是否需要更新的回调处理 updateURL:如果需要升级webapp则为webapp的下载链接;如果需要升级Native则为native的下载链接
typedef void (^WVAPPUpdateCallback) (WV_UPDATE_CHECK_RESULT result, NSString * updateURL);

#pragma mark -
#pragma mark -WVNativeApp

@interface WVNativeApp : NSObject

/*!
 * 单例
 */
+ (id) instance;

/*!
 * 初始化
 * @nativeAppVersion : 传递本地客户端的版本
 */
- (void) initWVNativeApp:(NSString *) nativeAppVersion;

/*!
 * 初始化，并且禁止使用webview的reload行为
 * @nativeAppVersion : 传递本地客户端的版本
 */
- (void) initWVNativeApp:(NSString *)nativeAppVersion withForbiddenRereload:(BOOL) forbidden;

/*!
 * 是否已经安装APP
 * @appName: 安装软件名称
 * @seqId：安装软件的唯一性标记，如果该字段不支持，可以使用 WV_NP_SEQ_ID_DEFAULT
 */
- (BOOL) isInstalledApp:(NSString *) appName withSeqId:(NSString *) seqId;

/*!
 * 安装APP
 * @appName: 安装软件名称
 * @seqId：安装软件的唯一性标记，如果该字段不支持，可以使用 WV_NP_SEQ_ID_DEFAULT
 * @progressView：进队条指针
 * @downloadUrl：下载地址，如果本地不存在安装包，则自动从该地址下载
 * @callback：安装结果的回调
 */
- (void) installWVNativeApp:(NSString *) appName withAppSeqId:(NSString *) seqId withProgrossView:(UIProgressView *) progressView withDownLoadUrl:(NSString *) downloadUrl withInstallCallback:(WVAppInstallCallback) callback;

/*!
 * 检查是否需要升级
 * @appName: 安装软件名称
 * @seqId：安装软件的唯一性标记，如果该字段不支持，可以使用 WV_NP_SEQ_ID_DEFAULT
 * @callback：检查结果回调
 */
- (void) checkWVNativeAppNeedUpdate:(NSString *) appName withAppSeqId:(NSString *) seqId withUpdateCallback:(WVAPPUpdateCallback) callback;

/*!
 * 启动升级WebAPP，调用本方法前必须先调用 checkWVNativeAppNeedUpdate
 * @appName: 安装软件名称
 * @seqId：安装软件的唯一性标记，如果该字段不支持，可以使用 WV_NP_SEQ_ID_DEFAULT
 * @progressView：进队条指针
 * @callback：更新结果回调
 */
- (void) updateWVNativeApp:(NSString *) appName withSeqId:(NSString *) seqId withProcessView:(UIProgressView *) progressView withDownloadUrl:(NSString *) downLoadURL withUpdateCallback:(WVAppInstallCallback) callback;

/*!
 * 升级完成，切换APP到最新版本
 * @appName: 安装软件名称
 * @seqId：安装软件的唯一性标记，如果该字段不支持，可以使用 WV_NP_SEQ_ID_DEFAULT
 */
- (BOOL) switchToNewVersion:(NSString *) appName withSeqId:(NSString *) seqId;

/*!
 * 启动APP
 * @appName: 安装软件名称
 * @seqId：安装软件的唯一性标记，如果该字段不支持，可以使用 WV_NP_SEQ_ID_DEFAULT
 * @viewController：target controller
 */
- (BOOL) startWVNativeApp:(NSString *) appName withAppSeqId:(NSString *) seqId withTarget:(id) viewController;

/*!
 * 停止APP
* @viewController：target controller
 */
- (void) stopWVNativeApp:(NSString *) appName withAppSeqId:(NSString *) seqId WithTarget:(id) viewController;

/*!
 * 当前运行的APP的上下文环境
 */
+ (NSArray *) runningWVNativeAppContext;

/*!
 * 卸载APP
 * @appName: 安装软件名称
 * @seqId：安装软件的唯一性标记，如果该字段不支持，可以使用 WV_NP_SEQ_ID_DEFAULT
 */
- (BOOL) uninstallNativeApp:(NSString *) appName withSeqId:(NSString *) seqId;

/*!
 * 回滚到上一个版本，只能回滚一次
 * @appName: 安装软件名称
 * @seqId：安装软件的唯一性标记，如果该字段不支持，可以使用 WV_NP_SEQ_ID_DEFAULT
 */
- (BOOL) revertNativeAppToLastVersionWithAppName:(NSString *) appName withSeqId:(NSString *) seqId;

@end