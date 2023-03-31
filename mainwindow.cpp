/*
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "equipement.h"
#include <QMessageBox>
#include <QRegularExpressionValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0,9999999,this));
    ui->le_nom->setValidator( new QRegularExpressionValidator(QRegularExpression("[A-Za-z]+"), this));
    ui->le_nom->setMaxLength(12);
    ui->le_etat->setValidator( new QRegularExpressionValidator(QRegularExpression("[A-Za-z]+"), this));
    ui->le_etat->setMaxLength(12);

    ui->le_ids->setValidator(new QIntValidator(0,9999999,this));
    ui->le_nom_2->setValidator( new QRegularExpressionValidator(QRegularExpression("[A-Za-z]+"), this));
    ui->le_nom_2->setMaxLength(12);
    ui->le_etat_2->setValidator( new QRegularExpressionValidator(QRegularExpression("[A-Za-z]+"), this));
    ui->le_etat_2->setMaxLength(12);

    ui->tableView_2->setModel(Eqmp.afficher());


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_procceed_add_clicked()
{
    int id=ui->le_id->text().toInt();
    */
   /* int nombre= NULL /*ui->le_nbocc_2->text().toInt()*/;
   /* int Qr_code= NULL  /*ui->le_qr_2->text().toInt()*/;
 /*   int prix_achat=ui->le_prix->text().toInt();
    QString nom=ui->le_nom->text();
    QString etat=ui->le_etat->text();
    QString notes=ui->le_notes->text();

    Equipement E(id,nombre,Qr_code,prix_achat,nom,etat,notes);

    bool test=E.ajouter();
    if(test)
    {
        ui->tableView_2->setModel(Eqmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Ajout effectuée \n"
                                             "Click cancel to exit"),QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectuée \n"
                                          "Click cancel to exit "), QMessageBox::Cancel);
    }
}

void MainWindow::on_Delete_clicked()
{
    int id=ui->le_ids->text().toInt();
    bool test=Eqmp.supprimer(id);
    if(test)
    {
         ui->tableView_2->setModel(Eqmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Suppression effectuée \n"
                                             "Click cancel to exit"),QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                              QObject::tr("Suppression non effectuée \n"
                                          "Click cancel to exit "), QMessageBox::Cancel);
    }

}








void MainWindow::on_pushButton_17_clicked()
{
    int id=ui->le_ids->text().toInt();
    int nombre= NULL */ /*ui->le_nbocc_2->text().toInt()*/;
  /*  int Qr_code= NULL  /*ui->le_qr_2->text().toInt()*/;
 /*   int prix_achat=ui->le_prix_2->text().toInt();
    QString nom=ui->le_nom_2->text();
    QString etat=ui->le_etat_2->text();
    QString notes=ui->note_update->text();


    Equipement E(id,nombre,Qr_code,prix_achat,nom,etat,notes);

    bool test=E.modifier();
    if(test)
    {
        ui->tableView_2->setModel(Eqmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Update effectuée \n"
                                             "Click cancel to exit"),QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                              QObject::tr("Update non effectuée \n"
                                          "Click cancel to exit "), QMessageBox::Cancel);
    }
}
*/
