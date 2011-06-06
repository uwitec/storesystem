#pragma once
#include "StdAfx.h"
#include <QComboBox>
#include <QStandardItemModel>
#include "TypeDefine.h"
void setComboBoxCompleterModel(QComboBox* pBox, QStandardItemModel* model,
							   int32 column);
void setComboBoxCompleterModel(QComboBox* pBox, QStandardItemModel* model,
							   QCompleter* pCompleter, int32 column);
void setFactoryBoxID(QComboBox* pBox, uint32 MF_id);
uint32 getFactoryBoxID(QComboBox* pBox, int32 index);
void setProductBoxID(QComboBox* pBox, uint32 product_id);
uint32 getProductBoxID(QComboBox* pBox, int32 index);