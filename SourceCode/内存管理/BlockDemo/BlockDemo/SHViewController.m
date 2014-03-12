//
//  SHViewController.m
//  BlockDemo
//
//  Created by eason on 3/10/14.
//  Copyright (c) 2014 alibaba. All rights reserved.
//

#import "SHViewController.h"
#import "SHShowingView.h"
#import "SHBlockObject.h"
@interface SHViewController () <SHShowingViewDelegate>

@end

@implementation SHViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    

    /**
     *  exp1
     */
//    [self showDiff];

    /**
     *  exp2
     */
//    static int outA = 8;
//    int (^myPtr) (int) = ^(int a) {return outA+a;};
//   
//    outA = 5;
//    int result = myPtr(3);
//    NSLog(@"%d",result);
    
    /**
     *  exp3
     */
//    NSNumber *numberA = @8;
//    int (^myPtr1) (int) = ^(int a) {return [numberA intValue]+a;};
//    numberA = @12;
//    int result1 = myPtr1(3);
//    NSLog(@"%d",result1);
    
    /**
     *  OC中定义的一些block
     */
//    NSMutableArray *mulArray = [[NSMutableArray alloc] initWithObjects:@1,@2,@3,@4, nil];
//    [mulArray enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL *stop) {
//        NSLog(@"%@",obj);
//    }];
}


- (void)showVoidUsingBlock:(VoidBlockType)block
{
    if (block)
    {
        block();
    }
}

- (void)showIntUsingBlock:(IntParamBlockType)block
{
    int i = 5;
    if (block)
    {
        block(i);
    }
}
/**
 *  delegate和block的区别
 */
- (void)showDiff
{
    SHShowingView *showingView = [[SHShowingView alloc] initWithFrame:CGRectMake(0, 0, 260, 400)];
    showingView.delegate = self;
    showingView.center = self.view.center;
    [showingView setBtnClickType:^{
        UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"悲剧" message:@"去死吧，屌丝，还想泡老娘" delegate:nil cancelButtonTitle:@"人艰不拆" otherButtonTitles:@"伤不起", nil];
        [alertView show];
    }];
    [self.view addSubview:showingView];
}

#pragma mark -
#pragma mark SHShowingView Delegate
- (void)SHShowingViewLoveBtnClick:(SHShowingView *)view
{
    UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"悲剧" message:@"去死吧，屌丝，还想泡老娘" delegate:nil cancelButtonTitle:@"人艰不拆" otherButtonTitles:@"伤不起", nil];
    [alertView show];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
