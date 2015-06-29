# PKLormapping
1.特性

•支持面向对象，零SQL操作数据库<br>
•支持模拟器版本和真机版本<br>
•支持自定义SQL扩展<br>
•支持1级缓存，万级数据可达到百倍速度获取<br>
•支持c中基础类型映射，推荐使用NSNumber进行封装<br>
•支持分页查询，排序<br>
•支持线程池，默认为1，可自定义<br>
•支持多线程并发处理，线程安全<br>
•支持HQL语句<br>
•支持多表联动查询映射<br>
•支持事务处理机制<br>
•支持批量插入和更新<br><br>

⌀目前不支持join连接方式自动补全<br><br>

1.1版本<br>
修复：<br>
➤属性空值SQL映射失败BUG<br>
➤修复使用过程中数据内存占用问题<br><br>

新增：<br>
➤新增多表联动查询功能<br>
➤新增事务处理机制<br>
➤新增批量处理API，实测万级数据插入快3倍以上<br><br>

优化：<br>
➤优化1级缓存，减少内存压力<br>

2.接口说明<br>
 
开发中常用接口(可点开框架接口查看)：<br>

1)	PKLormapping ：框架头文件<br>
2)	PKHQLer ：HQL帮助类，负责组装条件查询，分页和排序<br>
3)	PKQueryPage ：分页类，负责分页<br>
4)	PKAccessThread ：数据库访问线程<br><br>

映射表命名规则<br>
表名 ：T_XXX_XX<br>
字段名 ：XXX_XX<br>
命名中数字不用下横线分割<br>
映射对象命名规则<br>
类名：驼峰命名方式，每个峰映射表名中的下横线，如：UserInfo -> T_USER_INFO<br>
属性名：驼峰命名方式，每个峰映射字段中的下横线，如：userId -> USER_ID<br>
类型：int,float,double类型最好使用NSNumber 存储，否则无法识别是否为空 命名中数字不用下横线分割<br><br>

5)	PKDataAccessDelegate ：数据回调接口<br>
6)	PKBaseEntityCategory ： 基础类类别<br><br>

3.	Demo<br>
//创建数据库访问线程池<br>

PKAccessThread ＊thread = [[PKAccessThread alloc] initWithSQLitePath:@"lorm.sqlite"];<br>
thread.poolCount = 2;//线程池并发数，默认1<br><br>

//创建某个对象<br>

    UserInfo *userInfo = [[UserInfo alloc] init];<br>
    userInfo.name = @"周先生";<br>
    userInfo.sex = @"男";<br>
    userInfo.age = 101;<br>
    userInfo.number = [NSNumber numberWithDouble:123.334];<br>
    userInfo.date = [NSDate date];<br><br>

//创建HQL帮助类<br>

    PKHQLer *hql = [[PKHQLer alloc] initForEntity:userInfo];<br>
[hql addLike:@"name" value:@"周"];//添加查询条件<br>

//创建分页类<br>

    PKQueryPage *queryPage = [[PKQueryPage alloc] init];<br>
    queryPage.rows = 100;//每页行数<br>
    queryPage.page = 0;//第x页<br>
hql.queryPage = queryPage;//放入HQL帮助类<br><br>

//创建访问线程加入线程池<br>
 *  多线程操作数据库初始化
 *  path为数据库路径
 */

-(id) initWithSQLitePath:(NSString *) path;<br><br>

/*
 * 创建通用数据库的线程，并加入到线程池
 * sql为执行sql
 * delegate 通过代理返回结果集
 */

-(void) execute:(NSString *) sql callBackTarget:(id) delegate;<br><br>

/*
 * 创建一个访问数据库的线程，并加入到线程池
 * obj 是注入对象，若请求是select需要添加注入对象
 * delegate 通过代理返回结果集
 */

-(void) queryExecute:(PKHQLer *) hql injectObj:(id) obj callBackTarget:(id) delegate;<br><br>

/*
 * 创建一个插入数据库的线程，并加入到线程池
 * obj 是注入对象，若请求是select需要添加注入对象
 * delegate 通过代理返回结果集
 */

-(void) insertExecute:(id) obj callBackTarget:(id) delegate;<br><br>

/*
 * 创建一个修改数据库的线程，并加入到线程池
 * obj 是注入对象，若请求是select需要添加注入对象
 * delegate 通过代理返回结果集
 */

-(void) updateExecute:(PKHQLer *) hql injectObj:(id) obj callBackTarget:(id) delegate;<br><br>

/*
 * 创建一个删除数据库的线程，并加入到线程池
 * obj 是注入对象，若请求是select需要添加注入对象
 * delegate 通过代理返回结果集
 */

-(void) deleteExecute:(PKHQLer *) hql injectObj:(id) obj callBackTarget:(id) delegate;<br><br>

/*
 * 创建一个查询总数数据库的线程，并加入到线程池
 * delegate 通过代理返回结果集
 */

-(void) countExecute:(PKHQLer *) hql injectObj:(id) obj callBackTarget:(id) delegate;<br><br>

/*
 *  创建一个批量插入数据库线程，并加入线程池
 *  batchArray 批量处理数据列表，元素必须为同类型对象
 *  delegate 通过代理返回结果集
 */

-(void) batchInsertExecute:(NSArray *) batchArray callBackTarget:(id) delegate;<br><br>

/*
 *  创建一个批量插入数据库线程，并加入线程池
 *  batchArray 批量处理数据列表，元素必须为同类型对象
 *  delegate 通过代理返回结果集
 */

-(void) batchUpdateExecute:(PKHQLer *) hql batchArray:(NSArray *) batchArray callBackTarget:(id) delegate;<br><br>

/*
 *  关闭数据库线程
 */

-(void) closeDataBaseThread;

//结果集回调函数<br>
//rs为返回的数据列表，state为SQL执行状态，YES为执行成功，NO为执行失败。<br>

-(void) dataResult:(id)rs state:(BOOL)state{……}<br><br>

UserInfo *userInfo = [[UserInfo alloc] init];//主表对象

    PKMultipleEntityBean *multipleEntiryBean = [[PKMultipleEntityBean alloc] init];//多表映射设置<br>
    multipleEntiryBean.mappingClass = [AddressBook class];//映射类<br>
    multipleEntiryBean.foreignKeyMapping = [NSDictionary dictionaryWithObject:@"userId" forKey:@"id"];//映射字段<br>
    
 mappingClass ：映射数组的对象class<br>
 foreignKeyMapping : 外键映射 ,key 为主键 （主表）, value 为外键 (从表)<br>
 如：{ id : userId } 对应数据库语句 -> id （主表）=  userId （从表）<br>
 
    PKArray *addressBookArray = [[PKArray alloc] init];//创建映射数组对象<br>
    addressBookArray.multipleEntityBean = multipleEntiryBean;//把关联表映射信息放入数组<br>
    userInfo.addressBook = addressBookArray;//从表映射设置完毕后放入需要映射的属性<br>
    
    PKHQLer *hql = [[PKHQLer alloc] initForEntity:userInfo];<br>
    [thread queryExecute:hql injectObj:userInfo callBackTarget:self];<br>

PS：<br>
主键和外键映射的属性非对象类型，必须用NSNumber类型才能自增长。<br>
多表关联映射，映射数组必须为PKArray数组。<br>
引用方式：#import "PKLormapping.framework/Headers/PKArray.h"<br>


4.	导入方式
 
头文件引用：<br>
#import "PKLormapping.framework/Headers/PKLormapping.h"<br><br>

5.	反馈<br>
author：周老师<br>
QQ：974871365<br>
e-mail：packyzhou@icloud.com<br>
Blog: http://blog.csdn.net/packyzhou<br><br>

