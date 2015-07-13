//
//  PKAccessThread.h
//  PKFrameTest
//
//  Created by 周老师 on 15/6/23.
//  Copyright © 2015年 packy. All rights reserved.

//访问SQLite线程
//多线程并发，线程超时，线程安全

#import <Foundation/Foundation.h>
#import "PKAccessTarget.h"
#import "PKUnitCommon.h"
#import "PKDataAccessDelegate.h"
#import "PKBaseEntityCategory.h"
#import "PKMapping.h"
#import "PKAccessThreadProtocol.h"
#define cachaCount 1 //缓存SQL数量
//typedef void (^result)(id rs);
static NSOperationQueue *poolQueue;//线程池
static NSMutableDictionary *cacheData;//缓存数据,key为查询SQL,Value为数据
static id sharedInstance;//数据库访问线程单例
@interface PKAccessThread : NSObject<PKAccessThreadProtocol>
{
    //映射
    PKMapping *mapping;
    //sqlite
}

@property(readonly,nonatomic) PKSQLite *sqlite;

@property NSInteger timeOut;//超时时间，默认为3秒
@property NSInteger poolCount;//线程池大小，默认为1
@property BOOL isCacheData;//是否缓存数据，默认为YES

@end
