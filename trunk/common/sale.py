# -*- coding:GBK -*-

class Purchase(object):
    '''进货单'''
    Type_Retail = 0     # 零售
    Type_WholeSale = 1  # 批发
    def __init__(self):
        self.id = None          # 货单id
        self.type = Purchase.Type_Retail  
        self.date = 0           # 进货日期
        self.product_id = None  # 产品id
        self.count = 0          # 产品数量        
        self.price_sell = 0     # 销售价
        self.price_pay = 0      # 实付
        self.seller = ""        # 经手人
        self.sale_addr = ""     # 地点
        self.buyer_name = ""    # 买家名字
        self.buyer_tel = ""     # 买家电话