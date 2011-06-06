# -*- coding:GBK -*-

class PurchaseS(object):
    ''' ����������¼'''
    
    def __init__(self, recordRow=None):
        if recordRow:
            self.id = recordRow["id"]
            self.product_id = recordRow["product_id"]
            self.count = recordRow["count"]
            self.batch = recordRow["batch"]
            self.price_pay = recordRow["price_pay"]
            self.fee_other = recordRow["fee_other"]
        else:
            self.id = None          # ����id
            self.product_id = None  # ������Ʒid
            self.count = 0          # ������Ʒ����
            self.batch = 0          # �������Σ���ͬ��PurchaseC�е�id
            self.price_pay = 0      # ʵ��
            self.fee_other = 0      # ��������
    
    def __repr__(self, *args, **kwargs):
        text = "PurchaseS["
        text += "id:%s product_id:%s count:%s " % (self.id,
                        self.product_id, self.count)
        text += "batch:%s price_pay:%s fee_other:%s]" % (self.batch,
                        self.price_pay, self.fee_other)
        return text


class PurchaseC(object):
    ''' ������¼����'''
    
    def __init__(self, recordRow=None):
        if recordRow:
            self.id = recordRow["id"]
            self.date = recordRow["date"]
            self.factory_id = recordRow["factory_id"]
            self.memo = recordRow["memo"].encode("gbk")
        else:
            self.id = None      # ����id����ͬ��PurchaseS�е�batch
            self.date = 0       # ��������
            self.factory_id = None  # �����̼�
            self.memeo = ""     # ��ע
    
    def __repr__(self, *args, **kwargs):
        text = "PurchaseC["
        text += "id:%s date:%s " % (self.id,
                        self.date)
        text += "factory_id:%s memo:%s]" % (self.factory_id,
                        self.memo)
        return text