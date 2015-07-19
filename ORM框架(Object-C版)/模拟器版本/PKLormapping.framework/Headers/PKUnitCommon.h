//
//  PKUnitCommon.h
//  PKFrameworkThreadTest
//
//  Created by 周老师 on 15/6/24.
//  Copyright © 2015年 packy. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PKUnitCommon : NSObject
/*
 *  date类型转string类型
 */
+(NSString *) dateFormatterString:(NSDate *) date formatter:(NSString *) formatter;

/*
 *  string类型转date类型
 */
+(NSDate *) stringFormatterDate:(NSString *) dateStr formatter:(NSString *) formatter;

/*
 *  日志打印
 */
+(void) sqlPrintln:(NSString *) msg;
@end
