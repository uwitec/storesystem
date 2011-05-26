# -*- coding:GBK -*-

class User(object):
    '''用户'''
    
    def __init__(self):
        self.name = ""      # 用户名
        self.password = ""  # 密码
        self.author = 1     # 权限，0为最高