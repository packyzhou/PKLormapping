//
//  PKHQLer.h
//  PKLormapping
//
//  Created by 周老师 on 15/6/20.
//  Copyright © 2015年 packy. All rights reserved.

//  数据库对象访问帮助类
//  组装SQL语句

#import <Foundation/Foundation.h>
#import "PKHQLProtocol.h"
#import "PKQueryPage.h"
#import "PKCharacterOperate.h"
@interface PKHQLer : NSObject<PKHQLProtocol>

@property(copy,nonatomic) NSString *tableName;//表名
@property(strong,nonatomic) NSMutableString *queryConditions;//查询条件，NSString类型
@property(strong,nonatomic) NSMutableString *orderByCondition;//排序条件，NSString类型
@property(strong,nonatomic) PKQueryPage *queryPage;//分页查询
@property(strong,nonatomic) NSMutableArray *columnArrays;//字段列表

@end
