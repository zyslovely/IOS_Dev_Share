/*!
 *  @FILE: YYZUICore.h
 *  @PROJECT: YYZPlugin
 *  @DESCRIPTION:
 *  vv2.0.1 增加，针对核心UI做管理
 *
 *  Created by 颜 垣 on 13-2-19.
 *  Copyright (c) 2012年 颜 垣. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

#pragma mark-
#pragma mark-Macro

#define TBWV_BACKGROUND_COLOR [UIColor colorWithPatternImage:[UIImage imageNamed:@"all_bg_small"]]
#define TBWV_ARROW [UIImage imageNamed:@"upload1"]
#define TBWV_TEXT_COLOR	 [UIColor colorWithWhite:102/255.0f alpha:1]
#define TBWV_TEXT_SHADOW_COLOR [UIColor whiteColor]

#define TBWV_FLIP_ANIMATION_DURATION 0.18f
#define TBWV_SIXTY_FIVE 65.0f
#define TBWV_SIXTY 60.0f
#define TBWV_F_V 70.0f

#define TBWV_NAV_RIG_IMG [UIImage imageNamed:@"navbar_small"]

#pragma mark-
#pragma mark-GlobalDefine

/*!
 * 下拉状态
 */
typedef enum {
	TBWVPullRefreshPulling = 0,
	TBWVPullRefreshNormal = 1,
	TBWVPullRefreshLoading = 2,
} TBWVPullRefreshState;

@interface YYZUICore : NSObject

+ (UILabel *) generateTopStatusTxt:(CGRect)frame withFontColor:(UIColor *) color;
+ (UILabel *) generateTopLstUpdateTxt:(CGRect)frame withFontColor:(UIColor *) color;
+ (CALayer *) generateArrowImg:(UIImage *) image;
+ (UIActivityIndicatorView *) generateActView;
+ (UIView *) generateTopView:(CGRect)frame;
+ (NSString *) generateLstUpdateTime;

@end
