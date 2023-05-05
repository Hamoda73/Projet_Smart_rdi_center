#ifndef STAGE_H
#define STAGE_H

#include <QDialog>
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include<QDate>
#include <QMessageBox>
#include <QtSql/QSqlError>

namespace Ui {
class stage;
}

class stage : public QDialog
{
    Q_OBJECT

public:
    explicit stage(QWidget *parent = nullptr);
    ~stage();
    stage(int,QString,QDate,QDate,int,QString);
    ///Getters//
    int getId_S(){ return ID_S; }
    QString getNom(){ return NOM; }
    QDate getDate_d(){ return DATE_D; }
    QDate getDate_f(){ return DATE_FIN; }
    int getNbr_place(){ return NBR_PLACE; }
    QString getType(){ return TYPE; }
    ///Setters//
    void setId_S(int id) { ID_S = id; }
    void setNom(const QString& nom) { NOM = nom; }
    void setDate_d(const QDate& date) { DATE_D = date; }
    void setDate_f(const QDate& date) { DATE_FIN = date; }
    void setNbr_place(int nbr) {NBR_PLACE = nbr; }
    void setType(const QString& type) { TYPE = type; }
    //functions
    bool ajouter();
    QSqlQueryModel* afficher(QString sortColumn);
    bool supprimer(int ID_S);
    bool modifier();
    void displayInventoryColumnChart();




private:
    Ui::stage *ui;
    QSqlDatabase db;
    int ID_S;
    QString NOM;
    QDate DATE_D;
    QDate DATE_FIN;
    int NBR_PLACE;
    QString TYPE;
    QString location; // Add location attribute


};

#endif // STAGE_H
