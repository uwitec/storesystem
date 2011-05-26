#include "StdAfx.h"
#include "PyInterface.h"

int PyInterface::ref_count = 0;

PyInterface::PyInterface(void)
{
	if( ref_count++ == 0 )
		Py_Initialize();
}

PyInterface::~PyInterface(void)
{
	if( --ref_count == 0 )
		Py_Finalize();
}

void PyInterface::loadModule(const char* moduleName)
{
	PyObjectPtr name(PyString_FromString(moduleName));
}