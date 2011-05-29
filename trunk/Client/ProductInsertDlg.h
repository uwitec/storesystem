#ifndef PRODUCTINSERTDLG_H
#define PRODUCTINSERTDLG_H

#include <QDialog>
#include "ui_ProductInsertDlg.h"
#include "Tables.h"

class ProductInsertDlg : public QDialog
{
	Q_OBJECT

public:
	ProductInsertDlg(QWidget *parent = 0);
	~ProductInsertDlg();
	const Product& getProduct(){ return m_product; }
public slots:
	void accept();
private:
	Ui::ProductInsertDlg ui;
	Product m_product;
};

#endif // PRODUCTINSERTDLG_H
