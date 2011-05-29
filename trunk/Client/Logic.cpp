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
		else if( tableName == "product" )
		{
			if( cmdType == "select" )
			{
				ProductPtrList& productList = m_productMgr.getProductList();
				m_pSqlCmd->parseCmdDataResult(cmd_obj, productList);
				m_productMgr.searchCallBack(productList);
			}
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

void Logic::userSearch(const QString& name)
{
	QString command = m_userMgr.searchCmd(name);
	QString net_msg = m_pSqlCmd->getCmdMsg("user", "select", command);
	m_pNet->send(net_msg);
}

void Logic::userUpdate(const QString& name, const QString& password,
					   int author)
{
	QString command = m_userMgr.updateCmd(name, password, author);
	if( command.size() > 0 )
	{
		QString net_msg = m_pSqlCmd->getCmdMsg("user", "update", command);
		m_pNet->send(net_msg);
	}
}

void Logic::productInsert(const Product& product)
{
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