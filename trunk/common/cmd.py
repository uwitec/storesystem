# -*- coding:GBK -*-
import cPickle
import db_global
from product import *
from purchase import *
from return_order import *
from sale import *
from user import *

class Cmd(object):
    '''SQL命令'''
    def __init__(self):
        self.cmd_type = ""
        self.cmd_table = ""
        self.cmd_object = None
        self.cmd_condition = None
    
    def set_cmd_object(self, cmd_object):
        '''设置操作的对象'''
        self.cmd_object = cmd_object
        #print 'set_cmd_object'
    
    def set_cmd_type(self, cmd_type):
        '''设置命令的类型'''
        # cmd_type[string],
        #    insert,插入数据
        #    select,查询数据
        #    update,更新数据
        #    delete,删除数据
        #    login, 登录
        #    logout,退出
        if cmd_type in db_global.Cmd_Type:
            self.cmd_type = cmd_type
        
    
    def set_cmd_condition(self, cmd_condition):
        '''设置条件'''
        # cmd_condition[string], 条件
        #    根据条件来构造where后面的语句
        self.cmd_condition = cmd_condition
    
    def __repr__(self):
        text = ""
        text += "cmd_type:%s " % self.cmd_type
        text += "cmd_table:%s " % self.cmd_table
        text += "cmd_condition:%s " % self.cmd_condition
        text += "cmd_object:%s " % self.cmd_object        
        return text

class CmdData(object):
    '''SQL命令的查询结果'''
    
    def __init__(self):
        pass

def get_cmd(table_name):
    cmd = Cmd()
    cmd.cmd_table = table_name
    return cmd

fmt_string = ("[*-&*", "*&-*]")
def fmt_msg(msg):
    '''按照网络格式，格式化传输的字符串'''
    # msg[string], 序列化后的字符串
    # return[string], 返回格式化的字符串
    fmtMsg = "%s%s%s" % (fmt_string[0], msg, fmt_string[1])
    #print fmtMsg
    return fmtMsg

def get_msg_from_fmt(fmtMsg):
    '''提取格式化的字符串'''
    # fmtMsg[string], 经过函数fmt_msg格式化后的字符串
    # return[string], 返回序列化后的字符串
    beg_ind = fmtMsg.find(fmt_string[0])
    if beg_ind < 0:
        return None, -1
    beg_ind += len(fmt_string[0])
    
    end_ind = fmtMsg.find(fmt_string[1])
    if end_ind < 0:
        return None, -1
    msg = fmtMsg[beg_ind : end_ind]

    return msg, end_ind

def marshal(cmd):
    '''对Cmd对象进行序列化'''
    # cmd[Cmd(object)], Cmd对象
    # return[string], 返回序列化后的字符串
    #print cmd
    return cPickle.dumps(cmd)

def unmarshal(cmd_msg):
    '''对marshal后的序列化字符串，进行反序列化'''
    # cmd_msg[string], marshal的返回值
    # return[Cmd(object)], Cmd对象
    return cPickle.loads(cmd_msg)

def pack(cmd):
    # cmd[Cmd(object)], Cmd对象
    msg = marshal(cmd)
    return fmt_msg(msg)
    
if __name__ == "__main__":
    p = Product()
    strp = cPickle.dumps(p)
    #print strp
    u = User()
    stru = cPickle.dumps(u)
    print cPickle.loads(strp + stru)
    print cPickle.loads(stru)
    
    def test_fmt_msg():
        msg = "select from good"
        fmtMsg = fmt_msg(msg)
        print fmtMsg
        msg = get_msg_from_fmt(fmtMsg)
        print msg
        msg = get_msg_from_fmt(fmt_string[0])
        print msg
    test_fmt_msg()
    
    def marshal_test():
        c = Cmd()
        p = Product()
        c.cmd_object = p
        strc = marshal(c)
        print strc
        c = unmarshal(strc)
        print c
    
    marshal_test()