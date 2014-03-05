//
//  SHNumber.m
//  ReferenceOwner1
//
//  Created by eason on 3/4/14.
//  Copyright (c) 2014 alibaba. All rights reserved.
//

#import "SHNumbers.h"

@implementation SHNumbers


- (id)init
{
    self = [super init];
    if (self)
    {
        _redNums = [[NSMutableArray alloc] init];
    }
    return self;
}

- (void)dealloc
{
    [_redNums release];
    [super dealloc];
}
@end
