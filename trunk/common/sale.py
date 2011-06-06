# -*- coding:GBK -*-

class SaleS(object):
    '''���۵�����¼'''
    def __init__(self, recordRow=None):
        if recordRow:
            self.id = recordRow["id"]
            self.product_id = recordRow["product_id"]
            self.count = recordRow["count"]
            self.batch = recordRow["batch"]
            self.price_pay = recordRow["price_pay"]
        else:
            self.id = None          # �۵�id
            self.product_id = None  # ��Ʒid
            self.count = 0          # ��Ʒ����
            self.batch = 0          # �������Σ���ͬ��SaleC�е�id
            self.price_pay = 0      # ʵ��
    
    def __repr__(self):
        text = "SaleS["
        text += "id:%s product_id:%s count:%s " % (self.id,
                    self.product_id, self.count)
        text += "batch:%s price_pay:%s]" % (self.batch,
                    self.price_pay)
        return text

class SaleC(object):
    '''���ۼ�¼����'''
    def __init__(self, recordRow=None):
        if recordRow:
            self.id = recordRow["id"]
            self.memo = recordRow["memo"].encode('gbk')
            self.seller = recordRow['seller'].encode('gbk')
            self.date = recordRow["date"].encode("gbk")
            self.addr = recordRow['addr'].encode('gbk')
        else:
            self.id = None       # �۵�id����ͬ��SaleS�е�����
            self.memo = ""       # ��ע������/����
            self.seller = ""     # �����ˣ���Ӧ��user
            self.date = ""
            self.addr = ""       # ���۵�ַ
    
    def __repr__(self):
        text = "SaleS["
        text += "id:%s memo:%s " % (self.id,
                    self.memo)
        text += "seller:%s addr:%s]" % (self.seller,
                    self.addr)
        return text