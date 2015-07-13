
//
//  PKEntityProtocol.h
//  PKLormapping
//
//  Created by 周老师 on 15/6/20.
//  Copyright © 2015年 packy. All rights reserved.
//

#ifndef PKEntityProtocol_h
#define PKEntityProtocol_h


#endif /* PKEntityProtocol_h */
@protocol PKEntityProtocol
-(NSString *) getEntityName;//获取类名
-(NSString *) getTableName;//获取表名,prefix为前缀，若类名包括项目签字，则填上

-(NSArray *) getPropertys;//获取类部分属性列表
-(NSArray *) getColumns;//获取表部分字段列表

-(NSArray *) getAllPropertys;//获取类全部属性列表
-(NSArray *) getAllColumns;//获取表全部字段列表

-(NSString *) getClassType;//获取对象类型

-(NSArray *) getPropertysBesidesType:(Class) type array:(NSArray *) array;//获取除了type以外的属性
-(NSArray *) getColumnsBesidesType:(NSString *) type array:(NSArray *) array;//获取除type以外的字段

-(NSArray *) getOnlyTypeObject:(Class) type;//获取只有type的对象
@end