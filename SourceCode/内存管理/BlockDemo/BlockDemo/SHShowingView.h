//
//  SHShowingView.h
//  BlockDemo
//
//  Created by eason on 3/11/14.
//  Copyright (c) 2014 alibaba. All rights reserved.
//

#import <UIKit/UIKit.h>
@class SHShowingView;
typedef void (^VoidBlockType)(void);
@protocol SHShowingViewDelegate <NSObject>

- (void)SHShowingViewLoveBtnClick:(SHShowingView *)view;

@end

@interface SHShowingView : UIView

@property (nonatomic,assign) id<SHShowingViewDelegate> delegate;
@property (nonatomic,copy) VoidBlockType btnClickType;



@end
