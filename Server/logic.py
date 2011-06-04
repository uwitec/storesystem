# -*- coding:GBK -*-
import data
import log
import mgr
class Logic:
    
    def __init__(self):
        self.logger = log.get_logger("Logic")
        self.logger.info("init Logic successfully")
        self.db = data.DataBase("sheng.db")
        self.user_mgr = mgr.UserManager(self.db)
        self.product_mgr = mgr.ProductManager(self.db)
        self.factory_mgr = mgr.FactoryManager(self.db)
        self.purchase_mgr = None
        self.return_order_mgr = None
        self.sale_mgr = None
    
    def process_cmd_obj(self, cmd_obj):
        cmd_table = cmd_obj.cmd_table.lower()
        if cmd_table == "user":
            return self.user_mgr.execute_command(cmd_obj)
        elif cmd_table == "product":
            return self.product_mgr.execute_command(cmd_obj)
        elif cmd_table == "factory":
            return self.factory_mgr.execute_command(cmd_obj)
    
    def build_sql_command(self, cmd_obj):
        pass
    
    def build_insert_common(self, cmd_obj):
        command = """
            INSERT into %s values
        """
    
    def Init_DataBase(self):
        pass

if __name__ == "__main__":
    from common.cmd import *
    def build_user():        
        user = User()
        user.name = "admin"
        user.password = "12345"
        
        cmd_obj = get_cmd("user")
        cmd_obj.set_cmd_object(user)
        cmd_obj.set_cmd_type("login")
        
        return cmd_obj
    
    def test_logic_usrmgr():
        cmd_obj = build_user()
        logic = Logic()
        cmd_res = logic.process_cmd_obj(cmd_obj)
        print cmd_res
    
    test_logic_usrmgr()