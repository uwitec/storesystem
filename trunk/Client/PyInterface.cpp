#include "StdAfx.h"
#include "PyInterface.h"
using namespace std;

PyObjectPtr PyObjectPtr::PyObjectPtrNull(NULL);

PyObjectPtr::PyObjectPtr(PyObject* obj, std::string objName)
:m_pObject(obj), m_objName(objName)
{
}
PyObjectPtr::PyObjectPtr(const PyObjectPtr& objPtr, std::string objName)
: m_objName(objName)
{
	//printf("copy construct\n");
	m_pObject = objPtr.m_pObject;
	m_objName = objPtr.m_objName;
	//Py_XINCREF(m_pObject);
	//PyObjectPtr_IncRef(*this);
	PyObjectPtr_IncRef(m_pObject, m_objName);
}

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
	//printf("operator = PyObjectPtr\n");
	pyRelease();
	PyObjectPtr_IncRef(obj.get(), obj.m_objName);
	m_pObject = obj.get();
	m_objName = obj.m_objName;
	return *this;
}

void PyObjectPtr::pyRelease()
{
	if( m_pObject )
	{
		PyObjectPtr_DecRef(m_pObject, m_objName);
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
	PyObjectPtr name(PyString_FromString(moduleName), moduleName);	
	m_pModule = PyImport_Import(name.get());
	m_pModule.setObjName("module");

	
	if( m_pModule.get() == NULL )
	{
		m_pLog->debug(string(moduleName) + " is NULL.");
		return;
	}
	m_pLog->info(string("open ") + moduleName + " successfully");
}

PyObjectPtr& PyInterface::getModuleFunction(const char* name)
{
	PyObjectPtrDict::iterator itr = m_pPyDict.find(string(name));
	if( itr != m_pPyDict.end() )
		return itr->second;
	PyObjectPtr func = this->getFunction(m_pModule, name);
	m_pPyDict[string(name)] = func;
	return m_pPyDict[string(name)];
}

PyObjectPtr PyInterface::getFunction(const PyObjectPtr& obj, const char* name)
{
	PyObjectPtr func(PyObject_GetAttrString(obj.get(), name), name);
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
	return func;
}

void PyInterface::setObjAttrInt(PyObjectPtr& pyObjPtr, const char* attrName, int value)
{
	PyObject_SetAttrString(pyObjPtr.get(), attrName, PyLong_FromLong(value));
}
void PyInterface::setObjAttrString(PyObjectPtr& pyObjPtr, const char* attrName, const char* value)
{
	PyObject_SetAttrString(pyObjPtr.get(), attrName, PyString_FromString(value));
}
void PyInterface::setObjAttrFloat(PyObjectPtr& pyObjPtr, const char* attrName, float value)
{
	PyObject_SetAttrString(pyObjPtr.get(), attrName, PyFloat_FromDouble(value));
}
void PyInterface::setObjAttrDouble(PyObjectPtr& pyObjPtr, const char* attrName, double value)
{
	PyObject_SetAttrString(pyObjPtr.get(), attrName, PyFloat_FromDouble(value));
}
void PyInterface::setObjAttrObject(PyObjectPtr& pyObjPtr, const char* attrName, PyObjectPtr& value)
{
	PyObject_SetAttrString(pyObjPtr.get(), attrName, value.get());
}