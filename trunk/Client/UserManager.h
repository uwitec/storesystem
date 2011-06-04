#pragma once
#include "Tables.h"
#include "TableManager.h"
#include "LogManager.h"
#include "MainWidget.h"
class UserManager : public TableManager
{
public:
	UserManager(void);
	~UserManager(void);
	QString loginCmd(const QString& name, const QString& password);
	QString insertCmd(const User& user);
	// @param name,��ѯ���û��������ַ�����ʾ���������û�
	QString searchCmd(const QString& name = "");
	// �޸���Ϊname���û��������Ȩ��
	// @param name, �û���
	// @param password, �޸ĺ�����룬���ַ�����ʾ���޸�
	// @param author, �޸ĺ��Ȩ�ޣ�-1��ʾ���޸�
	//				  Ȩ��0��ʾ����Ա��1��ʾ�ǹ���Ա
	QString updateCmd(const User& user);
public:
	void loginCallBack(bool isLogined, int32 author);
	void insertCallBack(const UserList& userList);
	void searchCallBack(const UserList& userList);
	void updateCallBack(int32 rowCount);
protected:	
	UserList m_userList;
};
