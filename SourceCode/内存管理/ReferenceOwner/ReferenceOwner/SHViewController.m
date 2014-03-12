//
//  SHViewController.m
//  ReferenceOwner
//
//  Created by eason on 3/4/14.
//  Copyright (c) 2014 alibaba. All rights reserved.
//

#import "SHViewController.h"
#import "SHOwnerObject.h"
@interface SHViewController ()
{
    SHOwnerObject *_ownerObject;
}

@end

@implementation SHViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    
    SHOwnerObject *ownerObject = [[SHOwnerObject alloc] init];
    NSLog(@"[ownerObject retainCount]:%d",[ownerObject retainCount]);
    /**
     *  exp1.ownerObject创建了对象，_ownerObject对其做了一次retain，拥有了该对象，但是ownerObject 没有对该对象进行释放，导致内存泄露 (谁创建，谁释放)
     */
//        _ownerObject = [ownerObject retain];
//        NSLog(@"[_ownerObject retainCount]:%d",[_ownerObject retainCount]);
    /**
     *  exp2.对局部变量ownerObject 做了一次retain，成为_ownerObject拥有指向ownerObject的实例 (谁retain，谁释放)
     */
//    _ownerObject = [ownerObject retain];
//    NSLog(@"[_ownerObject retainCount]:%d",[_ownerObject retainCount]);
//    [ownerObject release];
    
    /**
     *  exp3.对局部变量ownerObject 没有做引用，成为_ownerObject拥有指向ownerObject的实例 (没创建且没retain，别释放)
     */
    //    _ownerObject = ownerObject;
    //    NSLog(@"[_ownerObject retainCount]:%d",[_ownerObject retainCount]);
    //    [ownerObject release];
    
    
    /**
     *  可以这么写
     */
//    _ownerObject = [[SHOwnerObject alloc] init];
//    NSLog(@"[_ownerObject retainCount]:%d",[_ownerObject retainCount]);
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}

- (void)dealloc
{
    /**
     *  对于exp1.内存泄露
     *  对于exp2.没问题
     *  对于exp3.crash
     */
    [_ownerObject release];
    [super dealloc];
}
@end
