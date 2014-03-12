//
//  SHViewController.m
//  PropertyDemo
//
//  Created by eason on 3/11/14.
//  Copyright (c) 2014 alibaba. All rights reserved.
//

#import "SHViewController.h"
#import "SHPropertyObject.h"
#import "SHRetainObject.h"
@interface SHViewController ()

@end

@implementation SHViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    SHPropertyObject *propertyObj = [[[SHPropertyObject alloc] init]autorelease];
    
    /**
     *  readOnly Obj
     */
//    propertyObj.readOnlyObj = [[SHRetainObject alloc] init];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
