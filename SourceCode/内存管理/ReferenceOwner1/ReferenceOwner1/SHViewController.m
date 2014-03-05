//
//  SHViewController.m
//  ReferenceOwner1
//
//  Created by eason on 3/4/14.
//  Copyright (c) 2014 alibaba. All rights reserved.
//

#import "SHViewController.h"
#import "SHLottery.h"
#import "SHNumbers.h"
@interface SHViewController ()

@end

@implementation SHViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    /**
     *  exp1.
     */
//    SHLottery *lottery = [[SHLottery alloc] init];
//    SHNumbers *number1 = [[SHNumbers alloc] init];
//    [lottery setNumbers:number1];
//    NSLog(@"number1 retainCount:%d",[number1 retainCount]);
//    [number1 release];
//    NSLog(@"number1 retainCount:%d",[number1 retainCount]);
//    SHNumbers *number2 = [[SHNumbers alloc] init];
//    [lottery setNumbers:number2];
//    NSLog(@"number1 retainCount:%d",[number1 retainCount]);
//    [number2 release];
//    NSLog(@"number1 retainCount:%d",[number1 retainCount]);
    
    SHLottery *lottery = [[SHLottery alloc] init];
    SHNumbers *number1 = [[SHNumbers alloc] init];
    [lottery setNumbers:number1];
    SHLottery *lottery1 = [[SHLottery alloc] init];
    [number1 release];
    [lottery1 setNumbers:lottery.numbers];
    NSLog(@"%d",[lottery.numbers retainCount]);
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
