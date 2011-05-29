#include "StdAfx.h"
#include "MainWidget.h"
#include "Logic.h"
MainWidget::MainWidget(QWidget *parent)
: QTabWidget(parent), m_pLogic(NULL)
{
	ui.setupUi(this);
	initUserView();
	initProductView();
	initConnection();
}

MainWidget::~MainWidget(void)
{
}


void MainWidget::initUserView()
{
	m_pUserModel = new QStandardItemModel(0, 3, this);
	m_pUserModel->setHeaderData(0, Qt::Horizontal, CStr_To_Q("用户名"));
	m_pUserModel->setHeaderData(1, Qt::Horizontal, CStr_To_Q("密码"));
	m_pUserModel->setHeaderData(2, Qt::Horizontal, CStr_To_Q("权限"));
	ui.m_pUserView->setModel(m_pUserModel);
	LogManager::getSingleton().getDefaultLog()->debug("initUserView");
}

void MainWidget::initProductView()
{
	m_pProductModel = new QStandardItemModel(0, 10, this);
	Qt::Orientation org = Qt::Horizontal;
	m_pProductModel->setHeaderData(0, org, "id");
	m_pProductModel->setHeaderData(1, org, CStr_To_Q("产品名"));
	m_pProductModel->setHeaderData(2, org, CStr_To_Q("类别"));
	m_pProductModel->setHeaderData(3, org, CStr_To_Q("厂商"));
	m_pProductModel->setHeaderData(4, org, CStr_To_Q("数量"));
	m_pProductModel->setHeaderData(5, org, CStr_To_Q("进货日期"));
	m_pProductModel->setHeaderData(6, org, CStr_To_Q("进货价"));
	m_pProductModel->setHeaderData(7, org, CStr_To_Q("内围价"));
	m_pProductModel->setHeaderData(8, org, CStr_To_Q("外围价"));
	m_pProductModel->setHeaderData(9, org, CStr_To_Q("其它费用"));
	ui.m_pProductView->setModel(m_pProductModel);

	m_pProductInsertDlg = new ProductInsertDlg(this);
}

void MainWidget::initConnection()
{
	connect( ui.m_pProductAddBtn, SIGNAL(clicked()),
			 this, SLOT(onInsertProductClick()) );
}

void MainWidget::setUserData(const UserList& userList)
{
	uint32 list_size = userList.size();
	UserList::const_iterator itr = userList.begin();
	UserList::const_iterator end = userList.end();
	while( itr != end )
	{
		uint32 row = m_pUserModel->rowCount();
		m_pUserModel->insertRow(row);
		m_pUserModel->setData( m_pUserModel->index(row, 0), itr->name );
		m_pUserModel->setData( m_pUserModel->index(row, 1), itr->password);
		m_pUserModel->setData( m_pUserModel->index(row, 2), itr->authority);
		++itr;
	}
}

void MainWidget::setProductData(const ProductPtrList& productList)
{
	uint32 list_size = productList.size();
	ProductPtrList::const_iterator itr = productList.begin();
	ProductPtrList::const_iterator end = productList.end();
	while( itr != end )
	{
		uint32 row = m_pProductModel->rowCount();
		m_pProductModel->insertRow(row);
		m_pProductModel->setData( m_pProductModel->index(row, 0), (*itr)->id );
		m_pProductModel->setData( m_pProductModel->index(row, 1), (*itr)->name );
		++itr;
	}
}

void MainWidget::onInsertProductClick()
{
	if( m_pProductInsertDlg->exec() == QDialog::Accepted )
	{
		if( m_pLogic )
			m_pLogic->productInsert( m_pProductInsertDlg->getProduct() );
	}
}