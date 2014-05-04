//
//  SHLeakObject.m
//  LeakDemo
//
//  Created by eason on 3/5/14.
//  Copyright (c) 2014 alibaba. All rights reserved.
//

#import "SHLeakObject.h"

@implementation SHLeakObject

- (void)helloLeak
{
    NSLog(@"hello Leak!");
}

- (void)leakByButtonClick
{
    NSLog(@"leakByButtonClick!");
}

- (NSArray *)leakArray
{
    NSArray *array = [[[NSArray alloc] initWithObjects:@"step1",@"step2", nil] autorelease];
    return array;
}
@end
