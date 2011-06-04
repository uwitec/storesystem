#pragma
#include "StdAfx.h"
#define __DEBUG
#ifdef __DEBUG
#include "UserManager.h"

// UserManager����
void TestUMSearch();
void TestUMLogin();
void TestUMUpdate();

// SqlCmd����
void TestCmdgetCmdMsg();
void TestCmdcutReplyMsg();

// Logic����
void TestLogicLogin();
void TestLogicUserSearch();
void TestLogicUserUpdate();
void TestLogicParseReplyMsg();
void TestLogicProductSearch();
void TestLogicProductInsert(Logic& logic);
void TestLogicFactoryInsert(Logic& logic);

// PyInterface����
void TestPy();

// ������������
void BuildTestData();










#endif