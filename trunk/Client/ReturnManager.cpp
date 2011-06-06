#include "StdAfx.h"
#include "ReturnManager.h"

ReturnManager::ReturnManager(void)
: TableManager()
{
	m_pLog = LogManager::getSingleton().getLog("ReturnManager");
	m_pLog->setStdStreamActive(true);
}

ReturnManager::~ReturnManager(void)
{
}
