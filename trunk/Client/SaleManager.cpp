#include "StdAfx.h"
#include "SaleManager.h"

SaleManager::SaleManager(void)
: TableManager()
{
	m_pLog = LogManager::getSingleton().getLog("SaleManager");
	m_pLog->setStdStreamActive(true);
}

SaleManager::~SaleManager(void)
{
}

QString SaleManager::searchAllCCmd() const
{
	return "select * from saleC";
}

QString SaleManager::insertCCmd(const SaleC& saleC) const
{
	QString cmd = QString("insert into saleC values(null,"
		"'%1', '%2', '%3')")
		.arg(saleC.memo).arg(saleC.seller).arg(saleC.addr);
	return cmd;
}

QString SaleManager::updateCCmd(const SaleC& saleC) const
{
	QString cmd = QString("update saleC set "
		"memo='%1', seller='%2', addr='%3' "
		"where id=%4")
		.arg(saleC.memo).arg(saleC.seller)
		.arg(saleC.addr).arg(saleC.id);
	return cmd;
}

QString SaleManager::searchAllSCmd() const
{
	return "select * from saleS";
}

QString SaleManager::insertSCmd(const SaleS& saleS) const
{
	QString cmd = QString("insert into saleS values(null,"
		"product_id=%1, count=%2, batch=%3, price_pay=%4)")
		.arg(saleS.product_id).arg(saleS.count)
		.arg(saleS.batch).arg(saleS.price_pay);
	return cmd;
}

QString SaleManager::updateSCmd(const SaleS& saleS) const
{
	QString cmd = QString("update saleS set "
		"product_id=%1, count=%2, price_pay=%3 "
		"where id=%4")
		.arg(saleS.product_id).arg(saleS.count)
		.arg(saleS.price_pay).arg(saleS.id);
	return cmd;
}

void SaleManager::searchCCallBack(SaleCPtrList& saleCPtrList)
{
	m_pLog->debug(std::string("searchCCallBack size = ")+SConvert::toString(saleCPtrList.size()));
	// ɾ��ԭ������
	SaleCPtrList::iterator itr = saleCPtrList.begin();
	SaleCPtrList::iterator end = saleCPtrList.end();
	while(itr != end)
	{
		delete *itr;
		++itr;
	}
	m_saleCPtrList.clear();
	// ����µ�����
	itr = saleCPtrList.begin();
	end = saleCPtrList.end();
	while( itr != end )
	{
		m_saleCPtrList.push_back(*itr);
		++itr;
	}
	if(m_pGui)
		m_pGui->setSaleCData(m_saleCPtrList);
		//m_pLog->debug("searchCCallBack->GUI is NOT implemented");
}

void SaleManager::insertCCallBack(SaleCPtrList& saleCPtrList)
{
	SaleCPtrList::iterator itr = saleCPtrList.begin();
	SaleCPtrList::iterator end = saleCPtrList.end();
	while( itr != end )
	{
		m_saleCPtrList.push_back(*itr);
		if(m_pGui)
			m_pGui->addSaleCData(*itr);
		++itr;
	}
}

void SaleManager::updateCCallBack(SaleCPtrList& saleCPtrList)
{
	SaleCPtrList::iterator itr = saleCPtrList.begin();
	SaleCPtrList::iterator end = saleCPtrList.end();
	while( itr != end )
	{
		int32 row = -1;
		SaleCPtr pSale = this->find(saleCPtrList, (*itr)->id, row);
		if(NULL == pSale)
		{
			m_pLog->error(std::string("updateCCallBack->id = ") + SConvert::toString((*itr)->id) + " Not Found");
			++itr;
			continue;
		}
		pSale->copy( *(*itr) );
		if(m_pGui && row >= 0)
		{
			//m_pLog->debug("updateCCallBack->GUI is NOT implemented");
			m_pGui->updateSaleCData(pSale, row);
		}
		++itr;
	}
}

void SaleManager::searchSCallBack(SaleSPtrList& saleSPtrList)
{

	// ���ԭ��������
	SaleSPtrListDict::iterator itr = m_saleSDict.begin();
	SaleSPtrListDict::iterator end = m_saleSDict.end();
	while(itr != end)
	{
		SaleSPtrList::iterator vitr = itr->second.begin();
		SaleSPtrList::iterator vend = itr->second.end();
		while(vitr != vend)
		{
			delete *vitr;
			++vitr;
		}
		++itr;
	}
	m_saleSDict.clear();

	// �����µ�����
	SaleSPtrList::iterator vitr = saleSPtrList.begin();
	SaleSPtrList::iterator vend = saleSPtrList.end();
	while(vitr != vend)
	{
		m_saleSDict[(*vitr)->batch].push_back(*vitr);
		++vitr;
	}
	if(m_pGui)
		m_pLog->debug("searchSCallBack->GUI not implemented.");
}

void SaleManager::insertSCallBack(SaleSPtrList& saleSPtrList)
{
	SaleSPtrList::iterator vitr = saleSPtrList.begin();
	SaleSPtrList::iterator vend = saleSPtrList.end();
	while(vitr != vend)
	{
		m_saleSDict[(*vitr)->batch].push_back(*vitr);
		if(m_pGui)
			m_pGui->addSaleSData(*vitr);
		//m_pLog->debug("insertSCallBack->GUI not implemented.");
		++vitr;
	}
}

void SaleManager::updateSCallBack(SaleSPtrList& saleSPtrList)
{
	SaleSPtrList::iterator vitr = saleSPtrList.begin();
	SaleSPtrList::iterator vend = saleSPtrList.end();
	while(vitr != vend)
	{
		uint32 batch = (*vitr)->batch;
		SaleSPtrListDict::iterator itr = m_saleSDict.find(batch);
		SaleSPtrListDict::iterator end = m_saleSDict.end();
		// ���β����������
		if(itr == end)
		{
			m_pLog->error(std::string("updateSCallBack->batch=")+SConvert::toString(batch)+"NOT found.");
			++vitr;
			continue;
		}
		int32 row = -1;
		SaleSPtr pSaleS = this->find(itr->second, (*vitr)->id, row);
		// ��¼������¼�����������
		if(NULL == pSaleS)
		{
			m_pLog->error(std::string("updateSCallBack->id = ") + SConvert::toString((*vitr)->id) + " Not Found");
			++vitr;
			continue;
		}
		pSaleS->copy(*(*vitr));
		if(m_pGui && row >= 0)
		{
			m_pGui->updateSaleSData(pSaleS, row);
			//m_pLog->debug("updateSCallBack->GUI not implemented.");
		}
		++vitr;
	}
}