//
//  PKAccessTarget.h
//  PKFrameTest
//
//  Created by 周老师 on 15/6/23.
//  Copyright © 2015年 packy. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PKHQLer.h"
#import "PKDataAccessDelegate.h"
@interface PKAccessTarget : NSObject
@property BOOL isStop;
@property NSInteger timeOut;//超时时间，默认为3秒
@property(copy,nonatomic) NSString *sql;//执行SQL
@property id obj; //映射类
@property PKHQLer *hql;//hql辅助类
@property id<PKDataAccessDelegate> delegate;//代理
@end
