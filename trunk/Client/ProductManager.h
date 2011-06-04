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
	// @param proList,�鵽�Ĳ�Ʒ�б�
	void searchCallBack(const ProductPtrList& proList);
	// @param proList,����ӵĲ�Ʒ�б�
	void insertCallBack(ProductPtrList& proList);
	// @param proList,���µĲ�Ʒ�б�
	void updateCallBack(ProductPtrList& proList);
protected:
	ProductPtr findProduct(int32 id, int32& row);
protected:
	ProductPtrList m_productList;
	
};
