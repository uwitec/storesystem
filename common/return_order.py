# -*- coding:GBK -*-

class ReturnOrder(object):
    '''退货单'''
    
    def __init__(self, recordRow=None):
        self.id = None          # 货单id
        self.product_id = None  # 产品
        self.count = 0          # 产品数量
        self.date = ""          # 进货日期
        self.price_ret = 0      # 退货价格
        