//
//  SHViewController.m
//  NSThread
//
//  Created by eason on 3/10/14.
//  Copyright (c) 2014 alibaba. All rights reserved.
//

#import "SHViewController.h"

@interface SHViewController ()

@end

@implementation SHViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	
//两种NSThread实现方法 第一种方式会直接创建线程并且开始运行线程，第二种方式是先创建线程对象，然后再运行线程操作，在运行线程操作前可以设置线程的优先级等线程信息
    
    
//    [NSThread detachNewThreadSelector:@selector(doThread) toTarget:self withObject:nil];
    
//    for (int i = 0; i<10 ;i ++)
//    {
//        NSThread* myThread = [[NSThread alloc] initWithTarget:self selector:@selector(doThread:) object:[NSNumber numberWithInt:i]];
//        [myThread setThreadPriority:i];
//        [myThread start];
//    }
    
//    [self performSelectorInBackground:@selector(doThread) withObject:nil];
    
    
    /**
     *  NSOperation
     *
     *  @param void
     *
     *  @return
     */
//    NSInvocationOperation *invocationOperation = [[NSInvocationOperation alloc] initWithTarget:self selector:@selector(doThread:) object:nil];
//    NSInvocationOperation *invocationOperation1 = [[NSInvocationOperation alloc] initWithTarget:self selector:@selector(doOtherThread:) object:nil];
//    
////    [invocationOperation1  addDependency:invocationOperation];
//    NSOperationQueue *queue = [[NSOperationQueue alloc]init];
//    [queue addOperation:invocationOperation];
//    [queue addOperation:invocationOperation1];
    //直接加几个operation机那里
//    [queue addOperation:invocationOperation];
    
    NSObject
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}

- (void)doThread:(NSNumber *)obj
{
    if (obj)
    {
        NSLog(@"%@",[NSString stringWithFormat:@"doThread:%@",obj]);
    }else
    {
        NSLog(@"%@",[NSString stringWithFormat:@"doThread and obj = nil"]);
    }
    
}
- (void)doOtherThread:(NSNumber *)obj
{
    if (obj)
    {
        NSLog(@"%@",[NSString stringWithFormat:@"doOtherThread:%@",obj]);
    }else
    {
        NSLog(@"%@",[NSString stringWithFormat:@"doOtherThread and obj = nil"]);
    }
    
}

@end
