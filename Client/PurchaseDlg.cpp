#include "StdAfx.h"
#include "PurchaseDlg.h"
#include "Gui.h"

PurchaseDlg::PurchaseDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect( ui.m_pAcceptCBtn, SIGNAL(clicked()),
			 this, SLOT(accept()) );
	connect( ui.m_pAcceptSBtn, SIGNAL(clicked()),
			 this, SLOT(accept()) );
	connect( ui.m_pProductIDBox, SIGNAL(currentIndexChanged(int)),
			 this, SLOT(onProductChanged(int)) );
	ui.m_pDateEdit->setDate(QDate::currentDate());
}

PurchaseDlg::~PurchaseDlg()
{

}

void PurchaseDlg::setPurchaseC(const PurchaseC& purC)
{
	m_purchaseC.id = purC.id;
	ui.m_pIDEdit->setText(QString("%1").arg(purC.id));
	ui.m_pDateEdit->setDate(QDate::fromString(purC.date, "yyyy-MM-dd"));
	setFactoryBoxID(ui.m_pMF_idBox, purC.factory_id);
	ui.m_pMemoEdit->setText(purC.memo);
}

void PurchaseDlg::setPurchaseS(const PurchaseS& purS)
{
	m_purchaseS.id = purS.id;
	ui.m_pCountSpin->setValue(purS.count);
	ui.m_pBatchEdit->setText(QString("%1").arg(purS.batch));
	ui.m_pPricePaySpin->setValue(purS.price_pay * 0.01);
	ui.m_pFeeOtherSpin->setValue(purS.fee_other * 0.01);
	setProductBoxID(ui.m_pProductIDBox, purS.product_id);
}

void PurchaseDlg::setPurchaseSBatch(uint32 batch)
{
	ui.m_pBatchEdit->setText(QString("%1").arg(batch));
}

void PurchaseDlg::setFactoryModel(QStandardItemModel* pFactoryModel, QCompleter* pCompleter)
{
	setComboBoxCompleterModel(ui.m_pMF_idBox, pFactoryModel, pCompleter, 1);
}

void PurchaseDlg::setProductModel(QStandardItemModel* pProductModel, QCompleter* pCompleter)
{
	setComboBoxCompleterModel(ui.m_pProductIDBox, pProductModel, pCompleter, 1);
}

void PurchaseDlg::setPurchaseSVisible(bool isVisible)
{
	ui.m_pPurchaseSGroup->setVisible(isVisible);
	ui.m_pPurchaseCGroup->setVisible(!isVisible);
}

void PurchaseDlg::accept()
{
	if(ui.m_pPurchaseCGroup->isVisible())
	{
		m_purchaseC.date = ui.m_pDateEdit->date().toString("yyyy-MM-dd");
		m_purchaseC.memo = ui.m_pMemoEdit->text();
		m_purchaseC.factory_id = getFactoryBoxID(ui.m_pMF_idBox, ui.m_pMF_idBox->currentIndex());
	}
	else
	{
		m_purchaseS.product_id = getProductBoxID(ui.m_pProductIDBox, ui.m_pProductIDBox->currentIndex());
		m_purchaseS.count = ui.m_pCountSpin->value();
		m_purchaseS.price_pay = ui.m_pPricePaySpin->value() * 100;
		m_purchaseS.fee_other = ui.m_pFeeOtherSpin->value() * 100;
		m_purchaseS.batch = ui.m_pBatchEdit->text().toUInt();
	}
	QDialog::accept();
}

void PurchaseDlg::onProductChanged(int index)
{
	if(index < 0)
		return;
	QStandardItemModel* pProductModel 
		= static_cast<QStandardItemModel*>(ui.m_pProductIDBox->model());
	if(index >= pProductModel->rowCount())
		return;
	QModelIndex count_index = pProductModel->index(index, 4);
	QModelIndex date_index = pProductModel->index(index, 5);
	QModelIndex buy_index = pProductModel->index(index, 6);
	QString info = QString::fromLocal8Bit("日期：%1,数量：%2,购买价格：%3")
		.arg(pProductModel->data(date_index).toString())
		.arg(pProductModel->data(count_index).toString())
		.arg(pProductModel->data(buy_index).toString());
	ui.m_pProductInfoEdit->setText(info);
}