/********************************************************************************
** Form generated from reading UI file 'employes.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYES_H
#define UI_EMPLOYES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_employes
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QPushButton *pushButton_4;
    QPushButton *PDFButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLineEdit *lineEdit_8;
    QTableView *tab_emp;
    QLabel *label_8;
    QComboBox *comboBox;
    QPushButton *pb_tri;
    QWidget *tab_3;
    QGroupBox *groupBox_8;
    QGroupBox *groupBox_5;
    QLineEdit *messageTextEdit;
    QPushButton *pushButton_7;
    QLineEdit *phoneNumberLineEdit;
    QLabel *label_9;
    QLabel *label_19;
    QLineEdit *le_nom_4;
    QLabel *label_12;
    QWidget *tab_2;
    QGroupBox *groupBox_3;
    QLineEdit *le_nom;
    QLabel *label_2;
    QLineEdit *le_prenom;
    QLineEdit *le_cin;
    QLabel *label_3;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *le_tel;
    QLineEdit *le_email;
    QLineEdit *le_pwd;
    QGroupBox *groupBox_2;
    QLineEdit *le_role;
    QPushButton *pb_ajouter;
    QGroupBox *groupBox_11;
    QLineEdit *le_role_2;
    QPushButton *pb_ajouter_2;
    QLabel *label;
    QWidget *tab_4;
    QGroupBox *groupBox_7;
    QLineEdit *les_cin;
    QLabel *label_13;
    QPushButton *pb_supprimer;
    QGroupBox *groupBox_6;
    QLineEdit *lineEdit_2;
    QWidget *tab_5;
    QGroupBox *groupBox_9;
    QGroupBox *groupBox_10;
    QPushButton *pb_modifier;
    QLabel *label_10;
    QLineEdit *le_nom_2;
    QLabel *label_11;
    QLineEdit *le_prenom_2;
    QLabel *label_14;
    QLineEdit *le_cin_2;
    QLabel *label_15;
    QLineEdit *le_tel_2;
    QLabel *label_16;
    QLineEdit *le_email_2;
    QLabel *label_17;
    QLineEdit *le_pwd_2;
    QLabel *label_18;
    QLineEdit *le_role_3;

    void setupUi(QWidget *employes)
    {
        if (employes->objectName().isEmpty())
            employes->setObjectName("employes");
        employes->resize(948, 648);
        employes->setStyleSheet(QString::fromUtf8(""));
        tabWidget = new QTabWidget(employes);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 951, 601));
        tabWidget->setStyleSheet(QString::fromUtf8("#ajouter{background-image: url(:/img/rsz_333650138_1407283670085581_4559768689364842168_n.jpg);}\n"
"#tab{background-image: url(:/img/rsz_333650138_1407283670085581_4559768689364842168_n.jpg);}\n"
""));
        tab = new QWidget();
        tab->setObjectName("tab");
        tab->setStyleSheet(QString::fromUtf8(""));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 0, 941, 591));
        groupBox->setStyleSheet(QString::fromUtf8("#groupBox{background-image: url(:/img/rsz back2.jpg);}\n"
"\n"
""));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(140, 400, 75, 24));
        pushButton_4->setStyleSheet(QString::fromUtf8("*{\n"
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
"	background-image: url(:/img/white.jpg);\n"
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
        PDFButton = new QPushButton(groupBox);
        PDFButton->setObjectName("PDFButton");
        PDFButton->setGeometry(QRect(450, 400, 75, 24));
        PDFButton->setStyleSheet(QString::fromUtf8("*{\n"
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
"	background-image: url(:/img/white.jpg);\n"
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
        scrollArea = new QScrollArea(groupBox);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 90, 921, 311));
        scrollArea->setStyleSheet(QString::fromUtf8("background-image: url(:/img/333535462_722083709369591_6432692376230598368_n.png);\n"
"border-radius:10px;\n"
"background:#023020;"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 921, 311));
        lineEdit_8 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(150, 10, 661, 22));
        lineEdit_8->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        tab_emp = new QTableView(scrollAreaWidgetContents);
        tab_emp->setObjectName("tab_emp");
        tab_emp->setGeometry(QRect(140, 50, 701, 241));
        tab_emp->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        scrollArea->setWidget(scrollAreaWidgetContents);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(230, 400, 51, 16));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        comboBox = new QComboBox(groupBox);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(280, 400, 69, 21));
        comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pb_tri = new QPushButton(groupBox);
        pb_tri->setObjectName("pb_tri");
        pb_tri->setGeometry(QRect(370, 400, 61, 24));
        pb_tri->setStyleSheet(QString::fromUtf8("*{\n"
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
"	background-image: url(:/img/white.jpg);\n"
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
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        groupBox_8 = new QGroupBox(tab_3);
        groupBox_8->setObjectName("groupBox_8");
        groupBox_8->setGeometry(QRect(0, 0, 941, 581));
        groupBox_8->setStyleSheet(QString::fromUtf8("#groupBox_8{background-image: url(:/img/rsz back2.jpg);}\n"
""));
        groupBox_5 = new QGroupBox(groupBox_8);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(320, 170, 591, 211));
        groupBox_5->setStyleSheet(QString::fromUtf8("\n"
"#groupBox_5{background-image: url(:/img/269692057_1624625321227485_6672185886649751140_n.jpg);\n"
"border-radius:10px;}\n"
""));
        messageTextEdit = new QLineEdit(groupBox_5);
        messageTextEdit->setObjectName("messageTextEdit");
        messageTextEdit->setGeometry(QRect(20, 20, 551, 141));
        pushButton_7 = new QPushButton(groupBox_5);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(260, 170, 75, 24));
        pushButton_7->setStyleSheet(QString::fromUtf8("*{\n"
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
"	background-image: url(:/img/white.jpg);\n"
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
        phoneNumberLineEdit = new QLineEdit(groupBox_8);
        phoneNumberLineEdit->setObjectName("phoneNumberLineEdit");
        phoneNumberLineEdit->setGeometry(QRect(10, 190, 251, 22));
        phoneNumberLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"background:transparent;\n"
"border:none;\n"
"border-bottom:1px solid #7CFC00;\n"
"font-size:20px;\n"
"color:white"));
        label_9 = new QLabel(groupBox_8);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 170, 141, 16));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_19 = new QLabel(groupBox_8);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(10, 230, 141, 16));
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        le_nom_4 = new QLineEdit(groupBox_8);
        le_nom_4->setObjectName("le_nom_4");
        le_nom_4->setGeometry(QRect(10, 250, 251, 22));
        le_nom_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"background:transparent;\n"
"border:none;\n"
"border-bottom:1px solid #7CFC00;\n"
"font-size:20px;\n"
"color:white"));
        label_12 = new QLabel(groupBox_8);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(510, 100, 141, 51));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 24pt \"Segoe UI\";"));
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(0, 0, 971, 601));
        groupBox_3->setStyleSheet(QString::fromUtf8("#groupBox_3{background-image: url(:/img/rsz back2.jpg);}\n"
""));
        le_nom = new QLineEdit(groupBox_3);
        le_nom->setObjectName("le_nom");
        le_nom->setGeometry(QRect(320, 120, 251, 22));
        le_nom->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"background:transparent;\n"
"border:none;\n"
"border-bottom:1px solid #7CFC00;\n"
"font-size:20px;\n"
"color:white"));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(320, 150, 61, 16));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        le_prenom = new QLineEdit(groupBox_3);
        le_prenom->setObjectName("le_prenom");
        le_prenom->setGeometry(QRect(320, 170, 251, 22));
        le_prenom->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"background:transparent;\n"
"border:none;\n"
"border-bottom:1px solid #7CFC00;\n"
"font-size:20px;\n"
"color:white"));
        le_cin = new QLineEdit(groupBox_3);
        le_cin->setObjectName("le_cin");
        le_cin->setGeometry(QRect(320, 220, 251, 22));
        le_cin->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"background:transparent;\n"
"border:none;\n"
"border-bottom:1px solid #7CFC00;\n"
"font-size:20px;\n"
"color:white"));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(320, 200, 49, 16));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_2 = new QPushButton(groupBox_3);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(500, 450, 75, 24));
        pushButton_2->setStyleSheet(QString::fromUtf8("*{\n"
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
"	background-image: url(:/img/white.jpg);\n"
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
"background:#ff0000;\n"
"}"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(320, 250, 49, 16));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(320, 300, 49, 16));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(320, 350, 91, 16));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(320, 400, 49, 16));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        le_tel = new QLineEdit(groupBox_3);
        le_tel->setObjectName("le_tel");
        le_tel->setGeometry(QRect(320, 270, 251, 22));
        le_tel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"background:transparent;\n"
"border:none;\n"
"border-bottom:1px solid #7CFC00;\n"
"font-size:20px;\n"
"color:white"));
        le_email = new QLineEdit(groupBox_3);
        le_email->setObjectName("le_email");
        le_email->setGeometry(QRect(320, 320, 251, 22));
        le_email->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"background:transparent;\n"
"border:none;\n"
"border-bottom:1px solid #7CFC00;\n"
"font-size:20px;\n"
"color:white"));
        le_pwd = new QLineEdit(groupBox_3);
        le_pwd->setObjectName("le_pwd");
        le_pwd->setGeometry(QRect(320, 370, 251, 22));
        le_pwd->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"background:transparent;\n"
"border:none;\n"
"border-bottom:1px solid #7CFC00;\n"
"font-size:20px;\n"
"color:white"));
        groupBox_2 = new QGroupBox(groupBox_3);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(280, 90, 341, 401));
        groupBox_2->setStyleSheet(QString::fromUtf8("background:transparent;\n"
""));
        le_role = new QLineEdit(groupBox_2);
        le_role->setObjectName("le_role");
        le_role->setGeometry(QRect(40, 330, 251, 22));
        le_role->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"background:transparent;\n"
"border:none;\n"
"border-bottom:1px solid #7CFC00;\n"
"font-size:20px;\n"
"color:white"));
        pb_ajouter = new QPushButton(groupBox_2);
        pb_ajouter->setObjectName("pb_ajouter");
        pb_ajouter->setGeometry(QRect(40, 360, 75, 24));
        pb_ajouter->setStyleSheet(QString::fromUtf8("*{\n"
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
"	background-image: url(:/img/white.jpg);\n"
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
        groupBox_11 = new QGroupBox(groupBox_2);
        groupBox_11->setObjectName("groupBox_11");
        groupBox_11->setGeometry(QRect(0, 0, 341, 401));
        groupBox_11->setStyleSheet(QString::fromUtf8("background:transparent;\n"
""));
        le_role_2 = new QLineEdit(groupBox_11);
        le_role_2->setObjectName("le_role_2");
        le_role_2->setGeometry(QRect(40, 330, 251, 22));
        le_role_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"background:transparent;\n"
"border:none;\n"
"border-bottom:1px solid #7CFC00;\n"
"font-size:20px;\n"
"color:white"));
        pb_ajouter_2 = new QPushButton(groupBox_11);
        pb_ajouter_2->setObjectName("pb_ajouter_2");
        pb_ajouter_2->setGeometry(QRect(40, 360, 75, 24));
        pb_ajouter_2->setStyleSheet(QString::fromUtf8("*{\n"
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
"	background-image: url(:/img/white.jpg);\n"
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
        label = new QLabel(groupBox_11);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 10, 49, 16));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        groupBox_11->raise();
        le_role->raise();
        pb_ajouter->raise();
        groupBox_2->raise();
        le_prenom->raise();
        le_nom->raise();
        label_2->raise();
        le_cin->raise();
        label_3->raise();
        pushButton_2->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        le_tel->raise();
        le_email->raise();
        le_pwd->raise();
        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        groupBox_7 = new QGroupBox(tab_4);
        groupBox_7->setObjectName("groupBox_7");
        groupBox_7->setGeometry(QRect(0, 0, 941, 581));
        groupBox_7->setStyleSheet(QString::fromUtf8("#groupBox_7{background-image: url(:/img/rsz back2.jpg);}\n"
""));
        les_cin = new QLineEdit(groupBox_7);
        les_cin->setObjectName("les_cin");
        les_cin->setGeometry(QRect(350, 260, 221, 22));
        les_cin->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"background:transparent;\n"
"border:none;\n"
"border-bottom:1px solid #7CFC00;\n"
"font-size:20px;\n"
"color:white"));
        label_13 = new QLabel(groupBox_7);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(350, 230, 141, 16));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pb_supprimer = new QPushButton(groupBox_7);
        pb_supprimer->setObjectName("pb_supprimer");
        pb_supprimer->setGeometry(QRect(350, 310, 75, 24));
        pb_supprimer->setStyleSheet(QString::fromUtf8("*{\n"
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
"	background-image: url(:/img/white.jpg);\n"
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
"background:#ff0000;\n"
"}"));
        groupBox_6 = new QGroupBox(groupBox_7);
        groupBox_6->setObjectName("groupBox_6");
        groupBox_6->setGeometry(QRect(310, 189, 311, 171));
        lineEdit_2 = new QLineEdit(groupBox_7);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(310, 160, 311, 31));
        lineEdit_2->setStyleSheet(QString::fromUtf8("font-size:15px;\n"
"background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        groupBox_6->raise();
        les_cin->raise();
        label_13->raise();
        pb_supprimer->raise();
        lineEdit_2->raise();
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        groupBox_9 = new QGroupBox(tab_5);
        groupBox_9->setObjectName("groupBox_9");
        groupBox_9->setGeometry(QRect(0, 0, 941, 591));
        groupBox_9->setStyleSheet(QString::fromUtf8("#groupBox_9{background-image: url(:/img/rsz back2.jpg);}\n"
"\n"
""));
        groupBox_10 = new QGroupBox(groupBox_9);
        groupBox_10->setObjectName("groupBox_10");
        groupBox_10->setGeometry(QRect(290, 90, 341, 401));
        groupBox_10->setStyleSheet(QString::fromUtf8("background:transparent;\n"
""));
        pb_modifier = new QPushButton(groupBox_10);
        pb_modifier->setObjectName("pb_modifier");
        pb_modifier->setGeometry(QRect(130, 370, 75, 24));
        pb_modifier->setStyleSheet(QString::fromUtf8("*{\n"
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
"	background-image: url(:/img/white.jpg);\n"
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
        label_10 = new QLabel(groupBox_10);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(40, 20, 49, 16));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        le_nom_2 = new QLineEdit(groupBox_10);
        le_nom_2->setObjectName("le_nom_2");
        le_nom_2->setGeometry(QRect(40, 40, 251, 22));
        le_nom_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"background:transparent;\n"
"border:none;\n"
"border-bottom:1px solid #7CFC00;\n"
"font-size:20px;\n"
"color:white"));
        label_11 = new QLabel(groupBox_10);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(40, 70, 61, 16));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        le_prenom_2 = new QLineEdit(groupBox_10);
        le_prenom_2->setObjectName("le_prenom_2");
        le_prenom_2->setGeometry(QRect(40, 90, 251, 22));
        le_prenom_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"background:transparent;\n"
"border:none;\n"
"border-bottom:1px solid #7CFC00;\n"
"font-size:20px;\n"
"color:white"));
        label_14 = new QLabel(groupBox_10);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(40, 120, 49, 16));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        le_cin_2 = new QLineEdit(groupBox_10);
        le_cin_2->setObjectName("le_cin_2");
        le_cin_2->setGeometry(QRect(40, 140, 251, 22));
        le_cin_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"background:transparent;\n"
"border:none;\n"
"border-bottom:1px solid #7CFC00;\n"
"font-size:20px;\n"
"color:white"));
        label_15 = new QLabel(groupBox_10);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(40, 170, 49, 16));
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        le_tel_2 = new QLineEdit(groupBox_10);
        le_tel_2->setObjectName("le_tel_2");
        le_tel_2->setGeometry(QRect(40, 190, 251, 22));
        le_tel_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"background:transparent;\n"
"border:none;\n"
"border-bottom:1px solid #7CFC00;\n"
"font-size:20px;\n"
"color:white"));
        label_16 = new QLabel(groupBox_10);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(40, 220, 49, 16));
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        le_email_2 = new QLineEdit(groupBox_10);
        le_email_2->setObjectName("le_email_2");
        le_email_2->setGeometry(QRect(40, 240, 251, 22));
        le_email_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"background:transparent;\n"
"border:none;\n"
"border-bottom:1px solid #7CFC00;\n"
"font-size:20px;\n"
"color:white"));
        label_17 = new QLabel(groupBox_10);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(40, 270, 91, 16));
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        le_pwd_2 = new QLineEdit(groupBox_10);
        le_pwd_2->setObjectName("le_pwd_2");
        le_pwd_2->setGeometry(QRect(40, 290, 251, 22));
        le_pwd_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"background:transparent;\n"
"border:none;\n"
"border-bottom:1px solid #7CFC00;\n"
"font-size:20px;\n"
"color:white"));
        label_18 = new QLabel(groupBox_10);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(40, 320, 49, 16));
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        le_role_3 = new QLineEdit(groupBox_10);
        le_role_3->setObjectName("le_role_3");
        le_role_3->setGeometry(QRect(40, 340, 251, 22));
        le_role_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"background:transparent;\n"
"border:none;\n"
"border-bottom:1px solid #7CFC00;\n"
"font-size:20px;\n"
"color:white"));
        tabWidget->addTab(tab_5, QString());

        retranslateUi(employes);
        QObject::connect(pushButton_2, &QPushButton::clicked, le_role, qOverload<>(&QLineEdit::clear));
        QObject::connect(pushButton_2, &QPushButton::clicked, le_pwd, qOverload<>(&QLineEdit::clear));
        QObject::connect(pushButton_2, &QPushButton::clicked, le_email, qOverload<>(&QLineEdit::clear));
        QObject::connect(pushButton_2, &QPushButton::clicked, le_tel, qOverload<>(&QLineEdit::clear));
        QObject::connect(pushButton_2, &QPushButton::clicked, le_cin, qOverload<>(&QLineEdit::clear));
        QObject::connect(pushButton_2, &QPushButton::clicked, le_prenom, qOverload<>(&QLineEdit::clear));
        QObject::connect(pushButton_2, &QPushButton::clicked, le_nom, qOverload<>(&QLineEdit::clear));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(employes);
    } // setupUi

    void retranslateUi(QWidget *employes)
    {
        employes->setWindowTitle(QCoreApplication::translate("employes", "Form", nullptr));
        groupBox->setTitle(QString());
        pushButton_4->setText(QCoreApplication::translate("employes", "Stats", nullptr));
        PDFButton->setText(QCoreApplication::translate("employes", "PDF", nullptr));
        lineEdit_8->setPlaceholderText(QCoreApplication::translate("employes", "saisir CIN d'employe", nullptr));
        label_8->setText(QCoreApplication::translate("employes", "Trier par", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("employes", "nom", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("employes", "cin", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("employes", "email", nullptr));

        pb_tri->setText(QCoreApplication::translate("employes", "trier", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("employes", "Acceuil", nullptr));
        groupBox_8->setTitle(QString());
        groupBox_5->setTitle(QString());
        messageTextEdit->setPlaceholderText(QCoreApplication::translate("employes", "Saisir votre message", nullptr));
        pushButton_7->setText(QCoreApplication::translate("employes", "Envoyer", nullptr));
        phoneNumberLineEdit->setText(QString());
        phoneNumberLineEdit->setPlaceholderText(QCoreApplication::translate("employes", "foulen", nullptr));
        label_9->setText(QCoreApplication::translate("employes", "To :", nullptr));
        label_19->setText(QCoreApplication::translate("employes", "From", nullptr));
        le_nom_4->setText(QString());
        le_nom_4->setPlaceholderText(QCoreApplication::translate("employes", "foulen", nullptr));
        label_12->setText(QCoreApplication::translate("employes", "Body", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("employes", "SMS", nullptr));
        groupBox_3->setTitle(QString());
        le_nom->setText(QString());
        le_nom->setPlaceholderText(QCoreApplication::translate("employes", "foulen", nullptr));
        label_2->setText(QCoreApplication::translate("employes", "Nom", nullptr));
        le_prenom->setPlaceholderText(QCoreApplication::translate("employes", "foulen", nullptr));
        le_cin->setPlaceholderText(QCoreApplication::translate("employes", "00000000", nullptr));
        label_3->setText(QCoreApplication::translate("employes", "CIN", nullptr));
        pushButton_2->setText(QCoreApplication::translate("employes", "CLEAR", nullptr));
        label_4->setText(QCoreApplication::translate("employes", "Tel Num", nullptr));
        label_5->setText(QCoreApplication::translate("employes", "Email", nullptr));
        label_6->setText(QCoreApplication::translate("employes", "Mot de passe", nullptr));
        label_7->setText(QCoreApplication::translate("employes", "Role", nullptr));
        le_tel->setPlaceholderText(QCoreApplication::translate("employes", "11111111", nullptr));
        le_email->setPlaceholderText(QCoreApplication::translate("employes", "Exemple@exemp.com", nullptr));
        le_pwd->setPlaceholderText(QCoreApplication::translate("employes", "xxxxxxxx", nullptr));
        groupBox_2->setTitle(QString());
        le_role->setPlaceholderText(QCoreApplication::translate("employes", "xxxxxxxx", nullptr));
        pb_ajouter->setText(QCoreApplication::translate("employes", "Ajouter", nullptr));
        groupBox_11->setTitle(QString());
        le_role_2->setPlaceholderText(QCoreApplication::translate("employes", "xxxxxxxx", nullptr));
        pb_ajouter_2->setText(QCoreApplication::translate("employes", "ADD", nullptr));
        label->setText(QCoreApplication::translate("employes", "Prenom", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("employes", "Ajouter", nullptr));
        groupBox_7->setTitle(QString());
        les_cin->setPlaceholderText(QCoreApplication::translate("employes", "00000000", nullptr));
        label_13->setText(QCoreApplication::translate("employes", "Saisir Cin:", nullptr));
        pb_supprimer->setText(QCoreApplication::translate("employes", "Supprimer", nullptr));
        groupBox_6->setTitle(QString());
        lineEdit_2->setText(QCoreApplication::translate("employes", "                               Supprimer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("employes", "Supprimer", nullptr));
        groupBox_9->setTitle(QString());
        groupBox_10->setTitle(QString());
        pb_modifier->setText(QCoreApplication::translate("employes", "Modifier", nullptr));
        label_10->setText(QCoreApplication::translate("employes", "Prenom", nullptr));
        le_nom_2->setPlaceholderText(QCoreApplication::translate("employes", "foulen", nullptr));
        label_11->setText(QCoreApplication::translate("employes", "Nom", nullptr));
        le_prenom_2->setPlaceholderText(QCoreApplication::translate("employes", "foulen", nullptr));
        label_14->setText(QCoreApplication::translate("employes", "CIN", nullptr));
        le_cin_2->setPlaceholderText(QCoreApplication::translate("employes", "00000000", nullptr));
        label_15->setText(QCoreApplication::translate("employes", "Tel Num", nullptr));
        le_tel_2->setPlaceholderText(QCoreApplication::translate("employes", "11111111", nullptr));
        label_16->setText(QCoreApplication::translate("employes", "Email", nullptr));
        le_email_2->setPlaceholderText(QCoreApplication::translate("employes", "Exemple@exemp.com", nullptr));
        label_17->setText(QCoreApplication::translate("employes", "Mot de passe", nullptr));
        le_pwd_2->setPlaceholderText(QCoreApplication::translate("employes", "xxxxxxxx", nullptr));
        label_18->setText(QCoreApplication::translate("employes", "Role", nullptr));
        le_role_3->setPlaceholderText(QCoreApplication::translate("employes", "xxxxxxxx", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("employes", "modifier", nullptr));
    } // retranslateUi

};

namespace Ui {
    class employes: public Ui_employes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYES_H
