#pragma once
#pragma comment(lib, "python27.lib")
#include <python.h>
#include "LogManager.h"
class PyObjectPtr
{
public:
	PyObjectPtr(PyObject* obj = NULL, std::string objName = "")
		: m_pObject(obj), m_objName(objName){}
	~PyObjectPtr();
	PyObject& operator * (){ return *m_pObject; };
	PyObjectPtr& operator = (PyObject* obj);	
	PyObjectPtr& operator = (PyObjectPtr& obj);	
	PyObject* get(){ return m_pObject; }
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
	PyObjectPtr& getFunction(const char* name);
protected:
	PyObjectPtr m_pModule;	// ģ��
	static int ref_count;	// ���ü���
	Log* m_pLog;			// ��־
	typedef std::map<std::string, PyObjectPtr> PyObjectPtrDict;
	// �洢������python����
	PyObjectPtrDict m_pPyDict;
};
