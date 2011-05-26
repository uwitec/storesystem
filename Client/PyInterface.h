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
	PyObjectPtr m_pModule;	// 模块
	static int ref_count;	// 引用计数
	Log* m_pLog;			// 日志
	typedef std::map<std::string, PyObjectPtr> PyObjectPtrDict;
	// 存储函数等python对象
	PyObjectPtrDict m_pPyDict;
};
