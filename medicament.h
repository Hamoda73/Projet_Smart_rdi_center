#ifndef MEDICAMENT_H
#define MEDICAMENT_H
#include <string>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QZXing.h>
#include <QDate>
#include <QtSql>
#include <qtableview.h>

class medicament
{
    int id_med,dosage,cab;
    QString nom_c,dci,date_s,date_d,hdp;
public:
    medicament();
    medicament(int id_med,QString nom_c,QString dci,int dosage,QString date_s,QString date_d);

    //Getters
    int getId(){return id_med;}
    QString getCommercial(){return nom_c;}
    QString getDci(){return dci;}
    int getDosage(){return dosage;}
    QString getDates(){return date_s;}
    QString getDated(){return date_d;}
    QString gethdp(){return hdp;}

    //Setters
    void setCommercial(int id_med){this->id_med=id_med;}
    void setDci(QString d){dci=d;}
    void setDosage(int g){dosage=g;}
    void setDates(QString s){date_s=s;}
    void setDated(QString e){date_d=e;}
    void sethdp(QString t){hdp=t;}

    //Functions
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int id_med);
    bool modifier();
    bool ajouterCAB(int id_med,QString cab);
    bool ModifierStatus(int id_med);
    bool QtArduino(int id_med);

};

#endif // MEDICAMENT_H
