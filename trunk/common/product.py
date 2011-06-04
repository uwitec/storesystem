# -*- coding:GBK -*-

class Product(object):
    '''��Ʒ��'''
    def __init__(self, recordRow=None):
        if recordRow:
            self.id = recordRow["id"]
            self.id = recordRow["id"]
            self.name = recordRow["name"].encode('gbk')
            self.type = recordRow["type"].encode('gbk')
            self.MF_id = recordRow["MF_id"]
            self.count = recordRow["count"]
            self.date = recordRow["date"].encode('gbk')
            self.price_buy = recordRow["price_buy"]
            self.price_nw = recordRow["price_nw"]
            self.price_ww = recordRow["price_ww"]
            self.fee_other = recordRow["fee_other"]
        else:
            self.id = None
            self.name = ""      # ����
            self.type = 0       # ����
            self.MF_id = None   # ����id
            self.count = 0      # ��Ʒ����
            self.date = ""      # ��������
            self.price_buy = 0  # ����۸� 
            self.price_nw = 0   # ��Χ��
            self.price_ww = 0   # ��Χ��
            self.fee_other = 0  # ��������
    
    def __repr__(self):
        text = "Product["
        text += "id:%s name:%s type:%s MF_id:%s " % (self.id,
                        self.name, self.type, self.MF_id)
        text += "count:%s date:%s price_buy:%s " % (self.count,
                        self.date, self.price_buy)
        text += "price_nw:%s price_ww:%s fee_other:%s]" % (self.price_nw,
                        self.price_ww, self.fee_other)
        return text