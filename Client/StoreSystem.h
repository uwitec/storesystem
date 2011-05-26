#ifndef STORESYSTEM_H
#define STORESYSTEM_H

#include <QtGui/QMainWindow>
#include "ui_StoreSystem.h"
#include "MainWidget.h"

class StoreSystem : public QMainWindow
{
	Q_OBJECT

public:
	StoreSystem(QWidget *parent = 0, Qt::WFlags flags = 0);
	~StoreSystem();

protected:
	MainWidget* m_pMainWidget;

private:
	Ui::StoreSystemClass ui;
};

#endif // STORESYSTEM_H
