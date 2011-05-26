#pragma once
#pragma comment(lib, "python27.lib")
#include <python.h>
class PyObjectPtr
{
public:
	PyObjectPtr(PyObject* obj = NULL)
		: m_pObject(obj){}	
	~PyObjectPtr()
	{
		pyRelease();
	}
	PyObject* operator -> ()
	{
		return m_pObject;
	}
	PyObject& operator * ()
	{
		return *m_pObject;
	}
	PyObjectPtr& operator = (PyObject* obj)
	{
		pyRelease();
		m_pObject = obj;
		return *this;
	}
protected:
	void pyRelease()
	{
		if( m_pObject )
		{
			Py_XDECREF(m_pObject);
			m_pObject = NULL;
		}
	}
	PyObject* m_pObject;
};

class PyInterface
{
public:
	PyInterface(void);
	virtual ~PyInterface(void);
	void loadModule(const char* moduleName);
protected:
	PyObjectPtr m_pModule;
	static int ref_count;
};
