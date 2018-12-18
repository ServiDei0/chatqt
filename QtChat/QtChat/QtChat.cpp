#include "QtChat.h"

#include <QMessageBox>
#include <QTcpSocket>
#include <qtcpserver.h>


void QtChat::sendStr(QString str)
{
	quint32 num = str.length();
	QByteArray ba;
	QDataStream ds(&ba, QIODevice::WriteOnly);
	ds << num;
	socket->write(ba);

	QByteArray mess;
	mess.append(str);
	socket->write(mess);
}


QtChat::QtChat(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.sendButt, SIGNAL(clicked()), this, SLOT(on_btn_sendButt_clicked()));
	QObject::connect(ui.connectButt, SIGNAL(clicked()), this, SLOT(on_btn_connectButt_clicked()));
	
}

void QtChat::on_btn_sendButt_clicked()
{
	sendStr(ui.tbMess->toPlainText());

	ui.tbMess->clear();
}


void QtChat::on_btn_connectButt_clicked()
{
	socket = new QTcpSocket(this);
	connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
	socket->connectToHost(*(new QHostAddress(ui.leIP->text())), ui.lePort->text().toInt());
	sendStr(ui.leLogin->text());
	sendStr(ui.lePassword->text());
	//if (ui.rbWithoutReg->isChecked())
	/*	socket->write("l");
	else*/
		socket->write("r");

}

void QtChat::readyRead()
{
	while (socket->bytesAvailable() > 0)
		if (flagConnected)
		{
			QByteArray  byteLength = socket->read(4);

			qint32 length = byteLength[0] * 512 + byteLength[1] * 65 + byteLength[2] * 8 + byteLength[3];
			QByteArray Data;
			Data.append(socket->readAll());
			ui.tbMain->append(Data);
		}
		else
		{
			QByteArray com = socket->read(1);
			if (com[0] == 'a')
			{
				QMessageBox msg;
				msg.setText("Connected!");
				msg.exec();
				flagConnected = true;
				ui.tbMain->setEnabled(true);
				ui.tbMess->setEnabled(true);
				ui.sendButt->setEnabled(true);
				ui.leIP->setEnabled(false);
				ui.leLogin->setEnabled(false);
				ui.lePassword->setEnabled(false);
				ui.lePort->setEnabled(false);
				ui.connectButt->setEnabled(false);
				//ui.rbWithoutReg->setEnabled(false);
				//ui.rbWithReg->setEnabled(false);
			}
			else if (com[0] == 'b')
			{
				QMessageBox msg;
				msg.setText("Account created! Connected");
				msg.exec();
				flagConnected = true;
				ui.tbMain->setEnabled(true);
				ui.tbMess->setEnabled(true);
				ui.sendButt->setEnabled(true);
				ui.leIP->setEnabled(false);
				ui.leLogin->setEnabled(false);
				ui.lePassword->setEnabled(false);
				ui.lePort->setEnabled(false);
				ui.connectButt->setEnabled(false);
				//ui.rbWithoutReg->setEnabled(false);
				//ui.rbWithReg->setEnabled(false);
			}
			else if (com[0] == 'c')
			{
				QMessageBox msg;
				msg.setText("Incorrected login or password!");
				msg.exec();
			}
			else if (com[0] == 'd')
			{
				//QMessageBox msg;
				QMessageBox msg;
				msg.setText("Connected!");
				msg.exec();
				flagConnected = true;
				ui.tbMain->setEnabled(true);
				ui.tbMess->setEnabled(true);
				ui.sendButt->setEnabled(true);
				ui.leIP->setEnabled(false);
				ui.leLogin->setEnabled(false);
				ui.lePassword->setEnabled(false);
				ui.lePort->setEnabled(false);
				ui.connectButt->setEnabled(false);
				/*msg.setText("User with this name already exists!");
				msg.exec();*/
			}
		}
}