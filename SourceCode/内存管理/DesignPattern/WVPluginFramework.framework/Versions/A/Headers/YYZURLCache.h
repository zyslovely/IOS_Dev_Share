/*!
 * @FILE: YYZURLCache.h
 * @PROJECT: YYZPlugin
 * @DESCRIPTION:
 * 通用缓存，只缓存JS和CSS文件，具体的规则将有服务端推送
 * 推送的规则可以配置的内容：
 * 资源匹配格式：资源的类型、版本
 * 如果不配置版本，则默认只有一个版本，如果配置了版本，则资源在本地的存储将带有版本标记
 *
 * [ATTENTION!!!] : IOS 4.x 版本将不起作用，内部实现已经屏蔽了IOS 4.x的系统，即便使用也不会报错
 *
 *  Created by 颜 垣 on 12-11-30.
 *  Copyright (c) 2012年 一淘网. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "URLCacheRuleCheckResult.h"
#import "WVURLCACHEASIHttpRequest.h"
#import "WVCacheStatistics.h"

/*@
 * 任何的继承于YYZURLCache的Cache处理器，都需要主动实现该方法
 */
@protocol WebViewNSURLCacheProtocol <NSObject>

/*!
 * 强依赖：当前请求本缓存处理器是否能够进行处理
 */
@required
- (URLCacheRuleCheckResult *) checkURLCacheRule:(NSURLRequest *) request;

@end

/*@
 * YYZURLCache
 */
@interface YYZURLCache : NSURLCache <WebViewNSURLCacheProtocol>

/*!
 * 单例
 */
+ (id) instance;

/*!
 * 初始化
 */
- (void) initCache;

/*!
 * 处理预置资源
 */
- (void) processPrePackageRes;

/*!
 * 清理缓存
 */
- (void) removeAllCachedResponses;

/*!
 * 清理内存+磁盘内存
 */
- (void) removeAllCachedResponsesInMemAndSD;

/*!
 * 动态的增加一条规则到字典
 */
+ (void) addDynamicRuleForWebApp:(NSString *) rule;

/*!
 * 读取资源，子类可通过重写该方法完成自己资源下载/读取的过程
 * 如果资源已经存在于本地，则会直接返回
 * 如果资源需要网络下载，则不会直接返回，而是会使用delegate返回，请参见 <WVURLRequest>
 */
- (NSCachedURLResponse *) getResource:(NSURLRequest *)request withCheckResult:(URLCacheRuleCheckResult *) checkResult;

/*!
 * 从网络读取资源
 * @request：请求
 * @checkResult：规则检查结果
 * @completeCallback：成功完成的回调
 * @failedCallback：失败完成的回调
 * @withHeader：请求资源是否带有头字段，如果不带头字段，可以禁止304发生
 */
- (void) getResourceFromNet:(NSURLRequest *)request withCheckResult:(URLCacheRuleCheckResult *) checkResult withComplete:(WVCacheDownloadComplete) compelteCallback withFailed:(WVCacheDownloadFailed) failedCallback withHeader:(BOOL) withHeader;

/*!
 * 清理某个请求的内存+磁盘内存
 */
- (void) removeCachedResponseForRequest:(NSURLRequest *)request;

/*!
 * 判断某个请求是否存在本地缓存
 * @request：请求
 * @checkResult：本地规则的执行结果，如果存在则传入，如果不存在，则传nil
 */
- (NSCachedURLResponse *) checkIsExisteLocalCacheForReqeust:(NSURLRequest *) request withCheckResult:(URLCacheRuleCheckResult *) checkResult;

/*!
 * 主动将返回数据存储于内存中
 * mimeType:
 *  js|css|png|jpg|jpeg|gif|htm|html
 */
+ (void) storeResponseForRequest:(NSURLRequest *) request withResponseData:(NSData *) data withMIMEType:(NSString *) mimeType;

#pragma mark-
#pragma mark- 子类继承规范方法

/*!
 * [自定义处理器子类必须实现/建议内部也调用super] 校验请求是否是缓存模块会处理的地址
 */
- (URLCacheRuleCheckResult *) checkURLCacheRule:(NSURLRequest *) request;

/*!
 * [自定义处理器子类必须使用该方法返回成功结果]返回成功缓存的结果
 */
- (NSCachedURLResponse *) returnSuccessNSCachedURLResponse:(NSCachedURLResponse *) response forRequest:(NSURLRequest *) request withReadFromType:(WVRESOURCE_READ_FROM) readFrom;

/*!
 * [自定义处理器子类必须使用该方法返回失败结果]返回失败缓存的结果
 */
- (NSCachedURLResponse *) returnFailedNSCachedURLResponse:(NSCachedURLResponse *) response forRequest:(NSURLRequest *) request withError:(NSError *) error;

#pragma mark-
#pragma mark-过期方法

/*!
 * [自定义处理器子类必须使用该方法返回成功结果]返回成功缓存的结果
 */
- (NSCachedURLResponse *) returnSuccessNSCachedURLResponse:(NSCachedURLResponse *) response forRequest:(NSURLRequest *) request  __attribute__((deprecated));

@end
