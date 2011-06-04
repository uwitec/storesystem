# -*- coding:GBK -*-

class Purchase(object):
    '''������'''
    Type_Retail = 0     # ����
    Type_WholeSale = 1  # ����
    def __init__(self, recordRow=None):
        if recordRow:
            self.id = recordRow["id"]
            self.type = recordRow["type"]
            self.date = recordRow["date"]
            self.product_id = recordRow["product_id"]
            self.count = recordRow["count"]
            self.price_sell = recordRow["price_sell"]
            self.price_pay = recordRow["price_pay"]
            self.seller = recordRow["seller"]
            self.sale_addr = recordRow["sale_addr"]
            self.buyer_name = recordRow["buyer_name"]
            self.buyer_tel = recordRow["buyer_tel"]
        else:
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