#pragma once
#include "TableManager.h"
#include "Tables.h"
class PurchaseManager :
	public TableManager
{
public:
	PurchaseManager(void);
	virtual ~PurchaseManager(void);
	// ------进货记录集合------
	// 查找所有的进货记录集合
	QString searchAllCCmd() const;
	QString insertCCmd(const PurchaseC& purC) const;
	QString updateCCmd(const PurchaseC& purC) const;
	PurchaseCPtr getPurchaseCPtr(int32 index) const;
	
	// ------进货单条记录------
	QString searchSCmd(uint32 batch);
	QString searchAllSCmd() const;
	QString insertSCmd(const PurchaseS& purS) const;
	// batch批次是不可以修改的
	QString updateSCmd(const PurchaseS& purS) const;
	const PurchaseSPtrList& getPurchaseSPtrList(uint32 batch) const;
public:
	// ------进货记录集合------
	void searchCCallBack(PurchaseCPtrList& purCPtrList);
	void insertCCallBack(PurchaseCPtrList& purCPtrList);
	void updateCCallBack(PurchaseCPtrList& purCPtrList);
	
	// ------进货单条记录------
	void searchSCallBack(uint32 batch, PurchaseSPtrList purSPtrList);
	void searchSCallBack(PurchaseSPtrList& purSPtrList);
	void insertSCallBack(PurchaseSPtrList& purSPtrList);
	void updateSCallBack(PurchaseSPtrList& purSPtrList);
protected:
	PurchaseCPtrList m_purchaseCPtrList;
	PurchaseSPtrListDict m_purchaseSDict;
};
