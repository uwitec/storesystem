#ifndef FACTORYDLG_H
#define FACTORYDLG_H

#include <QDialog>
#include "ui_FactoryDlg.h"
#include "Tables.h"
class FactoryDlg : public QDialog
{
	Q_OBJECT

public:
	FactoryDlg(QWidget *parent = 0);
	~FactoryDlg();
	const Factory& getFactory(){ return m_factory; }
	void setFactory(const Factory& factory);
	void setCompleterModel(QStandardItemModel* pFactoryModel);
public slots:
	void accept();
private:
	Ui::FactoryDlg ui;
	Factory m_factory;
};

#endif // FACTORYDLG_H
