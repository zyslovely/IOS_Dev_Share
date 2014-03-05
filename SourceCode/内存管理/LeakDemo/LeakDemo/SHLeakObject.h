//
//  SHLeakObject.h
//  LeakDemo
//
//  Created by eason on 3/5/14.
//  Copyright (c) 2014 alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SHLeakObject : NSObject


- (void)helloLeak;
- (void)leakByButtonClick;
- (NSArray *)leakArray;
@end
