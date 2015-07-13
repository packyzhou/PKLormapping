//
//  PKMappingProtocol.h
//  PKlormTest
//
//  Created by 周老师 on 15/6/26.
//  Copyright (c) 2015年 packy. All rights reserved.
//

#ifndef PKlormTest_PKMappingProtocol_h
#define PKlormTest_PKMappingProtocol_h

@protocol PKMappingProtocol


-(id) initWithMapping:(NSString *) databaseFile;
/*
 *  查询映射
 *  sql：查询的SQL
 *  obj：映射对象
 *  返回一个映射对象
 */
-(id) queryMappingBySQL:(NSString *) sql obj:(id) object;
/*
 * 查询映射的SQL组装
 */
-(NSString *) queryMappingSQL:(id) object HQL:(PKHQLer *)hql;
/*
 *  插入映射
 */
-(BOOL) insertMappingBySQL:(id) object;

/*
 *  更新映射
 */
-(BOOL) updateMappingBySQL:(id) object HQL:(PKHQLer *)hql;

/*
 *  删除映射
 */
-(BOOL) deleteByHQL:(id) object HQL:(PKHQLer *)hql;

/*
 *  总数
 */
-(NSInteger) countBySQL:(id) object HQL:(PKHQLer *) hql;

/*
 *  预留关闭数据库用
 */
-(void) clean;

@end
#endif
