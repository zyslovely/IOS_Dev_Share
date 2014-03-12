//
//  SHShowingView.m
//  BlockDemo
//
//  Created by eason on 3/11/14.
//  Copyright (c) 2014 alibaba. All rights reserved.
//

#import "SHShowingView.h"

@implementation SHShowingView

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {

        UIImage *image = [UIImage imageNamed:@"1.jpg"];
        int width = 260;
        int height = width*1.0/image.size.width*image.size.height;
        
        UIImageView *imageView = [[UIImageView alloc] initWithFrame:CGRectMake(0, 0, width, height)];
        imageView.image = image;
        [self addSubview:imageView];
        
        UIButton *btn = [UIButton buttonWithType:UIButtonTypeCustom];
        [btn setTitle:@"我爱你" forState:UIControlStateNormal];
        [btn setTitle:@"我爱你" forState:UIControlStateHighlighted];
        btn.backgroundColor = [UIColor redColor];
        btn.titleLabel.textColor = [UIColor whiteColor];
        btn.frame = CGRectMake(imageView.center.x - width/2, CGRectGetMaxY(imageView.frame) + 20, width, 44);
        [btn addTarget:self action:@selector(btnClick:) forControlEvents:UIControlEventTouchUpInside];
        [self addSubview:btn];
        
    }
    return self;
}


- (void)btnClick:(id)sender
{
    /**
     *  使用delegate实现回调
     *
     *  @param SHShowingViewLoveBtnClick:
     *
     *  @return
     */
//    if ([self.delegate respondsToSelector:@selector(SHShowingViewLoveBtnClick:)])
//    {
//        [self.delegate SHShowingViewLoveBtnClick:self];
//    }
    
    /**
     *  使用block实现回调
     */
    if (_btnClickType)
    {
        _btnClickType();
    }
}



@end
