# -*- coding:GBK -*-

class Purchase(object):
    '''������'''
    Type_Retail = 0     # ����
    Type_WholeSale = 1  # ����
    def __init__(self):
        self.id = None          # ����id
        self.type = Purchase.Type_Retail  
        self.date = 0           # ��������
        self.product_id = None  # ��Ʒid
        self.count = 0          # ��Ʒ����        
        self.price_sell = 0     # ���ۼ�
        self.price_pay = 0      # ʵ��
        self.seller = ""        # ������
        self.sale_addr = ""     # �ص�
        self.buyer_name = ""    # �������
        self.buyer_tel = ""     # ��ҵ绰