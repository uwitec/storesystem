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
	// ��ȡSQL����������Ϣ
	// @param tableName, �������
	// @param cmdType, ��������
	// @param command, SQL���
	// @return ����ֵ����ֱ�ӷ��͵�������Ϣ
	QString getCmdMsg(const QString& tableName,
		const QString& cmdType,
		const QString& command);
	// ��ȡ������Ϣ�е�������Ϣ
	// @param replyMsg, ������Ϣ
	// @param fullMsg, ����������������������Ϣ
	// @param hadCut, �����������ѽ�ȡ�ĳ���
	void cutReplyMsg(const QString& replyMsg,
					 QString& fullMsg,
					 int32& hadCut);
	// ��ȡ������Ϣ�е�CmdData����
	// @param fullMsg, ������������Ϣ��������cutReplyMsg�ĵڶ�����������
	// @param tableName, ������������ȡ���ı����
	// @param cmdType, ������������ȡ������������
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
	// ��ȡ�������
	// @param tableName, ����
	// @param cmdType, ������
	// @param condition, �������
	// @param object, �������
	PyObjectPtr getCmdObject(const char* tableName,
							 const char* cmdType,
							 const char* condition,
							 PyObjectPtr& object);	
	void executeCmd(const PyObjectPtr& cmd_obj);
	PyInterface m_py;
	Log* m_pLog;
	Logic* m_pLogic;
	// ����
	static void initTableName();
	static const int32 kTableNameSize = 6;
	static const char* kTableName[kTableNameSize];
	// sql����
	static void initSqlCmdTypeName();
	static const uint32 kSqlCmdTypeNameSize = 6;
	static const char* kSqlCmdTypeName[kSqlCmdTypeNameSize];
};