#pragma once
#include "StdAfx.h"
#include "LogManager.h"
class ClientNet : public QObject
{
	Q_OBJECT
public:
	ClientNet(void);
	virtual ~ClientNet(void);
	// 发送消息给服务器
	void send( const char* msg );
public slots:
	void errorHandle(QAbstractSocket::SocketError socketError);
	void connectedHandle();
protected:
	void send();
	QTcpSocket* m_pTcpSocket;
	Log* m_pLog;
	bool m_isConnected;
	QString m_sentBuf;
};
