#pragma once
#include <QString>
#include "SqlCmd.h"
#include "ClientNet.h"
#include "LogManager.h"
#include "UserManager.h"
#include "ProductManager.h"
#include "FactoryManager.h"
#include "StoreSystem.h"
#include "PurchaseManager.h"
#include "SaleManager.h"
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
	void userInsert(const User& user);
	void userSearch(const QString& name);
	void userUpdate(const User& user);
	
	void productInsert(const Product& product);
	void productSearch();
	void productUpdate(const Product& product);
	const ProductPtr getProductPtr(int32 index) const
	{ return m_productMgr.getProductPtr(index); }

	void factoryInsert(const Factory& factory);
	void factorySearch();
	void factoryUpdate(const Factory& factory);
	const FactoryPtr getFactoryPtr(int32 index) const
	{ return m_factoryMgr.getFactoryPtr(index); }

	void purchaseCInsert(const PurchaseC& purC);
	void purchaseCSearch();
	void purchaseCUpdate(const PurchaseC& purC);
	const PurchaseCPtr getPurchaseCPtr(int32 index) const
	{ return m_purchaseMgr.getPurchaseCPtr(index); }
	
	void purchaseSInsert(const PurchaseS& purS);
	void purchaseSSearch();
	void purchaseSUpdate(const PurchaseS& purS);
	const PurchaseSPtrList& getPurchaseSPtrList(uint32 batch) const
	{ return m_purchaseMgr.getPurchaseSPtrList(batch); }
protected:
	SqlCmd* m_pSqlCmd;
	ClientNet* m_pNet;
	Log* m_pLog;
	UserManager m_userMgr;
	ProductManager m_productMgr;
	FactoryManager m_factoryMgr;
	PurchaseManager m_purchaseMgr;
	SaleManager m_saleMgr;
};
