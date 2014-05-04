//
//  WVUILoadingBox.h
//  YYZPlugin
//
//  Created by christ.yuj on 13-7-19.
//  Copyright (c) 2013年 颜 垣. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface WVUILoadingBox : UIView

@property (nonatomic, strong) UILabel* loadingBoxTitle;

- (void) resize:(CGRect) frame;

@end
