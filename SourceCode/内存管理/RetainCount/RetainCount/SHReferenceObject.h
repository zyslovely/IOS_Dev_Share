//
//  SHReferenceObject.h
//  RetainCount
//
//  Created by eason on 3/4/14.
//  Copyright (c) 2014 alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SHAnotherObject;
@interface SHReferenceObject : NSObject


@property (nonatomic,retain) SHAnotherObject *anotherObj;

+ (void)function;
@end
