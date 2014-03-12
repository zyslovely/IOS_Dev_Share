//
//  SHViewController.m
//  DesignPattern
//
//  Created by eason on 3/11/14.
//  Copyright (c) 2014 alibaba. All rights reserved.
//

#import "SHViewController.h"

@interface SHViewController ()

@end

@implementation SHViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    
    NSNumber *number    = [NSNumber numberWithInt:1];
    NSNumber *number1   = [NSNumber numberWithBool:YES];
    NSNumber *number2   = [NSNumber numberWithFloat:1.0];
    NSNumber *number3   = [NSNumber numberWithLong:1L];
    NSNumber *number4   = [NSNumber numberWithInteger:@1];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleReceiveNotification:) name:@"notif" object:nil];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)postNotification
{
    [[NSNotificationCenter defaultCenter] postNotificationName:@"notif" object:nil];
}

- (void)handleReceiveNotification:(NSNotification *)notif
{
    NSLog(@"哈哈哈哈");
}


- (void)dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}
@end
