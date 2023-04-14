#ifndef UI_STAGE_H
#define UI_STAGE_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include<QDate>




class stage
{
public:
    stage();
    stage(int,QString,QDate,QDate,int,QString);
    ///Getters//
    int getId_S(){ return Id_S; }
    QString getNom(){ return Nom; }
    QDate getDate_d(){ return Date_d; }
    QDate getDate_f(){ return Date_f; }
    int getNbr_place(){ return Nbr_place; }
    QString getType(){ return Type; }
    ///Setters//
    void setId_S(int id) { Id_S = id; }
    void setNom(const QString& nom) { Nom = nom; }
    void setDate_d(const QDate& date) { Date_d = date; }
    void setDate_f(const QDate& date) { Date_f = date; }
    void setNbr_place(int nbr) { Nbr_place = nbr; }
    void setType(const QString& type) { Type = type; }
    //functions
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer();


private :
    int Id_S;
    QString Nom;
    QDate Date_d;
    QDate Date_f;
    int Nbr_place;
    QString Type;


};


#endif // UI_STAGE_H
