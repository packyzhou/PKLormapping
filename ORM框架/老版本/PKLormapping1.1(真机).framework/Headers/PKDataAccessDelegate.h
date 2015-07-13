//
//  PKDataAccessDelegate.h
//  PKFrameworkThreadTest
//
//  Created by 周老师 on 15/6/24.
//  Copyright © 2015年 packy. All rights reserved.
//

#ifndef PKDataAccessDelegate_h
#define PKDataAccessDelegate_h


#endif /* PKDataAccessDelegate_h */

//数据访问协议
@protocol PKDataAccessDelegate
/*
 *  数据集回调
 *  rs:数据集
 *  state:状态 0为没数据返回，1为有数据返回
 */
-(void) dataResult:(id) rs state:(BOOL) state;
@end