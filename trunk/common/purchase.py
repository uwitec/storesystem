# -*- coding:GBK -*-

class Purchase(object):
    '''������'''
    
    def __init__(self):
        self.id = None          # ����id
        self.product_id = None  # ��Ʒ
        self.count = 0          # ��Ʒ����
        self.date = 0           # ��������
        self.MF_id = None       # ����
        self.price_pc = 0       # ������
        self.price_pay = 0      # ʵ��
        self.fee_other = 0      # ��������