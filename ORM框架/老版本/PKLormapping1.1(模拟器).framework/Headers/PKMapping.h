//
//  PKMapping.h
//  PKFrameworkThreadTest
//
//  Created by 周老师 on 15/6/24.
//  Copyright © 2015年 packy. All rights reserved.
//  对象映射类

#import <Foundation/Foundation.h>
#import "PKSQLite.h"
#import "PKBaseEntityCategory.h"
#import "PKUnitCommon.h"
#import "PKHQLer.h"
#import "PKMappingProtocol.h"
#import "PKCharacterOperate.h"
/*
 *  映射表命名规则
 *  表名 ：T_XXX_XX
 *  字段名 ：XXX_XX
 *  命名中数字不用下横线分割
 */

/*
 *  映射对象命名规则
 *  类名：驼峰命名方式，每个峰映射表名中的下横线，如：UserInfo -> T_USER_INFO
 *  属性名：驼峰命名方式，每个峰映射字段中的下横线，如：userId -> USER_ID
 *  类型：int,float,double类型最好使用NSNumber 存储，否则无法识别是否为空
 *  命名中数字不用下横线分割
 */
static PKSQLite *sqlite ;//sqlite处理类
typedef void (^returnSQL)(NSString *sqlBlock);

@interface PKMapping : NSObject<PKMappingProtocol>
{

}
@property(readonly,nonatomic,strong) PKSQLite *sqliteDB;

@end
