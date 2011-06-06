#include "StdAfx.h"
#include "FactoryManager.h"

FactoryManager::FactoryManager(void)
: TableManager()
{
	m_pLog = LogManager::getSingleton().getLog("FactoryManager");
	m_pLog->setStdStreamActive(true);
}

FactoryManager::~FactoryManager(void)
{
}

QString FactoryManager::searchAllCmd()
{
	return "select * from factory";
}

QString FactoryManager::insertCmd(const Factory& factory)
{
	const Factory& f = factory;
	QString cmd = QString("insert into factory values(null,"
		"'%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8', '%9')")
		.arg(f.name).arg(f.contact).arg(f.post).arg(f.phone)
		.arg(f.zip_code).arg(f.addr).arg(f.email).arg(f.card_type)
		.arg(f.card_num);
	return cmd;
}

QString FactoryManager::updateCmd(const Factory& factory)
{
	const Factory& f = factory;
	QString cmd = QString("update factory set "
		"name='%1', contact='%2', post='%3',"
		"phone='%4', zip_code='%5', addr='%6',"
		"email='%7', card_type='%8', card_num='%9' "
		"where id=%10")
		.arg(f.name).arg(f.contact).arg(f.post)
		.arg(f.phone).arg(f.zip_code).arg(f.addr)
		.arg(f.email).arg(f.card_type).arg(f.card_num)
		.arg(f.id);
	return cmd;
}

const FactoryPtr FactoryManager::getFactoryPtr(int32 index) const
{
	if( index >= 0 && index < m_factoryPtrList.size() )
		return m_factoryPtrList[index];
	return NULL;
}

void FactoryManager::searchCallBack(FactoryPtrList& factoryList)
{
	m_pLog->debug(std::string("search count = ") + SConvert::toString(factoryList.size()));
	FactoryPtrList::iterator itr = factoryList.begin();
	FactoryPtrList::iterator end = factoryList.end();
	while( itr != end )
	{
		m_factoryPtrList.push_back(*itr);
		++itr;
	}
	if( m_pGui )
		m_pGui->setFactoryData(factoryList);
}

void FactoryManager::insertCallBack(FactoryPtrList& factoryList)
{
	//m_pLog->debug("insertCallBack NOT define.");
	FactoryPtrList::iterator itr = factoryList.begin();
	FactoryPtrList::iterator end = factoryList.end();
	while( itr != end )
	{
		if( m_pGui )
			m_pGui->addFactoryData(*itr);
		m_factoryPtrList.push_back(*itr);
		++itr;
	}
}

void FactoryManager::updateCallBack(FactoryPtrList& factoryList)
{
	//m_pLog->debug("updateCallBack NOT define.");
	FactoryPtrList::iterator itr = factoryList.begin();
	FactoryPtrList::iterator end = factoryList.end();
	while( itr != end )
	{
		int32 row = -1;
		//ProductPtr pProduct = this->findProduct( (*itr)->id, row );
		FactoryPtr pFactory = this->find( m_factoryPtrList, (*itr)->id, row );
		if( NULL == pFactory )
		{
			m_pLog->error(std::string("updateCallBack->id = ") + SConvert::toString((*itr)->id) + " Not Found");
			++itr;
			continue;
		}
		pFactory->copy( *(*itr) );
		// 更新GUI
		if( m_pGui && row >= 0 )
		{
			m_pGui->updateFactoryData(pFactory, row);
		}
		// 删除临时的记录
		delete *itr;
		m_pLog->debug(std::string("updateCallBack with:") + SConvert::toString((*itr)->id));
		m_pLog->debug(std::string("updateCallBack with:") + Q_To_CStr((*itr)->name));
		++itr;
	}
}