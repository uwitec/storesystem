#pragma once
#include "Tables.h"
#include "LogManager.h"
#include "MainWidget.h"
class UserManager
{
public:
	UserManager(void);
	~UserManager(void);
	void setGui(MainWidget* pGui){ m_pGui = pGui; }
	QString loginCmd(const QString& name, const QString& password);
	// @param name,��ѯ���û��������ַ�����ʾ���������û�
	QString searchCmd(const QString& name);
	// �޸���Ϊname���û��������Ȩ��
	// @param name, �û���
	// @param password, �޸ĺ�����룬���ַ�����ʾ���޸�
	// @param author, �޸ĺ��Ȩ�ޣ�-1��ʾ���޸�
	//				  Ȩ��0��ʾ����Ա��1��ʾ�ǹ���Ա
	QString updateCmd(const QString& name, const QString& password,
					  int32 author);
public:
	void loginCallBack(bool isLogined, int32 author);
	void searchCallBack(const UserList& userList);
	void updateCallBack(int32 rowCount);
protected:	
	UserList m_userList;
	Log* m_pLog;
	MainWidget* m_pGui;
};
