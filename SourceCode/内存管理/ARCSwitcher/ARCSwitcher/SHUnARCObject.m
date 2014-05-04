//
//  SHUnARCObject.m
//  ARCSwitcher
//
//  Created by eason on 3/10/14.
//  Copyright (c) 2014 alibaba. All rights reserved.
//

#import "SHUnARCObject.h"
#import "SHARCObject.h"
@implementation SHUnARCObject


- (id)init
{
    self = [super init];
    if (self)
    {
        SHARCObject *arcObj = [[SHARCObject alloc] init];
        _arcObject = arcObj;
    }
    return self;
}

@end
