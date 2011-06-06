#pragma once
#include "ui_MainWidget.h"
//#include <QStandardItemModel>
#include "Tables.h"
#include "ProductDlg.h"
#include "FactoryDlg.h"
#include "PurchaseDlg.h"
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
	void initPurchaseView();
	void initSaleView();
	void initCompleteModel();
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
	
	void setPurchaseCData(const PurchaseCPtrList& purchaseCPtrList);
	void addPurchaseCData(const PurchaseCPtr pPurchaseC);
	void updatePurchaseCData(const PurchaseCPtr pPurchaseC, int32 row);

	void setPurchaseSData(const PurchaseSPtrList& purchaseSPtrList, uint32 batch);
	void addPurchaseSData(const PurchaseSPtr pPurchaseS);
	void updatePurchaseSData(const PurchaseSPtr pPurchaseS, int32 row);

	void setSaleCData(const SaleCPtrList& saleCPtrList);
	void addSaleCData(const SaleCPtr pSaleC);
	void updateSaleCData(const SaleCPtr pSaleC, int32 row);

	void setSaleSData(const SaleSPtrList& saleSPtrList, uint32 batch);
	void addSaleSData(const SaleSPtr pSaleS);
	void updateSaleSData(const SaleSPtr pPurchaseS, int32 row);
public slots:
	void onInsertProductClick();
	void onUpdateProductClick();

	void onInsertFactoryClick();
	void onUpdateFactoryClick();

	void onInsertPurchaseCClick();
	void onUpdatePurchaseCClick();
	void onPurchaseCViewClick(const QModelIndex & index);

	void onInsertPurchaseSClick();
	void onUpdatePurchaseSClick();
protected:
	Ui::MainWidget ui;
	QStandardItemModel* m_pUserModel;
	QStandardItemModel* m_pProductModel;
	QStandardItemModel* m_pFactoryModel;

	QStandardItemModel* m_pPurchaseCModel;
	QStandardItemModel* m_pPurchaseSModel;

	QStandardItemModel* m_pSaleCModel;
	QStandardItemModel* m_pSaleSModel;
	ProductDlg* m_pProductDlg;
	FactoryDlg* m_pFactoryDlg;
	PurchaseDlg* m_pPurchaseDlg;
protected:
	Logic* m_pLogic;
	// 当前显示的进货批次
	int32 m_iCurPurchaseBatch;
	// 当前显示的销售批次
	int32 m_iCurSaleBatch;
};
