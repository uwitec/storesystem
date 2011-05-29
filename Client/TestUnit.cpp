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
	testLog->debug(um.updateCmd("admin", "12345", 1).toLocal8Bit().data());
	testLog->debug(um.updateCmd("admin", "", 1).toLocal8Bit().data());
	testLog->debug(um.updateCmd("admin", "", -1).toLocal8Bit().data());
	testLog->debug(um.updateCmd("", "12345", 1).toLocal8Bit().data());
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
	logic.userUpdate("admin", "12345", 0);
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

#include "PyInterface.h"
void TestPy()
{
	PyInterface py;
	py.loadModule("common.cmd");
	py.getModuleFunction("get_cmd_msg");
	py.getModuleFunction("get_msg_from_fmt");
}
#endif