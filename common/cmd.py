# -*- coding:GBK -*-
import cPickle
import db_global
from product import *
from purchase import *
from return_order import *
from sale import *
from user import *

class Cmd(object):
    '''SQL����'''
    def __init__(self):
        self.cmd_type = ""
        self.cmd_table = ""
        self.cmd_object = None
        self.cmd_condition = None
    
    def set_cmd_object(self, cmd_object):
        '''���ò����Ķ���'''
        self.cmd_object = cmd_object
        #print 'set_cmd_object'
    
    def set_cmd_type(self, cmd_type):
        '''�������������'''
        # cmd_type[string],
        #    insert,��������
        #    select,��ѯ����
        #    update,��������
        #    delete,ɾ������
        #    login, ��¼
        #    logout,�˳�
        if cmd_type in db_global.Cmd_Type:
            self.cmd_type = cmd_type
        
    
    def set_cmd_condition(self, cmd_condition):
        '''��������'''
        # cmd_condition[string], ����
        #    ��������������where��������
        self.cmd_condition = cmd_condition
    
    def __repr__(self):
        text = ""
        text += "cmd_type:%s " % self.cmd_type
        text += "cmd_table:%s " % self.cmd_table
        text += "cmd_condition:%s " % self.cmd_condition
        text += "cmd_object:%s " % self.cmd_object        
        return text

class CmdData(object):
    '''SQL����Ĳ�ѯ���'''
    
    def __init__(self):
        pass

def get_cmd(table_name):
    cmd = Cmd()
    cmd.cmd_table = table_name
    return cmd

fmt_string = ("[*-&*", "*&-*]")
def fmt_msg(msg):
    '''���������ʽ����ʽ��������ַ���'''
    # msg[string], ���л�����ַ���
    # return[string], ���ظ�ʽ�����ַ���
    fmtMsg = "%s%s%s" % (fmt_string[0], msg, fmt_string[1])
    #print fmtMsg
    return fmtMsg

def get_msg_from_fmt(fmtMsg):
    '''��ȡ��ʽ�����ַ���'''
    # fmtMsg[string], ��������fmt_msg��ʽ������ַ���
    # return[string], �������л�����ַ���
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
    '''��Cmd����������л�'''
    # cmd[Cmd(object)], Cmd����
    # return[string], �������л�����ַ���
    #print cmd
    return cPickle.dumps(cmd)

def unmarshal(cmd_msg):
    '''��marshal������л��ַ��������з����л�'''
    # cmd_msg[string], marshal�ķ���ֵ
    # return[Cmd(object)], Cmd����
    return cPickle.loads(cmd_msg)

def pack(cmd):
    # cmd[Cmd(object)], Cmd����
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