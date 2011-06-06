#include "StdAfx.h"
#include "FactoryDlg.h"
#include "Gui.h"
FactoryDlg::FactoryDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect( ui.m_pAcceptBtn, SIGNAL(clicked()),
			 this, SLOT(accept()) );	
}

FactoryDlg::~FactoryDlg()
{

}

void FactoryDlg::setFactory(const Factory& factory)
{
	m_factory.id = factory.id;
	ui.m_pNameBox->setEditText(factory.name);
	ui.m_pContactBox->setEditText(factory.contact);
	ui.m_pPostBox->setEditText(factory.post);
	ui.m_pPhoneBox->setEditText(factory.phone);
	ui.m_pZipCodeBox->setEditText(factory.zip_code);
	ui.m_pAddrBox->setEditText(factory.addr);
	ui.m_pEmailBox->setEditText(factory.email);
	ui.m_pCardTypeBox->setEditText(factory.card_type);
	ui.m_pCardNumBox->setEditText(factory.card_num);
}

void FactoryDlg::setCompleterModel(QStandardItemModel* pFactoryModel)
{
	setComboBoxCompleterModel(ui.m_pNameBox, pFactoryModel, 1);
	setComboBoxCompleterModel(ui.m_pContactBox, pFactoryModel, 2);
	setComboBoxCompleterModel(ui.m_pPostBox, pFactoryModel, 3);
	setComboBoxCompleterModel(ui.m_pPhoneBox, pFactoryModel, 4);
	setComboBoxCompleterModel(ui.m_pZipCodeBox, pFactoryModel, 5);
	setComboBoxCompleterModel(ui.m_pAddrBox, pFactoryModel, 6);
	setComboBoxCompleterModel(ui.m_pEmailBox, pFactoryModel, 7);
	setComboBoxCompleterModel(ui.m_pCardTypeBox, pFactoryModel, 8);
	setComboBoxCompleterModel(ui.m_pCardNumBox, pFactoryModel, 9);
}

void FactoryDlg::accept()
{
	m_factory.name = ui.m_pNameBox->currentText();
	m_factory.contact = ui.m_pContactBox->currentText();
	m_factory.post = ui.m_pPostBox->currentText();
	m_factory.phone = ui.m_pPhoneBox->currentText();
	m_factory.zip_code = ui.m_pZipCodeBox->currentText();
	m_factory.addr = ui.m_pAddrBox->currentText();
	m_factory.email = ui.m_pEmailBox->currentText();
	m_factory.card_type = ui.m_pCardTypeBox->currentText();
	m_factory.card_num = ui.m_pCardNumBox->currentText();
	QDialog::accept();
}