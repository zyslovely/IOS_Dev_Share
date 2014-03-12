//
//  SHExecBadAccessObj.h
//  SigabrtException
//
//  Created by eason on 3/7/14.
//  Copyright (c) 2014 alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>
@class SHExecBadAccessObj;
@protocol SHExecBadAccessObjDelegate <NSObject>

- (void)delegateDoSomething:(SHExecBadAccessObj *)obj;

@end

@interface SHExecBadAccessObj : NSObject



@property (nonatomic,assign) id<SHExecBadAccessObjDelegate> delegate;
- (void)doSomething;
@end
