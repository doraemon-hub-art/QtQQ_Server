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
	bool run();//����

signals:
	void signalTcpMsgComes(QByteArray&);

protected:
	//���ͻ������µ�����ʱ������
	void incomingConnection(qintptr socketDescriptor);

private slots:
	//��������
	void SocketDataProcessing(QByteArray& SendData,int descriptor);

	//�Ͽ����Ӵ���
	void SocketDisconnected(int descriptor);
private:
	int m_port;//�˿ں�
	QList<QTcpSocket*>m_tcpSocketConnectList;//��������


};
