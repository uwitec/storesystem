#pragma once
#include "ui_MainWidget.h"
//#include <QStandardItemModel>
#include "Tables.h"
#include "ProductDlg.h"
#include "FactoryDlg.h"
class Logic;
class MainWidget : QTabWidget
{
	Q_OBJECT
public:
	MainWidget(QWidget *parent = 0);
	~MainWidget(void);
	void initUserView();
	void initProductView();
	void initFactoryView();
	void initConnection();
	void setLogic(Logic* pLogic){ m_pLogic = pLogic; }

	void setUserData(const UserList& userList);
	void addUserData(const User& user);

	void setProductData(const ProductPtrList& productList);
	void addProductData(const ProductPtr pProduct);
	void updateProductData(const ProductPtr pProduct, int32 row);

	void setFactoryData(const FactoryPtrList& factoryPtrList);
	void addFactoryData(const FactoryPtr pFactory);
	void updateFactoryData(const FactoryPtr pFactory, int32 row);
	
public slots:
	void onInsertProductClick();
	void onUpdateProductClick();

	void onInsertFactoryClick();
	void onUpdateFactoryClick();
protected:
	Ui::MainWidget ui;
	QStandardItemModel* m_pUserModel;
	QStandardItemModel* m_pProductModel;
	QStandardItemModel* m_pFactoryModel;
	ProductDlg* m_pProductDlg;
	FactoryDlg* m_pFactoryDlg;
	Logic* m_pLogic;
};
