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
	QString searchAllCmd();
	QString insertCmd(const Product& product);
	QString updateCmd(const Product& product);
	ProductPtrList& getProductList(){ return m_productList; }
public:
	// @param proList,查到的产品列表
	void searchCallBack(const ProductPtrList& proList);
	// @param proList,新添加的产品列表
	void insertCallBack(ProductPtrList& proList);
	// @param proList,更新的产品列表
	void updateCallBack(ProductPtrList& proList);
protected:
	ProductPtr findProduct(int32 id, int32& row);
protected:
	ProductPtrList m_productList;
	
};
