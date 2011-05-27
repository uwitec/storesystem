# -*- coding:GBK -*-
import data
import log
class Logic:
    
    def __init__(self):
        self.logger = log.get_logger("Logic")
        self.logger.info("init Logic successfully")
        self.db = data.DataBase("sheng.db")
    
    def process_cmd_obj(self, cmd_obj):
        pass
    
    def build_sql_command(self, cmd_obj):
        pass
    
    def build_insert_common(self, cmd_obj):
        command = """
            INSERT into %s values
        """
    
    def Init_DataBase(self):
        pass

if __name__ == "__main__":
    pass