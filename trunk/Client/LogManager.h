#pragma once
#include <map>
#include <QMutex>
#include "Log.h"
class LogManager
{
public:
	static LogManager& getSingleton();
	~LogManager(void);
	// 获取默认的日志类
	Log* getDefaultLog();
	// 获取特定的日志类
	Log* getLog(const char* name, LogLevel level = LogLevel_Debug,
				bool isStdActived = false);
protected:
	LogManager(void);
	static LogManager* pLogManager;
	std::ostream* m_pStream;
	Log* m_pDefaultLog;
	typedef std::map<std::string, Log*> LogDict;
	LogDict m_logDict;
	static QMutex mutex;
};
