//
//  PKMappingCategory.h
//  PKlormTest
//
//  Created by 周老师 on 15/6/25.
//  Copyright (c) 2015年 packy. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PKMapping.h"
#import "PKArray.h"
//映射辅助分类
@interface PKMapping (PKMappingCategory)
//查询
-(NSString *) mappingQueryColumnsToSQL:(NSArray *)columns;
-(NSMutableArray *) mappingObject:(sqlite3_stmt *) result obj:(id)obj;
-(void) mappingPropertyWithColumn:(NSString *) columnType object:(id) rsObj index:(int) i sqliteResult:(sqlite3_stmt *) resul;
//增加
-(NSString *) mappingInsertColumnsToSQL:(id) obj;
-(void) mappingInsertValuesToSQL:(NSMutableString *)sql obj:(id) obj;
//更新
-(void) mappingUpdateValuesToSQL:(NSMutableString *)sql obj:(id) obj;
@end
