//
//  YYZFileBrowserViewController.h
//  YYZPlugin
//
//  [Attention:内部隐藏工具，外部客户端禁止使用!!!]
//
//  该隐藏工具的功能是展示当前所有WindVane框架处理的文件列表，以及可以阅读、删除等行为
//
//  Created by 颜 垣 on 13-7-11.
//  Copyright (c) 2013年 颜 垣. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface YYZFileBrowserViewController : UIViewController

+ (BOOL) isHiddenUtilEvent : (NSString *) requestUrl;

@end
