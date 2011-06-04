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

QString ProductManager::searchAllCmd()
{
	return "select * from product";
}

QString ProductManager::insertCmd(const Product& product)
{
	const Product& p = product;
	QString cmd = QString("insert into product values(null,"
		"'%1', '%2', %3, %4, '%5', %6, %7, %8, %9)")
		.arg((p.name)).arg((p.type)).arg(p.MF_id).arg(p.count)
		.arg((p.date)).arg(p.price_buy).arg(p.price_nw).arg(p.price_ww)
		.arg(p.fee_other);
	return cmd;
}

QString ProductManager::updateCmd(const Product& product)
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

void ProductManager::searchCallBack(const ProductPtrList& proList)
{
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
	while( itr != end )
	{
		int32 row = -1;
		//ProductPtr pProduct = this->findProduct( (*itr)->id, row );
		ProductPtr pProduct = this->find( proList, (*itr)->id, row );
		if( NULL == pProduct )
		{
			m_pLog->error(std::string("updateCallBack->id = ") + SConvert::toString((*itr)->id) + " Not Found");
		}
		pProduct->copy( *(*itr) );
		// ¸üÐÂGUI
		if( m_pGui && row >= 0 )
		{
			m_pGui->updateProductData(pProduct, row);
		}
		m_pLog->debug(std::string("updateCallBack with:") + SConvert::toString((*itr)->id));
		m_pLog->debug(std::string("updateCallBack with:") + Q_To_CStr((*itr)->name));
		++itr;
	}
}

ProductPtr ProductManager::findProduct(int32 id, int32& row)
{
	if( m_productList.size() <= 3 )
	{
		int32 size = m_productList.size();
		for( int32 i = 0; i < size; ++i )
		{
			if( m_productList[i]->id == id )
			{
				row = i;
				return m_productList[i];
			}
		}
	}
	else
	{
		uint32 left = 0;
		uint32 right = m_productList.size() - 1;
		if( m_productList[left]->id == id )
			return m_productList[left];
		if( m_productList[right]->id == id )
			return m_productList[right];
		uint32 mid = (left + right) / 2;
		while( right - left > 1 )
		{
			uint32 midId = m_productList[mid]->id;
			if( midId == id )
			{
				row = mid;
				return m_productList[mid];
			}
			if( midId < id )
				left = mid;
			else
				right = mid;
			mid = (left + right) / 2;
		}
	}
	return NULL;
}