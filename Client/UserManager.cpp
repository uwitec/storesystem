#include "StdAfx.h"
#include "UserManager.h"

UserManager::UserManager(void)
: TableManager()
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

QString UserManager::insertCmd(const User& user)
{
	const User& u = user;
	QString cmd = QString("insert into user values(null, "
		"'%1', '%2', %3)").arg(u.name).arg(u.password).arg(u.authority);
	return cmd;
}

QString UserManager::searchCmd(const QString& name)
{
	QString cmd = QString::fromLocal8Bit("select * from user ");
	if( !name.isNull() && !name.isEmpty() )
		cmd += QString::fromLocal8Bit("where name='%1'").arg(name);
	return cmd;
}

QString UserManager::updateCmd(const User& user)
{
	// name为空，不执行SQL命令
	if( user.name.isNull() || user.name.isEmpty() )
		return "";
	// password 和 author 同时不合法
	if( user.password.isEmpty() && user.authority == -1 )
		return "";
	// author不合法
	if( user.authority != -1 && user.authority != 0 && user.authority != 1 )
		return "";
	QString set = "";
	if( user.password.size() > 0 )
		set = QString("password='%1'").arg(user.password);
	char dot = ' ';
	if( set.size() > 0 )
		dot = ',';
	if( user.authority != -1 )
		set += QString("%1author=%2").arg(dot).arg(user.authority);
	QString cmd = QString("update user set %1 where name='%2'").arg(set).arg(user.name);
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

void UserManager::insertCallBack(const UserList& userList)
{
	if( m_pGui )
	{
		UserList::const_iterator itr = userList.begin();
		UserList::const_iterator end = userList.end();
		while( itr != end )
		{
			m_pGui->addUserData(*itr);
			++itr;
		}
	}
	m_pLog->debug("insertCallBack");
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