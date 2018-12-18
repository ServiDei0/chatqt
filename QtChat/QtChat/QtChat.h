#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtChat.h"
#include <QTcpSocket>

class QtChat : public QMainWindow
{
	Q_OBJECT

public:
	QtChat(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtChatClass ui;
	QTcpSocket *socket;
	bool flagConnected = false;
	void sendStr(QString str);
	private slots:
	void on_btn_sendButt_clicked();
	void on_btn_connectButt_clicked();
	void readyRead();
};
