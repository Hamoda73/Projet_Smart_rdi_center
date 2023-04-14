#ifndef MEDICAMENT_H
#define MEDICAMENT_H
#include <string>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QZXing.h>

class medicament
{
    int id,dosage,cab;
    QString nom_c,dci,date_s,date_d;
public:
    medicament();
    medicament(int id,QString nom_c,QString dci,int dosage,QString date_s,QString date_d);

    //Getters
    int getId(){return id;}
    QString getCommercial(){return nom_c;}
    QString getDci(){return dci;}
    int getDosage(){return dosage;}
    QString getDates(){return date_s;}
    QString getDated(){return date_d;}

    //Setters
    void setCommercial(int id){this->id=id;}
    void setDci(QString d){dci=d;}
    void setDosage(int g){dosage=g;}
    void setDates(QString s){date_s=s;}
    void setDated(QString e){date_d=e;}

    //Functions
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int id);
    bool modifier();
    bool ajouterCAB(int id,QString cab);
};

#endif // MEDICAMENT_H
