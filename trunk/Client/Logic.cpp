#include "StdAfx.h"
#include "Logic.h"
Logic::Logic(void)
: m_pNet(NULL), m_pLog(NULL), m_pSqlCmd(NULL)
{
	m_pLog = LogManager::getSingleton().getLog("Logic");
	m_pLog->setLogLevel(LogLevel_Debug);
	m_pLog->setStdStreamActive(true);
	m_pSqlCmd = new SqlCmd;
	m_pSqlCmd->setLogic(this);
	m_pNet = new ClientNet(this);
	m_pNet->setLogic(this);
}

Logic::~Logic(void)
{
}

void Logic::setGui(MainWidget* pGui)
{
	pGui->setLogic(this);
	m_userMgr.setGui(pGui);
	m_productMgr.setGui(pGui);
	m_factoryMgr.setGui(pGui);
	m_purchaseMgr.setGui(pGui);
}

void Logic::executeCmd(const char* cmd)
{
	//m_net.send(cmd);
}

int32 Logic::parseReplyMsg(const QString& replyMsg)
{
	QString fullMsg = "";
	int32 cutSize = -1;
	m_pSqlCmd->cutReplyMsg(replyMsg, fullMsg, cutSize);
	if( cutSize > 0 )
	{
		QString tableName = "";
		QString cmdType = "";
		PyObjectPtr cmd_obj = m_pSqlCmd->parseCmdData(fullMsg, tableName, cmdType);
		m_pLog->debug( Q_To_CStr(QString("table:%1\tcmd::%2").arg(tableName).arg(cmdType)) );
		if( tableName == "user" )
		{
			if( cmdType == "login" )
			{
				bool isLogined = false;
				int32 author = 1;
				m_pSqlCmd->parseCmdDataResult(cmd_obj, isLogined, author);
				m_userMgr.loginCallBack(isLogined, author);
			}
			else if( cmdType == "insert" )
			{
				UserList userList;
				m_pSqlCmd->parseCmdDataResult(cmd_obj, userList);
				m_userMgr.insertCallBack(userList);
			}
			else if( cmdType == "select" )
			{
				UserList userList;
				m_pSqlCmd->parseCmdDataResult(cmd_obj, userList);
				m_userMgr.searchCallBack(userList);
			}
			else if( cmdType == "update" )
			{
				int32 value;
				m_pSqlCmd->parseCmdDataResult(cmd_obj, value);
				m_userMgr.updateCallBack(value);
			}
		}
		else if(tableName == "product")
		{
			ProductPtrList productList;
			if(cmdType == "delete")
				m_pLog->debug("product delete is NOT implemented");
			else
				m_pSqlCmd->parseCmdDataResult(cmd_obj, productList);

			if(cmdType == "select")
				m_productMgr.searchCallBack(productList);			
			else if(cmdType == "insert")
				m_productMgr.insertCallBack(productList);			
			else if(cmdType == "update")
				m_productMgr.updateCallBack(productList);
			
		}
		else if(tableName == "factory")
		{
			FactoryPtrList factoryPtrList;
			if(cmdType == "delete")
				m_pLog->debug("factory delete is NOT implemented");
			else
				m_pSqlCmd->parseCmdDataResult(cmd_obj, factoryPtrList);

			if(cmdType == "select")			
				m_factoryMgr.searchCallBack(factoryPtrList);
			
			else if(cmdType == "insert")			
				m_factoryMgr.insertCallBack(factoryPtrList);
			
			else if(cmdType == "update")			
				m_factoryMgr.updateCallBack(factoryPtrList);
			
		}
		else if( tableName == "purchaseC" )
		{
			PurchaseCPtrList purchaseCPtrList;
			if(cmdType == "delete")
				m_pLog->debug("purchaseC delete is NOT implemented");
			else
				m_pSqlCmd->parseCmdDataResult(cmd_obj, purchaseCPtrList);

			if(cmdType == "select")
				m_purchaseMgr.searchCCallBack(purchaseCPtrList);
			else if(cmdType == "insert")
				m_purchaseMgr.insertCCallBack(purchaseCPtrList);
			else if(cmdType == "update")
				m_purchaseMgr.updateCCallBack(purchaseCPtrList);
		}
		else if(tableName == "purchaseS")
		{
			PurchaseSPtrList purchaseSPtrList;
			if(cmdType == "delete")
				m_pLog->debug("purchaseS delete is NOT implemented");
			else
				m_pSqlCmd->parseCmdDataResult(cmd_obj, purchaseSPtrList);

			if(cmdType == "select")
				m_purchaseMgr.searchSCallBack(purchaseSPtrList);
			else if(cmdType == "insert")
				m_purchaseMgr.insertSCallBack(purchaseSPtrList);
			else if(cmdType == "update")
				m_purchaseMgr.updateSCallBack(purchaseSPtrList);
		}
		else if(tableName == "saleC")
		{
			SaleCPtrList saleCPtrList;
			if(cmdType == "delete")
				m_pLog->debug("saleC delete is NOT implemented");
			else
				m_pSqlCmd->parseCmdDataResult(cmd_obj, saleCPtrList);

			if(cmdType == "select")
				m_saleMgr.searchCCallBack(saleCPtrList);
			else if(cmdType == "insert")
				m_saleMgr.insertCCallBack(saleCPtrList);
			else if(cmdType == "update")
				m_saleMgr.updateCCallBack(saleCPtrList);
		}
		else if(tableName == "saleS")
		{
			SaleSPtrList saleSPtrList;
			if(cmdType == "delete")
				m_pLog->debug("saleC delete is NOT implemented");
			else
				m_pSqlCmd->parseCmdDataResult(cmd_obj, saleSPtrList);

			if(cmdType == "select")
				m_saleMgr.searchSCallBack(saleSPtrList);
			else if(cmdType == "insert")
				m_saleMgr.insertSCallBack(saleSPtrList);
			else if(cmdType == "update")
				m_saleMgr.updateSCallBack(saleSPtrList);
		}
		else if(tableName == "returnC")
		{
			m_pLog->debug("returnC NOT implemented.");
		}
		else if(tableName == "returnS")
		{
			m_pLog->debug("returnS NOT implemented.");
		}
	}
	return cutSize;
}

void Logic::userLogin(const QString& name, const QString& password)
{
	QString command = m_userMgr.loginCmd(name, password);
	QString net_msg = m_pSqlCmd->getCmdMsg("user", "login", command);
	m_pNet->send(net_msg);
}

void Logic::userInsert(const User& user)
{
	QString command = m_userMgr.insertCmd(user);
	QString net_msg = m_pSqlCmd->getCmdMsg("user", "insert", command);
	m_pNet->send(net_msg);
}

void Logic::userSearch(const QString& name)
{
	QString command = m_userMgr.searchCmd(name);
	QString net_msg = m_pSqlCmd->getCmdMsg("user", "select", command);
	m_pNet->send(net_msg);
}

void Logic::userUpdate(const User& user)
{
	QString command = m_userMgr.updateCmd(user);
	if( command.size() > 0 )
	{
		QString net_msg = m_pSqlCmd->getCmdMsg("user", "update", command);
		m_pNet->send(net_msg);
	}
}

void Logic::productInsert(const Product& product)
{
	//m_pLog->debug("productInsert");
	QString command = m_productMgr.insertCmd(product);
	QString net_msg = m_pSqlCmd->getCmdMsg("product", "insert", command);
	m_pNet->send(net_msg);
}

void Logic::productSearch()
{
	QString command = m_productMgr.searchAllCmd();
	QString net_msg = m_pSqlCmd->getCmdMsg("product", "select", command);
	m_pNet->send(net_msg);
}

void Logic::productUpdate(const Product& product)
{
	QString command = m_productMgr.updateCmd(product);
	QString net_msg = m_pSqlCmd->getCmdMsg("product", "update", command);
	m_pNet->send(net_msg);
}

void Logic::factoryInsert(const Factory& factory)
{
	//m_pLog->debug("factoryInsert");
	QString command = m_factoryMgr.insertCmd(factory);
	QString net_msg = m_pSqlCmd->getCmdMsg("factory", "insert", command);
	m_pNet->send(net_msg);
}

void Logic::factorySearch()
{
	QString command = m_factoryMgr.searchAllCmd();
	QString net_msg = m_pSqlCmd->getCmdMsg("factory", "select", command);
	m_pNet->send(net_msg);
}

void Logic::factoryUpdate(const Factory& factory)
{
	QString command = m_factoryMgr.updateCmd(factory);
	QString net_msg = m_pSqlCmd->getCmdMsg("factory", "update", command);
	m_pNet->send(net_msg);
}

void Logic::purchaseCInsert(const PurchaseC& purC)
{
	QString command = m_purchaseMgr.insertCCmd(purC);
	QString net_msg = m_pSqlCmd->getCmdMsg("purchaseC", "insert", command);
	m_pNet->send(net_msg);
}

void Logic::purchaseCSearch()
{
	QString command = m_purchaseMgr.searchAllCCmd();
	QString net_msg = m_pSqlCmd->getCmdMsg("purchaseC", "select", command);
	m_pNet->send(net_msg);
}

void Logic::purchaseCUpdate(const PurchaseC& purC)
{
	QString command = m_purchaseMgr.updateCCmd(purC);
	QString net_msg = m_pSqlCmd->getCmdMsg("purchaseC", "update", command);
	m_pNet->send(net_msg);
}

void Logic::purchaseSInsert(const PurchaseS& purS)
{
	QString command = m_purchaseMgr.insertSCmd(purS);
	QString net_msg = m_pSqlCmd->getCmdMsg("purchaseS", "insert", command);
	m_pNet->send(net_msg);
}

void Logic::purchaseSSearch()
{
	QString command = m_purchaseMgr.searchAllSCmd();
	QString net_msg = m_pSqlCmd->getCmdMsg("purchaseS", "select", command);
	m_pNet->send(net_msg);
}

void Logic::purchaseSUpdate(const PurchaseS& purS)
{
	QString command = m_purchaseMgr.updateSCmd(purS);
	QString net_msg = m_pSqlCmd->getCmdMsg("purchaseS", "update", command);
	m_pNet->send(net_msg);
}