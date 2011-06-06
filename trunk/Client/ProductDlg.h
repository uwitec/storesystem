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
	// 让产品名、类型名的ComboBox有自动完成的功能
	// @param pProductModel，产品的Model
	void setCompleterModel(QStandardItemModel* pProductModel);
	// 让厂商的ComboBox具有厂商选项
	// @param pFactoryModel，厂商的Model
	// @param pCompleter，自动完成
	void setFactoryModel(QStandardItemModel* pFactoryModel,
						 QCompleter* pCompleter);
public slots:
	void accept();
protected:
	Ui::ProductDlg ui;
	Product m_product;
};

#endif // PRODUCTINSERTDLG_H
