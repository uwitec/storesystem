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
	PyObjectPtr user_obj = this->callFunction( user_class, "" );
	m_py.setObjAttrString(user_obj, "name", userName);
	m_py.setObjAttrString(user_obj, "password", password);

	// 获取Cmd对象
	PyObjectPtr cmd_obj = this->getCmdObject( kTableName[SqlTable_User], kSqlCmdTypeName[SqlCmdType_Login], "", user_obj );
	this->executeCmd( cmd_obj );
}

PyObjectPtr SqlCmd::callFunction(PyObjectPtr& pyFuncObj, const char* fmt, ...)
{
	va_list v;
	uint32 narg = 0;
	va_start(v, fmt);
	// 检查有效参数
	uint32 fmtLen = strlen(fmt);
	for( uint32 i = 0; i < fmtLen; ++i )
	{
		if( fmt[i] == 's' ) ++narg;
		else if( fmt[i] == 'i' ) ++narg;
		else if( fmt[i] == 'f' ) ++narg;
		else if( fmt[i] == 'd' ) ++narg;
		else if( fmt[i] == 'o' ) ++narg;
		else
		{
			m_pLog->warning(std::string("callFunction fmt ") + fmt[i] + " is not fmt");
		}
	}
	if( fmtLen != narg )
	{
		m_pLog->warning(std::string("callFunction NOT all fmt=") + fmt + " is valid.");
	}
	PyObjectPtr args(PyTuple_New(narg), "args");
	int32 index = 0;
	for( uint32 i = 0; i < fmtLen; ++i )
	{
		if( fmt[i] == 's' )
			PyTuple_SetItem(args.get(), index++, PyString_FromString(va_arg(v, char*)) );
		else if( fmt[i] == 'i' )
			PyTuple_SetItem(args.get(), index++, PyInt_FromLong(va_arg(v, int)));
		else if( fmt[i] == 'f' )
			PyTuple_SetItem(args.get(), index++, PyFloat_FromDouble(va_arg(v, float)));
		else if( fmt[i] == 'd' )
			PyTuple_SetItem(args.get(), index++, PyFloat_FromDouble(va_arg(v, float)));
		else if( fmt[i] == 'o' )
			PyTuple_SetItem(args.get(), index++, va_arg(v, PyObject*));
	}
	PyObjectPtr values( PyObject_CallObject(pyFuncObj.get(), args.get()), "value" );
	va_end(v);
	return values;
}

PyObjectPtr SqlCmd::getCmdObject(
	const char* tableName, const char* cmdType,
	const char* condition, PyObjectPtr& object)
{
	// 获取Cmd对象
	PyObjectPtr get_cmd_func = m_py.getModuleFunction("get_cmd");
	PyObjectPtr cmd_obj = this->callFunction(get_cmd_func, "s", tableName);

	// 调用set_cmd_type函数
	PyObjectPtr set_cmd_type_func(m_py.getFunction(cmd_obj, "set_cmd_type"), "set_cmd_type");
	this->callFunction( set_cmd_type_func, "s", cmdType );

	// 调用set_cmd_object函数
	PyObjectPtr set_cmd_object_func = m_py.getFunction(cmd_obj, "set_cmd_object");
	this->callFunction( set_cmd_object_func, "o", object.get() );

	// 调用set_cmd_condition函数
	PyObjectPtr set_cmd_condition_func = m_py.getFunction(cmd_obj, "set_cmd_condition");
	this->callFunction( set_cmd_condition_func, "s", condition );
	return cmd_obj;
}

void SqlCmd::executeCmd(const PyObjectPtr& cmd_obj)
{
	PyObjectPtr marshal_func = m_py.getModuleFunction("marshal");
	PyObjectPtr marshal_res = this->callFunction(marshal_func, "o", cmd_obj);
	PyObjectPtr fmt_msg_func = m_py.getModuleFunction("fmt_msg");
	PyObjectPtr fmt_msg_res = this->callFunction(fmt_msg_func, "o", marshal_res.get());
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