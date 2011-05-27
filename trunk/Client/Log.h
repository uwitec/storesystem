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
	void setStdStreamActive(bool isActived);
	void setLogLevel(LogLevel level = LogLevel_Debug);
	void debug(const std::string& msg);	
	void warning(const std::string& msg);	
	void error(const std::string& msg);	
	void info(const std::string& msg);
protected:
	void setLogName(const char* name);
	void logMessage(const std::string& msg, LogLevel level);
	std::string decorate(const std::string& msg, LogLevel level);
	std::string m_name;			// 日志名字
	LogLevel m_logLevel;		// 日志等级
	std::ostream* m_pStream;	// 日志输出流
	std::ostream* m_pStdStream;	// 控制台
	bool m_isStdActived;
};
