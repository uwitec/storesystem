#include "StdAfx.h"
#include "Gui.h"
void setComboBoxCompleterModel(QComboBox* pBox, 
		QStandardItemModel* model, int32 column)
{
	QCompleter* pCompleter = new QCompleter(model, pBox);
	pCompleter->setCompletionColumn(column);
	pBox->setCompleter(pCompleter);
	pBox->setModel(model);
	pBox->setModelColumn(column);
}

void setComboBoxCompleterModel(QComboBox* pBox, QStandardItemModel* model,
							   QCompleter* pCompleter, int32 column)
{
	pBox->setCompleter(pCompleter);
	pBox->setModel(model);
	pBox->setModelColumn(column);
}

void setFactoryBoxID(QComboBox* pBox, uint32 MF_id)
{
	QStandardItemModel* pFactoryModel 
		= static_cast<QStandardItemModel*>(pBox->model());
	int32 rowCount = pFactoryModel->rowCount();
	for( int32 row = 0; row < rowCount; ++row )
	{
		QModelIndex id_index = pFactoryModel->index(row, 0);
		if( MF_id == pFactoryModel->data(id_index).toUInt() )
		{
			pBox->setCurrentIndex(row);
			break;
		}
	}
}

uint32 getFactoryBoxID(QComboBox* pBox, int32 index)
{	
	QStandardItemModel* pFactoryModel =
		static_cast<QStandardItemModel*>(pBox->model());
	QModelIndex id_index = pFactoryModel->index(index, 0);
	return pFactoryModel->data(id_index).toUInt();
}

void setProductBoxID(QComboBox* pBox, uint32 product_id)
{
	QStandardItemModel* pProductModel 
		= static_cast<QStandardItemModel*>(pBox->model());
	int32 rowCount = pProductModel->rowCount();
	for( int32 row = 0; row < rowCount; ++row )
	{
		QModelIndex id_index = pProductModel->index(row, 0);
		if( product_id == pProductModel->data(id_index).toUInt() )
		{
			pBox->setCurrentIndex(row);
			break;
		}
	}
}

uint32 getProductBoxID(QComboBox* pBox, int32 index)
{
	QStandardItemModel* pProductModel =
		static_cast<QStandardItemModel*>(pBox->model());
	QModelIndex id_index = pProductModel->index(index, 0);
	return pProductModel->data(id_index).toUInt();
}