/********************************************************************************
** Form generated from reading UI file 'QtChat.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTCHAT_H
#define UI_QTCHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtChatClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lePassword;
    QLineEdit *leIP;
    QLabel *label_4;
    QLineEdit *lePort;
    QTextEdit *tbMain;
    QPushButton *connectButt;
    QLineEdit *leLogin;
    QLabel *label_3;
    QTextEdit *tbMess;
    QPushButton *sendButt;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtChatClass)
    {
        if (QtChatClass->objectName().isEmpty())
            QtChatClass->setObjectName(QString::fromUtf8("QtChatClass"));
        QtChatClass->resize(600, 400);
        centralWidget = new QWidget(QtChatClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(430, 0, 47, 13));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(430, 50, 47, 13));
        lePassword = new QLineEdit(centralWidget);
        lePassword->setObjectName(QString::fromUtf8("lePassword"));
        lePassword->setGeometry(QRect(430, 70, 161, 20));
        leIP = new QLineEdit(centralWidget);
        leIP->setObjectName(QString::fromUtf8("leIP"));
        leIP->setGeometry(QRect(430, 120, 161, 20));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(430, 150, 81, 16));
        lePort = new QLineEdit(centralWidget);
        lePort->setObjectName(QString::fromUtf8("lePort"));
        lePort->setGeometry(QRect(430, 170, 161, 20));
        tbMain = new QTextEdit(centralWidget);
        tbMain->setObjectName(QString::fromUtf8("tbMain"));
        tbMain->setEnabled(false);
        tbMain->setGeometry(QRect(10, 0, 411, 281));
        tbMain->setReadOnly(true);
        tbMain->setTabStopWidth(200);
        tbMain->setTabStopDistance(200.000000000000000);
        tbMain->setCursorWidth(0);
        connectButt = new QPushButton(centralWidget);
        connectButt->setObjectName(QString::fromUtf8("connectButt"));
        connectButt->setGeometry(QRect(430, 200, 161, 23));
        leLogin = new QLineEdit(centralWidget);
        leLogin->setObjectName(QString::fromUtf8("leLogin"));
        leLogin->setGeometry(QRect(430, 20, 161, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(430, 100, 61, 16));
        tbMess = new QTextEdit(centralWidget);
        tbMess->setObjectName(QString::fromUtf8("tbMess"));
        tbMess->setEnabled(false);
        tbMess->setGeometry(QRect(10, 290, 411, 41));
        sendButt = new QPushButton(centralWidget);
        sendButt->setObjectName(QString::fromUtf8("sendButt"));
        sendButt->setEnabled(false);
        sendButt->setGeometry(QRect(430, 290, 161, 41));
        QtChatClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtChatClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        QtChatClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtChatClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtChatClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtChatClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtChatClass->setStatusBar(statusBar);

        retranslateUi(QtChatClass);

        QMetaObject::connectSlotsByName(QtChatClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtChatClass)
    {
        QtChatClass->setWindowTitle(QApplication::translate("QtChatClass", "QtChat", nullptr));
        label->setText(QApplication::translate("QtChatClass", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        label_2->setText(QApplication::translate("QtChatClass", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        leIP->setText(QApplication::translate("QtChatClass", "127.0.0.1", nullptr));
        label_4->setText(QApplication::translate("QtChatClass", "\320\237\320\276\321\200\321\202 \321\201\320\265\321\200\320\262\320\265\321\200\320\260:", nullptr));
        lePort->setText(QApplication::translate("QtChatClass", "1213", nullptr));
        connectButt->setText(QApplication::translate("QtChatClass", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265", nullptr));
        label_3->setText(QApplication::translate("QtChatClass", "IP \321\201\320\265\321\200\320\262\320\265\321\200\320\260:", nullptr));
        sendButt->setText(QApplication::translate("QtChatClass", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtChatClass: public Ui_QtChatClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTCHAT_H
