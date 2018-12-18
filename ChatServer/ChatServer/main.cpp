#include <QtCore/QCoreApplication>
#include "ServerClass.h"
#include <QtSql>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	setlocale(LC_ALL, "Russian");
	ServerClass server;
	server.StartSever();
	return a.exec();
}
