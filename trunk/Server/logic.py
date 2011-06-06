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
        self.purchaseC_mgr = mgr.PurchaseCManager(self.db)
        self.purchaseS_mgr = mgr.PurchaseSManager(self.db)
        self.saleC_mgr = mgr.SaleCManager(self.db)
        self.saleS_mgr = mgr.SaleSManager(self.db)
        self.returnC_mgr = mgr.ReturnCManager(self.db)
        self.returnS_mgr = mgr.ReturnSManager(self.db)
    
    def process_cmd_obj(self, cmd_obj):
        cmd_table = cmd_obj.cmd_table.lower()
        if cmd_table == "user":
            return self.user_mgr.execute_command(cmd_obj)
        elif cmd_table == "product":
            return self.product_mgr.execute_command(cmd_obj)
        elif cmd_table == "factory":
            return self.factory_mgr.execute_command(cmd_obj)
        elif cmd_table == "purchasec":
            return self.purchaseC_mgr.execute_command(cmd_obj)
        elif cmd_table == "purchases":
            return self.purchaseS_mgr.execute_command(cmd_obj)
        elif cmd_table == "salec":
            return self.saleC_mgr.execute_command(cmd_obj)
        elif cmd_table == "sales":
            return self.saleS_mgr.execute_command(cmd_obj)
        elif cmd_table == "returnc":
            return self.returnC_mgr.execute_command(cmd_obj)
        elif cmd_table == "returns":
            return self.returnS_mgr.execute_command(cmd_obj) 

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