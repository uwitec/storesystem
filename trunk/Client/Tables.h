#pragma once
#include "StdAfx.h"
#include "TypeDefine.h"
#include <QString>
#include <list>
#include <map>
#include <vector>
struct User
{
	uint32 id;
	QString name;
	QString password;
	int32 authority;
};
typedef std::list<User> UserList;


struct Product
{
	uint32 id;		
	QString name;		// ����
	QString type;		// ����
	uint32 MF_id;		// ����id
	uint32 count;		// ��Ʒ����
	QString date;		// ��������
	uint32 price_buy;	// ����۸�
	uint32 price_nw;	// ��Χ��
	uint32 price_ww;	// ��Χ��
	uint32 fee_other;	// ��������
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

// �̼�
struct Factory
{
	uint32 id;			// 
	QString name;		// �̼���
	QString contact;	// ��ϵ��
	QString post;		// ְλ
	QString phone;		// ��ϵ�绰
	QString zip_code;	// �ʱ�
	QString addr;		// ��ַ
	QString email;		// ����
	QString card_type;	// ���п�����
	QString card_num;	// ���п�����
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

// ����������¼
struct PurchaseS
{
	uint32 id;			// ����ID
	uint32 product_id;	// ��ƷID
	uint32 count;		// ������Ʒ����
	uint32 batch;		// ����
	uint32 price_pay;	// ʵ��
	uint32 fee_other;	// ��������
	void copy(const PurchaseS& pur)
	{
		id = pur.id;
		product_id = pur.product_id;
		count = pur.count;
		batch = pur.batch;
		price_pay = pur.price_pay;
		fee_other = pur.fee_other;
	}
};
typedef PurchaseS* PurchaseSPtr;
typedef std::vector<PurchaseSPtr> PurchaseSPtrList;
typedef std::map<uint32, PurchaseSPtrList> PurchaseSPtrListDict;

// ������¼����
struct PurchaseC
{
	uint32 id;			// ����id��ͬһ�����ε�PurchaseSΪһ��PurchaseC
	QString date;		// ��������
	uint32 factory_id;	// �����̼�
	QString memo;		// ��ע
	void copy(const PurchaseC& purC)
	{
		id = purC.id;
		date = purC.date;
		factory_id = purC.factory_id;
		memo = purC.memo;
	}
};
typedef PurchaseC* PurchaseCPtr;
typedef std::vector<PurchaseCPtr> PurchaseCPtrList;

// ���۵�����¼
struct SaleS
{
	uint32 id;			// �۵�ID
	uint32 product_id;	// ���۵Ĳ�ƷID
	uint32 count;		// ��������
	uint32 batch;		// �������Σ���Ӧ��SaleC�е�ID
	uint price_pay;		// ʵ��
	void copy(const SaleS& saleS)
	{
		id = saleS.id;
		product_id = saleS.product_id;
		count = saleS.count;
		batch = saleS.batch;
		price_pay = saleS.price_pay;
	}
};
typedef SaleS* SaleSPtr;
typedef std::vector<SaleSPtr> SaleSPtrList;
typedef std::map<uint32, SaleSPtrList> SaleSPtrListDict;

// ���ۼ�¼����
struct SaleC
{
	uint32 id;		// �۵�id
	QString memo;	// ��ע������/����
	QString seller;	// �����ˣ���Ӧ��user
	QString date;	// ��������
	QString addr;	// ���۵�ַ
	void copy(const SaleC& saleC)
	{
		id = saleC.id;
		memo = saleC.memo;
		seller = saleC.seller;
		date = saleC.date;
		addr = saleC.addr;
	}
};
typedef SaleC* SaleCPtr;
typedef std::vector<SaleCPtr> SaleCPtrList;

// �˻�������¼
struct ReturnS
{
	uint32 id;			// �˻���id
	uint32 product_id;	// ��ƷID
	uint32 count;		// �˻���Ʒ����
	uint32 batch;		// �˻����Σ���Ӧ��ReturnC�е�id
	uint32 price_ret;	// �˻��ܼ۸�
	void copy(const ReturnS& ret)
	{
		id = ret.id;
		product_id = ret.product_id;
		count = ret.count;
		batch = ret.batch;
		price_ret = ret.price_ret;
	}
};
typedef ReturnS* ReturnSPtr;
typedef std::vector<ReturnSPtr> ReturnSPtrList;
typedef std::map<uint32, ReturnSPtrList> ReturnSPtrListDict;


// �˻���¼����
struct ReturnC
{
	uint32 id;		// �˻���¼����ID
	QString date;	// �˻�����
	QString memo;	// ��ע
	void copy(const ReturnC& ret)
	{
		id = ret.id;
		date = ret.date;
		memo = ret.memo;
	}
};
typedef ReturnC* ReturnCPtr;
typedef std::vector<ReturnCPtr> ReturnCPtrList;