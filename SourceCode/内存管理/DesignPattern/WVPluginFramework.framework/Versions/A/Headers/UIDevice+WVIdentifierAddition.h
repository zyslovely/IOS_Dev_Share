//
//  UIDevice+WVPlugin.h
//  YYZPlugin
//
//  Created by christ.yuj on 13-5-28.
//  Copyright (c) 2013年 颜 垣. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIDevice (WVIdentifierAddition)

/*
 * @method uniqueDeviceIdentifier
 * @description use this method when you need a unique identifier in one app.
 * It generates a hash from the MAC-address in combination with the bundle identifier
 * of your app.
 */

- (NSString *) uniqueDeviceIdentifierForWV;

/*
 * @method uniqueGlobalDeviceIdentifier
 * @description use this method when you need a unique global identifier to track a device
 * with multiple apps. as example a advertising network will use this method to track the device
 * from different apps.
 * It generates a hash from the MAC-address only.
 */

- (NSString *) uniqueGlobalDeviceIdentifierForWV;

@end
