#ifndef PRODUCTINSERTDLG_H
#define PRODUCTINSERTDLG_H

#include <QDialog>
#include "ui_ProductDlg.h"
#include "Tables.h"

class ProductDlg : public QDialog
{
	Q_OBJECT

public:
	ProductDlg(QWidget *parent = 0);
	~ProductDlg();
	const Product& getProduct(){ return m_product; }
	void setProduct(const Product& product);
public slots:
	void accept();
private:
	Ui::ProductDlg ui;
	Product m_product;
};

#endif // PRODUCTINSERTDLG_H
