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
		m_pLog->setStdStreamActive(true);
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

PyObjectPtr PyInterface::callFunction(PyObjectPtr& pyFuncObj, const char* fmt, ...)
{
	va_list v;
	uint32 narg = 0;
	va_start(v, fmt);
	// 检查有效参数
	uint32 fmtLen = strlen(fmt);
	for( uint32 i = 0; i < fmtLen; ++i )
	{
		if( fmt[i] == 's' ) ++narg;
		else if( fmt[i] == 'i' ) ++narg;
		else if( fmt[i] == 'f' ) ++narg;
		else if( fmt[i] == 'd' ) ++narg;
		else if( fmt[i] == 'o' ) ++narg;
		else
		{
			m_pLog->warning(std::string("callFunction fmt ") + fmt[i] + " is not fmt");
		}
	}
	if( fmtLen != narg )
	{
		m_pLog->warning(std::string("callFunction NOT all fmt=") + fmt + " is valid.");
	}
	PyObjectPtr args(PyTuple_New(narg), "args");
	int32 index = 0;
	for( uint32 i = 0; i < fmtLen; ++i )
	{
		if( fmt[i] == 's' )
			PyTuple_SetItem(args.get(), index++, PyString_FromString(va_arg(v, char*)) );
		else if( fmt[i] == 'i' )
			PyTuple_SetItem(args.get(), index++, PyInt_FromLong(va_arg(v, int)));
		else if( fmt[i] == 'f' )
			PyTuple_SetItem(args.get(), index++, PyFloat_FromDouble(va_arg(v, float)));
		else if( fmt[i] == 'd' )
			PyTuple_SetItem(args.get(), index++, PyFloat_FromDouble(va_arg(v, float)));
		else if( fmt[i] == 'o' )
			PyTuple_SetItem(args.get(), index++, va_arg(v, PyObject*));
	}
	PyObjectPtr values( PyObject_CallObject(pyFuncObj.get(), args.get()), "value" );
	va_end(v);
	return values;
}

PyObjectPtr PyInterface::getFunction(const PyObjectPtr& obj, const char* name)
{
	PyObjectPtr func(PyObject_GetAttrString(obj.get(), name), name);
	if( func.get() == NULL )
	{
		m_pLog->error(string("getFunction with name = ") + name + " is NULL.");
		return PyObjectPtr::PyObjectPtrNull;
	}
	int canBeCalled = PyCallable_Check(func.get());
	if( 0 == canBeCalled )
	{
		m_pLog->error(string("getFunction with name = ") + name + " is not callable.");
		return PyObjectPtr::PyObjectPtrNull;
	}
	return func;
}

void PyInterface::setObjAttrInt(PyObjectPtr& pyObjPtr, const char* attrName, int value)
{
	PyObjectPtr pyValue(PyLong_FromLong(value));
	PyObject_SetAttrString(pyObjPtr.get(), attrName, pyValue.get());
}
void PyInterface::setObjAttrString(PyObjectPtr& pyObjPtr, const char* attrName, const char* value)
{
	PyObjectPtr pyValue(PyString_FromString(value));
	PyObject_SetAttrString(pyObjPtr.get(), attrName, pyValue.get());
}
void PyInterface::setObjAttrFloat(PyObjectPtr& pyObjPtr, const char* attrName, float value)
{
	PyObjectPtr pyValue(PyFloat_FromDouble(value));
	PyObject_SetAttrString(pyObjPtr.get(), attrName, pyValue.get());
}
void PyInterface::setObjAttrDouble(PyObjectPtr& pyObjPtr, const char* attrName, double value)
{
	PyObjectPtr pyValue(PyFloat_FromDouble(value));
	PyObject_SetAttrString(pyObjPtr.get(), attrName, pyValue.get());
}
void PyInterface::setObjAttrObject(PyObjectPtr& pyObjPtr, const char* attrName, PyObjectPtr& value)
{
	PyObject_SetAttrString(pyObjPtr.get(), attrName, value.get());
}

int32 PyInterface::getObjAttrInt(PyObjectPtr& pyObjPtr, const char* attrName)
{
	PyObjectPtr pyAttrName(PyString_FromString(attrName));
	return PyLong_AsLong(PyObject_GetAttr(pyObjPtr.get(), pyAttrName.get()));
}

const char* PyInterface::getObjAttrString(PyObjectPtr& pyObjPtr, const char* attrName)
{
	PyObjectPtr pyAttrName(PyString_FromString(attrName));
	return PyString_AsString(PyObject_GetAttr(pyObjPtr.get(), pyAttrName.get()));
}

PyObjectPtr PyInterface::getObjAttrObject(PyObjectPtr& pyObjPtr, const char* attrName)
{
	PyObjectPtr pyAttrName(PyString_FromString(attrName));
	return PyObjectPtr(PyObject_GetAttr(pyObjPtr.get(), pyAttrName.get()), attrName);
}