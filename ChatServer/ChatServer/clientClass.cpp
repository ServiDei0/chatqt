#include "clientClass.h"
#include <QDataStream>
#include <QtSql>

clientClass::clientClass(QSqlDatabase *dbIn, QString nameIn, QString passIn, QTcpSocket *socIn, QObject *parent)
	: QObject(parent)
{
	db = dbIn;
	name = nameIn;
	pass = passIn;
	socket = socIn;
}

clientClass::~clientClass()
{

}

void clientClass::run()
{
	QString com = socket->read(1);
	if (com == "l")
	{
		if (db->open())
		{

			QSqlQuery query;

			bool loggedIn = false;
			query.exec("SELECT * FROM users");

			while (query.next())
			{
				if (query.value(0).toString().trimmed() == name)
					if (query.value(1).toString().trimmed() == pass)
						loggedIn = true;
			}

			if (loggedIn)
			{
				qDebug() << name << " connected";//////////////////
				socket->write("a");
				sendMSG(loadHistory() + "\nNew messages :------------------------- ");
			}
			else
			{
				qDebug() << name << " connection denied";/////////////
				socket->write("c");
				socket->waitForBytesWritten();
				disconnected();
			}
		}
	}
	else
	{
		if (db->open())
		{

			QSqlQuery query;

			bool exists = false;
			query.exec("SELECT * FROM users");

			while (query.next())
			{
				if (query.value(0).toString().trimmed() == name)
					exists = true;
			}

			if (exists)
			{
				qDebug() << name << " connection denied";////////////
				socket->write("d");
				socket->waitForBytesWritten();
				disconnected();
			}
			else
			{
				qDebug() << name << "  connected";////////////////
				query.prepare("INSERT INTO users VALUES(:name,:password)");
				query.bindValue(":name", name);
				query.bindValue(":password", pass);
				query.exec();
				socket->write("b");
				sendMSG(loadHistory() + "\nNew messages :----------------------- ");
			}
		}
	}
	connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
	connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
	connect(&message, SIGNAL(objectNameChanged(QString)), this, SLOT(send()));
}

void clientClass::readyRead()
{
	while (socket->bytesAvailable() > 0)
	{
		QByteArray  byteLength = socket->read(4);

		qint32 length = byteLength[0] * 512 + byteLength[1] * 65 + byteLength[2] * 8 + byteLength[3];
		QByteArray Data;
		for (qint32 i = 0; i < length; i++)
			Data.append(socket->read(1));
		qDebug() << name << " writes: " << Data;//////////

		insertToHistory(name + ": " + Data);///////////
		message.setObjectName(name + ": " + Data);/////////////
	}
}

void clientClass::disconnected()
{
	socket->deleteLater();
	qDebug() << name << " disconnected";/////////////
	this->deleteLater();
}

void clientClass::send()
{
	sendMSG(message.objectName());
}

void clientClass::sendMSG(QString msg)
{
	quint32 num = msg.length();
	QByteArray ba;
	QDataStream ds(&ba, QIODevice::WriteOnly);
	ds << num;
	socket->write(ba);

	QByteArray messByte;
	messByte.append(msg);
	socket->write(messByte);
}

void clientClass::insertToHistory(QString message)
{
	if (db->open())
	{
		QSqlQuery query;
		query.prepare("INSERT INTO history VALUES(:msg)");
		query.bindValue(":msg", message);
		query.exec();
	}
}

QString clientClass::loadHistory()
{
	QSqlQuery query;

	bool loggedIn = false;
	query.exec("SELECT * FROM history");

	QString historyStr;
	while (query.next())
		historyStr += query.value(0).toString().trimmed() + '\n';

	return historyStr;
}
