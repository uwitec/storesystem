# -*- coding:GBK -*-

class PurchaseS(object):
    ''' 进货单条记录'''
    
    def __init__(self, recordRow=None):
        if recordRow:
            self.id = recordRow["id"]
            self.product_id = recordRow["product_id"]
            self.count = recordRow["count"]
            self.batch = recordRow["batch"]
            self.price_pay = recordRow["price_pay"]
            self.fee_other = recordRow["fee_other"]
        else:
            self.id = None          # 货单id
            self.product_id = None  # 进货产品id
            self.count = 0          # 进货产品数量
            self.batch = 0          # 进货批次，等同于PurchaseC中的id
            self.price_pay = 0      # 实付
            self.fee_other = 0      # 其它费用
    
    def __repr__(self, *args, **kwargs):
        text = "PurchaseS["
        text += "id:%s product_id:%s count:%s " % (self.id,
                        self.product_id, self.count)
        text += "batch:%s price_pay:%s fee_other:%s]" % (self.batch,
                        self.price_pay, self.fee_other)
        return text


class PurchaseC(object):
    ''' 进货记录集合'''
    
    def __init__(self, recordRow=None):
        if recordRow:
            self.id = recordRow["id"]
            self.date = recordRow["date"]
            self.factory_id = recordRow["factory_id"]
            self.memo = recordRow["memo"].encode("gbk")
        else:
            self.id = None      # 货单id，等同于PurchaseS中的batch
            self.date = 0       # 进货日期
            self.factory_id = None  # 进货商家
            self.memeo = ""     # 备注
    
    def __repr__(self, *args, **kwargs):
        text = "PurchaseC["
        text += "id:%s date:%s " % (self.id,
                        self.date)
        text += "factory_id:%s memo:%s]" % (self.factory_id,
                        self.memo)
        return text