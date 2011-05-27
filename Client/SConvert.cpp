#include "StdAfx.h"
#include "SConvert.h"
using namespace std;
SConvert::SConvert(void)
{
}

SConvert::~SConvert(void)
{
}

const char* SConvert::toCStr(const QString& str)
{
	return str.toLocal8Bit().data();
}

int SConvert::toInt(const std::string& str)
{
	stringstream ss;
	ss<<str;
	int a;
	ss>>a;
	return a;
}

float SConvert::toFloat(const std::string& str)
{
	stringstream ss;
	ss<<str;
	float a;
	ss>>a;
	return a;
}

double SConvert::toDouble(const std::string& str)
{
	stringstream ss;
	ss<<str;
	double a;
	ss>>a;
	return a;
}