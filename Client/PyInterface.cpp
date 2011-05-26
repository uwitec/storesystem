#include "StdAfx.h"
#include "PyInterface.h"
using namespace std;

PyObjectPtr PyObjectPtr::PyObjectPtrNull(NULL);

PyObjectPtr::~PyObjectPtr()
{
	pyRelease();
}

PyObjectPtr& PyObjectPtr::operator = (PyObject* obj)
{
	pyRelease();
	m_pObject = obj;
	return *this;
}

PyObjectPtr& PyObjectPtr::operator = (PyObjectPtr& obj)
{
	pyRelease();
	Py_XINCREF(obj.get());
	m_pObject = obj.get();		
	return *this;
}

void PyObjectPtr::pyRelease()
{
	if( m_pObject )
	{
		//printf("Py_XDECREF");
		Py_XDECREF(m_pObject);		
		char msg[2048];
		sprintf_s(msg, sizeof(msg), "%s:%d Py_XDECREF", m_objName.c_str(), 
			Py_REFCNT(m_pObject));
		LogManager::getSingleton().getDefaultLog()->debug(msg);
		m_pObject = NULL;
	}
}

int PyInterface::ref_count = 0;
PyInterface::PyInterface(void)
{
	if( ref_count++ == 0 )
	{
		Py_Initialize();
		m_pLog = LogManager::getSingleton().getLog("PyInterface");
		m_pLog->setLogLevel(LogLevel_Debug);
		m_pLog->info("Py_Initialize");
	}
}

PyInterface::~PyInterface(void)
{
	if( --ref_count == 0 )
	{
		Py_Finalize();
		m_pLog->info("Py_Finalize");
	}
}

void PyInterface::loadModule(const char* moduleName)
{
	PyObjectPtr name(PyString_FromString(moduleName), "moduleName");
	m_pModule = PyImport_Import(name.get());
	m_pModule.setObjName("module");

	
	if( m_pModule.get() == NULL )
	{
		m_pLog->debug(string(moduleName) + " is NULL.");
		return;
	}
	m_pLog->info(string("open ") + moduleName + " successfully");
}

PyObjectPtr& PyInterface::getFunction(const char* name)
{
	PyObjectPtrDict::iterator itr = m_pPyDict.find(string(name));
	if( itr != m_pPyDict.end() )
		return itr->second;
	PyObjectPtr func(PyObject_GetAttrString(m_pModule.get(), name));
	if( func.get() == NULL )
	{
		m_pLog->error(string("getFunction with name = ") + name + " is NULL.");
		return PyObjectPtr::PyObjectPtrNull;
	}
	if( PyCallable_Check(func.get()) == 0 )
	{
		m_pLog->error(string("getFunction with name = ") + name + " is not callable.");
		return PyObjectPtr::PyObjectPtrNull;
	}
	m_pPyDict[string(name)] = func;
	return m_pPyDict[string(name)];
}