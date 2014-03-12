//
//  SHViewController.m
//  SigabrtException
//
//  Created by eason on 3/7/14.
//  Copyright (c) 2014 alibaba. All rights reserved.
//

#import "SHViewController.h"
#import "SHSigabrtObject.h"
#import "SHExecBadAccessObj.h"
@interface SHViewController () <SHExecBadAccessObjDelegate>
{
    SHExecBadAccessObj *_obj;
}
@end

@implementation SHViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    UIButton *sigBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    [sigBtn setTitle:@"点我点我" forState:UIControlStateNormal];
    sigBtn.titleLabel.font = [UIFont systemFontOfSize:16];
    [sigBtn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [sigBtn setBackgroundColor:[UIColor redColor]];
    sigBtn.frame = CGRectMake(0, 0, 200, 88);
    sigBtn.center = self.view.center;
    [sigBtn addTarget:self action:@selector(btnClick:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:sigBtn];
    
    SHExecBadAccessObj *badObj = [[SHExecBadAccessObj alloc] init];
    badObj.delegate = self;
    [badObj release];
    _obj = badObj;
}

- (void)btnClick:(id)sender
{
    
    /**
     *  sigabrt
     *
     *  @param
     *
     *  @return
     */
    
    UIButton *btn = (UIButton *)sender;
    [btn setTitle:@"我要挂啦(3)" forState:UIControlStateNormal];
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT,
                                             0), ^{
        [NSThread sleepForTimeInterval:1.0];
        dispatch_async(dispatch_get_main_queue(), ^{
            [btn setTitle:@"真的要挂啦(2)" forState:UIControlStateNormal];
        });
        
        [NSThread sleepForTimeInterval:1.0];
        dispatch_async(dispatch_get_main_queue(), ^{
            [btn setTitle:@"挂啦(1)" forState:UIControlStateNormal];
        });
        [NSThread sleepForTimeInterval:1.0];
        SHSigabrtObject *obj = [[SHSigabrtObject alloc] init];
        [obj performSelector:@selector(guala:)];
    });
    /**
     *  EXC_BAD_ACCESS
     *
     *  @param void
     *
     *  @return
     */
    [_obj doSomething];
}

#pragma mark -
#pragma mark SHExecBadAccessObj Delegate
- (void)delegateDoSomething:(SHExecBadAccessObj *)obj
{
    NSLog(@"gogogo");
}


- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}

@end
