# -*- coding:GBK -*-

class ReturnS(object):
    '''退货单条记录'''
    
    def __init__(self, recordRow=None):
        if recordRow:
            self.id = recordRow["id"]
            self.product_id = recordRow["product_id"]
            self.count = recordRow["count"]
            self.batch = recordRow["batch"]
            self.price_ret = recordRow["price_ret"]
        else:
            self.id = None          # 退货单id
            self.product_id = None  # 产品
            self.count = 0          # 产品数量
            self.batch = None       # 退货批次
            self.price_ret = 0      # 退货总价格
    
    def __repr__(self):
        text = "ReturnS["
        text += "id:%s product_id:%s count:%s " % (self.id,
                    self.product_id, self.count)
        text += "batch:%s price_ret:%s]" % (self.batch,
                    self.price_ret)
        return text

class ReturnC(object):
    '''退货记录集合'''
    
    def __init__(self, recordRow=None):
        if recordRow:
            self.id = recordRow["id"]
            self.date = recordRow["date"]            
            self.memo = recordRow["memo"].encode("gbk")
        else:
            self.id = None      # 退货单id，对应于ReturnS中的批次
            self.date = 0       # 退货日期
            self.memo = ""      # 备注
    
    def __repr__(self):
        text = "ReturnS["
        text += "id:%s date:%s memo:%s]" % (self.id,
                    self.date, self.memo)
        return text
    

