# -*- coding:GBK -*-

class Purchase(object):
    '''进货单'''
    
    def __init__(self):
        self.id = None          # 货单id
        self.product_id = None  # 产品
        self.count = 0          # 产品数量
        self.date = 0           # 进货日期
        self.MF_id = None       # 厂商
        self.price_pc = 0       # 进货价
        self.price_pay = 0      # 实付
        self.fee_other = 0      # 其它费用