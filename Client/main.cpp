#include "stdafx.h"
#include "StoreSystem.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	StoreSystem w;
	w.show();
	return a.exec();
}
