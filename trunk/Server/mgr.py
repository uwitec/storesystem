# -*- coding:GBK -*-

from common.product import *
from common.purchase import *
from common.return_order import *
from common.sale import *
from common.user import *
from common.factory import *

import common.db_global as db_global
import common.cmd as cmd


def create_cmd_data(cmd_obj):
    cmd_data = cmd.CmdData()
    cmd_data.cmd_type = cmd_obj.cmd_type
    cmd_data.cmd_table = cmd_obj.cmd_table
    return cmd_data

class DataBaseManager(object):
    '''���ݿ������'''
    
    def __init__(self, db):
        # db[DataBase(object)], DataBaseʵ��
        self.db = db
        self.cursor = db.get_cursor()
        self.cmd_body = ""  # SQL������䣬��select * from user
    
    def execute_command(self, cmd_obj):
        #print cmd_obj
        cmd_type = cmd_obj.cmd_type.lower()
        if cmd_type == db_global.Cmd_Login:
            return self.execute_login_command(cmd_obj)
        elif cmd_type == db_global.Cmd_Select:
            return self.execute_select_command(cmd_obj)
        elif cmd_type == db_global.Cmd_Update:
            return self.execute_update_command(cmd_obj)
        elif cmd_type == db_global.Cmd_Insert:
            return self.execute_insert_command(cmd_obj)
        elif cmd_type == db_global.Cmd_Delete:
            return self.execute_delete_command(cmd_obj)
    
    def execute_select_command(self, cmd_obj):
        self.cursor.execute(cmd_obj.cmd_command)
        cmd_data = create_cmd_data(cmd_obj)
        cmd_data.cmd_result = []
        for row in self.cursor:
            cmd_data.cmd_result.append(self.make_instance(row))
        return cmd_data
    
    def execute_update_command(self, cmd_obj):        
        command = cmd_obj.cmd_command.decode('gbk')
        self.cursor.execute(command)
        cmd_data = create_cmd_data(cmd_obj)
        cmd_data.cmd_result = []
        where_index = command.find("where")
        where = None
        if where_index > 0:
            where = command[where_index:]

        # ��ѯ�������
        if where:
            # ��ȡ���µļ�¼
            self.cursor.execute(self.cmd_body + where)
            for row in self.cursor:
                cmd_data.cmd_result.append(self.make_instance(row))
        return cmd_data
    
    def execute_insert_command(self, cmd_obj):
        command = cmd_obj.cmd_command.decode('gbk')
        self.db.safe_execute(command, self.cursor)
        #self.cursor.execute(command)
        cmd_data = create_cmd_data(cmd_obj)
        cmd_data.cmd_result = []
        # ��ȡ�²���ļ�¼
        self.cursor.execute(self.cmd_body + "where id = ?",
                            (self.cursor.lastrowid,))
        for row in self.cursor:
            cmd_data.cmd_result.append(self.make_instance(row))
        return cmd_data
    
    def execute_delete_command(self, cmd_obj):
        raise Exception("execute_delete_command NOT define.")
    
    def make_instance(self, row):
        '''���ɵ�����¼ʵ������������'''
        raise Exception("make_instance NOT define.")


class UserManager(DataBaseManager):
    '''�û�������'''
    
    def __init__(self, db):
        super(UserManager, self).__init__(db)
        self.cmd_body = "select * from user "
    
    def execute_login_command(self, cmd_obj):
        self.cursor.execute(cmd_obj.cmd_command)
        cmd_data = create_cmd_data(cmd_obj)
        cmd_data.cmd_result = False, None
        one = self.cursor.fetchone()
        if one:
            cmd_data.cmd_result = True, one["author"]
        return cmd_data
    
    def make_instance(self, row):
        '''���ݼ�¼����User��ʵ��'''
        return User(row)

class ProductManager(DataBaseManager):
    '''��Ʒ������'''
    
    def __init__(self, db):
        super(ProductManager, self).__init__(db)
        self.cmd_body = "select * from product "
    
    def make_instance(self, row):
        return Product(row)

class FactoryManager(DataBaseManager):
    '''���̹�����'''
    def __init__(self, db):
        super(FactoryManager, self).__init__(db)
        self.cmd_body = "select * from factory "
    
    def make_instance(self, row):
        return Factory(row)
    
    
class PurchaseSManager(DataBaseManager):
    '''����������¼������'''
    
    def __init__(self, db):
        super(PurchaseSManager, self).__init__(db)
        self.cmd_body = "select * from purchaseS "
    
    def make_instance(self, row):
        return PurchaseS(row)

class PurchaseCManager(DataBaseManager):
    '''������¼���Ϲ�����'''
    
    def __init__(self, db):
        super(PurchaseCManager, self).__init__(db)
        self.cmd_body = "select * from purchaseC "
    
    def make_instance(self, row):
        return PurchaseC(row)

class SaleSManager(DataBaseManager):
    '''���۵�����¼������'''
    
    def __init__(self, db):
        super(SaleSManager, self).__init__(db)
        self.cmd_body = "select * from saleS "
    
    def make_instance(self, row):
        return SaleS(row)

class SaleCManager(DataBaseManager):
    '''���۵�����¼������'''
    
    def __init__(self, db):
        super(SaleCManager, self).__init__(db)
        self.cmd_body = "select * from saleC "
    
    def make_instance(self, row):
        return SaleC(row)

class ReturnSManager(DataBaseManager):
    '''�˻�������¼������'''
    
    def __init__(self, db):
        super(ReturnSManager, self).__init__(db)
        self.cmd_body = "select * from returnS "
    
    def make_instance(self, row):
        return ReturnS(row)

class ReturnCManager(DataBaseManager):
    '''�˻���¼���Ϲ�����'''
    
    def __init__(self, db):
        super(ReturnCManager, self).__init__(db)
        self.cmd_body = "select * from returnC "
    
    def make_instance(self, row):
        return ReturnC(row)

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
    
    def test_pro_update():
        c = cmd.get_cmd("product", "update",
                "update product set name='one' where id = 2")
        pMgr = ProductManager(db)
        ret = pMgr.execute_command(c)
        print ret
    test_pro_update()  
    