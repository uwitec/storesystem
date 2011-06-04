#pragma once
#include "PyInterface.h"
#include "Tables.h"
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
	// 获取SQL命令网络消息
	// @param tableName, 表格名称
	// @param cmdType, 操作名称
	// @param command, SQL语句
	// @return 返回值，可直接发送的网络消息
	QString getCmdMsg(const QString& tableName,
		const QString& cmdType,
		const QString& command);
	// 提取网络消息中的完整消息
	// @param replyMsg, 网络消息
	// @param fullMsg, 传出参数，完整的网络消息
	// @param hadCut, 传出参数，已截取的长度
	void cutReplyMsg(const QString& replyMsg,
					 QString& fullMsg,
					 int32& hadCut);
	// 提取完整消息中的CmdData对象
	// @param fullMsg, 完整的网络消息，必须是cutReplyMsg的第二个传出参数
	// @param tableName, 传出参数，提取出的表格名
	// @param cmdType, 传出参数，提取出的命令类型
	PyObjectPtr parseCmdData(const QString& fullMsg,
					 QString& tableName,
					 QString& cmdType);
	void parseCmdDataResult(PyObjectPtr& cmd_obj,
					 bool& isLogined, int32& author);
	void parseCmdDataResult(PyObjectPtr& cmd_obj,
					 UserList& userList);
	void parseCmdDataResult(PyObjectPtr& cmb_obj,
					 int32& value);
	void parseCmdDataResult(PyObjectPtr& cmd_obj,
					 ProductPtrList& productList);
	void parseCmdDataResult(PyObjectPtr& cmd_obj,
					 FactoryPtrList& factoryPtrList);
protected:
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