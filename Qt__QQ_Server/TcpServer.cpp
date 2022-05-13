#include "TcpServer.h"
#include <QTcpSocket>
#include "TcpSocket.h"

TcpServer::TcpServer(int port)
	:m_port(port)
{
}

TcpServer::~TcpServer()
{
}

bool TcpServer::run() {
	if (this->listen(QHostAddress::AnyIPv4, m_port)) {
		qDebug() << QString::fromLocal8Bit("����˼����˿� %1 �ɹ�!")
			.arg(m_port);
		return true;
	} else {
		qDebug() << QString::fromLocal8Bit("����˼����˿� %1 ʧ��!")
			.arg(m_port);
		return false;
	}
}

void TcpServer::incomingConnection(qintptr socketDescriptor) {
	qDebug() << QString::fromLocal8Bit("�µ�����:") << socketDescriptor << endl;

	TcpSocket* tcpsocket = new TcpSocket();
	tcpsocket->setSocketDescriptor(socketDescriptor);
	tcpsocket->run();

	//�յ��ͻ��˵����ݣ�server���д���
	connect(tcpsocket, SIGNAL(signalGetDataFromClient(QByteArray&,int)),this,
		SLOT(SocketDataProcessing(QByteArray&,int)));
	//�յ��ͻ��˶Ͽ����Ӻ�server���д���
	connect(tcpsocket, SIGNAL(signalClientDisconnect(int)),this,
		SLOT(SocketDisconnected(int)));
	//��socket��ӵ�������
	m_tcpSocketConnectList.append(tcpsocket);
}

void TcpServer::SocketDataProcessing(QByteArray& SendData, int descriptor) {
	//�ҵ���ǰ���ĸ��ͻ��˷�������
	for (int i = 0; i < m_tcpSocketConnectList.count(); i++) {
		QTcpSocket *item = m_tcpSocketConnectList.at(i);
		if (item->socketDescriptor() == descriptor) {
			qDebug() << QString::fromLocal8Bit("����IP:") 
				<< item->peerAddress().toString()
				<< QString::fromLocal8Bit("����������:") 
				<< QString(SendData);
			emit signalTcpMsgComes(SendData);
		}
	}
	
}



void TcpServer::SocketDisconnected(int descriptor) {
	for (int i = 0; i < m_tcpSocketConnectList.count(); i++) {
		QTcpSocket* item = m_tcpSocketConnectList.at(i);
		int itemDescriptor = item->socketDescriptor();

		//���ҶϿ����ӵ�socket��ͨ��������������
		if (itemDescriptor == descriptor || itemDescriptor == -1) {
			//�Ͽ���socket���������Ƴ�
			m_tcpSocketConnectList.removeAt(i);
			item->deleteLater();//������Դ
			qDebug() <<QString::fromLocal8Bit("TcpSocket�Ͽ�����")
				<< descriptor << endl;
			return;
		}
	}
}

