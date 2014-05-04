//
//  NSObject+WVJSBridgeInterface.h
//  WindVaneDemo
//
//  Created by 颜 垣 on 14-2-26.
//  Copyright (c) 2014年 颜 垣. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "WindVaneJSBridgeCore.h"

#pragma mark-提供对外的宏

/********************************************************
    [输出类使用] 提供给输出类使用的动态JSBridge的功能宏
 ********************************************************/

/*
 * [Function] 输出类的实现方法内部用于返回结果给JS的宏
 *
 * CALLBACK :[YYZResponse]  JSBridge的回调方法
 * RET      :[NSString]     返回给JS的状态Code
 * RESULT   :[ID]           返回给JS的结果值
 */
#define WV_JSB_CALLBACK(CALLBACK,RET,RESULT) \
[[self class] WVJSBridgeInterface$callback:CALLBACK withRet:RET withResult:RESULT];

/*
 * [Function] 禁止当前方法被输出给动态JSBridge的宏
 *
 * METHOD:[SEL] 禁止输出方法的访问器对象
 */
#define WV_JSB_FORBIDDEN_EXPORT(METHOD)     \
[[self class] WVJSBridgeInterface$forbiddenThisMethodToJSB:METHOD];

/*
 * [Function] 主动的释放服务
 */
#define WV_JSB_RELEASE_SERVICE \
[self WVJSBridgeInterface$release];

// -----------------------------------------------------------------------------------//

#pragma mark-WVJSBridgeInterfaceProtocol

/** [PUBLIC: 动态JSBridge提供给输出类的实现方法，实现类重写相关方法来完成AOP逻辑切入] **/
@protocol WVJSBridgeInterfaceProtocol <NSObject>

/*!
 * 实例化 - 必须实现 - 否则JSBridge 不会将其输出为服务
 */
@required
+ (id) instance;

/*!
 * 鉴权 - 选择性实现
 *
 * method:      输出方法SEL
 * params:      输出方法的参数
 * documentURL: 当前WebView中页面的地址
 * token:       备用值
 */
@optional
+ (BOOL) judgementAuth:(SEL) method withParam:(id) params withDocumentURL:(NSString *) documentURL withToken:(NSString *) token withWebView:(UIWebView *) webview;

/*!
 * 释放处理器
 */
@optional
+ (void) releaseInstance;

@end

// -----------------------------------------------------------------------------------//

#pragma mark-WVJSBridgeInterface

/** [PRIVATE: 动态JSBridge的私有实现，不允许直接调用] **/
@interface NSObject (WVJSBridgeInterface) <WVJSBridgeInterfaceProtocol>
// 返回结果
+ (void) WVJSBridgeInterface$callback:(YYZJSBResponse) callback withRet:(NSString *) ret withResult:(id) result;
// 禁止输出
+ (void) WVJSBridgeInterface$forbiddenThisMethodToJSB:(SEL) method;
// 鉴权调用
+ (BOOL) WVJSBridgeInterface$judgementCannotUseThisMethod:(SEL) method withParam:(id) params withDocumentURL:(NSString *) documentURL withToken:(NSString *) token withWebView:(UIWebView *) webview;
// 释放处理
- (void) WVJSBridgeInterface$release;

@end

#pragma mark-教程

// 具体的教程可以参考WindVane的版本正式文档，此处作为快捷上手帮助
/*
 * [STEP 1] 在你要输出为服务的类头文件引入 NSObject+WVJSBridgeInterface.h 你的类只需要继承于NSObject即可
 *
 * [STEP 2] 提供一个instance方法，返回你的对象实例，具体的函数定义参见 WVJSBridgeInterfaceProtocol
 *
 * [STEP 3] 如果你要做API的调用权限控制，请重写方法
 *          judgementAuth:withParam:withDocumentURL:withToken:,参见 WVJSBridgeInterfaceProtocol
 *          如果不提供自己的权限策略，则使用默认策略，你无须关心
 *
 * [STEP 4] 你要输出的方法的命名需要遵循规范：
 *          · 函数的入参必须为 xxx:(NSDictionary *) wealth xxx:(YYZJSBResponse) callback xxx:(UIWebView *) webview,
 *            第一个参数为DIC,
 *            第二个参数为JSBridge注入的Block对象类型,
 *            第三个参数为UIWebView类型
 *
 * [STEP 5] 如果你不希望某个方法被输出为JSBridge的方法，那么请使用 WV_JSB_FORBIDDEN_EXPORT(SEL)
 *
 * [STEP 6] 在你的方法中，使用 WV_JSB_CALLBACK(CALLBACK,RET,RESULT) 来输出你的结果给前端页面JS
 *
 * [特别的]  可能你提供的服务带有多个阶段输出性，请使用JS事件的方式将结果输出给前端JS
 */

// -------------------------------------------------------------------------------------------- //

/*
 * [设计想法] 为什么不直接设计成反射调用任意代码，并且OC不需要遵循任何规则?
 *
 *  其实对于前端页面和客户端具体编码的实现者而言比较好的设计方式是按照常规的习惯来编写OC代码，然后容器可以自动的通过
 *  反射的方式来调用任何的部分，当方法采用直接return的方式，那么则为同步输出，如果是异步的方式，则为异步输出。
 *  在技术上没有问题，但是在安全上缺存在着很大的漏洞隐患。一旦外部代码安全AOP拦截器逻辑出现bug，那么很可能系统的任何
 *  的类和方法，都能够被前端JS直接调用，尤其是下单和session相关数据的获取接口。
 *  所以，综合以上多种因素考虑，目前还是需要客户端OC实现者在编写输出方法的时候来遵循一定的规则和主动的调用一些方法。
 */