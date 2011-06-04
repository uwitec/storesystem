#pragma once
#include "StdAfx.h"
#include "TypeDefine.h"
#include <QString>
#include <list>
#include <vector>
struct User
{
	int32 id;
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
	void copy(const Product& product)
	{
		name = product.name;
		type = product.type;
		MF_id = product.MF_id;
		count = product.count;
		date = product.date;
		price_buy = product.price_buy;
		price_nw = product.price_nw;
		price_ww = product.price_ww;
		fee_other = product.fee_other;
	}
};
typedef Product* ProductPtr;
typedef std::vector<ProductPtr> ProductPtrList;
/*
self.id = None
self.name = ""      # ����
self.contact = ""   # ��ϵ��
self.post = ""      # ְλ
self.phone = ""     # ��ϵ�绰
self.zip_code = ""  # �ʱ�
self.addr = ""      # ��ַ
self.email = ""     # ����
self.card_type = "" # ���п�����
self.card_num = ""  # ���п���
*/
struct Factory
{
	int32 id;
	QString name;
	QString contact;
	QString post;
	QString phone;
	QString zip_code;
	QString addr;
	QString email;
	QString card_type;
	QString card_num;
	void copy(const Factory& factory)
	{
		name = factory.name;
		contact = factory.contact;
		post = factory.post;
		phone = factory.phone;
		zip_code = factory.zip_code;
		addr = factory.addr;
		email = factory.email;
		card_type = factory.card_type;
		card_num = factory.card_num;
	}
};
typedef Factory* FactoryPtr;
typedef std::vector<FactoryPtr> FactoryPtrList;