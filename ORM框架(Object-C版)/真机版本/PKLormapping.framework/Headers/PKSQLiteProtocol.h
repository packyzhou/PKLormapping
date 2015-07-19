//
//  PKSQLiteProtocol.h
//  PKlormTest
//
//  Created by 周老师 on 15/6/26.
//  Copyright (c) 2015年 packy. All rights reserved.
//

#ifndef PKlormTest_PKSQLiteProtocol_h
#define PKlormTest_PKSQLiteProtocol_h

@protocol PKSQLiteProtocol

-(id) initWithSQLite:(NSString *) fileName ;//初始化数据库实例
-(BOOL) cheackTableExist:(NSString *) tableName;//检查表示否存在
-(BOOL) createTable:(NSString *) tableName columnName:(NSString *) columnName,...;//创建表
-(BOOL) createTable:(NSString *) tableName columnNames:(NSArray *) columnNames;//创建表
-(sqlite3_stmt *) selectBySQL:(NSString *) sql;//根据SQL查询
-(sqlite3_stmt *) select:(NSString *)tableName sort:(NSString *)sort condition:(NSString *) condition,...;//根据条件查询
-(BOOL) deleted:(NSString *)tableName condition:(NSString *) condition,...;//删除
//执行事务的sql语句
-(BOOL) execute:(NSString *)sql;
-(void) closeDB;//关闭数据库
-(void) doCommit;//提交事务
-(void)doBegin;//开始事务
-(void) backUp;//事务回滚

@end
#endif
