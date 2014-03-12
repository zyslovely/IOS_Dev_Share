//
//  SHRetainObject.m
//  PropertyDemo
//
//  Created by eason on 3/11/14.
//  Copyright (c) 2014 alibaba. All rights reserved.
//

#import "SHRetainObject.h"

@implementation SHRetainObject


#pragma mark - NSCoding, NSCopying
- (id)initWithCoder:(NSCoder *)aDecoder {
    
    self = [super init];
    if (self) {
    }
    
    return self;
}

- (void)encodeWithCoder:(NSCoder *)aCoder {

    
}

- (id)copyWithZone:(NSZone *)zone {
    
    SHRetainObject *obj = [[SHRetainObject allocWithZone:zone] init];
    return obj;
}
@end
