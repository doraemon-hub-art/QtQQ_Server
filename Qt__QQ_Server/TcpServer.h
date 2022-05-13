#pragma once

#include <QTcpServer>
#include <QDebug>


class TcpServer : public QTcpServer
{
	Q_OBJECT

public:
	TcpServer(int port);
	~TcpServer();
public:
	bool run();//监听

signals:
	void signalTcpMsgComes(QByteArray&);

protected:
	//当客户端有新的连接时，调用
	void incomingConnection(qintptr socketDescriptor);

private slots:
	//处理数据
	void SocketDataProcessing(QByteArray& SendData,int descriptor);

	//断开链接处理
	void SocketDisconnected(int descriptor);
private:
	int m_port;//端口号
	QList<QTcpSocket*>m_tcpSocketConnectList;//链接链表


};
