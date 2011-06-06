#pragma once
#include "TableManager.h"
#include "Tables.h"
class PurchaseManager :
	public TableManager
{
public:
	PurchaseManager(void);
	virtual ~PurchaseManager(void);
	// ------������¼����------
	// �������еĽ�����¼����
	QString searchAllCCmd() const;
	QString insertCCmd(const PurchaseC& purC) const;
	QString updateCCmd(const PurchaseC& purC) const;
	PurchaseCPtr getPurchaseCPtr(int32 index) const;
	
	// ------����������¼------
	QString searchSCmd(uint32 batch);
	QString searchAllSCmd() const;
	QString insertSCmd(const PurchaseS& purS) const;
	// batch�����ǲ������޸ĵ�
	QString updateSCmd(const PurchaseS& purS) const;
	const PurchaseSPtrList& getPurchaseSPtrList(uint32 batch) const;
public:
	// ------������¼����------
	void searchCCallBack(PurchaseCPtrList& purCPtrList);
	void insertCCallBack(PurchaseCPtrList& purCPtrList);
	void updateCCallBack(PurchaseCPtrList& purCPtrList);
	
	// ------����������¼------
	void searchSCallBack(uint32 batch, PurchaseSPtrList purSPtrList);
	void searchSCallBack(PurchaseSPtrList& purSPtrList);
	void insertSCallBack(PurchaseSPtrList& purSPtrList);
	void updateSCallBack(PurchaseSPtrList& purSPtrList);
protected:
	PurchaseCPtrList m_purchaseCPtrList;
	PurchaseSPtrListDict m_purchaseSDict;
};
