//
//  PKCharacterOperate.h
//  PKLormapping
//
//  Created by 周老师 on 15/6/23.
//  Copyright © 2015年 packy. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#import "PKClassBean.h"
#import "PKTableBean.h"
#import "PKUnitCommon.h"
@interface PKCharacterOperate : NSObject
/*  驼峰字符串处理成数据库字符串
 *  如：userInfo -> USER_INFO
 */
+(NSString *) humpCharacterOperate:(NSString *) c;

/*  类获取属性列表
 *  UserInfo -> {Map{name,type},Map{sex,type},Map{age,type}}
 *  map{属性名,字段类型}
 */
+(NSArray *) classPropertyWithArray:(Class) class;

/*  类映射表字段列表
 *  UserInfo -> {Map{name,type},Map{sex,type},Map{age,type}}
 *  map{字段名,字段类型}
 */
+(NSArray *) classColumnWithArray:(Class) class;

/*  对象类型字符串转数据库类型
 *  NSString -> Text
 */
+(NSString *) objTypeTranslateDataType:(NSString *) type;

/*
 * 映射类型字符处理
 */
+(id) extraMapping:(id) value type:(NSString *)type;
@end
