//
//  PKMultipleEntityBean.h
//  PKlormTest
//
//  Created by 周老师 on 15/6/27.
//  Copyright (c) 2015年 packy. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PKMultipleEntityBean : NSObject
/*
 *  mappingClass ：映射数组的对象class
 *  foreignKeyMapping : 外键映射 ,key 为主键 （主表）, value 为外键 (从表)
 *  如：{ id : userId } 对应数据库语句 -> id （主表）=  userId （从表）
 */
@property Class mappingClass;//映射对象class
@property(strong,nonatomic) NSDictionary *foreignKeyMapping;//外键映射
@end
