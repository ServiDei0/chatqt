#pragma once
#include <QTcpServer>
#include <QtSQL>

class ServerClass : public QTcpServer
{
	Q_OBJECT

public:
	QList<QTcpSocket*> clientList;
	QSqlDatabase db;

	ServerClass(QObject *parent = 0);
	~ServerClass();
	void StartSever();
	QString readStr(QTcpSocket *soc);
protected:
	void incomingConnection(qintptr handle) Q_DECL_OVERRIDE;
};
