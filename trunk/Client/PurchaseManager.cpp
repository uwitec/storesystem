#include "StdAfx.h"
#include "PurchaseManager.h"

PurchaseManager::PurchaseManager(void)
: TableManager()
{
	m_pLog = LogManager::getSingleton().getLog("PurchaseManager");
	m_pLog->setStdStreamActive(true);
}

PurchaseManager::~PurchaseManager(void)
{
}

QString PurchaseManager::searchAllCCmd() const
{
	return "select * from purchaseC";
}

QString PurchaseManager::insertCCmd(const PurchaseC& purC) const
{
	const PurchaseC& p = purC;
	QString cmd = QString("insert into purchaseC values(null,"
		"'%2', %3, '%4')").arg(p.date).arg(p.factory_id).arg(p.memo);
	return cmd;
}

QString PurchaseManager::updateCCmd(const PurchaseC& purC) const
{
	const PurchaseC& p = purC;
	QString cmd = QString("update purchaseC set "
		"date='%1', factory_id=%2, memo='%3' where id=%4")
		.arg(p.date).arg(p.factory_id).arg(p.memo).arg(p.id);
	return cmd;
}

PurchaseCPtr PurchaseManager::getPurchaseCPtr(int32 index) const
{
	if(index >= 0 && index < m_purchaseCPtrList.size())
		return m_purchaseCPtrList[index];
	return NULL;
}

QString PurchaseManager::searchAllSCmd() const
{
	return "select * from purchaseS";
}

QString PurchaseManager::insertSCmd(const PurchaseS& purS) const
{
	QString cmd = QString("insert into purchaseS values(null,"
		"%1, %2, %3, %4, %5)").arg(purS.product_id).arg(purS.count)
		.arg(purS.batch).arg(purS.price_pay).arg(purS.fee_other);
	return cmd;
}

QString PurchaseManager::updateSCmd(const PurchaseS& purS) const
{
	QString cmd = QString("update purchaseS set "
		"product_id=%1, count=%2, price_pay=%3,"
		"fee_other=%4 where id=%5 ")
		.arg(purS.product_id).arg(purS.count)
		.arg(purS.price_pay)
		.arg(purS.fee_other).arg(purS.id);
	return cmd;
}

const PurchaseSPtrList& PurchaseManager::getPurchaseSPtrList(uint32 batch) const
{
	PurchaseSPtrListDict::const_iterator itr = m_purchaseSDict.find(batch);
	return itr->second;
}

void PurchaseManager::searchCCallBack(PurchaseCPtrList& purCPtrList)
{
	m_pLog->debug(std::string("searchCCallBack size = ")+SConvert::toString(purCPtrList.size()));
	// 删除原先数据
	PurchaseCPtrList::iterator itr = m_purchaseCPtrList.begin();
	PurchaseCPtrList::iterator end = m_purchaseCPtrList.end();
	while(itr != end)
	{
		delete *itr;
		++itr;
	}
	m_purchaseCPtrList.clear();
	// 添加新的数据
	itr = purCPtrList.begin();
	end = purCPtrList.end();
	while( itr != end )
	{
		m_purchaseCPtrList.push_back(*itr);
		++itr;
	}
	if(m_pGui)
		m_pGui->setPurchaseCData(m_purchaseCPtrList);
}

void PurchaseManager::insertCCallBack(PurchaseCPtrList& purCPtrList)
{	
	PurchaseCPtrList::iterator itr = purCPtrList.begin();
	PurchaseCPtrList::iterator end = purCPtrList.end();
	while( itr != end )
	{
		m_purchaseCPtrList.push_back(*itr);
		if(m_pGui)
			m_pGui->addPurchaseCData(*itr);
		++itr;
	}
}

void PurchaseManager::updateCCallBack(PurchaseCPtrList& purCPtrList)
{
	PurchaseCPtrList::iterator itr = purCPtrList.begin();
	PurchaseCPtrList::iterator end = purCPtrList.end();
	while( itr != end )
	{
		int32 row = -1;
		PurchaseCPtr pPurchase = this->find(m_purchaseCPtrList, (*itr)->id, row);
		if(NULL == pPurchase)
		{
			m_pLog->error(std::string("updateCCallBack->id = ") + SConvert::toString((*itr)->id) + " Not Found");
			++itr;
			continue;
		}
		pPurchase->copy( *(*itr) );
		if(m_pGui && row >= 0)
		{
			//m_pLog->debug("updateCCallBack->GUI is NOT implemented");
			m_pGui->updatePurchaseCData(pPurchase, row);
		}
		++itr;
	}
}

void PurchaseManager::searchSCallBack(PurchaseSPtrList& purSPtrList)
{
	// 清空原来的数据
	PurchaseSPtrListDict::iterator itr = m_purchaseSDict.begin();
	PurchaseSPtrListDict::iterator end = m_purchaseSDict.end();
	while(itr != end)
	{
		PurchaseSPtrList::iterator vitr = itr->second.begin();
		PurchaseSPtrList::iterator vend = itr->second.end();
		while(vitr != vend)
		{
			delete *vitr;
			++vitr;
		}
		++itr;
	}
	m_purchaseSDict.clear();

	// 创建新的数据
	PurchaseSPtrList::iterator vitr = purSPtrList.begin();
	PurchaseSPtrList::iterator vend = purSPtrList.end();
	while(vitr != vend)
	{
		m_purchaseSDict[(*vitr)->batch].push_back(*vitr);
		++vitr;
	}
	if(m_pGui)
		m_pLog->debug("searchSCallBack->GUI not implemented.");
}

void PurchaseManager::insertSCallBack(PurchaseSPtrList& purSPtrList)
{
	PurchaseSPtrList::iterator vitr = purSPtrList.begin();
	PurchaseSPtrList::iterator vend = purSPtrList.end();
	while(vitr != vend)
	{
		m_purchaseSDict[(*vitr)->batch].push_back(*vitr);
		if(m_pGui)
			m_pGui->addPurchaseSData(*vitr);
			//m_pLog->debug("insertSCallBack->GUI not implemented.");
		++vitr;
	}
}

void PurchaseManager::updateSCallBack(PurchaseSPtrList& purSPtrList)
{
	PurchaseSPtrList::iterator vitr = purSPtrList.begin();
	PurchaseSPtrList::iterator vend = purSPtrList.end();
	while(vitr != vend)
	{
		uint32 batch = (*vitr)->batch;
		PurchaseSPtrListDict::iterator itr = m_purchaseSDict.find(batch);
		PurchaseSPtrListDict::iterator end = m_purchaseSDict.end();
		// 批次不存在则错误
		if(itr == end)
		{
			m_pLog->error(std::string("updateSCallBack->batch=")+SConvert::toString(batch)+"NOT found.");
			++vitr;
			continue;
		}
		int32 row = -1;
		PurchaseSPtr pPurchaseS = this->find(itr->second, (*vitr)->id, row);
		// 记录单条记录不存在则错误
		if(NULL == pPurchaseS)
		{
			m_pLog->error(std::string("updateSCallBack->id = ") + SConvert::toString((*vitr)->id) + " Not Found");
			++vitr;
			continue;
		}
		pPurchaseS->copy(*(*vitr));
		if(m_pGui && row >= 0)
		{
			m_pGui->updatePurchaseSData(pPurchaseS, row);
			//m_pLog->debug("updateSCallBack->GUI not implemented.");
		}
		++vitr;
	}
}