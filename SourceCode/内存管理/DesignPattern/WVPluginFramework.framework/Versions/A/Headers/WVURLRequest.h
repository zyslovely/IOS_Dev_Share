//
//  WVURLRequest.h
//  YYZPlugin
//
//  Created by 颜 垣 on 13-10-23.
//  Copyright (c) 2013年 颜 垣. All rights reserved.
//

#import <Foundation/Foundation.h>

// 专门提供返回接受行为的Delegate
@protocol WVURLRequestDelegate <NSObject>
// 成功回调方法
- (void) didRecieveCachedURLResponse:(NSCachedURLResponse *) response forRequest:(NSURLRequest *) request;

// 失败回调方法
- (void) didFailedRecieveCachedURLResponse:(NSCachedURLResponse *) response withError:(NSError *) error forRequest:(NSURLRequest *) request;
@end

@interface WVURLRequest : NSMutableURLRequest
// 接受返回值的delegate
@property (nonatomic, strong) id<WVURLRequestDelegate> delegate;
@end
