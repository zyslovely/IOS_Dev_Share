//
//  SHReferenceObject.m
//  RetainCount
//
//  Created by eason on 3/4/14.
//  Copyright (c) 2014 alibaba. All rights reserved.
//

#import "SHReferenceObject.h"
#import "SHAnotherObject.h"
@implementation SHReferenceObject


- (id)init
{
    self = [super init];
    if (self)
    {
        _desc = @"描述dddd";
        /**
         *  计算引用计数
         */
        SHAnotherObject *anotherObject = [[SHAnotherObject alloc] init];
        NSLog(@"SHAnotherObject retainCount:%d",[anotherObject retainCount]);
        [anotherObject retain];
        NSLog(@"SHAnotherObject retainCount:%d",[anotherObject retainCount]);
        [anotherObject retain];
        NSLog(@"SHAnotherObject retainCount:%d",[anotherObject retainCount]);
        _anotherObj = anotherObject;
        NSLog(@"SHAnotherObject _anotherObj:%d",[_anotherObj retainCount]);
        [anotherObject release];
        NSLog(@"SHAnotherObject anotherObject:%d",[anotherObject retainCount]);
        [anotherObject release];
        NSLog(@"SHAnotherObject anotherObject:%d",[anotherObject retainCount]);
    }
    return self;
}

- (void)dealloc
{
    NSLog(@"SHAnotherObject retainCount:%d",[_anotherObj retainCount]);
    [_anotherObj release];
    [super dealloc];
}
@end
