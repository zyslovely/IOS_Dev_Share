//
//  SHSingleObj.m
//  DesignPattern
//
//  Created by eason on 3/11/14.
//  Copyright (c) 2014 alibaba. All rights reserved.
//

#import "SHSingleObj.h"
static SHSingleObj *sharedObj = nil;
@implementation SHSingleObj

- (id)sharedSHSingleObj
{
    /**
     *  exp1
     */
    @synchronized (self)
    {
        if (sharedObj == nil)
        {
           sharedObj =  [[SHSingleObj alloc] init];
        }
    }
    return sharedObj;
    
    /**
     *  exp2
     */
//    static SHSingleObj *obj=nil;
//    static dispatch_once_t   p;
//    dispatch_once(&p,^{
//        obj=[[SHSingleObj alloc]init];
//    });
//    return obj;
}
@end
