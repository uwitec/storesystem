#include "StdAfx.h"
#include "UserManager.h"

UserManager::UserManager(void)
:	m_pGui(NULL)
{
	m_pLog = LogManager::getSingleton().getLog("UserManager");
	m_pLog->setStdStreamActive(true);
}

UserManager::~UserManager(void)
{
}

QString UserManager::loginCmd(const QString& name, const QString& password)
{
	QString cmd = QString::fromLocal8Bit("select * from user "
		"where name=\'%1\' and password=\'%2\'").arg(name).arg(password);
	return cmd;
}

QString UserManager::searchCmd(const QString& name)
{
	QString cmd = QString::fromLocal8Bit("select * from user ");
	if( !name.isNull() && !name.isEmpty() )
		cmd += QString::fromLocal8Bit("where name='%1'").arg(name);
	return cmd;
}

QString UserManager::updateCmd(const QString& name, const QString& password, int32 author)
{
	// name为空，不执行SQL命令
	if( name.isNull() || name.isEmpty() )
		return name;
	// password 和 author 同时不合法
	if( (password.isNull() || password.isEmpty()) && author == -1 )
		return "";
	// author不合法
	if( author != -1 && author != 0 && author != 1 )
		return "";
	QString set = "";
	if( password.size() > 0 )
		set = QString("password='%1'").arg(password);
	char dot = ' ';
	if( set.size() > 0 )
		dot = ',';
	if( author != -1 )
		set += QString("%1author=%2").arg(dot).arg(author);
	QString cmd = QString("update user set %1 where name='%2'").arg(set).arg(name);
	return cmd;
}

void UserManager::loginCallBack(bool isLogined, int32 author)
{
	if( isLogined )
	{
		m_pLog->info("login success.");
	}
	else
	{
		m_pLog->info("login failed");
	}
}

void UserManager::searchCallBack(const UserList& userList)
{
	m_pLog->info(std::string("search result count = ") 
		+ SConvert::toString(userList.size()));
	if( m_pGui )
		m_pGui->setUserData(userList);
}

void UserManager::updateCallBack(int32 rowCount)
{
	m_pLog->info(std::string("update rowCount = ")
		+ SConvert::toString(rowCount));
}