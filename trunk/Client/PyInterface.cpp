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
	//printf("~PyInterface\n");
}

void PyInterface::loadModule(const char* moduleName)
{
	PyObjectPtr name(PyString_FromString(moduleName));
	m_pModule = PyImport_Import(name.get());
	//printf("get\n");
	if( m_pModule.get() == NULL )
	{
		printf("%s is NULL", moduleName);
		return;
	}
}