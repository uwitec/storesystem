#include "stdafx.h"
#include "StoreSystem.h"
#include <QtGui/QApplication>
#include "PyInterface.h"
#include "LogManager.h"
#include "SConvert.h"
#include "SqlCmd.h"
#include "ClientNet.h"
#include "Logic.h"
#include "LoginDlg.h"
#include <QDebug>
#ifdef __DEBUG
#include "TestUnit.h"
#endif

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);	
	QTextCodec* codec = QTextCodec::codecForName("GBK");
	QTextCodec::setCodecForCStrings( QTextCodec::codecForName("GBK") );
	QTextCodec::setCodecForLocale( QTextCodec::codecForName("GBK") );
	//BuildTestData();
	StoreSystem gui;
	gui.show();
	Logic logic;
	logic.setGui(gui.getMainWidget());
	logic.userSearch("");
	logic.productSearch();
	logic.factorySearch();
	logic.purchaseCSearch();
	logic.purchaseSSearch();

	//TestLogicProductInsert(logic);
	//LoginDlg loginDlg;
	//loginDlg.show();
	//translator.load("qt_zh_CN.ts");
	//TestUMSearch();
	//TestUMLogin();
	//TestUMUpdate();
	//TestCmdgetCmdMsg();
	//TestCmdcutReplyMsg();
	
	//TestLogicLogin();
	//TestLogicUserSearch();
	//TestLogicUserUpdate();
	//TestLogicParseReplyMsg();
	//ClientNet net;
	//TestPy();
	//SqlCmd sqlCmd;
	//Logic logic;
	//logic.setSqlCmd(&sqlCmd);
	//ClientNet net(&logic);
	//logic.SetNet(&net);
	//logic.userLogin("admin", "12345");
	return a.exec();	
}


/*
// pythonµ÷ÊÔ
int main()
{	
	PyInterface py;	
	PyObject* pModel = PyImport_ImportModule("cmd");
	if( PyCallable_Check(pModel) )
		printf("callable\n");
	PyObject_CallObject(pModel, NULL);
	if( pModel == NULL )
		printf("model is NULL\n");
	PyObject* pFunc = PyObject_GetAttrString(pModel, "cmd.get_cmd_msg");
	if( pFunc == NULL )
		printf("pFunc is NULL\n");
	//py.loadModule("init_client");
	//py.loadModule("cmd");
	//py.getModuleFunction("get_cmd_msg");
	//PyObjectPtr module = py.getModule();
	//PyObjectPtr path( py.getObjAttrObject(module, "path") );
	//PyList_Append(path.get(), PyString_FromString("common") );
	//printf(PyString_AsString(path.get()));
	//py.loadModule("common.cmd");
	return 0;
	//SqlCmd cmd;
	//PyObjectPtr func(cmd.callFunction("fmt_msg", "s", "hello world"), "fmt_msg");
	//PyInterface py;
	//
	//py.loadModule("common.cmd");
	//PyObjectPtr get_cmd = py.getFunction("get_cmd");
	//PyObjectPtr args(Py_BuildValue("(s)", "user"));
	//PyObjectPtr value = PyObject_CallObject(get_cmd.get(), args.get());
	//PyObjectPtr attr = PyObject_GetAttrString(value.get(), "__repr__");
	//PyObjectPtr text = PyObject_CallObject(attr.get(), NULL);
	//printf(PyString_AsString(text.get()));
	//printf("%d\n", Py_REFCNT(func.get()));
	//func = py.getFunction("get_cmd");
	//printf("%d\n", Py_REFCNT(func.get()));
	//func = py.getFunction("get_cmd");
	//printf("%d\n", Py_REFCNT(func.get()));
	//printf("%s\n", SConvert::toString(123.05f).c_str());
	
}
*/