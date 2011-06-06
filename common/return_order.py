# -*- coding:GBK -*-

class ReturnS(object):
    '''�˻�������¼'''
    
    def __init__(self, recordRow=None):
        if recordRow:
            self.id = recordRow["id"]
            self.product_id = recordRow["product_id"]
            self.count = recordRow["count"]
            self.batch = recordRow["batch"]
            self.price_ret = recordRow["price_ret"]
        else:
            self.id = None          # �˻���id
            self.product_id = None  # ��Ʒ
            self.count = 0          # ��Ʒ����
            self.batch = None       # �˻�����
            self.price_ret = 0      # �˻��ܼ۸�
    
    def __repr__(self):
        text = "ReturnS["
        text += "id:%s product_id:%s count:%s " % (self.id,
                    self.product_id, self.count)
        text += "batch:%s price_ret:%s]" % (self.batch,
                    self.price_ret)
        return text

class ReturnC(object):
    '''�˻���¼����'''
    
    def __init__(self, recordRow=None):
        if recordRow:
            self.id = recordRow["id"]
            self.date = recordRow["date"]            
            self.memo = recordRow["memo"].encode("gbk")
        else:
            self.id = None      # �˻���id����Ӧ��ReturnS�е�����
            self.date = 0       # �˻�����
            self.memo = ""      # ��ע
    
    def __repr__(self):
        text = "ReturnS["
        text += "id:%s date:%s memo:%s]" % (self.id,
                    self.date, self.memo)
        return text
    

