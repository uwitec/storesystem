#include "stdafx.h"
#include "StoreSystem.h"
#include <QtGui/QApplication>
#include "PyInterface.h"
#include "LogManager.h"
#include "SConvert.h"
#include "SqlCmd.h"
#include "ClientNet.h"
#include "Logic.h"
#include <QDebug>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTranslator translator;
	translator.load("qt_zh_CN.ts");
	//StoreSystem w;
	//w.show();
	//ClientNet net;
	//net.send("hello world");
	Logic logic;
	SqlCmd* p_cmd = logic.getSqlCmd();
	p_cmd->login("admin", "12345");
	//QString str = "hello world";
	//qDebug()<<str<<str.mid(1);
	return a.exec();
}


/*
// pythonµ÷ÊÔ
int main()
{
	//return 0;
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