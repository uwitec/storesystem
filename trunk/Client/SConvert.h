#pragma once
#include <string>
#include <sstream>
#include <QString>
#define Q_To_CStr(qStr)\
	qStr.toLocal8Bit().data()
#define CStr_To_Q(cStr)\
	QString::fromLocal8Bit(cStr)

class SConvert
{
public:
	~SConvert(void);
	template<typename T>
	static std::string toString(const T& value)
	{		
		std::stringstream ss;
		ss<<value;
		return ss.str();
	}
	static const char* toCStr(const QString& str);
	static int toInt(const std::string& str);
	static float toFloat(const std::string& str);
	static double toDouble(const std::string& str);
protected:
	SConvert(void);	
};
