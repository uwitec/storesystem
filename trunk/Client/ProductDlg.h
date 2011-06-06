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
	// �ò�Ʒ������������ComboBox���Զ���ɵĹ���
	// @param pProductModel����Ʒ��Model
	void setCompleterModel(QStandardItemModel* pProductModel);
	// �ó��̵�ComboBox���г���ѡ��
	// @param pFactoryModel�����̵�Model
	// @param pCompleter���Զ����
	void setFactoryModel(QStandardItemModel* pFactoryModel,
						 QCompleter* pCompleter);
public slots:
	void accept();
protected:
	Ui::ProductDlg ui;
	Product m_product;
};

#endif // PRODUCTINSERTDLG_H
