#include "StdAfx.h"
#include "ProductInsertDlg.h"

ProductInsertDlg::ProductInsertDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect( ui.m_pAcceptBtn, SIGNAL(clicked()),
			 this, SLOT(accept()) );
}

ProductInsertDlg::~ProductInsertDlg()
{

}

void ProductInsertDlg::accept()
{
	m_product.name = ui.m_pNameBox->currentText();
	m_product.type = ui.m_pTypeBox->currentText();
	// ----产商ID---未作验证
	m_product.MF_id = 0;
	m_product.count = ui.m_pCountSpin->value();
	m_product.date = ui.m_pDateEdit->text();
	m_product.price_buy = ui.m_pPricebuySpin->value() * 100;
	m_product.price_nw = ui.m_pPricenwSpin->value() * 100;
	m_product.price_ww = ui.m_pPricewwSpin->value() * 100;
	m_product.fee_other = ui.m_pFeeOtherSpin->value() * 100;
	QDialog::accept();
}