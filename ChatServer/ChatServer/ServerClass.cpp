#include "ServerClass.h"

#include <QDataStream>
#include <QTcpSocket>
#include <clientClass.h>
#include <QtSQL>

ServerClass::ServerClass(QObject *parent)
	: QTcpServer(parent)
{

}

ServerClass::~ServerClass()
{
	db.close();
}

void ServerClass::StartSever()
{
	QString serverStr = "LOCALHOST\\SQLEXPRESS";
	QString dbName = "qtchat";

	db = QSqlDatabase::addDatabase("QODBC");

	db.setConnectOptions();
	QString dsn = QString("DRIVER={SQL SERVER};SERVER=%1;DATABASE=%2;").arg(serverStr).arg(dbName);

	db.setDatabaseName(dsn);

	this->listen(QHostAddress::Any, 1213);
}

void ServerClass::incomingConnection(qintptr handle)
{
	QTcpSocket *soc = new QTcpSocket;
	soc->setSocketDescriptor(handle);
	soc->waitForReadyRead();

	QString name = readStr(soc);
	QString pass = readStr(soc);
	

	clientClass *client = new clientClass(&db, name, pass, soc, this);
	clientList.append(soc);
	connect(client, SIGNAL(destroyed()), client, SLOT(deleteLater()));
	client->run();

}

QString ServerClass::readStr(QTcpSocket *soc)
{
	QByteArray byteLength = soc->read(4);
	qint32 len = byteLength[0] * 512 + byteLength[1] * 65 + byteLength[2] * 8 + byteLength[3];
	QByteArray Data;
	for (qint32 i = 0; i < len; i++)
		Data.append(soc->read(1));
	return Data;
}