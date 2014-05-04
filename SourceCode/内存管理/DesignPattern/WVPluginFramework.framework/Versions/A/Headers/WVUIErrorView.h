//
//  YYZUIErrorView.h
//  YYZPlugin
//
//  Created by christ.yuj on 13-5-7.
//  Copyright (c) 2013年 颜 垣. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface WVUIErrorView : UIView

- (void)showViewForError:(NSError *)error inView:(UIView*)parentView;

- (void)removeErrorView;
@end
