//
//  SHViewController.m
//  Animation
//
//  Created by eason on 4/8/14.
//  Copyright (c) 2014 alibaba. All rights reserved.
//

#import "SHViewController.h"

@interface SHViewController ()
{
    CALayer *layer;
}

@end

@implementation SHViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor blackColor];
    
    layer = [CALayer layer];
    layer.bounds = CGRectMake(0, 0, 200, 200);
    layer.position = CGPointMake(160, 100);
    layer.backgroundColor = [UIColor redColor].CGColor;
    layer.borderColor = [UIColor whiteColor].CGColor;
    layer.opacity = 1.0f;
    [self.view.layer addSublayer:layer];

    UIButton *btn   = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    btn.frame       = CGRectMake(0, 0, 100, 100);
    btn.center      = self.view.center;
    btn.backgroundColor     = [UIColor redColor];
    btn.layer.cornerRadius  = 20;
    btn.layer.opacity = 0.5;
    btn.layer.borderColor = [[UIColor whiteColor] CGColor];
    btn.layer.borderWidth = 5;
    [btn setTitle:@"点一下" forState:UIControlStateNormal];
    [btn addTarget:self action:@selector(changeLayerProperty) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:btn];

    
    //sublayer
//    CALayer *alayer = [[CALayer alloc] init];
//    alayer.bounds = CGRectMake(0, 0, 60, 30);
//    alayer.backgroundColor = [[UIColor blackColor] CGColor];
//    [btn.layer addSublayer:alayer];
	// Do any additional setup after loading the view, typically from a nib.
}

-(void)changeLayerProperty
{
    
    
    /********************************************************************/
    //设置变化动画过程是否显示，默认为YES不显示 0.25
///隐式动画 exp.1
//    [CATransaction setDisableActions:NO];    //  设置是否禁止隐式动画
//    layer.cornerRadius = (layer.cornerRadius == 0.0f) ? 30.0f : 0.0f;    //   设置圆角
//    layer.opacity = (layer.opacity == 1.0f) ? 0.5f : 1.0f;   // 设置透明度
    
    
    
    
    /********************************************************************/
    
//    [CATransaction begin];
//    
//    //动画嵌套 ,只有当最外层的事务commit了之后,整个动画才开始.
//    [CATransaction begin];
//    [CATransaction setValue:[NSNumber numberWithFloat:1.0f] forKey:kCATransactionAnimationDuration];
////    layer.backgroundColor = [[UIColor grayColor] CGColor];
//    layer.borderWidth = 10;
//    [CATransaction commit];
//    
//    //显式事务默认开启动画效果,kCFBooleanTrue关闭
//    [CATransaction setValue:(id)kCFBooleanFalse forKey:kCATransactionDisableActions];
//
//    //动画执行时间
//    [CATransaction setValue:[NSNumber numberWithFloat:5.0f] forKey:kCATransactionAnimationDuration];
//
//    layer.cornerRadius = (layer.cornerRadius == 0.0f) ? 30.0f : 0.0f;
//    layer.opacity = (layer.opacity == 1.0f) ? 0.5f : 1.0f;
//
//    
//    [CATransaction commit];
    
    [UIView animateWithDuration:1.0 animations:^{
        layer.borderWidth = 10;
    }];

//    CATransition *animation = [CATransition animation];
//    [animation setDuration:1.25f];
//    [animation setTimingFunction:UIViewAnimationCurveEaseInOut];
//    [animation setType:@"cube"];
//    [animation setSubtype: kCATransitionFromTop];
//    animation.startProgress = 0.0;
//    animation.endProgress = 0.5;
//    [layer addAnimation:animation forKey:@"Reveal"]; //what does the key mean?
    
    
    /***********************CAAnimationGroup*********************************************/
//    CAAnimationGroup *animGroup = [CAAnimationGroup animation];
//    
//    //贝塞尔曲线路径
//    UIBezierPath *movePath = [UIBezierPath bezierPath];
//    [movePath moveToPoint:CGPointMake(10.0, 10.0)];
//    [movePath addQuadCurveToPoint:CGPointMake(100, 300) controlPoint:CGPointMake(300, 100)];
//    [movePath addQuadCurveToPoint:CGPointMake(300, 100) controlPoint:CGPointMake(100, 300)];
//    
//    //以下必须导入QuartzCore包
//    CAKeyframeAnimation * posAnim = [CAKeyframeAnimation animationWithKeyPath:@"position"];
//    posAnim.path = movePath.CGPath;
//    posAnim.removedOnCompletion = YES;
//    
//    //缩放动画
//    CABasicAnimation *scaleAnim = [CABasicAnimation animationWithKeyPath:@"transform"];
//    scaleAnim.fromValue = [NSValue valueWithCATransform3D:CATransform3DIdentity];
//    scaleAnim.toValue = [NSValue valueWithCATransform3D:CATransform3DMakeScale(0.1, 0.1, 1.0)];
//    scaleAnim.removedOnCompletion = YES;
//    
//    CABasicAnimation *borderAnim = [CABasicAnimation animationWithKeyPath:@"borderWidth"];
//    borderAnim.fromValue = [NSNumber numberWithDouble:0.0];
//    borderAnim.toValue = [NSNumber numberWithDouble:5.0];
//    borderAnim.removedOnCompletion = YES;
//    
//    //透明动画
//    CABasicAnimation *opacityAnim = [CABasicAnimation animationWithKeyPath:@"alpha"];
//    opacityAnim.fromValue = [NSNumber numberWithFloat:1.0];
//    opacityAnim.toValue = [NSNumber numberWithFloat:0.1];
//    opacityAnim.removedOnCompletion = YES;
//
//    animGroup.animations = [NSArray arrayWithObjects:posAnim,borderAnim,scaleAnim,opacityAnim, nil];
//    animGroup.duration = 1;
//    [layer addAnimation:animGroup forKey:nil];
    
    
    
    /***********************CABaseAnimation*********************************************/
//    CABasicAnimation *baseAnimation = [CABasicAnimation animationWithKeyPath:@"borderWidth"];
//    baseAnimation.duration = 1;
//    baseAnimation.fromValue = [NSNumber numberWithDouble:1.0];
//    baseAnimation.toValue = [NSNumber numberWithDouble:10.0];
//
//    [layer addAnimation:baseAnimation forKey:nil];
    
    
    
//    CGMutablePathRef path = CGPathCreateMutable();
//    CGPathMoveToPoint(path,NULL,50.0,120.0);
//    //下面5行添加5条直线的路径到path中
//    CGPathAddLineToPoint(path, NULL, 60, 130);
//    CGPathAddLineToPoint(path, NULL, 70, 140);
//    CGPathAddLineToPoint(path, NULL, 80, 150);
//    CGPathAddLineToPoint(path, NULL, 90, 160);
//    CGPathAddLineToPoint(path, NULL, 100, 170);
//    //下面四行添加四条曲线路径到path
//    CGPathAddCurveToPoint(path,NULL,50.0,275.0,150.0,275.0,70.0,120.0);
//    CGPathAddCurveToPoint(path,NULL,150.0,275.0,250.0,275.0,90.0,120.0);
//    CGPathAddCurveToPoint(path,NULL,250.0,275.0,350.0,275.0,110.0,120.0);
//    CGPathAddCurveToPoint(path,NULL,350.0,275.0,450.0,275.0,130.0,120.0);
//    CAKeyframeAnimation *animation = [CAKeyframeAnimation animationWithKeyPath:@"position"];
//    //设置path属性
//    [animation setPath:path];
//    [animation setDuration:3.0];
//    
//    [animation setAutoreverses:YES];
//    CFRelease(path);
//    [layer addAnimation:animation forKey:NULL];
}
@end
