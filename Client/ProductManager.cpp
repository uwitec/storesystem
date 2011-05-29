#include "StdAfx.h"
#include "ProductManager.h"

ProductManager::ProductManager(void)
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

void ProductManager::searchCallBack(const ProductPtrList& proList)
{
	m_pLog->debug(std::string("search count = ") + SConvert::toString(proList.size()));
	if( m_pGui )
		m_pGui->setProductData(proList);
}