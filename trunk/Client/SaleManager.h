#pragma once
#include "TableManager.h"

class SaleManager :
	public TableManager
{
public:
	SaleManager(void);
	virtual ~SaleManager(void);
	// ------销售记录集合------
	// 查找所有的进货记录集合
	QString searchAllCCmd() const;
	QString insertCCmd(const SaleC& saleC) const;
	QString updateCCmd(const SaleC& saleC) const;
	SaleCPtr getSaleCPtr(int32 index) const;

	// ------进货单条记录------
	QString searchSCmd(uint32 batch);
	QString searchAllSCmd() const;
	QString insertSCmd(const SaleS& saleS) const;
	// batch批次是不可以修改的
	QString updateSCmd(const SaleS& saleS) const;
	const SaleSPtrList& getSaleSPtrList(uint32 batch) const;
public:
	// ------进货记录集合------
	void searchCCallBack(SaleCPtrList& saleCPtrList);
	void insertCCallBack(SaleCPtrList& saleCPtrList);
	void updateCCallBack(SaleCPtrList& saleCPtrList);

	// ------进货单条记录------
	void searchSCallBack(SaleSPtrList& saleSPtrList);
	void insertSCallBack(SaleSPtrList& saleSPtrList);
	void updateSCallBack(SaleSPtrList& saleSPtrList);
protected:
	SaleCPtrList m_saleCPtrList;
	SaleSPtrListDict m_saleSDict;
};
