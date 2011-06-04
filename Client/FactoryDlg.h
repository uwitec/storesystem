#ifndef FACTORYDLG_H
#define FACTORYDLG_H

#include <QDialog>
#include "ui_FactoryDlg.h"

class FactoryDlg : public QDialog
{
	Q_OBJECT

public:
	FactoryDlg(QWidget *parent = 0);
	~FactoryDlg();

private:
	Ui::FactoryDlg ui;
};

#endif // FACTORYDLG_H
