//
//  SHLottery.m
//  ReferenceOwner1
//
//  Created by eason on 3/4/14.
//  Copyright (c) 2014 alibaba. All rights reserved.
//

#import "SHLottery.h"
#import "SHNumbers.h"
@implementation SHLottery

- (void)setNumbers:(SHNumbers *)numbers
{
    /**
     *  exp1,如果当前_numbers存在引用，则造成内存泄露
     */
//    _numbers = [numbers retain];
    
    /**
     *  正确写法
     */
//    [numbers retain];
//    [_numbers release];
//    _numbers = numbers;
}

/**
 *  如果直接返回一个初始化的对象，肿么办
 *
 *  @return
 */
- (SHNumbers*)createNumbers
{
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    [pool drain];
    SHNumbers *number = [[SHNumbers alloc] init];
    return number;
}

- (void)dealloc
{
    [_numbers release];
    [super dealloc];
}
@end
