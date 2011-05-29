#pragma once
#include <QString>
#include "SqlCmd.h"
#include "ClientNet.h"
#include "LogManager.h"
#include "UserManager.h"
#include "ProductManager.h"
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
	// @param replyMsg, 服务器发送给客户端的消息
	// @return, 返回已提出的消息索引，-1代表消息不完整
	int32 cutFullMsg(const QString& replyMsg);
	int32 parseReplyMsg(const QString& replyMsg);
	void userLogin(const QString& name, const QString& password);
	void userSearch(const QString& name);
	void userUpdate(const QString& name, const QString& password,
					int author);
	void productInsert(const Product& product);
	void productSearch();
protected:
	SqlCmd* m_pSqlCmd;
	ClientNet* m_pNet;
	Log* m_pLog;
	UserManager m_userMgr;
	ProductManager m_productMgr;
};
