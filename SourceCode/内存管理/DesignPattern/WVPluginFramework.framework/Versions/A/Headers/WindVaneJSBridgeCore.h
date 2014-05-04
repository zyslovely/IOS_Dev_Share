//
//  WindVaneJSBridgeCore.h
//  YYZPlugin
//
//  Created by 颜 垣 on 14-2-26.
//  Copyright (c) 2014年 颜 垣. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#pragma mark-全局开关

// 是否开启动态JSBridge服务
#define WINDVANE_JSBRIDGE_OPEN_DYNAMIC_MODAL    YES

#pragma mark-常用宏定义

/** 返回JSON字段: 状态码 **/
#define MSG_RESULT_CODE_NAME        @"ret"
/** 返回JSON字段: 返回值 **/
#define MSG_RESULT_VALUE_NAME       @"value"

/** 成功返回 **/
#define MSG_RET_SUCCESS     @"HY_SUCCESS"
/** 失败返回 **/
#define MSG_RET_FAILED      @"HY_FAILED"
/** 关闭 **/
#define MSG_RET_CLOSE       @"HY_CLOSED"
/** 发生异常 **/
#define MSG_RET_EXP         @"HY_EXCEPTION"
/** 参数错误 **/
#define MSG_RET_PARAM_ERR   @"HY_PARAM_ERR"
/** 无此服务 **/
#define MSG_RET_NO_HANDLER  @"HY_NO_HANDLER"
/** 权限禁止 **/
#define MSG_RET_NO_PERMIT   @"HY_NO_PERMISSION"

#pragma mark-Define JSBridge Block

// 定义回写方法类型（执行码, 回写数据）
typedef void (^YYZJSBResponse)(NSString * code, NSDictionary * responseData);
// 定义服务处理器类型(入参, 回写数据)
typedef void (^YYZJSBHandler)(id data, YYZJSBResponse yyzJSBResponseCallback);

// 定义新的服务处理器类型 - [4.0.0]
typedef void (^WVJSBHandler)(id data, YYZJSBResponse yyzJSBResponseCallback, UIViewController * sourceViewController, UIWebView * webView);
// 定义释放服务处理器类型 - [4.0.0]
typedef void (^WVJSBResetHandler)(UIViewController * sourceViewController, UIWebView * webView);
// 定义销毁服务处理器类型 - [4.0.0]
typedef void (^WVJSBDeallocHandler)(UIViewController * sourceViewController, UIWebView * webView);

@interface WindVaneJSBridgeCore : NSObject

+ (NSString *) parseJSBHandlerName:(NSURLRequest *)_request;
+ (NSString *) parseJSBHandlerIfid:(NSURLRequest *)_request;
+ (NSString *) parseJSBHandlerClassName:(NSURLRequest *)_request;
+ (NSString *) parseJSBHandlerParam:(NSURLRequest *)_request;

@end

/*
 * WindVaneAPIAuthCheckProtocol
 */
@class WVApiAuthCheckResult;
@protocol WindVaneAPIAuthCheckProtocol <NSObject>

/*
 * 验权AOP
 */
@optional
- (WVApiAuthCheckResult *) apiAuthCheck:(NSString *) className withMethod:(NSString *) method withParam:(id) data;

@end
