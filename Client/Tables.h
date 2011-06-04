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
self.name = ""      # 名称
self.type = 0       # 类型
self.MF_id = None   # 产商id
self.count = 0      # 产品数量
self.date = ""      # 进货日期
self.price_buy = 0  # 购买价格
self.price_nw = 0   # 内围价
self.price_ww = 0   # 外围价
self.fee_other = 0  # 其它费用
*/

struct Product
{
	int32 id;		
	QString name;	// 名称
	QString type;	// 类型
	int32 MF_id;	// 产商id
	uint32 count;	// 产品数量
	QString date;	// 进货日期
	uint32 price_buy;//购买价格
	uint32 price_nw;// 内围价
	uint32 price_ww;// 外围价
	uint32 fee_other;//其它费用
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
self.name = ""      # 厂名
self.contact = ""   # 联系人
self.post = ""      # 职位
self.phone = ""     # 联系电话
self.zip_code = ""  # 邮编
self.addr = ""      # 地址
self.email = ""     # 邮箱
self.card_type = "" # 银行卡类型
self.card_num = ""  # 银行卡号
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