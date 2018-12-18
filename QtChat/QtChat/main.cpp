#include "QtChat.h"
#include <QtWidgets/QApplication>
#include <thread>
#include <iostream>
#include <QTcpSocket>


using namespace std;
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	setlocale(LC_ALL, "Russian");
	QtChat w;

	w.show();
	return a.exec();
}
