# -*- coding:GBK -*-

class Purchase(object):
    '''进货单'''
    
    def __init__(self, recordRow=None):
        if recordRow:
            self.id = recordRow["id"]
            self.product_id = recordRow["recordRow"]
            self.count = recordRow["count"]
            self.date = recordRow["date"]
            self.MF_id = recordRow["MF_id"]
            self.price_pc = recordRow["price_pc"]
            self.price_pay = recordRow["price_pay"]
            self.fee_other = recordRow["fee_other"]
        else:
            self.id = None          # 货单id
            self.product_id = None  # 产品
            self.count = 0          # 产品数量
            self.date = 0           # 进货日期
            self.MF_id = None       # 厂商
            self.price_pc = 0       # 进货价
            self.price_pay = 0      # 实付
            self.fee_other = 0      # 其它费用
    
    def __repr__(self, *args, **kwargs):
        text = "Purchase["
        text += "id:%s product_id:%s count:%s " % (self.id,
                        self.product_id, self.count)
        text += "MF_id:%s price_pc:%s price_pay:%s " % (self.MF_id,
                        self.price_pc, self.price_pay)
        text += "fee_other:%s]" % self.fee_other