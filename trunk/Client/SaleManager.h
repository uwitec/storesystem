#pragma once
#include "TableManager.h"

class SaleManager :
	public TableManager
{
public:
	SaleManager(void);
	virtual ~SaleManager(void);
	// ------���ۼ�¼����------
	// �������еĽ�����¼����
	QString searchAllCCmd() const;
	QString insertCCmd(const SaleC& saleC) const;
	QString updateCCmd(const SaleC& saleC) const;
	SaleCPtr getSaleCPtr(int32 index) const;

	// ------����������¼------
	QString searchSCmd(uint32 batch);
	QString searchAllSCmd() const;
	QString insertSCmd(const SaleS& saleS) const;
	// batch�����ǲ������޸ĵ�
	QString updateSCmd(const SaleS& saleS) const;
	const SaleSPtrList& getSaleSPtrList(uint32 batch) const;
public:
	// ------������¼����------
	void searchCCallBack(SaleCPtrList& saleCPtrList);
	void insertCCallBack(SaleCPtrList& saleCPtrList);
	void updateCCallBack(SaleCPtrList& saleCPtrList);

	// ------����������¼------
	void searchSCallBack(SaleSPtrList& saleSPtrList);
	void insertSCallBack(SaleSPtrList& saleSPtrList);
	void updateSCallBack(SaleSPtrList& saleSPtrList);
protected:
	SaleCPtrList m_saleCPtrList;
	SaleSPtrListDict m_saleSDict;
};
