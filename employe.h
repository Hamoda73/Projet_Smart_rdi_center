#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QUrlQuery>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QApplication>
  #include <QNetworkReply>
class Employe
{
    QString nom,prenom,email,password,role,cin, numtel;
public:
    Employe();
    Employe(QString,QString,QString,QString,QString,QString,QString);
    //getters
    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    QString getCin(){return cin;}
    QString getEmail(){return email;}
    QString getPassword(){return password;}
    QString getRole(){return role;}
    QString getNumtel(){return numtel;}
    //setters
    void setNom(QString n){nom=n;}
    void setPrenom(QString p){prenom=p;}
    void setEmail(QString e){email=e;}
    void setPassword(QString p2){password=p2;}
    void setRole(QString r){role=r;}
    void setCin(QString c){cin=c;}
    void setNum(QString nu){numtel=nu;}
    //fonctionnalités
    bool ajouter ();
    QSqlQueryModel* afficher();
    bool supprimer (QString);
    bool modifier();
    QSqlQueryModel* affichercin();
    QSqlQueryModel* affichernom();
    QSqlQueryModel* afficheremail();


};

#endif // EMPLOYE_H
