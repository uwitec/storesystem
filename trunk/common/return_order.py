# -*- coding:GBK -*-

class ReturnOrder(object):
    '''�˻���'''
    
    def __init__(self, recordRow=None):
        self.id = None          # ����id
        self.product_id = None  # ��Ʒ
        self.count = 0          # ��Ʒ����
        self.date = ""          # ��������
        self.price_ret = 0      # �˻��۸�
        