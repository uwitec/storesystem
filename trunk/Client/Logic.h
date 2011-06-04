#pragma once
#include <QString>
#include "SqlCmd.h"
#include "ClientNet.h"
#include "LogManager.h"
#include "UserManager.h"
#include "ProductManager.h"
#include "FactoryManager.h"
#include "StoreSystem.h"
class Logic
{
public:
	Logic(void);
	virtual ~Logic(void);
	void setSqlCmd(SqlCmd* pSqlCmd){ m_pSqlCmd = pSqlCmd; }
	void SetNet(ClientNet* pNet){ m_pNet = pNet; }
	void setGui(MainWidget* pGui);
	void executeCmd(const char* cmd);
	void executeCmd(const QString& cmd);
	// @param replyMsg, ���������͸��ͻ��˵���Ϣ
	// @return, �������������Ϣ������-1������Ϣ������
	int32 cutFullMsg(const QString& replyMsg);
	int32 parseReplyMsg(const QString& replyMsg);
	
	void userLogin(const QString& name, const QString& password);
	void userInsert(const User& user);
	void userSearch(const QString& name);
	void userUpdate(const User& user);
	
	void productInsert(const Product& product);
	void productSearch();
	void productUpdate(const Product& product);

	void factoryInsert(const Factory& factory);
	void factorySearch();
	void factoryUpdate(const Factory& factory);
protected:
	SqlCmd* m_pSqlCmd;
	ClientNet* m_pNet;
	Log* m_pLog;
	UserManager m_userMgr;
	ProductManager m_productMgr;
	FactoryManager m_factoryMgr;
};