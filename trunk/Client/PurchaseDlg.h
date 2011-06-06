#ifndef PURCHASEDLG_H
#define PURCHASEDLG_H

#include <QDialog>
#include "ui_PurchaseDlg.h"
#include "Tables.h"
class PurchaseDlg : public QDialog
{
	Q_OBJECT

public:
	PurchaseDlg(QWidget *parent = 0);
	~PurchaseDlg();
	void setPurchaseC(const PurchaseC& purC);
	PurchaseC getPurchaseC(){ return m_purchaseC; }
	void setPurchaseS(const PurchaseS& purS);
	PurchaseS getPurchaseS(){ return m_purchaseS; }
	void setPurchaseSBatch(uint32 batch);
	// 让厂商的ComboBox具有厂商选项
	// @param pFactoryModel，厂商的Model
	// @param pCompleter，自动完成
	void setFactoryModel(QStandardItemModel* pFactoryModel,
						 QCompleter* pCompleter);
	void setProductModel(QStandardItemModel* pProductModel,
						 QCompleter* pCompleter);
	void setPurchaseSVisible(bool isVisible);
public slots:
	void accept();
	void onProductChanged(int index);
private:
	PurchaseC m_purchaseC;
	PurchaseS m_purchaseS;
	Ui::PurchaseDlg ui;
};

#endif // PURCHASEDLG_H
