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
        SHAnotherObject *another = [[SHAnotherObject alloc] init];
        _anotherObj = another;
        [_anotherObj release];
//        /**
//         *  计算引用计数
//         */
//        SHAnotherObject *anotherObject = [[SHAnotherObject alloc] init];
//        NSLog(@"SHAnotherObject retainCount1:%lu",(unsigned long)[anotherObject retainCount]);
//        [anotherObject retain];
//        NSLog(@"SHAnotherObject retainCount2:%lu",[anotherObject retainCount]);
//        [anotherObject retain];
//        NSLog(@"SHAnotherObject retainCoun3:%lu",[anotherObject retainCount]);
//        _anotherObj = anotherObject;
//        NSLog(@"SHAnotherObject _anotherOb4:%lu",[_anotherObj retainCount]);
//        [anotherObject release];
//        NSLog(@"SHAnotherObject anotherObjec5:%lu",[anotherObject retainCount]);
//        [anotherObject release];
//        NSLog(@"SHAnotherObject anotherObjec6:%lu",[anotherObject retainCount]);
    }
    return self;
}

+ (void)function
{
    NSLog(@"do	func	tio	"	);
}

- (void)dealloc
{
    NSLog(@"SHAnotherObject retainCount:%lu",[_anotherObj retainCount]);
    [_anotherObj release];
    NSLog(@"SHAnotherObject retainCount:%lu",[_anotherObj retainCount]);
    [super dealloc];
}
@end
