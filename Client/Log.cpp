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

void Log::debug(const char* msg)
{
	if( m_logLevel <= LogLevel_Debug )
	{
		std::string text = this->decorate(msg);
		printf(text.c_str());
		(*m_pSstream)<<text<<std::endl;
	}
}

std::string Log::decorate(const char* msg, LogLevel level)
{
	char bytes[2048];
	sprintf_s(bytes, sizeof(bytes)-1, "[%s]", m_name.c_str());
	std::string text = bytes;
	return text;
}

void Log::setLogName(const char* name)
{
	m_name = name;
}