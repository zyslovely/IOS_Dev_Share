/*!
 *  @FILE: YYZProtocolUtil.h
 *  @PROJECT: YYZPlugin
 *  @DESCRIPTION:
 *
 *  用来基于协议获取参数的工具类
 *
 *  Created by 颜 垣 on 13-1-9.
 *  Copyright (c) 2012年 颜 垣. All rights reserved.
 */

#import <Foundation/Foundation.h>

/*!
 * 淘宝业务：URL跳转标记，用来判断当前执行Load的URL的类型
 */
typedef enum {
    T_DETAIL        = 100,
    T_SEARCH        = 200,
    T_SHOP          = 300,
    T_CART          = 400,
    T_ORDER         = 500,
    T_MYTB          = 600,
    T_FAV           = 700,
    T_YYZ           = 800,
    T_WW            = 900,
    T_LOGIN         = 1000,
    T_LOGOUT        = 1100,
    T_BUY           = 1200,
    T_TMALL_PACKAGE = 1300,
    T_ITUNES        = 1400
} TBWVLinkType;

@interface YYZProtocolUtil : NSObject

// 获取商品ID
+ (NSString *) getAuctionItemId:(NSDictionary *) param;

// 获取店铺ID
+ (NSString *) getShopId:(NSDictionary *) param;

// 获取店铺店主用户ID
+ (NSString *) getShopUserId:(NSDictionary *) param;

// 获取搜索关键字
+ (NSString *) getSearchKeyWorkd:(NSDictionary *) param;

// 获取搜索的类目ID
+ (NSString *) getSearchCateId:(NSDictionary *) param;

// 获取搜索的属性ID
+ (NSString *) getSearchPPath:(NSDictionary *) param;

// 获取订单状态类型值
+ (NSString *) getOrderStatus:(NSDictionary *) param;

// 获取下单操作的SKUID
+ (NSString *) getBuyOrderSkuId:(NSDictionary *) param;

// 获取下单操作的购物车ID
+ (NSArray *) getCartId:(NSDictionary *) param;

// 获取旺旺聊天对方的用户名
+ (NSString *) getWWChatToUser:(NSDictionary *) param;

// 获取聚划算的KEY
+ (NSString *) getJHSKey:(NSDictionary *) param;

// 获取登陆回来后的URL，如果能获取到，则使用之，如果获取不到，则刷新当前webview中的页面
+ (NSString *) getReloadPageUrlAfterLogin:(NSDictionary *) param;

@end
