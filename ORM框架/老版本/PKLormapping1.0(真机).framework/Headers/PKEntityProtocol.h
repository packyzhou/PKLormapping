
//
//  PKEntityProtocol.h
//  PKLormapping
//
//  Created by 周经伟 on 15/6/20.
//  Copyright © 2015年 packy. All rights reserved.
//

#ifndef PKEntityProtocol_h
#define PKEntityProtocol_h


#endif /* PKEntityProtocol_h */
@protocol PKEntityProtocol
-(NSString *) getEntityName;//获取类名
-(NSString *) getTableName;//获取表名,prefix为前缀，若类名包括项目签字，则填上

-(NSArray *) getPropertys;//获取类属性列表
-(NSArray *) getColumns;//获取表字段列表

-(NSString *) getClassType;//获取对象类型
@end