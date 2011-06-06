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
	QString name;		// 名称
	QString type;		// 类型
	uint32 MF_id;		// 产商id
	uint32 count;		// 产品数量
	QString date;		// 进货日期
	uint32 price_buy;	// 购买价格
	uint32 price_nw;	// 内围价
	uint32 price_ww;	// 外围价
	uint32 fee_other;	// 其它费用
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

// 商家
struct Factory
{
	uint32 id;			// 
	QString name;		// 商家名
	QString contact;	// 联系人
	QString post;		// 职位
	QString phone;		// 联系电话
	QString zip_code;	// 邮编
	QString addr;		// 地址
	QString email;		// 邮箱
	QString card_type;	// 银行卡类型
	QString card_num;	// 银行卡卡号
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

// 进货单条记录
struct PurchaseS
{
	uint32 id;			// 货单ID
	uint32 product_id;	// 产品ID
	uint32 count;		// 进货产品数量
	uint32 batch;		// 批次
	uint32 price_pay;	// 实付
	uint32 fee_other;	// 其它费用
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

// 进货记录集合
struct PurchaseC
{
	uint32 id;			// 货单id，同一个批次的PurchaseS为一个PurchaseC
	QString date;		// 进货日期
	uint32 factory_id;	// 进货商家
	QString memo;		// 备注
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

// 销售单条记录
struct SaleS
{
	uint32 id;			// 售单ID
	uint32 product_id;	// 销售的产品ID
	uint32 count;		// 销售数量
	uint32 batch;		// 销售批次，对应于SaleC中的ID
	uint price_pay;		// 实付
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

// 销售记录集合
struct SaleC
{
	uint32 id;		// 售单id
	QString memo;	// 备注：零售/批发
	QString seller;	// 经手人，对应于user
	QString date;	// 销售日期
	QString addr;	// 销售地址
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

// 退货单条记录
struct ReturnS
{
	uint32 id;			// 退货单id
	uint32 product_id;	// 产品ID
	uint32 count;		// 退货产品数量
	uint32 batch;		// 退货批次，对应于ReturnC中的id
	uint32 price_ret;	// 退货总价格
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


// 退货记录集合
struct ReturnC
{
	uint32 id;		// 退货记录集合ID
	QString date;	// 退货日期
	QString memo;	// 备注
	void copy(const ReturnC& ret)
	{
		id = ret.id;
		date = ret.date;
		memo = ret.memo;
	}
};
typedef ReturnC* ReturnCPtr;
typedef std::vector<ReturnCPtr> ReturnCPtrList;