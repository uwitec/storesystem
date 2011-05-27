#pragma once
#include <string>
#include <sstream>
#include <QString>
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
