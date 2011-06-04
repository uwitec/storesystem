# -*- coding:GBK -*-

class User(object):
    '''�û�'''
    
    def __init__(self, recordRow=None):
        if recordRow:
            self.name = recordRow["name"]
            self.password = recordRow["password"]
            self.author = recordRow["author"]
        else:
            self.name = ""      # �û���
            self.password = ""  # ����
            self.author = 1     # Ȩ�ޣ�0Ϊ���

    def __repr__(self):
        text = "User["
        text += "name:%s password:%s author:%d]" % (self.name,
                        self.password, self.author)
        return text