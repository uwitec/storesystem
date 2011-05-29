#pragma once
#include "Tables.h"
#include "LogManager.h"
#include "MainWidget.h"
class ProductManager
{
public:
	ProductManager(void);
	virtual ~ProductManager(void);
	void setGui(MainWidget* pGui){ m_pGui = pGui; }
	QString searchAllCmd();
	QString insertCmd(const Product& product);
	ProductPtrList& getProductList(){ return m_productList; }
public:
	void searchCallBack(const ProductPtrList& proList);
	void insertCallBack(int rowCount);
protected:
	ProductPtrList m_productList;
	Log* m_pLog;
	MainWidget* m_pGui;
};
