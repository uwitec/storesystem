# -*- coding:GBK -*-

class User(object):
    '''用户'''
    
    def __init__(self, recordRow=None):
        if recordRow:
            self.name = recordRow["name"]
            self.password = recordRow["password"]
            self.author = recordRow["author"]
        else:
            self.name = ""      # 用户名
            self.password = ""  # 密码
            self.author = 1     # 权限，0为最高

    def __repr__(self):
        text = "User["
        text += "name:%s password:%s author:%d]" % (self.name,
                        self.password, self.author)
        return text