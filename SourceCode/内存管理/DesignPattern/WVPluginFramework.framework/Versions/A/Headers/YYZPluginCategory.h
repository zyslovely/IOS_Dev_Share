/*!
 * @FILE: YYZPluginCategory.h
 * @PROJECT: YYZPlugin
 * @DESCRIPTION:
 * 加载控制插件，扩展了iOS原生的UIWebView
 *
 *  Created by 颜 垣 on 12-10-18.
 *  Copyright (c) 2012年 一淘网. All rights reserved.
 */

#import <UIKit/UIKit.h>
#import "YYZPluginProtocol.h"

#pragma mark -
#pragma mark -Enum_Define

/*!
 * 请求分发控制码
 */
enum {
    /* 标记请求是Hybrid请求 */
    ISYYZ=1,
    /* 标记请求非Hybrid请求 */
    NOTYYZ=2,
    /* 标记请求不确定，需要根据规则自动检测识别 */
    AUTOCHECKYYZ=3
};

/*!
 * 请求缓存策略控制码
 */
enum {
    /* 标记总是从网络请求 */
    YYZALWAYSNET=1,
    /* 标记使用缓存，缓存无过期时间，如果不存在缓存则从网络请求 */
    YYZALWAYSCACHEELSENET=2,
    /* 标记使用缓存请求，但是缓存带有过期时间，如果过期，则从网络请求 */
    YYZCACHEWITHEXPIRED=3
};

#pragma mark -
#define mark -Interface_Define

/*!
 * 针对UIWebview的Category
 */
@interface UIWebView (YYZUIWebView) <YYZPluginProtocol>

/*!
 * 单例
 */
+ (id) instance;

/*!
 * 检测是否是需要加载控制的请求
 */
- (BOOL) isYYZRequest: (NSString *) url;

/*!
 * 获取请求地址
 */
- (NSString *) getRequestUrl;

/*!
* 根据传入的本地地址获取真实请求的远程地址，本地地址是Hybrid插件生成的特定格式地址，如果非法，则原值返回
*/
/************* [v2.0 删除] ***************
+ (NSString *) getRealRequestUrl:(NSString *) requestUrl
*/

/*!
 * 加载本地的正在请求请稍后的提示页面
 */
- (void) loading;

/*!
 * 加载本地的正在请求请稍后的提示页面，指定地址
 */
- (void) loading:(NSString *) targetUrl;

/*!
 * 加载本地提示页面加载错误的提示页面
 */
- (void) load404:(NSString *) targetUrl;

/*!
 * 判断请求地址是否是正在加载中提示页面
 */
/************* [v2.0 增加] ***************/
- (BOOL) isLoadingPage:(NSString *) url;
/**/

/*!
 * 增加针对url的post和get请求方式，为兼容post请求下的waplugin插件而生，其他情况下也可以使用。
 */
/************* [v2.1 增加] ***************/
- (void)loadUrl:(NSString*)url isPost:(BOOL)isPost;

/*!
 * 是否是安全请求
 */
- (BOOL) isSecurityRequest;

@end
