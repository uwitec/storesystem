#pragma once
#include "Tables.h"
#include "TableManager.h"
#include "LogManager.h"
#include "MainWidget.h"
class ProductManager: public TableManager
{
public:
	ProductManager(void);
	virtual ~ProductManager(void);
	QString searchAllCmd() const;
	QString insertCmd(const Product& product) const;
	QString updateCmd(const Product& product) const;
	const ProductPtr getProductPtr(int32 index) const;
public:
	// @param proList,查到的产品列表
	void searchCallBack(ProductPtrList& proList);
	// @param proList,新添加的产品列表
	void insertCallBack(ProductPtrList& proList);
	// @param proList,更新的产品列表
	void updateCallBack(ProductPtrList& proList);
protected:
	ProductPtrList m_productList;
	
};
