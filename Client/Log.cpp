#include "StdAfx.h"
#include "Log.h"
#include "LogManager.h"
Log::Log(std::ostream& stream, LogLevel level)
: m_pSstream(&stream), m_logLevel(level)
{
	
}

Log::~Log(void)
{
}

void Log::setOutStream(std::ostream& stream)
{
	m_pSstream = &stream;
}

void Log::setLogLevel(LogLevel level)
{
	m_logLevel = level;
}

void Log::debug(const std::string& msg)
{
	if( m_logLevel <= LogLevel_Debug )
		this->logMessage(msg, LogLevel_Debug);
}

void Log::warning(const std::string& msg)
{
	if( m_logLevel <= LogLevel_Warning )
		this->logMessage(msg, LogLevel_Warning);
}

void Log::error(const std::string& msg)
{
	if( m_logLevel <= LogLevel_Error )
		this->logMessage(msg, LogLevel_Error);
}

void Log::info(const std::string& msg)
{
	this->logMessage(msg, LogLevel_Info);
}

std::string Log::decorate(const std::string& msg, LogLevel level)
{
	static const char* LogLevelName [] =
	{
		"Debug", "Warning", "Error", "Info"
	};
	char bytes[2048];
	sprintf_s(bytes, sizeof(bytes)-1, "%s\t[%s]%s", 
		LogLevelName[(int)level], m_name.c_str(), msg.c_str());
	std::string text = bytes;
	return text;
}

void Log::setLogName(const char* name)
{
	m_name = name;
}

void Log::logMessage(const std::string& msg, LogLevel level)
{
	std::string text = this->decorate(msg, level);
	(*m_pSstream)<<text<<std::endl;
}