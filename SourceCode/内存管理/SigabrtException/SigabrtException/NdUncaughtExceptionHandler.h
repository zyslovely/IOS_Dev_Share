//
//  SHNdUncaughtExceptionHandler.h
//  SigabrtException
//
//  Created by eason on 3/10/14.
//  Copyright (c) 2014 alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NdUncaughtExceptionHandler : NSObject

+ (void)setDefaultHandler;
+ (NSUncaughtExceptionHandler*)getHandler;
@end
