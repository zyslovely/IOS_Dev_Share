//
//  SHAppDelegate.m
//  DesignPattern
//
//  Created by eason on 3/11/14.
//  Copyright (c) 2014 alibaba. All rights reserved.
//

#import "SHAppDelegate.h"
#import "SHViewController.h"
#import <WVPluginFramework/WVPluginFramework.h>
#import <WVPluginFramework/WVWebViewController.h>
@interface SHAppDelegate ()
{
    UINavigationController *nav;
    SHViewController *viewController;
}
@end
@implementation SHAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];

    
    // 执行初始化
   [WindVane initWindVanePlugin];
    
    viewController = [[SHViewController alloc] init];
//    viewController.isUseToolBar = NO;
//    viewController.loadUrl = @"http://10.230.227.28:8888/login.do?redirectUrl=&token=AAoBARC-0vb91igY2crkwg0grAIoATIUbhJBWPZQ0LvVsjjSI03JA6szkKU6EHkFg_j9hmvLrs-S75Vxh6E";
//    nav = [[UINavigationController  alloc] initWithRootViewController:viewController];
    [self.window setRootViewController:viewController];
    [self.window makeKeyAndVisible];
    // Override point for customization after application launch.
    return YES;
}
							
- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
