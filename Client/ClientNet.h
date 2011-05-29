#pragma once
#include "StdAfx.h"
#include "LogManager.h"
class Logic;
class ClientNet : public QObject
{
	Q_OBJECT
public:
	ClientNet(Logic* pLogic = NULL);
	virtual ~ClientNet(void);
	void setLogic(Logic* pLogic){ m_pLogic = pLogic; }
	// ������Ϣ��������
	void send( const char* msg );
	void send(const QString& msg);
public slots:
	// ������Ϣ������
	void handleError(QAbstractSocket::SocketError socketError);
	void handleConnected();
	void handleReadyRead();
protected:
	void send();
	QTcpSocket* m_pTcpSocket;
	Log* m_pLog;
	Logic* m_pLogic;
	bool m_isConnected;
	QString m_sentBuf;
	QString m_recvBuf;
};
