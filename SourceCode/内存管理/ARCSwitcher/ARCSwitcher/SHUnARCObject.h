//
//  SHUnARCObject.h
//  ARCSwitcher
//
//  Created by eason on 3/10/14.
//  Copyright (c) 2014 alibaba. All rights reserved.
//  这是一个非ARC对象
//

#import <Foundation/Foundation.h>
@class SHARCObject;
@interface SHUnARCObject : NSObject

@property (nonatomic,strong) SHARCObject *arcObject;

@end
