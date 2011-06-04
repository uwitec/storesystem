#include "StdAfx.h"
#include "TestUnit.h"
#include <QtGui/QApplication>
#include "PyInterface.h"
#include "LogManager.h"
#include "SConvert.h"
#include "SqlCmd.h"
#include "ClientNet.h"
#include "Logic.h"
#ifdef __DEBUG
#include "LogManager.h"
#include "SqlCmd.h"
Log* testLog = LogManager::getSingleton().getLog("TestUnit", LogLevel_Debug, true);
void TestUMSearch()
{
	UserManager um;
	testLog->debug(um.searchCmd("admin").toLocal8Bit().data());
}

void TestUMLogin()
{
	UserManager um;
	testLog->debug(um.loginCmd("admin", "12345").toLocal8Bit().data());
}

void TestUMUpdate()
{
	UserManager um;
	User user;
	user.name = "admin";
	user.password = "12345";
	user.authority = 1;
	testLog->debug(um.updateCmd(user).toLocal8Bit().data());
	testLog->debug(um.updateCmd(user).toLocal8Bit().data());
	testLog->debug(um.updateCmd(user).toLocal8Bit().data());
	testLog->debug(um.updateCmd(user).toLocal8Bit().data());
}

void TestCmdgetCmdMsg()
{
	SqlCmd cmd;
	testLog->debug(cmd.getCmdMsg("user", "login", "select * from user")
		.toLocal8Bit().data());
}

void TestCmdcutReplyMsg()
{
	SqlCmd cmd;
	QString replyMsg = "connect";
	QString fullMsg = "";
	int32 hadCut = -1;
	cmd.cutReplyMsg(replyMsg, fullMsg, hadCut);
	testLog->debug(replyMsg.toLocal8Bit().data());
	testLog->debug(fullMsg.toLocal8Bit().data());
	testLog->debug(SConvert::toString(hadCut));
}
#include "Logic.h"
#include <windows.h>
void TestLogicLogin()
{
	static Logic logic;
	logic.userLogin("admin", "12345");
}

void TestLogicUserSearch()
{
	static Logic logic;
	logic.userSearch("");
}

void TestLogicUserUpdate()
{
	static Logic logic;
	User user;
	user.name = "admin";
	user.password = "12345";
	user.authority = 1;
	logic.userUpdate(user);
}

void TestLogicParseReplyMsg()
{
	static Logic logic;
	QString replyMsg = "connect";
	logic.parseReplyMsg(replyMsg);
}

void TestLogicProductSearch()
{
	static Logic logic;
	logic.productSearch();
}

void TestLogicProductInsert(Logic& logic)
{
	Product p;
	p.name = "手机";
	p.type = "重武器";
	p.count= 20;
	p.MF_id = 0;
	p.price_buy = 10000;
	p.price_nw = 100010;
	p.price_ww = 200000;
	p.date = "2011/5/29";
	p.fee_other = 0;
	logic.productInsert(p);
}

void TestLogicFactoryInsert(Logic& logic)
{
	Factory f;
	f.name = "饮料厂";
	f.addr = "饮料路饮料厂";
	f.email = "hello@world.com";
	logic.factoryInsert(f);
}

#include "PyInterface.h"
void TestPy()
{
	PyInterface py;
	py.loadModule("common.cmd");
	py.getModuleFunction("get_cmd_msg");
	py.getModuleFunction("get_msg_from_fmt");
}
#include <QFile>
#include <QTextStream>
void BuildTestData()
{
	static Logic logic;
	QFile file("buildTestData.txt");
	file.open(QFile::ReadOnly);
	QTextStream ts(&file);
	while( !ts.atEnd() )
	{
		QString name;
		int32 count;
		ts>>name>>count;
		printf("%s %d\n", name.toStdString().c_str(), count);
		if( name == "user" )
		{
			User user;
			for( int32 i = 0; i < count; ++i )
			{
				ts>>user.name>>user.password>>user.authority;
				//printf("user\n");
				logic.userInsert(user);
			}
		}
		else if( name == "factory" )
		{
			Factory factory;
			for( int32 i = 0; i < count; ++i )
			{
				ts>>factory.name>>factory.contact>>factory.post
				  >>factory.phone>>factory.zip_code>>factory.addr
				  >>factory.email>>factory.card_type>>factory.card_num;
				logic.factoryInsert(factory);
			}
		}
		else if( name == "product" )
		{
			Product product;
			for( int32 i = 0; i < count; ++i )
			{
				ts>>product.name>>product.type>>product.MF_id
				  >>product.count>>product.date>>product.price_buy
				  >>product.price_nw>>product.price_ww>>product.fee_other;
				logic.productInsert(product);
			}
		}
	}
}

#endif