#pragma once
#include <QObject>
#include <QTcpSocket>
#include <QtSql>

static QObject message;

class clientClass : public QObject
{
	Q_OBJECT
private:
	QTcpSocket *socket;

	QString name;
	QString pass;
	QSqlDatabase *db;
public:
	clientClass(QSqlDatabase *dbIn, QString nameIn, QString passIn, QTcpSocket *socIn, QObject *parent = 0);
	~clientClass();
	void run();
	public slots:
	void readyRead();
	void disconnected();
	void sendMSG(QString msg);
	void send();
	void insertToHistory(QString message);
	QString loadHistory();
};

