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
     *  exp1
     */
//    _numbers = [numbers retain];
    [numbers retain];
    [_numbers release];
    _numbers = [numbers retain];
}

- (void)dealloc
{
    [_numbers release];
    [super dealloc];
}
@end
