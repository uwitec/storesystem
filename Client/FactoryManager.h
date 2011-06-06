#pragma once
#include "StdAfx.h"
#include "Tables.h"
#include "LogManager.h"
#include "MainWidget.h"
#include "TableManager.h"
class FactoryManager : public TableManager
{
public:
	FactoryManager(void);
	~FactoryManager(void);
	void setGui(MainWidget* pGui){ m_pGui = pGui; }
	QString searchAllCmd();
	QString insertCmd(const Factory& factory);
	QString updateCmd(const Factory& factory);
	const FactoryPtr getFactoryPtr(int32 index) const;
	//FactoryPtrList& getFactoryPtrList(){ return m_factoryPtrList; }
public:
	void searchCallBack(FactoryPtrList& factoryList);
	void insertCallBack(FactoryPtrList& factoryList);
	void updateCallBack(FactoryPtrList& factoryList);
protected:
	FactoryPtrList m_factoryPtrList;
};
