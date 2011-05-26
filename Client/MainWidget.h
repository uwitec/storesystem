#pragma once
#include "ui_MainWidget.h"
class MainWidget : QTabWidget
{
	Q_OBJECT
public:
	MainWidget(QWidget *parent = 0);
	~MainWidget(void);

private:
	Ui::MainWidget ui;
};
