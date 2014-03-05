//
//  SHOwnerObject.m
//  ReferenceOwner
//
//  Created by eason on 3/4/14.
//  Copyright (c) 2014 alibaba. All rights reserved.
//

#import "SHOwnerObject.h"

@implementation SHOwnerObject


- (NSArray *)autoreleaseDemo
{
    NSArray *returnArray = [[NSArray alloc] initWithObjects:@"FML",@"WTF", nil];
    return [returnArray autorelease];
}

- (void)dealloc
{
    [super dealloc];
}
@end
