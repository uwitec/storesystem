#pragma once
#include <fstream>
#include <string>

enum LogLevel
{
	LogLevel_Debug = 0,	
	LogLevel_Warning = 1,
	LogLevel_Error = 2,
	LogLevel_Info = 3,
};
class LogManager;
class Log
{
	friend class LogManager;
public:
	Log(std::ostream& stream, LogLevel level = LogLevel_Debug);
	virtual ~Log(void);
	void setOutStream(std::ostream& stream);
	void setLogLevel(LogLevel level = LogLevel_Debug);
	void debug(const char* msg);
	void info(const char* msg);
	void warning(const char* msg);
	void error(const char* msg);
protected:	
	void setLogName(const char* name);
	std::string decorate(const char* msg);
	std::string m_name;			// 日志名字
	LogLevel m_logLevel;		// 日志等级
	std::ostream* m_pSstream;	// 日志输出流
};
