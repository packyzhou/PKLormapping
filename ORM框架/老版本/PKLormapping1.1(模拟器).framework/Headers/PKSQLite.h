//
//  PKSQLite.h
//  PKFrameTest
//
//  Created by 周老师 on 15/6/23.
//  Copyright © 2015年 packy. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <sqlite3.h>
#import "PKTableBean.h"
#import "PKCharacterOperate.h"
#import "PKSQLiteProtocol.h"
@interface PKSQLite : NSObject<PKSQLiteProtocol>
{
    sqlite3 *db;
}
@end
