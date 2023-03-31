#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include <QMessageBox>

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "qrcodegen.hpp"
#include <iostream>
#include <QSslSocket>
#include <QSslConfiguration>
#include <QTextStream>
#include <QByteArray>


using namespace std ;


class Equipement
{
public:
    int aux;
    Equipement();
    Equipement(int,int,QString,int,QString,QString,QString);


    int getid();
    int getnombre();
    QString getQRCode();
    int getprix_achat();

    QString getnom();
    QString getetat();

    void setid(int);
    void setnombre(int);

    void setprix_achat(int);
    void setnom(QString);
    void setetat(QString);



    bool ajouter();
    bool modifier();
    QSqlQueryModel* afficher();
    QSqlQueryModel * afficherasc();
    QSqlQueryModel * afficherdesc();
    QSqlQueryModel * affichertriprix();
    QSqlQueryModel * affichertriid();
    QSqlQueryModel * affichertrinombre();
    void getInventoryStats();
    void generateQRCode();



    bool supprimer(int);



private:
    int id,nombre,prix_achat;
    QString nom,Qr_code,etat,notes;
};

#endif // EQUIPEMENT_H
