# -*- coding:GBK -*-
import sqlite3
import os
import log
from distutils.cmd import Command
class DataBase(object):
    
    def __init__(self, filename):
        '''初始化数据库'''
        # filename[string],数据库文件名
        
        super(DataBase, self).__init__()
        # 生成日志对象
        self.logger = log.get_logger("DataBase")
        
        # 若数据库文件夹不存在，创建文件夹
        db_path = 'db'
        if not os.path.exists(db_path):
            self.logger.info("create directory: db")
            os.mkdir(db_path)
        
        db_name = os.path.join(db_path, filename)
        if not os.path.exists(db_name):
            self.logger.info("create database file:" + filename)
            self.__create_table(db_name)
        
        # 调试开关
        sqlite3.enable_callback_tracebacks(True)
        
        # 连接数据库
        self.con = sqlite3.connect(db_name)
        self.con.row_factory = sqlite3.Row
        self.logger.info("init DataBase successfully")

    def get_cursor(self):
        ''''''
        cursor = self.con.cursor()
        #cursor.row_factory = sqlite3.Row
        return cursor
    
    def safe_execute(self, command, cursor=None):
        '''安全地执行SQL语句'''
        try:
            if not cursor:
                cursor = self.con
            cursor.execute(command)
            self.con.commit()
        except Exception, e:
            self.logger.error('safe_execute->command=%s;%s' % (command, e))
            self.rollback()
    
    def safe_executemany(self, command, obj_list, cursor=None):
        '''执行多个SQL语句'''
        try:
            if not cursor:
                cursor = self.con
            cursor.executemany(command, obj_list)
            self.con.commit()
        except Exception, e:
            self.logger.error('safe_executemany->command=%s;%s' % (command, e))
            self.rollback()
    
    def rollback(self):
        '''出现错误时进行回滚'''
        self.con.rollback()
        self.logger.info('rollback from error')        
    
    def __create_table(self, db_name):
        '''创建新的数据库，当数据库不存在时调用'''
        # db_name[string],数据库文件绝对路径
        
        file = open(db_name, 'w')
        file.close()
        
        conn = sqlite3.connect(db_name)
        cursor = conn.cursor()
        self.__create_user_table(cursor)
        self.__create_product_table(cursor)
        self.__create_factory_table(cursor)
        self.__create_purchase_order_table(cursor)
        self.__create_return_order(cursor)
        self.__create_sale_order_table(cursor)    
        cursor.close()
        conn.commit()
    
    def __create_user_table(self, cursor):
        '''创建用户表'''
        command = """
        CREATE TABLE user(
            id        INTEGER PRIMARY KEY,
            name      TEXT NOT NULL,
            password  TEXT NOT NULL,
            author    INTEGER NOT NULL
        );
        """
        cursor.execute(command)
    
    def __create_product_table(self, cursor):
        '''创建产品数据表'''
        # (ID, 产品名称，类别，厂商ID，数量，日期，
        #  进货价，内围价，外围价，其它费用）
        command = """
        CREATE TABLE product(
            id        INTEGER PRIMARY KEY,
            name      TEXT NOT NULL,
            type      TEXT,
            MF_id     INTEGER NOT NULL,
            count     INTEGER NOT NULL,
            date      TEXT NOT NULL,
            price_buy INTEGER NOT NULL,
            price_nw  INTEGER,
            price_ww  INTEGER,
            fee_other INTEGER
            );
        """
        cursor.execute(command)
    
    def __create_factory_table(self, cursor):
        '''创建厂商数据表'''
        command = """
        CREATE TABLE factory(
            id        INTEGER PRIMARY KEY,
            name      TEXT,
            contact   TEXT,
            post      TEXT,
            phone     TEXT,
            zip_code  TEXT,
            addr      TEXT,
            email     TEXT,
            card_type TEXT,
            card_num  TEXT
        );            
        """
        cursor.execute(command)
    
    def __create_purchase_order_table(self, cursor):
        '''创建进货订单数据表'''
        command = """
        CREATE TABLE purchase_order(
            id        INTEGER PRIMARY KEY,
            product_id INTEGER NOT NULL,
            count     INTEGER NOT NULL,
            date      TEXT,
            MF_id     INTEGER,
            price_pc  INTEGER,
            price_pay INTEGER,
            fee_other INTEGER
        );
        """
        cursor.execute(command)
    
    def __create_sale_order_table(self, cursor):
        '''创建销售订单数据表'''
        command = """
        CREATE TABLE sale_order(
            id        INTEGER PRIMARY KEY,
            type      INTEGER,
            date      TEXT,
            product_id INTEGER NOT NULL,            
            count     INTEGER NOT NULL,
            price_sell INTEGER,
            price_pay  INTEGER,
            seller    TEXT,
            sale_addr TEXT,
            buyer_name TEXT,
            buyer_tel  TEXT
        );
        """
        cursor.execute(command)
    
    def __create_return_order(self, cursor):
        '''创建退货订单'''
        command = """
        CREATE TABLE return_order(
            id        INTEGER PRIMARY KEY,
            product_id INTEGER NOT NULL,
            count     INTEGER NOT NULL,
            date      TEXT,
            price_ret INTEGER
        );
        """
        cursor.execute(command)

if __name__ == "__main__":
    def build_data():
        db = DataBase("sheng.db")
        #build_all_data(db)
        select_user(db)
        select_product(db)
    
    def select_user(db):
        cursor = db.get_cursor()
        cursor.execute("select * from user where name=? and password=?", ("admin", 12345))
        for row in cursor.fetchall():
            print row        
    
    def build_all_data(db):
        import common.user
        user_list = [
            ("admin", "12345", 0),
            ("user1", "67890", 1)
        ]
        #db.safe_executemany("insert into user values(?, ?, ?)", user_list)
        
        import common.product
        product_list = [
            ("牙膏".decode('gbk'), "日用品".decode('gbk'), 0, 15, "2011-5-5", 1000, 1100, 1200, 100),
            ("水杯".decode('gbk'), "毒品".decode('gbk'), 0, 23, "2011-6-6", 500, 600, 700, 100),
            ("《C++编程》".decode('gbk'), "书籍".decode('gbk'), 3, 4, "2011-7-7", 4000, 4100, 4400, 500)
        ]
        #db.safe_executemany("insert into product values(null, ?, ?, ?, ?, ?, ?, ?, ?, ?)", product_list)
        
    def select_product(db):
        cursor = db.get_cursor()
        #cursor.execute("delete from product where id = 2")
        #cursor.execute("insert into product values(null, 'one', 'number', 0, 17, '2010-10-10', 100, 1100, 1200, 100)")
        #cursor.execute("select * from product where row_number() == 2")
        cursor.execute("select * from product")
        for row in cursor:
            print row["id"], row["name"].encode("gbk"), row["type"].encode("gbk")
            print row
    build_data()
    
    def shortCutMethod():
        import sqlite3
        
        persons = [
                   ("Hugo", "Boss"),
                   ("Calvin", "Klein")
                   ]
        
        con = sqlite3.connect(":memory:")
        
        # Create the table
        con.execute("create table person(firstname, lastname)")
        
        # Fill the table
        con.executemany("insert into person(firstname, lastname) values (?, ?)", persons)
        cursor = con.cursor()
        command = "update person set lastname=?, firstname=? where firstname='Hugo'"
        cursor.execute(command, ("sheng", 'chen'))
        #print cursor.rowcount
        print cursor.fetchall()
        where = command[command.find('where'):]
        print where
        #cursor = con.cursor()
        cursor.execute("select * from person ")
        for row in cursor:
            print row
    #shortCutMethod()
    #build_data()