/*!
 * @FILE: YYZinit.h
 * @PROJECT: YYZPlugin
 * @DESCRIPTION:
 * Hybrid模块初始化接口
 *
 *  Created by 颜 垣 on 12-10-22.
 *  Copyright (c) 2012年 一淘网. All rights reserved.
 */
#import <Foundation/Foundation.h>

@interface YYZinit : NSObject

///////////////////// PROPERTY BEGIN //////////////////////////

// 是否正在执行垃圾清理行为
@property (assign, atomic) BOOL clearing;
// 是否正在执行初始化行为
@property (assign, atomic) BOOL initing;

///////////////////// PROPERTY END //////////////////////////

///////////////////// METHOD BEGIN //////////////////////////

/*!
 * 单例
 */
+ (id) instance;

/*!
 * 初始化Hybrid模块
 */
- (void) buildInitYYZ;

/*!
 * Hybrid模块更新
 */
- (void) checkYYZUpdate;

/*!
 * Hybrid模块垃圾清理
 */
- (void) clearSDFiles;

/*!
 * 检查当前时间点是否可以更新
 */
+ (BOOL) isNeedUpdate;

///////////////////// METHOD END //////////////////////////

@end
