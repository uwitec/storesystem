#include "StdAfx.h"
#include "SqlCmd.h"
#include "TypeDefine.h"
#include "LogManager.h"
#include "Logic.h"
const char* SqlCmd::kTableName[];
const char* SqlCmd::kSqlCmdTypeName[];
SqlCmd::SqlCmd(void)
: m_pLogic(NULL)
{
	m_py.loadModule("common.cmd");
	m_pLog = LogManager::getSingleton().getLog("SqlCmd");
	m_pLog->setStdStreamActive(true);
	initTableName();
	initSqlCmdTypeName();
}

SqlCmd::~SqlCmd(void)
{
}

void SqlCmd::login(const char* userName, const char* password)
{
	// 获取python login对象
	PyObjectPtr user_class = m_py.getModuleFunction("User");
	PyObjectPtr user_obj = m_py.callFunction( user_class, "" );
	m_py.setObjAttrString(user_obj, "name", userName);
	m_py.setObjAttrString(user_obj, "password", password);

	// 获取Cmd对象
	PyObjectPtr cmd_obj = this->getCmdObject( kTableName[SqlTable_User], kSqlCmdTypeName[SqlCmdType_Login], "", user_obj );
	this->executeCmd( cmd_obj );
}

QString SqlCmd::getCmdMsg(const QString& tableName,
	const QString& cmdType, const QString& command)
{
	PyObjectPtr get_cmd_msg_func = m_py.getModuleFunction("get_cmd_msg");
	PyObjectPtr cmd_msg_obj = m_py.callFunction(get_cmd_msg_func, "sss",
		Q_To_CStr(tableName), Q_To_CStr(cmdType), Q_To_CStr(command));
	return PyString_AsString(cmd_msg_obj.get());
}
void SqlCmd::cutReplyMsg(const QString& replyMsg, QString& fullMsg, int32& hadCut)
{
	PyObjectPtr get_msg_func = m_py.getModuleFunction("get_msg_from_fmt");
	PyObjectPtr res = m_py.callFunction(get_msg_func, "s", Q_To_CStr(replyMsg));
	hadCut = PyLong_AsLong(PyTuple_GetItem(res.get(), 1));
	if( hadCut == -1 )
		fullMsg = "";
	else
		fullMsg = PyString_AsString(PyTuple_GetItem(res.get(), 0));
	m_pLog->debug(Q_To_CStr(fullMsg));
}

PyObjectPtr SqlCmd::parseCmdData(const QString& fullMsg,
								 QString& tableName,
								 QString& cmdType)
{
	PyObjectPtr unmarshal_func = m_py.getModuleFunction("unmarshal");
	PyObjectPtr cmd_data_obj = m_py.callFunction(unmarshal_func, "s", Q_To_CStr(fullMsg));
	tableName = m_py.getObjAttrString(cmd_data_obj, "cmd_table");
	cmdType = m_py.getObjAttrString(cmd_data_obj, "cmd_type");
	return cmd_data_obj;
}

void SqlCmd::parseCmdDataResult(PyObjectPtr& cmd_obj, bool& isLogined, int32& author)
{
	PyObjectPtr tuple_res = m_py.getObjAttrObject(cmd_obj, "cmd_result");
	isLogined = PyLong_AsLong(PyTuple_GetItem(tuple_res.get(), 0));
	if( isLogined )
		author = PyLong_AsLong(PyTuple_GetItem(tuple_res.get(), 1));
}

void SqlCmd::parseCmdDataResult(PyObjectPtr& cmd_obj, UserList& userList)
{
	userList.clear();
	PyObjectPtr list_res = m_py.getObjAttrObject(cmd_obj, "cmd_result");
	uint32 list_size = PyList_GET_SIZE(list_res.get());
	m_pLog->debug(std::string("list_size = ")+SConvert::toString(list_size));
	for( uint32 i = 0; i < list_size; ++i )
	{
		PyObjectPtr item(PyList_GetItem(list_res.get(), i));
		User user;
		user.name = m_py.getObjAttrString(item, "name");
		user.password = m_py.getObjAttrString(item, "password");
		user.authority = m_py.getObjAttrInt(item, "author");
		userList.push_back(user);
	}
}


void SqlCmd::parseCmdDataResult(PyObjectPtr& cmb_obj, int32& value)
{
	PyObjectPtr res = m_py.getObjAttrObject(cmb_obj, "cmd_result");
	value = PyLong_AsLong(res.get());
}

void SqlCmd::parseCmdDataResult(PyObjectPtr& cmd_obj, ProductPtrList& productList)
{
	ProductPtrList::iterator itr = productList.begin();
	ProductPtrList::iterator end = productList.end();
	while( itr != end )
	{
		delete *itr;
	}
	productList.clear();
	PyObjectPtr list_res = m_py.getObjAttrObject(cmd_obj, "cmd_result");
	uint32 list_size = PyList_GET_SIZE(list_res.get());
	for( uint32 i = 0; i < list_size; ++i )
	{
		PyObjectPtr item(PyList_GetItem(list_res.get(), i));
		Product* pPro = new Product;
		pPro->id = m_py.getObjAttrInt(item, "id");
		pPro->name = QString::fromLocal8Bit(m_py.getObjAttrString(item, "name"));
		productList.push_back(pPro);
	}
}
PyObjectPtr SqlCmd::getCmdObject(
	const char* tableName, const char* cmdType,
	const char* condition, PyObjectPtr& object)
{
	// 获取Cmd对象
	PyObjectPtr get_cmd_func = m_py.getModuleFunction("get_cmd");
	PyObjectPtr cmd_obj = m_py.callFunction(get_cmd_func, "s", tableName);

	// 调用set_cmd_type函数
	PyObjectPtr set_cmd_type_func(m_py.getFunction(cmd_obj, "set_cmd_type"), "set_cmd_type");
	m_py.callFunction( set_cmd_type_func, "s", cmdType );

	// 调用set_cmd_object函数
	PyObjectPtr set_cmd_object_func = m_py.getFunction(cmd_obj, "set_cmd_object");
	m_py.callFunction( set_cmd_object_func, "o", object.get() );

	// 调用set_cmd_condition函数
	PyObjectPtr set_cmd_condition_func = m_py.getFunction(cmd_obj, "set_cmd_condition");
	m_py.callFunction( set_cmd_condition_func, "s", condition );
	return cmd_obj;
}

void SqlCmd::executeCmd(const PyObjectPtr& cmd_obj)
{
	PyObjectPtr marshal_func = m_py.getModuleFunction("marshal");
	PyObjectPtr marshal_res = m_py.callFunction(marshal_func, "o", cmd_obj);
	PyObjectPtr fmt_msg_func = m_py.getModuleFunction("fmt_msg");
	PyObjectPtr fmt_msg_res = m_py.callFunction(fmt_msg_func, "o", marshal_res.get());
	if( m_pLogic )
		m_pLogic->executeCmd( PyString_AsString(fmt_msg_res.get()) );
}

void SqlCmd::initTableName()
{
	kTableName[SqlTable_User] = "user";
	kTableName[SqlTable_Product] = "product";
	kTableName[SqlTable_Factory] = "factory";
	kTableName[SqlTable_Purchase_Order] = "purchase_order";
	kTableName[SqlTable_Sale_Order] = "sale_order";
	kTableName[SqlTable_Return_Order] = "return_order";
}

void SqlCmd::initSqlCmdTypeName()
{
	kSqlCmdTypeName[SqlCmdType_Login] = "login";
	kSqlCmdTypeName[SqlCmdType_Logout] = "logout";
	kSqlCmdTypeName[SqlCmdType_Insert] = "insert";
	kSqlCmdTypeName[SqlCmdType_Select] = "select";
	kSqlCmdTypeName[SqlCmdType_Update] = "update";
	kSqlCmdTypeName[SqlCmdType_Delete] = "delete";
}