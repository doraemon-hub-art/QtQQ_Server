#pragma once

#include <QTcpSocket>

class TcpSocket : public QTcpSocket
{
	Q_OBJECT

public:
	TcpSocket();
	~TcpSocket();

	void run();
signals:
	//�ӿͻ����յ����ݺ����źŸ���server������Ҫ����
	void signalGetDataFromClient(QByteArray&, int);
	void signalClientDisconnect(int);//����server�пͻ��˶Ͽ����� 

private slots:
	void onReceiveData();//����readyRead�źŶ�ȡ������
	void onClientDisconnect();//����ͻ��˶Ͽ�����


private:
	int m_descriptor;//������������Ψһ��ʶ
};
