#include "StdAfx.h"
#include "MainWidget.h"
#include "Logic.h"
MainWidget::MainWidget(QWidget *parent)
:	QTabWidget(parent), m_pLogic(NULL),
	m_iCurPurchaseBatch(-1),
	m_iCurSaleBatch(-1)
{
	ui.setupUi(this);
	initUserView();
	initProductView();
	initFactoryView();
	initPurchaseView();
	initSaleView();
	initCompleteModel();
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

void MainWidget::initPurchaseView()
{
	m_pPurchaseCModel = new QStandardItemModel(0, 4, this);
	Qt::Orientation org = Qt::Horizontal;
	m_pPurchaseCModel->setHeaderData(0, org, "id");
	m_pPurchaseCModel->setHeaderData(1, org, CStr_To_Q("进货日期"));
	m_pPurchaseCModel->setHeaderData(2, org, CStr_To_Q("进货商家"));
	m_pPurchaseCModel->setHeaderData(3, org, CStr_To_Q("备注"));
	ui.m_pPurchaseCView->setModel(m_pPurchaseCModel);

	m_pPurchaseSModel = new QStandardItemModel(0, 6, this);
	m_pPurchaseSModel->setHeaderData(0, org, "id");
	m_pPurchaseSModel->setHeaderData(1, org, CStr_To_Q("产品"));
	m_pPurchaseSModel->setHeaderData(2, org, CStr_To_Q("数量"));
	m_pPurchaseSModel->setHeaderData(3, org, CStr_To_Q("批次"));
	m_pPurchaseSModel->setHeaderData(4, org, CStr_To_Q("实付"));
	m_pPurchaseSModel->setHeaderData(5, org, CStr_To_Q("其它费用"));
	ui.m_pPurchaseSView->setModel(m_pPurchaseSModel);

	m_pPurchaseDlg = new PurchaseDlg(this);
}

void MainWidget::initSaleView()
{
	m_pSaleCModel = new QStandardItemModel(0, 5, this);
	Qt::Orientation org = Qt::Horizontal;
	m_pSaleCModel->setHeaderData(0, org, "id");
	m_pSaleCModel->setHeaderData(1, org, CStr_To_Q("备注"));
	m_pSaleCModel->setHeaderData(2, org, CStr_To_Q("经手人"));
	m_pSaleCModel->setHeaderData(3, org, CStr_To_Q("销售日期"));
	m_pSaleCModel->setHeaderData(4, org, CStr_To_Q("销售地点"));
	ui.m_pSaleCView->setModel(m_pSaleCModel);

	m_pSaleSModel = new QStandardItemModel(0, 5, this);
	m_pSaleSModel->setHeaderData(0, org, "id");
	m_pSaleSModel->setHeaderData(1, org, CStr_To_Q("产品"));
	m_pSaleSModel->setHeaderData(2, org, CStr_To_Q("数量"));
	m_pSaleSModel->setHeaderData(3, org, CStr_To_Q("批次"));
	m_pSaleSModel->setHeaderData(4, org, CStr_To_Q("实付"));
	ui.m_pSaleSView->setModel(m_pSaleSModel);
}

void MainWidget::initCompleteModel()
{
	m_pProductDlg->setCompleterModel(m_pProductModel);
	m_pFactoryDlg->setCompleterModel(m_pFactoryModel);

	QCompleter* pFactoryCompleter = new QCompleter(m_pFactoryModel, this);
	m_pProductDlg->setFactoryModel(m_pFactoryModel, pFactoryCompleter);
	m_pPurchaseDlg->setFactoryModel(m_pFactoryModel, pFactoryCompleter);

	QCompleter* pProductCompleter = new QCompleter(m_pProductModel, this);
	m_pPurchaseDlg->setProductModel(m_pProductModel, pProductCompleter);	
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

	connect( ui.m_pPurchaseCAddBtn, SIGNAL(clicked()),
			 this, SLOT(onInsertPurchaseCClick()) );
	connect( ui.m_pPurchaseCUpdBtn, SIGNAL(clicked()),
			 this, SLOT(onUpdatePurchaseCClick()) );
	connect( ui.m_pPurchaseCView, SIGNAL(clicked(const QModelIndex&)),
			 this, SLOT(onPurchaseCViewClick(const QModelIndex&)) );

	// 进货单条记录
	connect( ui.m_pPurchaseSAddBtn, SIGNAL(clicked()),
			 this, SLOT(onInsertPurchaseSClick()) );
	connect( ui.m_pPurchaseSUpdBtn, SIGNAL(clicked()),
			 this, SLOT(onUpdatePurchaseSClick()) );
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

void MainWidget::setPurchaseCData(const PurchaseCPtrList& purchaseCPtrList)
{
	int32 iRowCount = m_pPurchaseCModel->rowCount();
	m_pPurchaseCModel->removeRows(0, iRowCount);
	PurchaseCPtrList::const_iterator itr = purchaseCPtrList.begin();
	PurchaseCPtrList::const_iterator end = purchaseCPtrList.end();
	while(itr != end)
	{
		this->addPurchaseCData(*itr);
		++itr;
	}
}

void setModelData(QStandardItemModel* model, int32 row, const PurchaseCPtr pPurchaseC)
{
	model->setData( model->index(row, 0), pPurchaseC->id );
	model->setData( model->index(row, 1), pPurchaseC->date );
	model->setData( model->index(row, 2), pPurchaseC->factory_id );
	model->setData( model->index(row, 3), pPurchaseC->memo );
}

void MainWidget::addPurchaseCData(const PurchaseCPtr pPurchaseC)
{
	uint32 row = m_pPurchaseCModel->rowCount();
	m_pPurchaseCModel->insertRow(row);
	setModelData(m_pPurchaseCModel, row, pPurchaseC);
}

void MainWidget::updatePurchaseCData(const PurchaseCPtr pPurchaseC, int32 row)
{
	setModelData(m_pPurchaseCModel, row, pPurchaseC);
}

void MainWidget::setPurchaseSData(const PurchaseSPtrList& purchaseSPtrList, uint32 batch)
{
	// 批次没有改变
	if(m_iCurPurchaseBatch == batch && 
	   purchaseSPtrList.size() == m_pPurchaseSModel->rowCount())
		return;
	int32 iRowCount = m_pPurchaseSModel->rowCount();
	m_pPurchaseSModel->removeRows(0, iRowCount);
	m_iCurPurchaseBatch = batch;
	PurchaseSPtrList::const_iterator itr = purchaseSPtrList.begin();
	PurchaseSPtrList::const_iterator end = purchaseSPtrList.end();
	while(itr != end)
	{
		this->addPurchaseSData(*itr);
		++itr;
	}
}

void setModelData(QStandardItemModel* model, int32 row, const PurchaseSPtr pPurchaseS)
{
	model->setData( model->index(row, 0), pPurchaseS->id );
	model->setData( model->index(row, 1), pPurchaseS->product_id );
	model->setData( model->index(row, 2), pPurchaseS->count );
	model->setData( model->index(row, 3), pPurchaseS->batch );
	model->setData( model->index(row, 4), pPurchaseS->price_pay * 0.01 );
	model->setData( model->index(row, 5), pPurchaseS->fee_other * 0.01 );
}

void MainWidget::addPurchaseSData(const PurchaseSPtr pPurchaseS)
{
	// 添加的批次不属于当前显示的批次，则不添加
	if(pPurchaseS->batch != m_iCurPurchaseBatch)
		return;
	uint32 row = m_pPurchaseSModel->rowCount();
	m_pPurchaseSModel->insertRow(row);
	setModelData(m_pPurchaseSModel, row, pPurchaseS);
}

void MainWidget::updatePurchaseSData(const PurchaseSPtr pPurchaseS, int32 row)
{
	if(pPurchaseS->batch != m_iCurPurchaseBatch)
		return;
	setModelData(m_pPurchaseSModel, row, pPurchaseS);
}

void MainWidget::setSaleCData(const SaleCPtrList& saleCPtrList)
{
	int32 iRowCount = m_pSaleCModel->rowCount();
	m_pSaleCModel->removeRows(0, iRowCount);
	SaleCPtrList::const_iterator itr = saleCPtrList.begin();
	SaleCPtrList::const_iterator end = saleCPtrList.end();
	while(itr != end)
	{
		this->addSaleCData(*itr);
		++itr;
	}
}

void setModelData(QStandardItemModel* model, int32 row, const SaleCPtr pSaleC)
{
	model->setData( model->index(row, 0), pSaleC->id );
	model->setData( model->index(row, 1), pSaleC->memo );
	model->setData( model->index(row, 2), pSaleC->seller );
	model->setData( model->index(row, 3), pSaleC->date );
	model->setData( model->index(row, 4), pSaleC->addr );
}

void MainWidget::addSaleCData(const SaleCPtr pSaleC)
{
	uint32 row = m_pSaleCModel->rowCount();
	m_pSaleCModel->insertRow(row);
	setModelData(m_pSaleCModel, row, pSaleC);
}

void MainWidget::updateSaleCData(const SaleCPtr pSaleC, int32 row)
{
	setModelData(m_pSaleCModel, row, pSaleC);
}

void MainWidget::setSaleSData(const SaleSPtrList& saleSPtrList, uint32 batch)
{
	// 批次没有改变
	if(m_iCurSaleBatch == batch && 
		saleSPtrList.size() == m_pSaleSModel->rowCount())
		return;
	int32 iRowCount = m_pSaleSModel->rowCount();
	m_pSaleSModel->removeRows(0, iRowCount);
	m_iCurSaleBatch = batch;
	SaleSPtrList::const_iterator itr = saleSPtrList.begin();
	SaleSPtrList::const_iterator end = saleSPtrList.end();
	while(itr != end)
	{
		this->addSaleSData(*itr);
		++itr;
	}
}

void setModelData(QStandardItemModel* model, int32 row, const SaleSPtr pPurchaseS)
{
	model->setData( model->index(row, 0), pPurchaseS->id );
	model->setData( model->index(row, 1), pPurchaseS->product_id );
	model->setData( model->index(row, 2), pPurchaseS->count );
	model->setData( model->index(row, 3), pPurchaseS->batch );
	model->setData( model->index(row, 4), pPurchaseS->price_pay * 0.01 );
}

void MainWidget::addSaleSData(const SaleSPtr pSaleS)
{
	// 添加的批次不属于当前显示的批次，则不添加
	if(pSaleS->batch != m_iCurPurchaseBatch)
		return;
	uint32 row = m_pSaleSModel->rowCount();
	m_pSaleSModel->insertRow(row);
	setModelData(m_pSaleSModel, row, pSaleS);
}

void MainWidget::updateSaleSData(const SaleSPtr pSaleS, int32 row)
{
	if(pSaleS->batch != m_iCurSaleBatch)
		return;
	setModelData(m_pSaleSModel, row, pSaleS);
}


// ---------消息响应函数---------
void MainWidget::onUpdateProductClick()
{
	QModelIndexList indexList = ui.m_pProductView->selectionModel()->selectedRows(0);
	if( indexList.size() < 1 )
		return;
	int32 row = indexList[0].row();
	if(m_pLogic)
	{
		ProductPtr pProduct = m_pLogic->getProductPtr(row);
		if(pProduct)
			m_pProductDlg->setProduct(*pProduct);
	}
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
		if( m_pLogic )
			m_pLogic->factoryInsert( m_pFactoryDlg->getFactory() );
	}
}

void MainWidget::onUpdateFactoryClick()
{
	QModelIndexList indexList = ui.m_pFactoryView->selectionModel()->selectedRows(0);
	if( indexList.size() < 1 )
		return;
	int32 row = indexList[0].row();

	if(m_pLogic)
	{
		FactoryPtr pFactory = m_pLogic->getFactoryPtr(row);
		if(pFactory)
			m_pFactoryDlg->setFactory(*pFactory);
	}
	if( m_pFactoryDlg->exec() == QDialog::Accepted )
	{
		if( m_pLogic )
			m_pLogic->factoryUpdate( m_pFactoryDlg->getFactory() );
	}
}

void MainWidget::onInsertPurchaseCClick()
{
	m_pPurchaseDlg->setPurchaseSVisible(false);
	if(m_pPurchaseDlg->exec() == QDialog::Accepted)
	{
		if(m_pLogic)
			m_pLogic->purchaseCInsert(m_pPurchaseDlg->getPurchaseC());
	}
}

void MainWidget::onUpdatePurchaseCClick()
{
	QModelIndexList indexList = ui.m_pPurchaseCView->selectionModel()->selectedRows(0);
	if( indexList.size() < 1 )
		return;
	int32 row = indexList[0].row();
	if(m_pLogic)
	{
		PurchaseCPtr pPur = m_pLogic->getPurchaseCPtr(row);
		if(pPur)
			m_pPurchaseDlg->setPurchaseC(*pPur);
	}
	m_pPurchaseDlg->setPurchaseSVisible(false);
	if(m_pPurchaseDlg->exec() == QDialog::Accepted)
	{
		if(m_pLogic)
			m_pLogic->purchaseCUpdate(m_pPurchaseDlg->getPurchaseC());
	}
}

void MainWidget::onPurchaseCViewClick(const QModelIndex & index)
{
	int32 row = index.row();
	PurchaseCPtr pPurchaseC = m_pLogic->getPurchaseCPtr(row);
	int32 iCurBatch = pPurchaseC->id;
	
	if(iCurBatch == m_iCurPurchaseBatch)
		return;
	// 当前批次不同，改变进货单条记录视图的内容
	PurchaseSPtrList purSPtrList = m_pLogic->getPurchaseSPtrList(iCurBatch);
	this->setPurchaseSData(purSPtrList, iCurBatch);
}

void MainWidget::onInsertPurchaseSClick()
{
	if(m_iCurPurchaseBatch < 0)
		return;
	m_pPurchaseDlg->setPurchaseSVisible(true);
	m_pPurchaseDlg->setPurchaseSBatch(m_iCurPurchaseBatch);
	if(m_pPurchaseDlg->exec() == QDialog::Accepted)
	{
		if(m_pLogic)
			m_pLogic->purchaseSInsert(m_pPurchaseDlg->getPurchaseS());
	}
}

void MainWidget::onUpdatePurchaseSClick()
{
	if(m_iCurPurchaseBatch < 0)
		return;
	QModelIndexList indexList = ui.m_pPurchaseSView->selectionModel()->selectedRows(0);
	if( indexList.size() < 1 )
		return;
	int32 row = indexList[0].row();
	if(m_pLogic)
	{
		const PurchaseSPtrList& purSList = m_pLogic->getPurchaseSPtrList(m_iCurPurchaseBatch);
		const PurchaseSPtr pPurS = purSList[row];
		m_pPurchaseDlg->setPurchaseS(*pPurS);
	}
	m_pPurchaseDlg->setPurchaseSVisible(true);
	if(m_pPurchaseDlg->exec() == QDialog::Accepted)
	{
		if(m_pLogic)
			m_pLogic->purchaseSUpdate(m_pPurchaseDlg->getPurchaseS());
	}
}