#include "StdAfx.h"
#include "ProductDlg.h"

ProductDlg::ProductDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect( ui.m_pAcceptBtn, SIGNAL(clicked()),
			 this, SLOT(accept()) );
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
	ui.m_pCountSpin->setValue(product.count);
	ui.m_pDateEdit->setDate(QDate::fromString(product.date, "yyyy-MM-dd"));
	ui.m_pPricebuySpin->setValue(product.price_buy * 0.01);
	ui.m_pPricenwSpin->setValue(product.price_nw * 0.01);
	ui.m_pPricewwSpin->setValue(product.price_ww * 0.01);
	ui.m_pFeeOtherSpin->setValue(product.fee_other * 0.01);
}

void ProductDlg::accept()
{
	m_product.name = ui.m_pNameBox->currentText();
	m_product.type = ui.m_pTypeBox->currentText();
	// ----产商ID---未作验证
	m_product.MF_id = 0;
	m_product.count = ui.m_pCountSpin->value();
	m_product.date = ui.m_pDateEdit->date().toString("yyyy-MM-dd");
	m_product.price_buy = ui.m_pPricebuySpin->value() * 100;
	m_product.price_nw = ui.m_pPricenwSpin->value() * 100;
	m_product.price_ww = ui.m_pPricewwSpin->value() * 100;
	m_product.fee_other = ui.m_pFeeOtherSpin->value() * 100;
	QDialog::accept();
}