//
//  SHViewController.m
//  DesignPattern
//
//  Created by eason on 3/11/14.
//  Copyright (c) 2014 alibaba. All rights reserved.
//

#import "SHViewController.h"

@interface SHViewController ()

@end

@implementation SHViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    [NSHTTPCookieStorage sharedHTTPCookieStorage].cookieAcceptPolicy =
    NSHTTPCookieAcceptPolicyAlways;
    
    NSString *url = @"http://10.230.227.28:8888/login.do?redirectUrl=&token=AAoBARDe5fiV1ygY2crkwg0grAIoATIURubVusIuf5GX_X87U6EZqUkXcuE6EFY3CFzq5tHQ6vKAefmTTng";
    
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:url]];
    
//    UIWebView *webView = [[UIWebView alloc] initWithFrame:CGRectMake(0, 20, 320, CGRectGetHeight(self.view.frame)-20)];
//    [webView loadRequest:[NSURLRequest requestWithURL:[NSURL URLWithString:url]]];
//    [self.view addSubview:webView];
    
//    UITextField *textField = [[UITextField alloc] initWithFrame:CGRectMake(0, 0, 320, 20)];
//    textField.text = url;
//    textField.center = self.view.center;
//    [self.view addSubview:textField];
    
    
//    self.view.backgroundColor = [UIColor whiteColor];
//    
//    NSNumber *number    = [NSNumber numberWithInt:1];
//    NSNumber *number1   = [NSNumber numberWithBool:YES];
//    NSNumber *number2   = [NSNumber numberWithFloat:1.0];
//    NSNumber *number3   = [NSNumber numberWithLong:1L];
//    NSNumber *number4   = [NSNumber numberWithInteger:@1];
//    
//    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleReceiveNotification:) name:@"notif" object:nil];
//    
//    [self postNotification];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)postNotification
{
    [[NSNotificationCenter defaultCenter] postNotificationName:@"notif" object:nil];
}

- (void)handleReceiveNotification:(NSNotification *)notif
{
    NSLog(@"哈哈哈哈");
}


- (void)dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}
@end
