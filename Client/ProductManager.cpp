#include "StdAfx.h"
#include "ProductManager.h"

ProductManager::ProductManager(void)
: TableManager()
{
	m_pLog = LogManager::getSingleton().getLog("ProductManager");
	m_pLog->setStdStreamActive(true);
}

ProductManager::~ProductManager(void)
{
}

QString ProductManager::searchAllCmd() const
{
	return "select * from product";
}

QString ProductManager::insertCmd(const Product& product) const
{
	const Product& p = product;
	QString cmd = QString("insert into product values(null,"
		"'%1', '%2', %3, %4, '%5', %6, %7, %8, %9)")
		.arg((p.name)).arg((p.type)).arg(p.MF_id).arg(p.count)
		.arg((p.date)).arg(p.price_buy).arg(p.price_nw).arg(p.price_ww)
		.arg(p.fee_other);
	return cmd;
}

QString ProductManager::updateCmd(const Product& product) const
{
	const Product& p = product;
	QString cmd = QString("update product set "
		"name='%1', type='%2', MF_id=%3, "
		"count=%4, date='%5', price_buy=%6, "
		"price_nw=%7, price_ww=%8, fee_other=%9 where id=%10")
		.arg((p.name)).arg((p.type)).arg(p.MF_id).arg(p.count)
		.arg((p.date)).arg(p.price_buy).arg(p.price_nw).arg(p.price_ww)
		.arg(p.fee_other).arg(p.id);
	return cmd;
}

const ProductPtr ProductManager::getProductPtr(int32 index) const
{
	if(index >= 0 && index < m_productList.size())
		return m_productList[index];
	return NULL;
}

void ProductManager::searchCallBack(ProductPtrList& proList)
{
	ProductPtrList::iterator itr = proList.begin();
	ProductPtrList::iterator end = proList.end();
	while( itr != end )
	{
		m_productList.push_back(*itr);
		++itr;
	}
	m_pLog->debug(std::string("search count = ") + SConvert::toString(proList.size()));
	if( m_pGui )
		m_pGui->setProductData(proList);
}

void ProductManager::insertCallBack(ProductPtrList& proList)
{
	ProductPtrList::iterator itr = proList.begin();
	ProductPtrList::iterator end = proList.end();
	while( itr != end )
	{
		if( m_pGui )
			m_pGui->addProductData(*itr);
		m_productList.push_back(*itr);
		++itr;
	}
}

void ProductManager::updateCallBack(ProductPtrList& proList)
{
	ProductPtrList::iterator itr = proList.begin();
	ProductPtrList::iterator end = proList.end();
	while(itr != end)
	{
		int32 row = -1;
		//ProductPtr pProduct = this->findProduct( (*itr)->id, row );
		ProductPtr pProduct = this->find(m_productList, (*itr)->id, row);
		if(NULL == pProduct)
		{
			m_pLog->error(std::string("updateCallBack->id = ") + SConvert::toString((*itr)->id) + " Not Found");
			++itr;
			continue;
		}
		pProduct->copy( *(*itr) );
		// 更新GUI
		if(m_pGui && row >= 0)
		{
			m_pGui->updateProductData(pProduct, row);
		}
		// 删除临时记录
		delete *itr;
		//m_pLog->debug(std::string("updateCallBack with id:") + SConvert::toString((*itr)->id));
		//m_pLog->debug(std::string("updateCallBack with row:") + SConvert::toString(row));
		++itr;
	}
}