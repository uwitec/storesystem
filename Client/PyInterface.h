#pragma once
#pragma comment(lib, "python27.lib")
#include <python.h>
#include "StdAfx.h"
#include "LogManager.h"
#include "SConvert.h"

#ifdef __DEBUG
	#define PyObjectPtr_IncRef(pyObj, pyName)\
		if( pyObj != NULL )\
		{\
			Py_XINCREF(pyObj);\
			Log* log = LogManager::getSingleton().getLog("PyObjectPtr");\
			log->debug(pyName + "\tPy_XDECREF\tref=" + SConvert::toString(Py_REFCNT(pyObj)));\
		}
	
	#define PyObjectPtr_DecRef(pyObj, pyName)\
		Log* log = LogManager::getSingleton().getLog("PyObjectPtr");\
		Py_XDECREF(pyObj);\
		if(pyObj)\
			log->debug(pyName + "\tPy_XDECREF\tref=" + SConvert::toString(Py_REFCNT(pyObj)));

#else
	#define PyObjectPtr_IncRef(pyObj, pyName)\
		Py_XINCREF(pyObj);
	#define PyObjectPtr_DecRef(pyObj, pyName)\
		Py_XDECREF(pyObj);
#endif

class PyObjectPtr
{
public:
	PyObjectPtr(PyObject* obj = NULL, std::string objName = "");
	PyObjectPtr(const PyObjectPtr& objPtr, std::string objName = "");
	~PyObjectPtr();
	PyObject& operator * (){ return *m_pObject; };
	PyObjectPtr& operator = (PyObject* obj);	
	PyObjectPtr& operator = (PyObjectPtr& obj);	
	PyObject* get(){ return m_pObject; }
	PyObject* get() const{ return m_pObject; }
	void setObjName(const char* name){ m_objName = name; }
	static PyObjectPtr PyObjectPtrNull;
protected:
	void pyRelease();
	PyObject* m_pObject;
	std::string m_objName;
};

class PyInterface
{
public:
	PyInterface(void);
	virtual ~PyInterface(void);
	void loadModule(const char* moduleName);
	// ���ģ��ĺ���
	PyObjectPtr& getModuleFunction(const char* name);
	// ����ض�ģ��ĺ���
	PyObjectPtr getFunction(const PyObjectPtr& obj, const char* name);
	// ����ģ������
	void setObjAttrInt(PyObjectPtr& pyObjPtr, const char* attrName, int value);
	void setObjAttrString(PyObjectPtr& pyObjPtr, const char* attrName, const char* value);
	void setObjAttrFloat(PyObjectPtr& pyObjPtr, const char* attrName, float value);
	void setObjAttrDouble(PyObjectPtr& pyObjPtr, const char* attrName, double value);
	void setObjAttrObject(PyObjectPtr& pyObjPtr, const char* attrName, PyObjectPtr& value);
protected:
	PyObjectPtr m_pModule;	// ģ��
	static int ref_count;	// ���ü���
	Log* m_pLog;			// ��־
	typedef std::map<std::string, PyObjectPtr> PyObjectPtrDict;
	// �洢������python����
	PyObjectPtrDict m_pPyDict;
};
