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
};
typedef std::vector<Product*> ProductPtrList;