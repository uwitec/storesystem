# -*- coding:GBK -*-
'''
��־�࣬Ϊ�������ļ��ṩ��־������
'''

import logging
import os
import datetime
class Log:
    
    def __init__(self, level=logging.DEBUG):
        # ����־�ļ������ڣ��򴴽��µ���־�ļ�
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
        '''�����־����'''
        # name[string],��־��������֣�������������
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