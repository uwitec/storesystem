#include "StdAfx.h"
#include "MainWidget.h"
#include "Logic.h"
MainWidget::MainWidget(QWidget *parent)
: QTabWidget(parent), m_pLogic(NULL)
{
	ui.setupUi(this);
	initUserView();
	initProductView();
	initFactoryView();
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

	m_pProductDlg = new ProductDlg(this);
}

void MainWidget::initFactoryView()
{
	m_pFactoryModel = new QStandardItemModel(0, 10, this);
	Qt::Orientation org = Qt::Horizontal;
	m_pFactoryModel->setHeaderData(0, org, "id");
	m_pFactoryModel->setHeaderData(1, org, CStr_To_Q("厂名"));
	m_pFactoryModel->setHeaderData(2, org, CStr_To_Q("联系人"));
	m_pFactoryModel->setHeaderData(3, org, CStr_To_Q("职位"));
	m_pFactoryModel->setHeaderData(4, org, CStr_To_Q("联系电话"));
	m_pFactoryModel->setHeaderData(5, org, CStr_To_Q("邮编"));
	m_pFactoryModel->setHeaderData(6, org, CStr_To_Q("地址"));
	m_pFactoryModel->setHeaderData(7, org, CStr_To_Q("邮箱"));
	m_pFactoryModel->setHeaderData(8, org, CStr_To_Q("银行卡类型"));
	m_pFactoryModel->setHeaderData(9, org, CStr_To_Q("银行卡号"));
	ui.m_pFactoryView->setModel(m_pFactoryModel);

	m_pFactoryDlg = new FactoryDlg(this);
}

void MainWidget::initConnection()
{
	connect( ui.m_pProductAddBtn, SIGNAL(clicked()),
			 this, SLOT(onInsertProductClick()) );
	connect( ui.m_pProductUpdBtn, SIGNAL(clicked()),
			 this, SLOT(onUpdateProductClick()) );
	connect( ui.m_pFactoryAddBtn, SIGNAL(clicked()),
			 this, SLOT(onInsertFactoryClick()) );
	connect( ui.m_pFactoryUpdBtn, SIGNAL(clicked()),
			 this, SLOT(onUpdateFactoryClick()) );
}

void MainWidget::setUserData(const UserList& userList)
{
	uint32 list_size = userList.size();
	UserList::const_iterator itr = userList.begin();
	UserList::const_iterator end = userList.end();
	while( itr != end )
	{
		this->addUserData( *itr );
		++itr;
	}
}

void MainWidget::addUserData(const User& user)
{
	uint32 row = m_pUserModel->rowCount();
	m_pUserModel->insertRow(row);
	m_pUserModel->setData( m_pUserModel->index(row, 0), user.name );
	m_pUserModel->setData( m_pUserModel->index(row, 1), user.password);
	m_pUserModel->setData( m_pUserModel->index(row, 2), user.authority);
}

void MainWidget::setProductData(const ProductPtrList& productList)
{
	ProductPtrList::const_iterator itr = productList.begin();
	ProductPtrList::const_iterator end = productList.end();
	while( itr != end )
	{		
		this->addProductData(*itr);
		++itr;
	}
}

void setModelData(QStandardItemModel* model, int32 row, const ProductPtr pProduct)
{
	model->setData( model->index(row, 0), pProduct->id );
	model->setData( model->index(row, 1), pProduct->name );
	model->setData( model->index(row, 2), pProduct->type );
	model->setData( model->index(row, 3), pProduct->MF_id );
	model->setData( model->index(row, 4), pProduct->count );
	model->setData( model->index(row, 5), pProduct->date );
	model->setData( model->index(row, 6), pProduct->price_buy * 0.01 );
	model->setData( model->index(row, 7), pProduct->price_nw * 0.01 );
	model->setData( model->index(row, 8), pProduct->price_ww * 0.01 );
	model->setData( model->index(row, 9), pProduct->fee_other * 0.01 );
}

void MainWidget::addProductData(const ProductPtr pProduct)
{
	uint32 row = m_pProductModel->rowCount();
	m_pProductModel->insertRow(row);
	setModelData(m_pProductModel, row, pProduct);
}

void MainWidget::updateProductData(const ProductPtr pProduct, int32 row)
{
	setModelData(m_pProductModel, row, pProduct);
}

void MainWidget::setFactoryData(const FactoryPtrList& factoryPtrList)
{
	FactoryPtrList::const_iterator itr = factoryPtrList.begin();
	FactoryPtrList::const_iterator end = factoryPtrList.end();
	while( itr != end )
	{
		this->addFactoryData(*itr);
		++itr;
	}
}

void setModelData(QStandardItemModel* model, int32 row, const FactoryPtr pFactory)
{
	model->setData( model->index(row, 0), pFactory->id );
	model->setData( model->index(row, 1), pFactory->name );
	model->setData( model->index(row, 2), pFactory->contact );
	model->setData( model->index(row, 3), pFactory->post );
	model->setData( model->index(row, 4), pFactory->phone );
	model->setData( model->index(row, 5), pFactory->zip_code );
	model->setData( model->index(row, 6), pFactory->addr );
	model->setData( model->index(row, 7), pFactory->email );
	model->setData( model->index(row, 8), pFactory->card_type );
	model->setData( model->index(row, 9), pFactory->card_num );
}

void MainWidget::addFactoryData(const FactoryPtr pFactory)
{
	uint32 row = m_pFactoryModel->rowCount();
	m_pFactoryModel->insertRow(row);
	setModelData(m_pFactoryModel, row, pFactory);
}

void MainWidget::updateFactoryData(const FactoryPtr pFactory, int32 row)
{
	setModelData(m_pFactoryModel, row, pFactory);
}

void MainWidget::onInsertProductClick()
{
	if( m_pProductDlg->exec() == QDialog::Accepted )
	{
		if( m_pLogic )
			m_pLogic->productInsert( m_pProductDlg->getProduct() );		
	}
}

void MainWidget::onUpdateProductClick()
{
	//QModelIndex index = ui.m_pProductView->currentIndex();
	QModelIndexList indexList = ui.m_pProductView->selectionModel()->selectedRows(0);
	const QAbstractItemModel* model = ui.m_pProductView->selectionModel()->model();
	int32 row = indexList[0].row();
	QModelIndex index = indexList[0];
	Product p;
	p.id = model->data(index).toInt();
	p.name = model->data(index.sibling(row, 1)).toString();
	p.type = model->data(index.sibling(row, 2)).toString();
	p.MF_id = model->data(index.sibling(row, 3)).toInt();
	p.count = model->data(index.sibling(row, 4)).toInt();
	p.date = model->data(index.sibling(row, 5)).toString();
	p.price_buy = model->data(index.sibling(row, 6)).toFloat() * 100;
	p.price_nw = model->data(index.sibling(row, 7)).toFloat() * 100;
	p.price_ww = model->data(index.sibling(row, 8)).toFloat() * 100;
	p.fee_other = model->data(index.sibling(row, 9)).toFloat() * 100;
	m_pProductDlg->setProduct(p);
	if( m_pProductDlg->exec() == QDialog::Accepted )
	{
		if( m_pLogic )
			m_pLogic->productUpdate( m_pProductDlg->getProduct() );
	}
}

void MainWidget::onInsertFactoryClick()
{
	if( m_pFactoryDlg->exec() == QDialog::Accepted )
	{
	}
}

void MainWidget::onUpdateFactoryClick()
{
	if( m_pFactoryDlg->exec() == QDialog::Accepted )
	{
	}
}