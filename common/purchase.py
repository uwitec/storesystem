# -*- coding:GBK -*-

class Purchase(object):
    '''������'''
    
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
            self.id = None          # ����id
            self.product_id = None  # ��Ʒ
            self.count = 0          # ��Ʒ����
            self.date = 0           # ��������
            self.MF_id = None       # ����
            self.price_pc = 0       # ������
            self.price_pay = 0      # ʵ��
            self.fee_other = 0      # ��������
    
    def __repr__(self, *args, **kwargs):
        text = "Purchase["
        text += "id:%s product_id:%s count:%s " % (self.id,
                        self.product_id, self.count)
        text += "MF_id:%s price_pc:%s price_pay:%s " % (self.MF_id,
                        self.price_pc, self.price_pay)
        text += "fee_other:%s]" % self.fee_other