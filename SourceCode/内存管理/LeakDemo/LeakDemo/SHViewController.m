//
//  SHViewController.m
//  LeakDemo
//
//  Created by eason on 3/5/14.
//  Copyright (c) 2014 alibaba. All rights reserved.
//

#import "SHViewController.h"
#import "SHLeakObject.h"
@interface SHViewController ()
{
    SHLeakObject *_object;
}

@end

@implementation SHViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    SHLeakObject *leakObject = [[SHLeakObject alloc] init];
    [leakObject helloLeak];
    _object = [leakObject retain];
    
    UIButton *btn = [UIButton buttonWithType:UIButtonTypeCustom];
    btn.frame = CGRectMake(0, 0, 200, 88);
    btn.center  =self.view.center;
    [btn setBackgroundColor:[UIColor redColor]];
    [self.view addSubview:btn];
    [btn setTitle:@"点我啊，亲~" forState:UIControlStateNormal];
    [btn addTarget:self action:@selector(btnClick:) forControlEvents:UIControlEventTouchUpInside];
}


- (void)btnClick:(id)sender
{
    NSLog(@"btn click!");
    [sender setTitle:@"么么哒" forState:UIControlStateNormal];
    [_object leakByButtonClick];
    NSArray *array = [[NSArray alloc] init];
    array = [_object leakArray];
    for (NSString *str in array)
    {
        NSLog(@"btnClick:%@",str);
    }
    SHLeakObject *leakObject2 = [[SHLeakObject alloc] init];
    [leakObject2 leakArray];
    _object = leakObject2;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)dealloc
{
    [_object release];
    [super dealloc];
    
}

@end
