/*!
 * @FILE: YYZGlobalContext.h
 * @PROJECT: YYZPlugin
 * @DESCRIPTION:
 * Hybrid插件运行全局上下文
 * 目的是使得Hybrid插件运行过程中能够统一上下文环境，便于数值保存和传递
 *
 *  Created by 颜 垣 on 12-10-18.
 *  Copyright (c) 2012年 一淘网. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "YYGlobalContextApi.h"
#import "WVUserConfig.h"

#pragma mark-
#pragma mark-LOCK

/******************* 全局开关控制部分 *******************/

/* 定义插件的版本号 */
#define WINDVANE_VERSION @"4.0.0"

// 测试逻辑开关
static const BOOL isTest = NO;

/***/

#pragma mark-
#pragma mark-GLOBAL

// SCHEME
#define HTTP_SCHEME                 @"http://"
#define HTTPS_SCHEME                @"https://"
#define FILE_SCHEME                 @"file://"
// for JSBridge
#define PROTOCOL_SCHEME             @"hybrid://"
// for Wapplugin
#define WAPLUGIN_PROTOCOL_SCHEMA    @"waplugin://"

// 刷新页面动作的URL标记参数
#define TBWV_LOAD_TAG           @"_ovldtg=1"
// 正在加载loading页面的URL标记参数
#define YYZ_LOADING_URL_TAG     @"_tbhylding=1"

// 为全局缓存模块预留的快速标记参数，带有此标记参数的将会直接采用缓存算法
#define YYZ_URLCACHE_TAG_NAME   @"_wvcrc"
#define YYZ_URLCACHE_TAG        @"_wvcrc=1"

// SID & TTID 参数名
#define YYZ_SID_KEY         @"sid"
#define YYZ_TTID_KEY        @"ttid"

#pragma mark -
#pragma mark -Define_Static_Variable

// 时间单位值
static const int MINITE     = 60;
static const int HALF_HOUR  = MINITE * 30;
static const int HOUR       = HALF_HOUR * 2;

// 控制常量 - 默认图片存储数量/页 - 最大存储图片数量/页
static const int DEFAULT_SV_IMG_COUNT   = 5;
static const int MAX_SV_IMG_COUNT       = 20;

#pragma mark -
#pragma mark -Define_YYZ_Json

/******************* YYZ 服务端UPDATE.DO配置接口 JSON 结构字段 *******************/

// 开关
#define YYZ_LOCK                @"lock"
// 页面加载控制的URL匹配规则JSON片段的KEY
#define YYZ_URL_RULE            @"rule"
/************** [2.4 删除，接入运维系统] **************
// 预留接口:下次更新配置数据的URL
#define YYZ_CHECK_UPDATE_URL    @"updateConfigUrl"
****************************************************/
// 阿里巴巴站点的匹配的规则
#define YYZ_ALIDOMAIN_PATTERN   @"alidomain"
// 是否是从cdn获取规则
#define YYZ_CDN_FETCH_RULE      @"cdn"
// Wap页面中的资源匹配正则表达式串 - 废弃
#define YYZ_MATCH_RULE          @"match"

// 对应于每条规则配置，以藏头尾HTML代码的开关 1 为开
#define YYZ_REMOVE_HF           @"removehf"
// 对应于每条规则配置，该规则下缓存时间，秒
#define YYZ_RULE_TIME           @"time"
// 对应于每条规则配置，该规则下的页面是否缓存图片
#define YYZ_RULE_IS_SV_IMG      @"saveimg"
// 对应于每条规则配置，该规则下的页面缓存图片最大个数
#define YYZ_SV_IMG_MAX_COUNT    @"svimgmxct"
// 记录最后更新时间字段
#define YYZ_LST_CHECK           @"lstCheckTime"
// 是否关闭统计模块的开关，1为开，0为关
#define WV_DATA_STATICSTICS_L   @"statistics"

// 开关值
#define YYZ_IS_LOCK                 @"1"
#define WV_DATA_STATICSTICS_L_OPEN  @"1"
#define WV_DATA_STATICSTICS_L_CLOSE @"0"

/***/

#pragma mark -
#pragma mark -Define_YYZ

// YYZ 初始化过程字段
#define  YYZ_FOLDER                     @"yyz"
// YYZ 存储通用资源的目录
#define  YYZ_COMMON_FOLDER              @"common"
// 加载控制 & 资源清单 配置文件名称
#define  YYZ_CONFIGURATION_FILE         @"yyz.config"
// 拦截规则配置文件名称
#define  YYZ_RULE_CONFIGURATION_FILE    @"ruleconfig.config"
// 初始化ZIP包文件名称
#define  YYZ_ZIP                        @"yyz.zip"
// [v2.0 增加] 初始化资源的ZIP包文件名称
#define  YYZ_RESOURCE_ZIP               @"common.zip"
// [v2.1 增加] 存储碎片较大的资源目录
#define  YYZ_MUCH_FOLDER                @"much"

/************* [v2.0 删除] ***************
// [v2.0 删除]YYZ 全局context 需要下载的资源的列表以及最后下载时间的KEY值
static NSString * NEED_UPDATE_R = @"need_update_r";
// [v2.0 删除]YYZ 全局context 用来记录上一次下载更新文件的时间的KEY值
static NSString * YYZ_LST_DOWNLOAD = @"yyz_lst_download";
**/

// YYZ 最后清理垃圾任务启动时间
#define  YYZ_LST_CLEAR          @"lstClearTime"
// YYZ 最后规则检查时间
#define  YYZ_LST_RULE_CHECK     @"lstRuleCkTime"
// YYZ 全局context 用来记录当前磁盘文件列表的资源字典的KEY值
#define  YYZ_RESOURCE_FILES_DIC @"yyz_file_dic"

#pragma mark -
#pragma mark -Define_PageName

#define  YYZ_404        @"404.html"
#define  YYZ_LOADING    @"loading.html"

#pragma mark -
#pragma mark -Define_Pattern

// YYZ 页面资源的正则匹配表达式(5)
#define RESOURCE_PATTERN    @"(href=[\"|']|src=[\"|'])((http://[^\\s|^\\<||^\"]+\\.(css|js))([^\"|^']*))[\"|']"
// YZY 兼容匹配SEAJS的正则表达式
#define RES_PATTERN_ALL     @"(href=[\"|']|src=[\"|']|\\.use\\(\")((http://[^\\s|^\\<||^\"]+\\.(css|js))([^\"|^']*))[\"|']"

// YYZ 页面图片资源匹配正则表达式(4)
#define RESOURCE_IMG_PATTERN   @"<img\\s+([^/|^>|^<]*)\\s{0,}src=[\"|'](http://[^\"|^']*\\.(gif|png|jpg|jpeg)[^\"|^']*)[\"\'][^/|^>]*(/>|>)"

// YYZ 阿里巴巴旗下子域名匹配正则表达式
#define ALI_DOMAIN_PATTERN  @"^(http|https)://[^\\?|^#]*\\.{0,1}(taobao|tmall|juhuasuan|hitao|taobaocdn|alipay|etao|alibaba|aliyun|alimama|weibo|tanx|alicdn|tbcdn|mmstat|laiwang|lwurl|tb|jaeapp)\\.(com|cn|net|to).*"

/************* [v2.4 增加，接入运维系统] *************/
// 更新缓存规则的Mtop API 名称
#define WV_UPDATE_CACHE_RULE_API    @"mtop.taobao.windvane.getCacheRule"
// 更新拦截规则的Mtop API 名称
#define WV_UPDATE_URL_RULE_API      @"com.taobao.windvane.urlRule"
/****************************************************/

#pragma mark -
#pragma mark -InterfaceDefine

@interface YYZGlobalContext : NSObject <YYGlobalContextApi>

@end
