#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <employes.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_Regbut_clicked()
{
    QString username=ui->Username_le->text();
    QString password=ui->password_le->text();
    QSqlQuery query;
         query.prepare("INSERT INTO LOGIN (USERNAME,PASSWORD)"
                       "VALUES ( :username,:password)");
         query.bindValue(":username", username);
         query.bindValue(":password", password);
        if( query.exec())
        {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                        QObject::tr("ajout effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("Ajout non effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }


}


void MainWindow::on_pushbutton_2_clicked()
{
    QString username = ui->lineEdit_6->text();
    QString password = ui->lineEdit_7->text();

    /*QSqlQuery query;
    query.prepare(QString ("SELECT * FROM  LOGIN WHERE USERNAME=:USERNAME AND PASSWORD=:PASSWORD"));
                  query.bindValue(":username",username);
                  query.bindValue(":password",password);

                  QString usernamefromDB = query.value(0).toString();
                  QString passwordfromDB = query.value(1).toString();

    if ( usernamefromDB == username &&  passwordfromDB ==password) {
        QMessageBox::information(this, "Login", "Login successful!");
        employes *employes= new class employes;
        employes->show();
        this->hide();

        // open the main application window or do any other actions required

    }
    else {
        QMessageBox::warning(this, "Login", "Invalid username or password.");

    }*/



        QSqlQuery query;
        query.prepare("SELECT password FROM login WHERE username = ?");
        query.addBindValue(username);
        query.exec();

        if (query.next()) {
            QString dbPassword = query.value(0).toString();
            if (password == dbPassword) {
                QMessageBox::information(this, "Login", "Login successful!");
                employes *employes= new class employes;
                employes->show();
                this->hide();
            } else {
                QMessageBox::warning(this, "Login failed", "Incorrect username or password.");
            }
        } else {
            QMessageBox::warning(this, "Login failed", "Incorrect username or password.");
        }



}

