//
//  PKQueryPage.h
//  PKLormapping
//
//  Created by 周老师 on 15/6/20.
//  Copyright © 2015年 packy. All rights reserved.

//分页

#import <Foundation/Foundation.h>

@interface PKQueryPage : NSObject
@property NSInteger rows;//每页行数
@property NSInteger page;//第x页
@property NSInteger recordCount;//总行数
@property NSInteger pageCount;//总页数
@property(copy,nonatomic) NSString *sort;//排序的字段
@property(copy,nonatomic) NSString *order;//排序方式 asc desc
@end
