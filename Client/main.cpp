#include "stdafx.h"
#include "StoreSystem.h"
#include <QtGui/QApplication>
#include "PyInterface.h"
#include "LogManager.h"
/*
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	StoreSystem w;
	w.show();
	return a.exec();
}
*/

// pythonµ÷ÊÔ
int main()
{
	PyInterface py;
	py.loadModule("common.cmd");

	LogManager mgr = LogManager::getSingleton();
	Log* log = mgr.getDefaultLog();
	log->debug("hello world");
	log->debug("very good");
}