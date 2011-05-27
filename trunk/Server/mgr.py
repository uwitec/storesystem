# -*- coding:GBK -*-

from product import *
from purchase import *
from return_order import *
from sale import *
from user import *
import db_global
class UserManager(object):
    '''用户管理类'''
    
    def __init__(self, db):
        # db[DataBase(object)], DataBase实例
        self.db = db
        self.cursor = db.get_cursor()
    
    def build_command(self, cmd_obj):
        if cmd_obj.type == db_global.Cmd_Login:
            build_login_command(cmd_obj)
    
    def build_login_command(self, cmd_obj):
        command = """
            select * from user where
            name=? and password=?
        """
        user = cmd_obj.cmd_object
        self.cursor.execute(command, (user.name, user.password))