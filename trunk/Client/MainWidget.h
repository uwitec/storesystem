#pragma once
#include "ui_MainWidget.h"
//#include <QStandardItemModel>
#include "Tables.h"
#include "ProductInsertDlg.h"
class Logic;
class MainWidget : QTabWidget
{
	Q_OBJECT
public:
	MainWidget(QWidget *parent = 0);
	~MainWidget(void);
	void initUserView();
	void initProductView();
	void initConnection();
	void setUserData(const UserList& userList);
	void setProductData(const ProductPtrList& productList);
	void setLogic(Logic* pLogic){ m_pLogic = pLogic; }
public slots:
	void onInsertProductClick();
protected:
	Ui::MainWidget ui;
	QStandardItemModel* m_pUserModel;
	QStandardItemModel* m_pProductModel;
	ProductInsertDlg* m_pProductInsertDlg;
	Logic* m_pLogic;
};
