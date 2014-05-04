//
//  NSString+WVHASHAddition.h
//  YYZPlugin
//
//  Created by christ.yuj on 13-5-28.
//  Copyright (c) 2013年 颜 垣. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (WVHASHAddition)

- (NSString *) stringFromMD5ForWV;

- (NSString *) stringFromSHA1ForWV;

@end
