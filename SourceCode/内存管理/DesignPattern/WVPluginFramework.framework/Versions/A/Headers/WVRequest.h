//
//  WVRequest.h
//  YYZPlugin
//
//  Created by 颜 垣 on 14-3-18.
//  Copyright (c) 2014年 颜 垣. All rights reserved.
//

#import <Foundation/Foundation.h>

@class WVRequest;
@protocol WVRequestDelegate <NSObject>
@optional
- (void)requestStarted:(WVRequest *)request;
- (void)requestFinished:(WVRequest *)request;
- (void)requestFailed:(WVRequest *)request;
@end

typedef void (^WVRequestBasicBlock)(void);

@interface WVRequest : NSObject

- (int) responseStatusCode;
- (NSData *) responseData;
- (NSString *) responseString;
- (void) setUserInfo:(NSDictionary *) userInfo;
- (NSDictionary * ) userInfo;
- (NSDictionary *) responseHeaders;
- (NSError *) error;

+ (id) requestWithURL:(NSURL *) newURL;
- (BOOL) isExecuting;
- (void) cancel;
- (void) setAllowCompressedResponse:(BOOL) allow;
- (void) setDelegate:(id) delegate;
- (id) operation;
- (void) setOperation:(id) operation;
- (void) startSynchronous;
- (void) startAsynchronous;
- (void) clearDelegatesAndCancel;
- (void) setTimeOutSeconds:(NSTimeInterval) time;
- (NSURL *) url;
- (void) setRequestCookies:(NSMutableArray *) cookie;
- (void) setRequestHeaders:(NSMutableDictionary *) header;
- (void) setShowAccurateProgress:(BOOL) progress;
- (void) setDownloadProgressDelegate:(id) progressDelegate;
- (BOOL) isFinished;
- (void) setShouldContinueWhenAppEntersBackground:(BOOL) p;
- (void) setUseCookiePersistence:(BOOL) p;
- (BOOL) isCancelled;
- (void) setCacheStoragePolicy:(int) p;
- (void) setDownloadCache:(id) d;
- (void) setDefaultDownloadCache;
- (void) setCompletionBlock:(WVRequestBasicBlock)aCompletionBlock;
- (void) setFailedBlock:(WVRequestBasicBlock)aFailedBlock;
@end