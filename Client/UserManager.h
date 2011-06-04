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
	// @param name,查询的用户名，空字符串表示查找所有用户
	QString searchCmd(const QString& name = "");
	// 修改名为name的用户的密码和权限
	// @param name, 用户名
	// @param password, 修改后的密码，空字符串表示不修改
	// @param author, 修改后的权限，-1表示不修改
	//				  权限0表示管理员，1表示非管理员
	QString updateCmd(const User& user);
public:
	void loginCallBack(bool isLogined, int32 author);
	void insertCallBack(const UserList& userList);
	void searchCallBack(const UserList& userList);
	void updateCallBack(int32 rowCount);
protected:	
	UserList m_userList;
};
