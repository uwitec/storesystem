#include "StdAfx.h"
#include "ProductDlg.h"
#include "Gui.h"

ProductDlg::ProductDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect( ui.m_pAcceptBtn, SIGNAL(clicked()),
			 this, SLOT(accept()) );
	ui.m_pDateEdit->setDate( QDate::currentDate() );
}

ProductDlg::~ProductDlg()
{

}

void ProductDlg::setProduct(const Product& product)
{
	m_product.id = product.id;
	ui.m_pNameBox->setEditText(product.name);
	ui.m_pTypeBox->setEditText(product.type);
	// ----产商ID---未作验证
	setFactoryBoxID(ui.m_pMF_idBox, product.MF_id);
	ui.m_pCountSpin->setValue(product.count);
	ui.m_pDateEdit->setDate(QDate::fromString(product.date, "yyyy-MM-dd"));
	ui.m_pPricebuySpin->setValue(product.price_buy * 0.01);
	ui.m_pPricenwSpin->setValue(product.price_nw * 0.01);
	ui.m_pPricewwSpin->setValue(product.price_ww * 0.01);
	ui.m_pFeeOtherSpin->setValue(product.fee_other * 0.01);
}

void ProductDlg::setCompleterModel(QStandardItemModel* pProductModel)
{
	setComboBoxCompleterModel(ui.m_pNameBox, pProductModel, 1);
	setComboBoxCompleterModel(ui.m_pTypeBox, pProductModel, 2);
}

void ProductDlg::setFactoryModel(QStandardItemModel* pFactoryModel,
								 QCompleter* pCompleter)
{
	//setComboBoxCompleterModel(ui.m_pMF_idBox, pFactoryModel, 1);
	setComboBoxCompleterModel(ui.m_pMF_idBox, pFactoryModel, pCompleter, 1);
}

void ProductDlg::accept()
{
	m_product.name = ui.m_pNameBox->currentText();
	m_product.type = ui.m_pTypeBox->currentText();
	m_product.MF_id = getFactoryBoxID(ui.m_pMF_idBox, ui.m_pMF_idBox->currentIndex());
	m_product.count = ui.m_pCountSpin->value();
	m_product.date = ui.m_pDateEdit->date().toString("yyyy-MM-dd");
	m_product.price_buy = ui.m_pPricebuySpin->value() * 100;
	m_product.price_nw = ui.m_pPricenwSpin->value() * 100;
	m_product.price_ww = ui.m_pPricewwSpin->value() * 100;
	m_product.fee_other = ui.m_pFeeOtherSpin->value() * 100;
	QDialog::accept();
}
