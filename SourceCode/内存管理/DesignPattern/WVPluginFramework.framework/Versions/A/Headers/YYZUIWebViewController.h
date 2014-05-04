/*!
 *  @FILE: YYZUIWebViewController.h
 *  @PROJECT: YYZPlugin
 *  @DESCRIPTION:
 *
 *  (ARC)
 *  带有顶部下拉刷新的Controller
 *
 *  Created by 颜 垣 on 13-1-7.
 *  Copyright (c) 2012年 颜 垣. All rights reserved.
 */

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import "WVRuleWebViewController.h"

@interface YYZUIWebViewController : WVRuleWebViewController

#pragma mark-
#pragma mark-功能相关属性字段

/*****************************[ 功能相关属性字段 ]***********************************/
// 加载页面的地址，默认的为loadUrl方式加载
@property (retain, nonatomic) NSString *    loadUrl;

// 是否使用LoadData方式加载，默认NO，如果设置为YES，需要重写 webViewLoadData 方法
@property (nonatomic) BOOL                  useData;

// 是否使用loadHtml方式加载，默认NO，如果设置为YES，需要重写 webViewLoadHTML 方法
@property (nonatomic) BOOL                  useHtml;
/**/

#pragma mark-
#pragma mark-UI/交互相关属性字段

/*****************************[ UI/交互相关属性字段 ]************************************/
// NavigationBar的标题
@property (retain, nonatomic) NSString *    navtitle;

// 是否使用带有前进、后退、刷新、停止基本浏览器功能的< 默认 >工具栏
@property (nonatomic) BOOL                  isUseToolBar;

// 是否使用自定义工具栏  - 如果设置为True，则默认工具栏不会创建
@property (nonatomic) BOOL                  isUseCustomToolBar;

// 是否使用动态显示工具栏效果
@property (nonatomic) BOOL                  showToolBarDynamic;

// 是否在导航栏右上角显示一个用来控制工具栏隐藏和出现的按钮
@property (nonatomic) BOOL                  useNavBtn;

// 自定义导航栏高度 - 用于计算高度
@property (nonatomic) float                 navBarHeight;

// 自定义切换栏高度 - 用于计算高度
@property (nonatomic) float                 tabBarHeight;

// 控制是否使用下拉刷新
@property (nonatomic) BOOL                  isUsePullRefresh;

// 控制当前要加载的地址，是否是指向本地存储中的webapp，如果是的话，将自动屏蔽webview的原生reload方法，改为发送事件给页面的方式
@property (nonatomic) BOOL                  isUsedForLocalWebApp;

// 控制是否显示加载框
@property (nonatomic) BOOL                  isShowLoadingBox;

// 控制是否禁止浏览器View的上下拖动效果
@property (nonatomic) BOOL                  isForbiddenBroswerViewPull;

// 是否仅在发生错误的时候，才使用工具栏，无错误发生的时候，一直隐藏起来，isUseToolBar=YES时候生效
@property (nonatomic) BOOL                  useToolBarOnlyError;

// 是否使用在工具栏的最左边的第一个按钮，一个大箭头返回按钮，默认行为是POP Controller，可重写，默认为YES
@property (nonatomic) BOOL                  useToolBarFirstLeftBtn;

// 是否开启自动刷新 - 自动刷新功能服务于缓存页面功能，当页面更新的时候，webview会自动的刷新一下当前页面到最新版本
@property (nonatomic, assign) BOOL          isOpenPageUpdateAutomatic;

// [iOS 7 适配] 设置status bar的背景色 - 默认为纯白色 - 仅限于开启适配功能情况下可用
@property (nonatomic, strong) UIColor *     statusBarColor;
/**/

#pragma mark-
#pragma mark-初始化/获取View对象等方法

/*!
 * 初始化
 */
- (id)init;

/*!
 * webview 对象
 */
- (UIWebView *) webview;

/*!
 * webViewScrollView 对象
 */
- (UIScrollView*) webViewScrollView;

#pragma mark-
#pragma mark-加载页面的相关方法

/*!
 * 执行加载WAP页面行为，默认的viewload会主动执行，如果子类需要定制viewload，则可以主动调用此方法
 */
- (void) runLoadWAPage;

/*!
 * 加载Data，子类需重写，但是不支持使用工具栏的情况
 */
- (void) webViewLoadData:(UIWebView *) webView;

/*!
 * 加载HTML，子类需重写，但是不支持使用工具栏的情况
 */
- (void) webViewLoadHTML:(UIWebView *) webView;

/*!
 * 校验WebView当前的URL是否和合法的URL，非loading页面
 */
- (BOOL) isCurrentUrlIsValidate;

/*!
 * 校验URL是否和合法的URL，非loading页面
 */
- (BOOL) isValidateUrl:(NSString *) url __attribute__((deprecated));

/*!
 * 获取当前WebView的URL
 */
- (NSString *) getCurrentUrl;

/*!
 * 不带额外的参数刷新页面
 */
- (void) reload;

/*!
 * 附带额外的参数刷新页面
 */
- (void) reloadWithNewParam:(NSDictionary *) paramDic __attribute__((deprecated));

/*!
 * 直接加载请求 默认使用get请求
 */
- (void) loadPageByUrl:(NSString *) url;
/*!
 * 直接加载请求 可选post或get
 */
- (void) loadPageByUrl:(NSString *) url isPost:(BOOL)isPost;

/*!
 * 加载请求，强制附带上tag参数，tag参数用来标记当前需要加载的请求是否是拦截到的URL，用来防止死循环
 */
- (void) loadPageByUrlWithTag:(NSString *) url;

/*!
 * 加载请求，强制去掉tag参数
 */
- (void) loadPageByUrlWithoutTag:(NSString *) url;

/*!
 * 设置TBWebViewDelegate
 */
- (void) setTBWebViewDelegate:(id) _delegate __attribute__((deprecated));

#pragma mark-
#pragma mark- WebViewDelegate

/*!
 * WebViewDelegate
 */
- (void)webViewDidStartLoad:(UIWebView *)webView;

/*!
 * WebViewDelegate
 */
- (void)webViewDidFinishLoad:(UIWebView *)webView;

/*!
 * WebViewDelegate
 */
- (void)webView:(UIWebView *)webView didFailLoadWithError:(NSError *)error;

/*!
 * WebViewDelegate
 */
- (BOOL)webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)_request navigationType:(UIWebViewNavigationType)navigationType;

#pragma mark-
#pragma mark- 基础API方法

// 工具栏第一个按钮的功能
- (void) goFirstClicked;
// WebView 行为:回退
- (void) webViewGoBack;
// WebView 行为:前进
- (void) webViewGoForward;
// WebView 行为:停止加载
- (void) webViewStopLoading;
// WebView 行为:刷新页面
- (void) webViewRefresh;
// WebView 行为:是否能回退
- (BOOL) webViewCanGoBack;
// WebView 行为:是否能前进
- (BOOL) webViewCanGoForward;

// 隐藏默认的工具栏
- (void) hiddenToolBar;
// 显示默认的工具栏
- (void) showToolBar;

#pragma mark-
#pragma mark- 功能定制相关方法

// 即将以本地APP模式启动，打开开关
- (void) viewControllerWillStartByLocalApp;

// 即将关闭本地APP，关闭开关
- (void) viewControllerWillEndLocalApp;

// 直接自动加载指定地址 API - 默认的指定了loadurl后，viewdidload就直接加载了
- (void) closeAutomaticalyLoad;
- (void) openAutomaticalyLoad;

// [iOS 7 适用] 是否自主控制status bar
// - iOS 7 的statusbar在Navigationbar隐藏的时候会透明，与webview中内容遮盖
// - 注意自主控制status bar仅限于在NavigationBar隐藏的场景才可以使用
// - 由于很多客户端有自定义容器所以内部没有做强制的控制
// 兼容iOS7 的风格，顶部无statusbar，透明，坐标从做顶端左侧开始
- (void) supportiOS7WithoutStatusBar;

// 兼容老版本的YYZ时代的缓存，这个缓存的处理是基于异步抓取HTML的模式，已经不建议使用，默认关闭，可以通过这个开关强制打开
- (void) supportSinglePageCache;

// 处理长按事件的开关，是否允许弹出 文字选择提示 以及 打开sheet对话框
- (void) forbiddenLongPressEvent;
- (void) permiteLongPressEvent;

// 开启服务：长按图片保存到相册
- (void) openLongPressSaveImage;
// 关闭服务：长按图片保存到相册
- (void) closeLongPressSaveImage;

// toast提示对话框
-(void)showAlert:(NSString *)msg;

#pragma mark-
#pragma mark- 定制UI相关方法

/*
 * 重写以下方法，实现基于默认工具栏的按钮图片等相关细节的定制
 */
// 下拉刷新左侧大箭头
- (UIImage *) getArrowImage;
// webview背景色
- (UIColor *) getBackgroundColor;
// 下拉刷新提示文案字体颜色
- (UIColor *) getTopArrowTxtColor;
// 导航栏右上角控制工具栏隐藏和消失的按钮图片
- (UIImage *) getNavRightBtnImage;

// 工具栏高度
- (float) getToolBarHeight;
// 获取工具栏背景图片
- (UIImage *) getToolBarBackgroundImage;
// 工具栏快速回到入口页面的按钮图片
- (UIImage *) getFastTargetBtnImage;
// 工具栏回退按钮的按钮图片
- (UIImage *) getGoBackBtnImage;
// 工具栏前进按钮的按钮图片
- (UIImage *) getGoForwardBtnImage;
// 工具栏刷新按钮的按钮图片
- (UIImage *) getRefreshBtnImage;
// 工具栏停止加载按钮的按钮图片
- (UIImage *) getStopLoadBtnImage;

/*
 * 重写以下方法，工具栏定制控制按钮
 */
-(id)customToolBarGoBackButton;
-(id)customToolBarGoForwardButton;
-(id)customToolBarRefreshButton;
-(id)customToolBarStopLoadingButton;

/*
 * 定制工具栏
 *
 * 工具栏包含TalbarView以及操作功能按钮，你可以通过上面的API来定制操作按钮，但是却不能定制默认ToolBar本身。
 * 因为不同客户端的ToolBar长相不同，我们不想过多的侵入UI方面，所以无现成接口使用。
 * 
 * 请按照以下步骤执行：
 *
 * - [STEP 1]
 * isUseCustomToolBar = YES;
 *
 * - [STEP 2]
 * 重写上面的 工具栏定制控制按钮customToolBar* 方法，创建自己的按钮View，浏览过程中按钮的状态会自动的被处理
 *
 * - [STEP 3]
 * 创建自己的TabbarView，然后将上面的按钮添加到TabbarView中，然后将TabbarView添加到self.view中
 *
 * 当然，最快捷的方式就是直接从windvane的gitlab切出属于自己APP的分支，然后直接改源码.
 */

/*
 * 重写以下方法，提供针对错误页面的定制，如果不定制就走原来的接口
 */
-(void)showErrorView:(UIWebView *)webView didFailLoadWithError:(NSError *)error;
-(void)removeErrorView;
-(BOOL)isErrorInfoViewShowing;

/*
 * 重写以下方法，提供针对加载的loadingbox的控制
 */
-(void)showLoadingBox;
-(void)showLoadingBoxWithTitle:(NSString*)title;
-(void)hiddenLoadingBox;

@end

/**************************************************************************
 * 最后修改版本 3.0.0 颜垣 进行了细化的区分和部分API的过期处理，去掉了较老的版本注释
 **************************************************************************/
