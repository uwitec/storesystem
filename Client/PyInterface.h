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
	PyObject& operator * ()
	{
		return *m_pObject;
	}
	PyObjectPtr& operator = (PyObject* obj)
	{
		pyRelease();
		m_pObject = obj;
		//printf("operator =\n");
		return *this;
	}
	PyObject* get(){ return m_pObject; }
protected:
	void pyRelease()
	{
		if( m_pObject )
		{
			Py_XDECREF(m_pObject);
			m_pObject = NULL;
			//printf("Py_XDECREF\n");
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
