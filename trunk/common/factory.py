# -*- coding:GBK -*-

class Factory(object):
    
    def __init__(self, recordRow=None):
        if recordRow:
            self.id = recordRow["id"]
            self.name = recordRow["name"].encode('gbk')
            self.contact = recordRow["contact"].encode('gbk')
            self.post = recordRow["post"].encode('gbk')
            self.phone = recordRow["phone"].encode('gbk')
            self.zip_code = recordRow["zip_code"].encode('gbk')
            self.addr = recordRow["addr"].encode('gbk')
            self.email = recordRow["email"].encode('gbk')
            self.card_type = recordRow["card_type"].encode('gbk')
            self.card_num = recordRow["card_num"].encode('gbk')
        else:
            self.id = None
            self.name = ""      # 厂名
            self.contact = ""   # 联系人
            self.post = ""      # 职位
            self.phone = ""     # 联系电话
            self.zip_code = ""  # 邮编
            self.addr = ""      # 地址
            self.email = ""     # 邮箱
            self.card_type = "" # 银行卡类型
            self.card_num = ""  # 银行卡号
    
    def __repr__(self):
        text = "Factory["
        text += "id:%s name:%s contact:%s post:%s " % (self.id,
                        self.name, self.contact, self.post)
        text += "phone:%s zip_code:%s addr:%s email:%s " % (self.phone,
                        self.zip_code, self.addr, self.email)
        text += "card_type:%s card_num:%s]" % (self.card_type, self.card_num)
        return text