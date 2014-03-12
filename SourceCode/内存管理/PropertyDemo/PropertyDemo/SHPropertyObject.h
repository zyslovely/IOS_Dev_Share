//
//  SHPropertyObject.h
//  PropertyDemo
//
//  Created by eason on 3/11/14.
//  Copyright (c) 2014 alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 *  retain,nonatomic
 */
@class SHRetainObject;
@interface SHPropertyObject : NSObject 


@property (nonatomic,retain) SHRetainObject *retainObj;
@property (nonatomic,assign) SHRetainObject *assignObj;
@property (nonatomic,copy)   SHRetainObject *copyObj;
@property (nonatomic,retain,readonly) SHRetainObject *readOnlyObj;

@end
