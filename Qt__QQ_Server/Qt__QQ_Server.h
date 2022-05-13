#pragma once

#include <QtWidgets/QDialog>
#include "ui_Qt__QQ_Server.h"
#include "TcpServer.h"
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QTimer>
#include <QSqlQuery>
#include <QFileDialog>
#include <QUdpSocket>

class Qt__QQ_Server : public QDialog {
	Q_OBJECT

public:
	Qt__QQ_Server(QWidget *parent = Q_NULLPTR);

private:
	//��ʼ��
	void initTcpSocket();//��ʼ��TCP

	bool connectMySql();

	void updateTableData(int depID = 0, int employeeID = 0);

	int getCompDepID();//��ȡ��˾ȺQQ��

	void setDepNameMap();

	void setStatusMap();

	void setOnlineMap();

	void initComboBoxData();//��ʼ����Ͽ������

	void initUdpSocket();//��ʼ��udp

private slots:
	void onUDPbroadMsg(QByteArray& btData);

	void onRefresh();

	void on_queryDepartmentBtn_clicked();//����Ⱥ����Ա��

	void on_queryIDBtn_clicked();//����Ա��QQ��(Ա����)ɸѡ

	void on_logoutBtn_clicked();//ע��Ա��QQ��

	void on_selectPictureBtn_clicked();//ѡ��ͼƬ(Ա����ͷ��)

	void on_addBtn_clicked();//����Ա��

private:
	Ui::QtQQ_ServerClass ui;//��Ϊ���Լ���ui�ļ��еĲ��������������ˣ�����ֱ�Ӹ��ƵĽ̳��еġ�
	//���ֲ�ͬ�����ɵ�ui xxx .h�ļ���ͬ���������ɵ�����Ҳ��ͬ��ע���޸ġ�

	QSqlQueryModel m_queryInfoModel;//��ѯ����Ա������Ϣ

	int m_compDepID;//��˾ȺQQ��

	QMap<QString, QString> m_statusMap;//״̬
	QMap<QString, QString>m_depNameMap;//��������
	QMap<QString, QString>m_onlineMap;//����

		

	QTimer* m_timer;//��ʱˢ������


	//������ͬ����֤�ˣ���ʱˢ��ʱ������ʾ�ղ���Ҫ��ѯ�����ݡ�
	int m_depID;				//����QQ��
	int m_employeeID;			//Ա��QQ��


	QString m_pixPath;//ͷ��·��

	TcpServer* m_tcpServer;//tcp�����
	QUdpSocket* m_udpSender;//udp�㲥
	

	//ip��ַ�ҵ���Ӧ�ļ�������˿ں��ҵ���Ӧ��Ӧ�ó���

};