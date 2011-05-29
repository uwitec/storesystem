#include "StdAfx.h"
#include "LogManager.h"

LogManager* LogManager::pLogManager = NULL;
QMutex LogManager::mutex;

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
		pLogManager->m_pDefaultLog->setLogName("DefaultLog");
		pLogManager->m_pDefaultLog->setMutex(&mutex);
	}
	return *pLogManager;
}

Log* LogManager::getDefaultLog()
{
	return m_pDefaultLog;
}

Log* LogManager::getLog(const char* name, LogLevel level, bool isStdActived)
{	
	std::string logName = name;
	LogDict::iterator itr = m_logDict.find(logName);
	Log* log;
	if( itr == m_logDict.end() )
	{
		log = new Log(*m_pStream, level, isStdActived);
		m_logDict[logName] = log;
		log->setLogName(name);
		log->setMutex(&mutex);
	}
	else
		log = itr->second;
	return log;
}

/*
使用方法：
LogManager mgr = LogManager::getSingleton();
Log* log = mgr.getDefaultLog();
log->debug("hello world");
log->info("very good");
log->warning("a warning give");
log->error("critical error happend");

log = mgr.getLog("python");
log->setLogLevel(LogLevel_Warning);
log->debug("no debug");
log->info("is info");
log->warning("is warning");
log->error("critical error");
*/