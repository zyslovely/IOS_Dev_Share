//
//  WVDateUtil.h
//
//  Created by  shuxiao on 14-1-2.
//  Copyright (c) 2014年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WVDateUtil : NSObject

/**
 *	返回当前时间,单位为毫秒
 *
 *	@return	以毫秒为单位的当前时间
 */
+ (double)currentTimeInMilliseconds;


/**
 *	返回date的毫秒数
 *
 *	@param 	date 	指定时间
 *
 *	@return	毫秒数
 */
+ (double)millisecondsWithDate:(NSDate *)date;


/**
 *	设置date的时,分,秒,年月日保持不变
 *
 *	@param 	originalDate 	原始时间
 *	@param 	hour 	新的小时
 *	@param 	miniute 	新的分钟
 *	@param 	second 	新的秒数
 *
 *	@return	修改后的date
 */
+ (NSDate *)resetDate:(NSDate *)originalDate hour:(NSInteger)hour miniute:(NSInteger)miniute second:(NSInteger)second;



/**
 *	获取今天指定时,分,秒的毫秒数
 *
 *	@param 	hour 	新的小时
 *	@param 	miniute 	新的分钟
 *	@param 	second 	新的秒数
 *
 *	@return	指定后的毫秒数
 */
+ (double)millisecondsTodayWithHour:(NSInteger)hour miniute:(NSInteger)miniute second:(NSInteger)second;

/**
 *	只获取该date的年月日
 *
 *	@param 	originalDate 	
 *
 *	@return
 */
+ (NSDate *)dateWithOnlyYearMonthDay:(NSDate *)originalDate;


@end
