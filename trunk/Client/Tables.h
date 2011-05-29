#pragma once
#include "StdAfx.h"
#include "TypeDefine.h"
#include <QString>
#include <list>
#include <vector>
struct User
{
	QString name;
	QString password;
	int32 authority;
};
typedef std::list<User> UserList;
/*
self.id = None
self.name = ""      # ����
self.type = 0       # ����
self.MF_id = None   # ����id
self.count = 0      # ��Ʒ����
self.date = ""      # ��������
self.price_buy = 0  # ����۸�
self.price_nw = 0   # ��Χ��
self.price_ww = 0   # ��Χ��
self.fee_other = 0  # ��������
*/

struct Product
{
	int32 id;		
	QString name;	// ����
	QString type;	// ����
	int32 MF_id;	// ����id
	uint32 count;	// ��Ʒ����
	QString date;	// ��������
	uint32 price_buy;//����۸�
	uint32 price_nw;// ��Χ��
	uint32 price_ww;// ��Χ��
	uint32 fee_other;//��������
};
typedef std::vector<Product*> ProductPtrList;