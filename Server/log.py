# -*- coding:GBK -*-
'''
日志类，为服务器文件提供日志服务功能
'''

import logging
import os
import datetime
class Log:
    
    def __init__(self, level=logging.DEBUG):
        # 若日志文件不存在，则创建新的日志文件
        db_path = os.path.dirname(__file__)
        log_path = os.path.join(db_path, "log")
        if not os.path.exists(log_path):
            os.mkdir(log_path)
        log_file = os.path.join(log_path, str(datetime.date.today()) + ".log")
        logging.basicConfig(level=level,
                            format='%(asctime)s %(name)-8s %(levelname)-8s %(message)s',
                            datefmt='%m-%d %H:%M',
                            filename=log_file)
    
    def get_logger(self, name):
        '''获得日志对象'''
        # name[string],日志对象的名字，可以任意命名
        return logging.getLogger(name)

__log = None
def get_logger(name):
    global __log
    if not __log:
        __log = Log(level=logging.DEBUG)
    return __log.get_logger(name)

if __name__ == "__main__":
    
    def test1():
        log = Log()
    
    test1()
    print str(datetime.date.today())