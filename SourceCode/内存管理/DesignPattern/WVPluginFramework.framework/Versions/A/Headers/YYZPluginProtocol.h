/*! 
* @FILE: YYZPluginProtocol.h
* @PROJECT: YYZPlugin
* @DESCRIPTION:
* Hybrid插件必须要实现的协议
* 使用协议的目的是在协作开发过程中，明确需要完成的对外API
*
*  Created by 颜 垣 & 叔敖 on 12-10-18.
*  Copyright (c) 2012年 一淘网. All rights reserved.
*/

#import <Foundation/Foundation.h>

// 安全请求TAG参数
#define WV_REQUEST_SECURITY_TAG     @"_windvanesec"
#define WV_REQUEST_SECURITY_SALT    @"_&^*(#$@!_1234567890_Y_WINDVANE_Alibaba"

#pragma mark-YYZCacheOption

/************* [v2.0.1 新增：服务于不接受配置的客户端请求] ***************/
/*!
 * 缓存配置项结构体
 */
typedef struct YYZCacheOption {
    // 缓存时间长度（秒）
    int cacheSeconds;
    // 是否缓存HTML代码中的图片
    BOOL isSaveImg;
    // 缓存的当前HTML代码中的图片最大个数
    int saveImgMaxCount;
    // 是否客户端主动去头去尾
    BOOL isRemoveHeaderFooter;
} YYZCacheOption;
/**/

#pragma mark-YYZPluginProtocol

@protocol YYZPluginProtocol <NSObject>

/*!
 * 加载请求
 * @request : 请求对象
 * @isYYZPageRequest: 当前request对象请求的是否是Hybrid的页面，
 *   ISYYZ:确认是，
 *   NOTYYZ:确认不是，
 *   AUTOCHECKYYZ:该函数内部会自动根据规则判断当前传入的request是否是Hybrid的请求
 * @setCacheStrage : 设置缓存策略
 *   YYZALWAYSNET:总是从网络下载
 *   YYZALWAYSCACHEELSENET:总是从缓存获取，只有缓存不存在才会去网络下载
 *   YYZCACHEWITHEXPIRED:优先从缓存获取，如果缓存不存在或者过期，则从网络下载
 * @isCountPV : 是否弥补因为缓存带来的PV/UV损失，如果补偿，则会发送一次请求到服务器
 */
@required
- (BOOL) loadRequest:(NSURLRequest *)request isYYZPageRequest:(int)isYYZpage setCacheStrage:(int) cacheStrage setIsCountPV:(BOOL)isCountPV;

/************* [v2.0.1 新增：服务于不接受配置的客户端请求] ***************/
/*!
 * 附带设定缓存参数，加载请求
 * @withCacheOption: see YYZCacheOption
 */
@required
- (BOOL) loadRequest:(NSURLRequest *)request withCacheOption:(YYZCacheOption) option setIsCountPV:(BOOL)isCountPV;
/**/

/*!
 * 初始化Hybrid插件
 */
@required
- (void) initYYZModule;

@end
