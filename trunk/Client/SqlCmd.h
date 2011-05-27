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
	// ����ģ�麯��
	// @param pyFuncObj, ��������
	// @param fmt, ������ʽ, s:�ַ���, i:����, f:�����ȸ���, d:˫���ȸ���
	//						 o:PyObject*
	// @param ...���ɱ����
	// @remark, ��printf�÷�����
	// @return ����ֵ�� �������ý��
	PyObjectPtr callFunction(PyObjectPtr& pyFuncObj, const char* fmt, ...);
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