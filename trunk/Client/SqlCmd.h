#pragma once
#include "PyInterface.h"
class Logic;
enum SqlTable
{
	SqlTable_User			= 0,
	SqlTable_Product		= 1,
	SqlTable_Factory		= 2,
	SqlTable_Purchase_Order = 3,
	SqlTable_Sale_Order		= 4,
	SqlTable_Return_Order	= 5
};
enum SqlCmdType
{
	SqlCmdType_Login = 0,
	SqlCmdType_Logout = 1,
	SqlCmdType_Insert = 2,
	SqlCmdType_Select = 3,
	SqlCmdType_Update = 4,
	SqlCmdType_Delete = 5
};
class SqlCmd
{
public:
	SqlCmd(void);
	virtual ~SqlCmd(void);
	void setLogic(Logic* pLogic){ m_pLogic = pLogic; }
	void login(const char* userName, const char* password);
protected:
	// 调用模块函数
	// @param pyFuncObj, 函数对象
	// @param fmt, 参数格式, s:字符串, i:整型, f:单精度浮点, d:双精度浮点
	//						 o:PyObject*
	// @param ...，可变参数
	// @remark, 与printf用法类似
	// @return 返回值， 函数调用结果
	PyObjectPtr callFunction(PyObjectPtr& pyFuncObj, const char* fmt, ...);
	// 获取命令对象
	// @param tableName, 表名
	// @param cmdType, 命令名
	// @param condition, 条件语句
	// @param object, 命令对象
	PyObjectPtr getCmdObject(const char* tableName,
							 const char* cmdType,
							 const char* condition,
							 PyObjectPtr& object);
	void executeCmd(const PyObjectPtr& cmd_obj);
	PyInterface m_py;
	Log* m_pLog;
	Logic* m_pLogic;
	// 表名
	static void initTableName();
	static const int32 kTableNameSize = 6;
	static const char* kTableName[kTableNameSize];
	// sql命令
	static void initSqlCmdTypeName();
	static const uint32 kSqlCmdTypeNameSize = 6;
	static const char* kSqlCmdTypeName[kSqlCmdTypeNameSize];
};