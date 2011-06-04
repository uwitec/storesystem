#include "StdAfx.h"
#include <QSettings>
#include "ClientNet.h"
#include "SConvert.h"
#include "Logic.h"
ClientNet::ClientNet(Logic* pLogic)
:	m_isConnected(false), m_sentBuf(""), m_recvBuf(""),
	m_pLogic(pLogic)
{
	m_pLog = LogManager::getSingleton().getLog("ClientNet");
	// 打开控制台输出开头-注：正式发布时不打开
	m_pLog->setStdStreamActive(true);
	m_pTcpSocket = new QTcpSocket(this);
	// 添加网络消息回调函数
	connect( m_pTcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
			 this, SLOT(handleError(QAbstractSocket::SocketError)) );
	connect( m_pTcpSocket, SIGNAL(connected()),
			 this, SLOT(handleConnected()) );
	connect( m_pTcpSocket, SIGNAL(readyRead()),
			 this, SLOT(handleReadyRead()) );
	QSettings ini("config.ini", QSettings::IniFormat);
	QString ip = ini.value("ip").toString();
	int32 port = ini.value("port").toInt();
	m_pLog->info(std::string("connect to ") + ip.toLocal8Bit().data() + ":" + SConvert::toString(port));
	m_pTcpSocket->connectToHost(ip, port);
}

ClientNet::~ClientNet(void)
{
}

void ClientNet::send( const char* msg )
{
	m_sentBuf += msg;
	//printf("%s\n", m_sentBuf.toLocal8Bit().data());
	//m_sentBuf = QString::fromUtf8("hello world");
	this->send();	
}

void ClientNet::send(const QString& msg)
{
	m_sentBuf += msg;
	this->send();
}

void ClientNet::handleError(QAbstractSocket::SocketError socketError)
{
	switch (socketError) {
	 case QAbstractSocket::RemoteHostClosedError:
		 m_pLog->error("RemoteHostClosedError");
		 break;
	 case QAbstractSocket::HostNotFoundError:
		 m_pLog->error("HostNotFoundError");
		 break;
	 case QAbstractSocket::ConnectionRefusedError:
		 m_pLog->error("ConnectionRefusedError");
		 break;
	 default:
		 m_pLog->error(SConvert::toCStr(m_pTcpSocket->errorString()));
	}
}

void ClientNet::handleConnected()
{
	m_pLog->info("connect to server successfully.");
	m_isConnected = true;
	this->send();
}

void ClientNet::handleReadyRead()
{
	m_recvBuf += m_pTcpSocket->readAll();
	//m_pLog->debug(m_recvBuf.toLocal8Bit().data());
	if( m_pLogic != NULL )
	{
		//m_pLogic->test();
		int32 hadCut = m_pLogic->parseReplyMsg(m_recvBuf);
		m_pLog->debug(SConvert::toString(hadCut));
		while( hadCut > 0 )
		{
			m_recvBuf = m_recvBuf.mid(hadCut);
			hadCut = m_pLogic->parseReplyMsg(m_recvBuf);
		}
	}
	//m_pLog->debug("finish cut");
}

void ClientNet::send()
{
	if( m_isConnected && m_sentBuf.size() > 0 )
	{
		//printf("\n\n%s\n\n", m_sentBuf.toLocal8Bit().data());
		//int32 sent = m_pTcpSocket->write(SConvert::toCStr(m_sentBuf));
		//const char* msg = ;
		int32 sent = m_pTcpSocket->write(m_sentBuf.toLocal8Bit().data());
		if( sent > 0 )
		{			
			m_sentBuf = m_sentBuf.mid(sent);
		}
	}
}