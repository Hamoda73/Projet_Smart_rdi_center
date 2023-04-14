#include "ui_stage.h"
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QDate>

stage::stage()
{

}

stage::stage(int id_s, QString nom, QDate date_d, QDate date_f, int nbr_place, QString type)
{
    this->Id_S = id_s;
    this->Nom = nom;
    this->Date_d = date_d;
    this->Date_f = date_f;
    this->Nbr_place = nbr_place;
    this->Type = type;
}

bool stage::ajouter()
{
    // Create a query to insert the data
    QSqlQuery query;
    QString res = QString::number(Id_S);
    query.prepare("INSERT INTO stages (ID_S, NOM, DATE_D, DATE_FIN, NBR_PLACE,TYPE) VALUES (:id, :nom, :date_d, :date_f, :nbr_place, :type)");
    query.bindValue(":id",res);
    query.bindValue(":nom",Nom);
    query.bindValue(":date_d",Date_d);
    query.bindValue(":date_f",Date_f);
    query.bindValue(":nbr_place",Nbr_place);
    query.bindValue(":type",Type);

    // Execute the query and return the result
    return query.exec();
}
