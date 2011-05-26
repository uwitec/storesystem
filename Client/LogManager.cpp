#include "StdAfx.h"
#include "LogManager.h"

LogManager* LogManager::pLogManager = NULL;

LogManager::LogManager(void)
: m_pStream(NULL), m_pDefaultLog(NULL)
{
}

LogManager::~LogManager(void)
{
	if( m_pStream )
	{
		m_pStream->flush();
		delete m_pStream;
		delete m_pDefaultLog;
		LogDict::iterator itr = m_logDict.begin();
		LogDict::iterator end = m_logDict.end();
		while( itr != end )
		{
			delete itr->second;
			++itr;
		}
	}
}

LogManager& LogManager::getSingleton()
{
	if( NULL == pLogManager )
	{
		pLogManager = new LogManager();
		pLogManager->m_pStream = new std::ofstream("log.log");
		pLogManager->m_pDefaultLog = new Log(*pLogManager->m_pStream);
	}
	return *pLogManager;
}

Log* LogManager::getDefaultLog()
{
	return m_pDefaultLog;
}

Log* LogManager::getLog(const char* name)
{
	std::string logName = name;
	LogDict::iterator itr = m_logDict.find(logName);
	Log* log;
	if( itr == m_logDict.end() )
	{
		log = new Log(*m_pStream);
		m_logDict[logName] = log;
		log->setLogName(name);
	}
	else
		log = itr->second;
	return log;
}