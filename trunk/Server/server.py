# -*- coding:GBK -*-
# -*- coding:GBK -*-

import asyncore, socket
import log
import logic

class Server(asyncore.dispatcher):
    '''�������������û�����'''
    def __init__(self):
        self.logger = log.get_logger("Server")
        asyncore.dispatcher.__init__(self)
        self.create_socket(socket.AF_INET, socket.SOCK_STREAM)
        host, port = '', 13579
        addr = (host, port)
        self.bind(addr)
        self.listen(100)
        self.client_set = set()
        self.logic = None        
        
    def handle_accept(self):
        '''�ͻ�������'''
        conn, addr = self.accept()      
        client = ClientAgent(conn, self)
        
    def handle_connect(self):
        # ����˵�connect��ʱû���ô�
        pass

    def handle_close(self):
        self.logger.info("handle_close->close")
        self.close()
    
    def append_client(self, client):
        self.client_set.add(client)
        
    def remove_client(self, client):
        self.client_set.remove(client)

class ClientAgent(asyncore.dispatcher):
    '''ÿ���û���Ӧ����������'''
    
    def __init__(self, sock, server):
        asyncore.dispatcher.__init__(self, sock=sock)
        self.server = server
        server.append_client(self)
        self.name = ''
        self.recvbuf = ''
        self.sentbuf = ''
        self.logger = log.get_logger('client')
        self.add_sentbuf("connect")

    def handle_close(self):
        self.logger.info("handle_close->%s close" % self.name)
        self.close()
        self.server.removeClient(self)
        
    def handle_read(self):
        self.recvbuf += self.recv(8192)
        self.logger.debug(self.recvbuf)
    
    def handle_write(self):
        sent = self.send(self.sentbuf)
        if sent > 0:
            self.logger.debug('handle_write->send %d bytes' % sent)
            # �س��ѷ��͵��ֽ�
            self.sentbuf = self.sentbuf[sent:]
    
    def writable(self):
        return len(self.sentbuf)>0
    
    def add_sentbuf(self, buf):
        self.sentbuf += buf

s = Server()
asyncore.loop()

if __name__ == "__main__":
    pass