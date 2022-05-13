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
	//初始化
	void initTcpSocket();//初始化TCP

	bool connectMySql();

	void updateTableData(int depID = 0, int employeeID = 0);

	int getCompDepID();//获取公司群QQ号

	void setDepNameMap();

	void setStatusMap();

	void setOnlineMap();

	void initComboBoxData();//初始化组合框的数据

	void initUdpSocket();//初始化udp

private slots:
	void onUDPbroadMsg(QByteArray& btData);

	void onRefresh();

	void on_queryDepartmentBtn_clicked();//根据群查找员工

	void on_queryIDBtn_clicked();//根据员工QQ号(员工号)筛选

	void on_logoutBtn_clicked();//注销员工QQ号

	void on_selectPictureBtn_clicked();//选择图片(员工的头像)

	void on_addBtn_clicked();//新增员工

private:
	Ui::QtQQ_ServerClass ui;//因为我自己的ui文件中的部件名字命名错了，所以直接复制的教程中的。
	//名字不同，生成的ui xxx .h文件不同，所以生成的类名也不同，注意修改。

	QSqlQueryModel m_queryInfoModel;//查询所有员工的信息

	int m_compDepID;//公司群QQ号

	QMap<QString, QString> m_statusMap;//状态
	QMap<QString, QString>m_depNameMap;//部门名称
	QMap<QString, QString>m_onlineMap;//在线

		

	QTimer* m_timer;//定时刷新数据


	//这两个同样保证了，定时刷新时内容显示刚才你要查询的内容。
	int m_depID;				//部门QQ号
	int m_employeeID;			//员工QQ号


	QString m_pixPath;//头像路径

	TcpServer* m_tcpServer;//tcp服务端
	QUdpSocket* m_udpSender;//udp广播
	

	//ip地址找到对应的计算机，端口号找到对应的应用程序

};