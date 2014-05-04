//
//  SHAnimationViewController.m
//  Animation
//
//  Created by eason on 4/8/14.
//  Copyright (c) 2014 alibaba. All rights reserved.
//

#import "SHAnimationViewController.h"

@interface SHAnimationViewController ()
{
    UIView *_aView;
}

@end

@implementation SHAnimationViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    _aView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 100, 100)];
    _aView.backgroundColor = [UIColor greenColor];
    [self.view addSubview:_aView];
    
    
    UIButton *btn = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    btn.frame = CGRectMake(0, 0, 100, 44);
    btn.center = self.view.center;
    [btn setTitle:@"点一下" forState:UIControlStateNormal];
    btn.backgroundColor = [UIColor redColor];
    [btn addTarget:self action:@selector(changeLayerProperty) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:btn];

    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void)changeLayerProperty
{
    
    [CATransaction begin];
    [CATransaction setValue:(id)kCFBooleanFalse forKey:kCATransactionDisableActions];
    [CATransaction setValue:[NSNumber numberWithFloat:5.0f] forKey:kCATransactionAnimationDuration];
    [CATransaction setAnimationTimingFunction:[CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseIn]];

    _aView.frame = CGRectMake(10, 10, 200, 200);
    __weak UIView *weakView = _aView;
    [CATransaction setCompletionBlock:^{
//        weakView.hidden = YES;
    }];
    [CATransaction commit];
}

@end
