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
	//m_pLog->debug(Q_To_CStr(fullMsg));
}

PyObjectPtr SqlCmd::parseCmdData(const QString& fullMsg,
								 QString& tableName,
								 QString& cmdType)
{
	PyObjectPtr unmarshal_func = m_py.getModuleFunction("unmarshal");
	
	PyObjectPtr cmd_data_obj = m_py.callFunction(unmarshal_func, "s", Q_To_CStr(fullMsg));
	if( cmd_data_obj.get() == NULL )
	{
		m_pLog->error("parseCmdData->cmd_data_obj is NULL.");
		return PyObjectPtr::PyObjectPtrNull;
	}
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
		Py_XINCREF(item.get());
		User user;
		user.id = m_py.getObjAttrInt(item, "id");
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
	m_pLog->debug("parseCmdDataResult->ProductPtrList");
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
		Py_XINCREF(item.get());
		Product* pProduct = new Product;
		pProduct->id = m_py.getObjAttrInt(item, "id");
		pProduct->name = m_py.getObjAttrString(item, "name");
		pProduct->type = m_py.getObjAttrString(item, "type");
		pProduct->MF_id = m_py.getObjAttrInt(item, "MF_id");
		pProduct->count = m_py.getObjAttrInt(item, "count");
		pProduct->date = m_py.getObjAttrString(item, "date");
		pProduct->price_buy = m_py.getObjAttrInt(item, "price_buy");
		pProduct->price_nw = m_py.getObjAttrInt(item, "price_nw");
		pProduct->price_ww = m_py.getObjAttrInt(item, "price_ww");
		pProduct->fee_other = m_py.getObjAttrInt(item, "fee_other");
		productList.push_back(pProduct);
	}
}

void SqlCmd::parseCmdDataResult(PyObjectPtr& cmd_obj, FactoryPtrList& factoryPtrList)
{
	m_pLog->debug("parseCmdDataResult->FactoryPtrList");

	FactoryPtrList::iterator itr = factoryPtrList.begin();
	FactoryPtrList::iterator end = factoryPtrList.end();
	while( itr != end )
	{
		delete *itr;
	}
	factoryPtrList.clear();
	PyObjectPtr list_res = m_py.getObjAttrObject(cmd_obj, "cmd_result");
	uint32 list_size = PyList_GET_SIZE(list_res.get());
	for( uint32 i = 0; i < list_size; ++i )
	{
		PyObjectPtr item(PyList_GetItem(list_res.get(), i));
		Py_XINCREF(item.get());
		FactoryPtr pFactory = new Factory;
		pFactory->id = m_py.getObjAttrInt(item, "id");
		pFactory->name = m_py.getObjAttrString(item, "name");
		pFactory->contact = m_py.getObjAttrString(item, "contact");
		pFactory->post = m_py.getObjAttrString(item, "post");
		pFactory->phone = m_py.getObjAttrString(item, "phone");
		pFactory->zip_code = m_py.getObjAttrString(item, "zip_code");
		pFactory->addr = m_py.getObjAttrString(item, "addr");
		pFactory->email = m_py.getObjAttrString(item, "email");
		pFactory->card_type = m_py.getObjAttrString(item, "card_type");
		pFactory->card_num = m_py.getObjAttrString(item, "card_num");
		factoryPtrList.push_back(pFactory);
	}
}

void SqlCmd::parseCmdDataResult(PyObjectPtr& cmd_obj, PurchaseCPtrList& purchaseCPtrList)
{
	m_pLog->debug("parseCmdDataResult->PurchaseCPtrList");
	PurchaseCPtrList::iterator itr = purchaseCPtrList.begin();
	PurchaseCPtrList::iterator end = purchaseCPtrList.end();
	while( itr != end )
	{
		delete *itr;
	}
	purchaseCPtrList.clear();
	PyObjectPtr list_res = m_py.getObjAttrObject(cmd_obj, "cmd_result");
	uint32 list_size = PyList_GET_SIZE(list_res.get());
	for( uint32 i = 0; i < list_size; ++i )
	{
		PyObjectPtr item(PyList_GetItem(list_res.get(), i));
		Py_XINCREF(item.get());
		PurchaseCPtr pPurchaseC = new PurchaseC;
		pPurchaseC->id = m_py.getObjAttrInt(item, "id");
		pPurchaseC->date = m_py.getObjAttrString(item, "date");
		pPurchaseC->factory_id = m_py.getObjAttrInt(item, "factory_id");
		pPurchaseC->memo = m_py.getObjAttrString(item, "memo");
		purchaseCPtrList.push_back(pPurchaseC);
	}
}

void SqlCmd::parseCmdDataResult(PyObjectPtr& cmd_obj, PurchaseSPtrList& purchaseSPtrList)
{
	m_pLog->debug("parseCmdDataResult->PurchaseSPtrList");
	PurchaseSPtrList::iterator itr = purchaseSPtrList.begin();
	PurchaseSPtrList::iterator end = purchaseSPtrList.end();
	while( itr != end )
	{
		delete *itr;
	}
	purchaseSPtrList.clear();
	PyObjectPtr list_res = m_py.getObjAttrObject(cmd_obj, "cmd_result");
	uint32 list_size = PyList_GET_SIZE(list_res.get());
	for( uint32 i = 0; i < list_size; ++i )
	{
		PyObjectPtr item(PyList_GetItem(list_res.get(), i));
		Py_XINCREF(item.get());
		PurchaseSPtr pPurchaseS = new PurchaseS;
		pPurchaseS->id = m_py.getObjAttrInt(item, "id");
		pPurchaseS->product_id = m_py.getObjAttrInt(item, "product_id");
		pPurchaseS->count = m_py.getObjAttrInt(item, "count");
		pPurchaseS->batch = m_py.getObjAttrInt(item, "batch");
		pPurchaseS->price_pay = m_py.getObjAttrInt(item, "price_pay");
		pPurchaseS->fee_other = m_py.getObjAttrInt(item, "fee_other");
		purchaseSPtrList.push_back(pPurchaseS);
	}
}
void SqlCmd::parseCmdDataResult(PyObjectPtr& cmd_obj, SaleCPtrList& saleCPtrList)
{
	m_pLog->debug("parseCmdDataResult->SaleCPtrList");
	SaleCPtrList::iterator itr = saleCPtrList.begin();
	SaleCPtrList::iterator end = saleCPtrList.end();
	while( itr != end )
	{
		delete *itr;
	}
	saleCPtrList.clear();
	PyObjectPtr list_res = m_py.getObjAttrObject(cmd_obj, "cmd_result");
	uint32 list_size = PyList_GET_SIZE(list_res.get());
	for( uint32 i = 0; i < list_size; ++i )
	{
		PyObjectPtr item(PyList_GetItem(list_res.get(), i));
		Py_XINCREF(item.get());
		SaleCPtr pSaleC = new SaleC;
		pSaleC->id = m_py.getObjAttrInt(item, "id");
		pSaleC->memo = m_py.getObjAttrString(item, "memo");
		pSaleC->seller = m_py.getObjAttrString(item, "seller");
		pSaleC->addr = m_py.getObjAttrString(item, "addr");
		saleCPtrList.push_back(pSaleC);
	}
}

void SqlCmd::parseCmdDataResult(PyObjectPtr& cmd_obj, SaleSPtrList& saleSPtrList)
{
	m_pLog->debug("parseCmdDataResult->SaleSPtrList");
	SaleSPtrList::iterator itr = saleSPtrList.begin();
	SaleSPtrList::iterator end = saleSPtrList.end();
	while( itr != end )
	{
		delete *itr;
	}
	saleSPtrList.clear();
	PyObjectPtr list_res = m_py.getObjAttrObject(cmd_obj, "cmd_result");
	uint32 list_size = PyList_GET_SIZE(list_res.get());
	for( uint32 i = 0; i < list_size; ++i )
	{
		PyObjectPtr item(PyList_GetItem(list_res.get(), i));
		Py_XINCREF(item.get());
		SaleSPtr pSaleS = new SaleS;
		pSaleS->id = m_py.getObjAttrInt(item, "id");
		pSaleS->product_id = m_py.getObjAttrInt(item, "product_id");
		pSaleS->count = m_py.getObjAttrInt(item, "count");
		pSaleS->batch = m_py.getObjAttrInt(item, "batch");
		pSaleS->price_pay = m_py.getObjAttrInt(item, "price_pay");
		saleSPtrList.push_back(pSaleS);
	}
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