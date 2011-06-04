#pragma
#include "StdAfx.h"
#define __DEBUG
#ifdef __DEBUG
#include "UserManager.h"

// UserManager测试
void TestUMSearch();
void TestUMLogin();
void TestUMUpdate();

// SqlCmd测试
void TestCmdgetCmdMsg();
void TestCmdcutReplyMsg();

// Logic测试
void TestLogicLogin();
void TestLogicUserSearch();
void TestLogicUserUpdate();
void TestLogicParseReplyMsg();
void TestLogicProductSearch();
void TestLogicProductInsert(Logic& logic);
void TestLogicFactoryInsert(Logic& logic);

// PyInterface测试
void TestPy();

// 建立基本数据
void BuildTestData();










#endif