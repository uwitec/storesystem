# -*- coding:GBK -*-

from common.product import *
from common.purchase import *
from common.return_order import *
from common.sale import *
from common.user import *
import common.db_global as db_global
import common.cmd as cmd
from cmd import Cmd

def create_cmd_data(cmd_obj):
    cmd_data = cmd.CmdData()
    cmd_data.cmd_type = cmd_obj.cmd_type
    cmd_data.cmd_table = cmd_obj.cmd_table
    return cmd_data

class DataBaseManager(object):
    '''数据库管理类'''
    
    def __init__(self, db):
        # db[DataBase(object)], DataBase实例
        self.db = db
        self.cursor = db.get_cursor()
    
    def execute_command(self, cmd_obj):
        if cmd_obj.cmd_type == db_global.Cmd_Login:
            return self.execute_login_command(cmd_obj)
        elif cmd_obj.cmd_type == db_global.Cmd_Select:
            return self.execute_select_command(cmd_obj)
        elif cmd_obj.cmd_type == db_global.Cmd_Update:
            return self.execute_update_comand(cmd_obj)
        elif cmd_obj.cmd_type == db_global.Cmd_Insert:
            return self.execute_insert_command(cmd_obj)

class UserManager(DataBaseManager):
    '''用户管理类'''
    
    def __init__(self, db):
        super(UserManager, self).__init__(db)
    
    def execute_login_command(self, cmd_obj):
        self.cursor.execute(cmd_obj.cmd_command)
        cmd_data = create_cmd_data(cmd_obj)
        cmd_data.cmd_result = False, None
        one = self.cursor.fetchone()
        if one:
            cmd_data.cmd_result = True, one["author"]
        return cmd_data
    
    def execute_select_command(self, cmd_obj):
        self.cursor.execute(cmd_obj.cmd_command)
        cmd_data = create_cmd_data(cmd_obj)
        cmd_data.cmd_result = []
        for row in self.cursor:
            user = User()
            user.name = row["name"]
            user.password = row["password"]
            user.author = row["author"]
            cmd_data.cmd_result.append(user)
        return cmd_data
    
    def execute_update_comand(self, cmd_obj):
        self.cursor.execute(cmd_obj.cmd_command)
        cmd_data = create_cmd_data(cmd_obj)
        # 影响的条数
        cmd_data.cmd_result = self.cursor.rowcount
        return cmd_data

class ProductManager(DataBaseManager):
    '''产品管理类'''
    
    def __init__(self, db):
        super(ProductManager, self).__init__(db)
    
    def execute_select_command(self, cmd_obj):
        self.cursor.execute(cmd_obj.cmd_command)
        cmd_data = create_cmd_data(cmd_obj)
        cmd_data.cmd_result = []
        for row in self.cursor:
            pro = Product()
            pro.id = row["id"]
            pro.name = row["name"]
            print row["name"]
            pro.type = row["type"]
            pro.MF_id = row["MF_id"]
            pro.count = row["count"]
            pro.date = row["date"]
            pro.price_buy = row["price_buy"]
            pro.price_nw = row["price_nw"]
            pro.price_ww = row["price_ww"]
            pro.fee_other = row["fee_other"]
            cmd_data.cmd_result.append(pro)
        return cmd_data
    
    def execute_insert_command(self, cmd_obj):
        print cmd_obj.cmd_command.decode('gbk')
        #self.cursor.execute(cmd_obj.cmd_command.decode('gbk'))
        self.db.safe_execute(cmd_obj.cmd_command.decode('gbk'))
        cmd_data = create_cmd_data(cmd_obj)
        cmd_data.cmd_result = self.cursor.rowcount
        self.cursor.execute("select * from product")
        for row in self.cursor:
            print row[0], row[1], row[2]
        return cmd_data
    
    def execute_update_command(self, cmd_obj):
        pass

class PurchaseManager(DataBaseManager):
    '''进货单管理类'''
    
    def __init__(self, db):
        super(PurchaseManager, self).__init__(db)
    

if __name__ == "__main__":
    import data
    db = data.DataBase("sheng.db")
    def text_login():
        c = cmd.get_cmd("user", "login",
                "select * from user where name='admin' and password='12345'")
        uMgr = UserManager(db)
        res = uMgr.execute_command(c)
        print res
    #text_login()
    
    def test_pro_select():
        c = cmd.get_cmd("product", "select",
                "select * from product")
        pMgr = ProductManager(db)
        ret = pMgr.execute_command(c)
        print ret
    test_pro_select()
    
    
    
    