//
//  WVNetworkQueue.h
//  YYZPlugin
//
//  Created by 隐风 on 14-3-18.
//  Copyright (c) 2014年 颜 垣. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WVNetworkQueue : NSObject
- (void) reset;
- (void) go;
- (void) addOperation:(id) operation;
- (void) setMaxConcurrentOperationCount:(int) count;
- (void) cancelAllOperations;
@end