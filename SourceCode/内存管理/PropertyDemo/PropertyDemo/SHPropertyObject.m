//
//  SHPropertyObject.m
//  PropertyDemo
//
//  Created by eason on 3/11/14.
//  Copyright (c) 2014 alibaba. All rights reserved.
//

#import "SHPropertyObject.h"
#import "SHRetainObject.h"
@implementation SHPropertyObject


- (id)init
{
    self = [super init];
    if (self)
    {
        
        SHRetainObject *retainObj = [[SHRetainObject alloc] init];
        NSLog(@"retain前对象内存地址:%@",retainObj);
        self.retainObj = retainObj;
        /**
         *  如果使用_下划线，需要调用一次retain使应用计数+1
         */
//        _retainObj = [retainObj retain];
        NSLog(@"retain后对象内存地址:%@",_retainObj);
        [retainObj release];
        
        
        
        
        SHRetainObject *assignObj = [[SHRetainObject alloc] init];
        NSLog(@"assign前对象内存地址:%@",assignObj);
        /**
         *  assign属性不会对对象做一个retain，引用计数没有+1，导致在SHPropertyObject对象发dealloc消息的时候，assign对象已经被release了
         */
        self.assignObj = assignObj;
        NSLog(@"assign后对象内存地址:%@",assignObj);
        [assignObj release];
        
        
        
        
        SHRetainObject *copyObj = [[SHRetainObject alloc] init];
        NSLog(@"copy前对象内存地址:%@",copyObj);
        /**
         *  使用.描述符，相当于执行了一次setter操作
         */
        self.copyObj = copyObj;
        /**
         *  使用setter相当于点描述符
         */
//        [copyObj setCopyObj:copyObj];
        /**
         *  如果是用下划线，不会进行一次copy
         */
//        _copyObj = copyObj;
        NSLog(@"copy后对象内存地址:%@",_copyObj);
        [copyObj release];
    }
    return self;
}





- (void)dealloc
{
    [_assignObj release];
    [_retainObj release];
    [_copyObj   release];
    [_readOnlyObj release];
    [super dealloc];
}
@end
