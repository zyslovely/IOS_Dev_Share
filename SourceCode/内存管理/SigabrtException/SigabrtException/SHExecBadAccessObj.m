//
//  SHExecBadAccessObj.m
//  SigabrtException
//
//  Created by eason on 3/7/14.
//  Copyright (c) 2014 alibaba. All rights reserved.
//

#import "SHExecBadAccessObj.h"

@implementation SHExecBadAccessObj

- (void)doSomething
{
    /**
     *  如果没有该方法的回调实现,会报错
     */
    if ([self.delegate respondsToSelector:@selector(delegateDoSomething:)])
    {
        [self.delegate delegateDoSomething:self];
    }
}
@end
