# -*- coding:GBK -*-

class SaleS(object):
    '''销售单条记录'''
    def __init__(self, recordRow=None):
        if recordRow:
            self.id = recordRow["id"]
            self.product_id = recordRow["product_id"]
            self.count = recordRow["count"]
            self.batch = recordRow["batch"]
            self.price_pay = recordRow["price_pay"]
        else:
            self.id = None          # 售单id
            self.product_id = None  # 产品id
            self.count = 0          # 产品数量
            self.batch = 0          # 销售批次，等同于SaleC中的id
            self.price_pay = 0      # 实付
    
    def __repr__(self):
        text = "SaleS["
        text += "id:%s product_id:%s count:%s " % (self.id,
                    self.product_id, self.count)
        text += "batch:%s price_pay:%s]" % (self.batch,
                    self.price_pay)
        return text

class SaleC(object):
    '''销售记录集合'''
    def __init__(self, recordRow=None):
        if recordRow:
            self.id = recordRow["id"]
            self.memo = recordRow["memo"].encode('gbk')
            self.seller = recordRow['seller'].encode('gbk')
            self.date = recordRow["date"].encode("gbk")
            self.addr = recordRow['addr'].encode('gbk')
        else:
            self.id = None       # 售单id，等同于SaleS中的批次
            self.memo = ""       # 备注：零售/批发
            self.seller = ""     # 经手人，对应于user
            self.date = ""
            self.addr = ""       # 销售地址
    
    def __repr__(self):
        text = "SaleS["
        text += "id:%s memo:%s " % (self.id,
                    self.memo)
        text += "seller:%s addr:%s]" % (self.seller,
                    self.addr)
        return text