#include "stdafx.h"
#include "StoreSystem.h"

StoreSystem::StoreSystem(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	m_pMainWidget = new MainWidget(this);
	this->setCentralWidget((QWidget*)(m_pMainWidget));
}

StoreSystem::~StoreSystem()
{

}
