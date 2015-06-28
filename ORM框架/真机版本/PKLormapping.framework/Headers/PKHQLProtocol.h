//
//  PKHQLProtocol.h
//  PKLormapping
//
//  Created by 周老师 on 15/6/20.
//  Copyright © 2015年 packy. All rights reserved.
//

#ifndef PKHQLProtocol_h
#define PKHQLProtocol_h


#endif /* PKHQLProtocol_h */
#import "PKEntityProtocol.h"

@class PKHQLer;

@protocol PKHQLProtocol
-(PKHQLer *) initForEntity:(id<PKEntityProtocol>) entiy;

/*添加等于比较条件
 * key为列名，value为值
 * 如:id == 1
 */
-(PKHQLer *) addEqual:(NSString *)key  value:(id) value;

/*添加不等于比较条件
 * key为列名，value为值
 * 如:id != 1
 */
-(PKHQLer *) addNotEqual:(NSString *)key  value:(id) value;

/*添加前后模糊查询条件
 * key为列名，value为值
 * 如:name like '%tom%'
 */
-(PKHQLer *) addLike:(NSString *)key  value:(id) value;

/*添加非前后模糊查询条件
 * key为列名，value为值
 * 如:name not like '%tom%'
 */
-(PKHQLer *) addNotLike:(NSString *)key  value:(id) value;

/*添加前置模糊查询条件
 * key为列名，value为值
 * 如:name like '%tom'
 */
-(PKHQLer *) addStartLike:(NSString *)key  value:(id) value;

/*添加后置模糊查询条件
 * key为列名，value为值
 * 如:name like 'tom%'
 */
-(PKHQLer *) addEndLike:(NSString *)key  value:(id) value;

/*添加in 查询条件
 * key为列名，value为值
 * 如:id in (1,2,3)
 */
-(PKHQLer *) addIn:(NSString *)key  value:(NSArray *) value;

/*添加not in 查询条件
 * key为列名，value为值
 * 如:id not in (1,2,3)
 */
-(PKHQLer *) addNotIn:(NSString *)key  value:(NSArray *) value;

/*添加 is null 查询条件
 * key为列名，value为值
 * 如:is null
 */
-(PKHQLer *) addIsNull:(NSString *)key ;

/*添加 is not null 查询条件
 * key为列名，value为值
 * 如:id not in (1,2,3)
 */
-(PKHQLer *) addNotNull:(NSString *)key ;

/*添加 小于 查询条件
 * key为列名，value为值
 * 如: id < 100
 */
-(PKHQLer *) addLessThan:(NSString *)key  value:(id) value;

/*添加 小于 查询条件
 * key为列名，value为值
 * 如: id <= 100
 */
-(PKHQLer *) addLessEqualThan:(NSString *)key  value:(id) value;

/*添加 大于 查询条件
 * key为列名，value为值
 * 如: id > 100
 */
-(PKHQLer *) addGreatThan:(NSString *)key  value:(id) value;

/*添加 大于等于 查询条件
 * key为列名，value为值
 * 如: id > 100
 */
-(PKHQLer *) addGreatEqualThan:(NSString *)key  value:(id) value;

/*添加 日期之间 查询条件
 * key为列名，startDate为开始时间 ，endDate 为结束时间
 * 如: date between '2015-02-20' and '2015-02-23'
 */
-(PKHQLer *) addBetweenDate:(NSString *)key  startDate:(NSString *) startDate endDate:(NSString *) endDate;

/*添加 等于日期 查询条件
 * key为列名，value为值
 * 如: date < '2015-02-20'
 */
-(PKHQLer *) addEqualDate:(NSString *)key  date:(NSString *) date;

/*添加 小于日期 查询条件
 * key为列名，value为值
 * 如: date < '2015-02-20'
 */
-(PKHQLer *) addLessDate:(NSString *)key  date:(NSString *) date;

/*添加 小于等于日期 查询条件
 * key为列名，value为值
 * 如: date <＝ '2015-02-20'
 */
-(PKHQLer *) addLessEqualDate:(NSString *)key  date:(NSString *) date;

/*添加 大于日期 查询条件
 * key为列名，value为值
 * 如: date >= '2015-02-20'
 */
-(PKHQLer *) addGreatDate:(NSString *)key  date:(NSString *) date;

/*添加 大于等于日期 查询条件
 * key为列名，value为值
 * 如: date >= '2015-02-20'
 */
-(PKHQLer *) addGreatEqualDate:(NSString *)key  date:(NSString *) date;

/*添加 or 查询条件
 * key为列名，hql为查询语句
 * 如: date >= '2015-02-20'
 */
-(PKHQLer *) addOr:(PKHQLer *) hql;

/*添加 全部为 or 查询条件
 * key为列名，hql为查询语句
 * 如: date >= '2015-02-20'
 */
-(PKHQLer *) addAllOr:(PKHQLer *) hql;


/*添加 排序
 * key为列名，type为 "desc" or "asc"
 * 如: order by id asc
 */
-(PKHQLer *) addOrderBy:(NSString *) key type:(NSString *)type;

/*获取查询语句*/
-(NSString *) getHQL;
@end