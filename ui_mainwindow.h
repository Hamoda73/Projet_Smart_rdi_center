/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QGroupBox *groupBox;
    QGroupBox *groupBox_3;
    QLabel *label_11;
    QLineEdit *lineEdit_6;
    QLabel *label_10;
    QLineEdit *lineEdit_7;
    QPushButton *pushbutton_2;
    QLabel *label;
    QPushButton *pushButton;
    QGroupBox *groupBox_4;
    QLabel *label_12;
    QLineEdit *Username_le;
    QLabel *label_13;
    QLineEdit *password_le;
    QPushButton *Regbut;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1202, 596);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, -10, 1201, 631));
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, -10, 1201, 591));
        groupBox->setStyleSheet(QString::fromUtf8("#groupBox{\n"
"background-image: url(:/img/rsz_backg_login.jpg);}"));
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(660, 160, 371, 311));
        groupBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        groupBox_3->setAlignment(Qt::AlignCenter);
        groupBox_3->setFlat(true);
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(40, 150, 151, 16));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit_6 = new QLineEdit(groupBox_3);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(40, 110, 251, 22));
        lineEdit_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"background:transparent;\n"
"border:none;\n"
"border-bottom:1px solid #000000;\n"
"font-size:15px;\n"
"color:black"));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(40, 90, 161, 16));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit_7 = new QLineEdit(groupBox_3);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(40, 170, 251, 22));
        lineEdit_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"background:transparent;\n"
"border:none;\n"
"border-bottom:1px solid #000000;\n"
"font-size:15px;\n"
"color:black\n"
""));
        pushbutton_2 = new QPushButton(groupBox_3);
        pushbutton_2->setObjectName("pushbutton_2");
        pushbutton_2->setGeometry(QRect(130, 250, 101, 31));
        pushbutton_2->setStyleSheet(QString::fromUtf8("*{\n"
" font-family:century gothic;\n"
"   font-size:14px;\n"
"}\n"
"\n"
"QFrame\n"
"{\n"
" 	 \n"
"}\n"
"QPushButton\n"
"{\n"
"\n"
"	\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(0, 170, 0);\n"
"}\n"
"QPushButton\n"
"{\n"
" border-radius:8px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color:rgb(255,255,255);\n"
" \n"
"border-radius:10px;\n"
"background:#3CB043;\n"
"}"));
        label = new QLabel(groupBox_3);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 40, 171, 31));
        label->setStyleSheet(QString::fromUtf8("*{\n"
" font-family:century gothic;\n"
"   font-size:20px;\n"
"}"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(810, 120, 61, 61));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius:30px;\n"
"background:white;}\n"
"QFrame{background:#333}\n"
"*{font-family:century gothic;\n"
"font-size:60px;}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/logingr.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(40, 50));
        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(180, 160, 371, 311));
        groupBox_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        groupBox_4->setAlignment(Qt::AlignCenter);
        groupBox_4->setFlat(true);
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(40, 150, 151, 16));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        Username_le = new QLineEdit(groupBox_4);
        Username_le->setObjectName("Username_le");
        Username_le->setGeometry(QRect(40, 110, 251, 22));
        Username_le->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"background:transparent;\n"
"border:none;\n"
"border-bottom:1px solid #000000;\n"
"font-size:15px;\n"
"color:black"));
        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(40, 90, 161, 16));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        password_le = new QLineEdit(groupBox_4);
        password_le->setObjectName("password_le");
        password_le->setGeometry(QRect(40, 170, 251, 22));
        password_le->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"background:transparent;\n"
"border:none;\n"
"border-bottom:1px solid #000000;\n"
"font-size:15px;\n"
"color:black\n"
""));
        Regbut = new QPushButton(groupBox_4);
        Regbut->setObjectName("Regbut");
        Regbut->setGeometry(QRect(130, 240, 101, 31));
        Regbut->setStyleSheet(QString::fromUtf8("*{\n"
" font-family:century gothic;\n"
"   font-size:14px;\n"
"}\n"
"\n"
"QFrame\n"
"{\n"
" 	 \n"
"}\n"
"QPushButton\n"
"{\n"
"\n"
"	\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(0, 170, 0);\n"
"}\n"
"QPushButton\n"
"{\n"
" border-radius:8px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color:rgb(255,255,255);\n"
" \n"
"border-radius:10px;\n"
"background:#3CB043;\n"
"}"));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(140, 40, 171, 31));
        label_2->setStyleSheet(QString::fromUtf8("*{\n"
" font-family:century gothic;\n"
"   font-size:20px;\n"
"}"));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1202, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        groupBox_3->setTitle(QString());
        label_11->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        lineEdit_6->setPlaceholderText(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        lineEdit_7->setPlaceholderText(QString());
        pushbutton_2->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Login Here", nullptr));
        pushButton->setText(QString());
        groupBox_4->setTitle(QString());
        label_12->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        Username_le->setPlaceholderText(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        password_le->setPlaceholderText(QString());
        Regbut->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
