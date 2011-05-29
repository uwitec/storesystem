#pragma once
#include <fstream>
#include <string>	
#include <QMutex>
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
	Log(std::ostream& stream, LogLevel level = LogLevel_Debug,
		bool isStdActived=false);
	virtual ~Log(void);
	void setOutStream(std::ostream& stream);
	void setStdStreamActive(bool isActived);
	void setLogLevel(LogLevel level = LogLevel_Debug);
	void setMutex(QMutex* pMutex){ m_pMutex = pMutex; }
	void debug(const std::string& msg);	
	void warning(const std::string& msg);	
	void error(const std::string& msg);	
	void info(const std::string& msg);
protected:
	void setLogName(const char* name);
	void logMessage(const std::string& msg, LogLevel level);
	std::string decorate(const std::string& msg, LogLevel level);
	std::string m_name;			// ��־����
	LogLevel m_logLevel;		// ��־�ȼ�
	std::ostream* m_pStream;	// ��־�����
	QMutex* m_pMutex;
	std::ostream* m_pStdStream;	// ����̨
	bool m_isStdActived;
};
