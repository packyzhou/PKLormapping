//
//  PKAccessThreadProtocol.h
//  PKlormTest
//
//  Created by 周老师 on 15/6/26.
//  Copyright (c) 2015年 packy. All rights reserved.
//

#ifndef PKlormTest_PKAccessThreadProtocol_h
#define PKlormTest_PKAccessThreadProtocol_h

@protocol PKAccessThreadProtocol

/*
 *  单例模式
 *  path为数据库路径
 */
+(id) shareAccess:(NSString *) path;

/*
 *  多线程操作数据库初始化
 *  path为数据库路径
 */
-(id) initWithSQLitePath:(NSString *) path;

/*
 * 创建通用数据库的线程，并加入到线程池
 * sql为执行sql
 * delegate 通过代理返回结果集
 */
-(void) execute:(NSString *) sql callBackTarget:(id) delegate;

/*
 * 创建一个访问数据库的线程，并加入到线程池
 * obj 是注入对象，若请求是select需要添加注入对象
 * delegate 通过代理返回结果集
 */
-(void) queryExecute:(PKHQLer *) hql injectObj:(id) obj callBackTarget:(id) delegate;

/*
 * 创建一个插入数据库的线程，并加入到线程池
 * obj 是注入对象，若请求是select需要添加注入对象
 * delegate 通过代理返回结果集
 */
-(void) insertExecute:(id) obj callBackTarget:(id) delegate;

/*
 * 创建一个修改数据库的线程，并加入到线程池
 * obj 是注入对象，若请求是select需要添加注入对象
 * delegate 通过代理返回结果集
 */
-(void) updateExecute:(PKHQLer *) hql injectObj:(id) obj callBackTarget:(id) delegate;

/*
 * 创建一个删除数据库的线程，并加入到线程池
 * obj 是注入对象，若请求是select需要添加注入对象
 * delegate 通过代理返回结果集
 */
-(void) deleteExecute:(PKHQLer *) hql injectObj:(id) obj callBackTarget:(id) delegate;

/*
 * 创建一个查询总数数据库的线程，并加入到线程池
 * delegate 通过代理返回结果集
 */
-(void) countExecute:(PKHQLer *) hql injectObj:(id) obj callBackTarget:(id) delegate;

/*
 *  创建一个批量插入数据库线程，并加入线程池
 *  batchArray 批量处理数据列表，元素必须为同类型对象
 *  delegate 通过代理返回结果集
 */
-(void) batchInsertExecute:(NSArray *) batchArray callBackTarget:(id) delegate;
/*
 *  创建一个批量插入数据库线程，并加入线程池
 *  batchArray 批量处理数据列表，元素必须为同类型对象
 *  delegate 通过代理返回结果集
 */
-(void) batchUpdateExecute:(PKHQLer *) hql batchArray:(NSArray *) batchArray callBackTarget:(id) delegate;

/*
 *  关闭数据库线程
 */
-(void) closeDataBaseThread;
@end
#endif
