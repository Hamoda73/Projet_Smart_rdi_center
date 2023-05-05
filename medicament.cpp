#include "medicament.h"
#include <QObject>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QLabel>

medicament::medicament()
{
    id_med=0;
    nom_c=" ";
    dci=" ";
    dosage=0;
    date_s=" ";
    date_d=" ";
}

medicament::medicament(int id_med,QString nom_c,QString dci,int dosage,QString date_s,QString date_d)
{
    this->id_med=id_med;
    this->nom_c=nom_c;
    this->dci=dci;
    this->dosage=dosage;
    this->date_s=date_s;
    this->date_d=date_d;
}

bool medicament::ajouter()
{
    QSqlQuery query;

    QString res = QString::number(id_med);

    query.prepare("insert into meds (id_med,nom_c,dci,dosage,date_s,date_d)" "values (:id_med, :nom_c, :dci, :dosage, :date_s, :date_d)");

    query.bindValue(":id_med",res);
    query.bindValue(":nom_c",nom_c);
    query.bindValue(":dci",dci);
    query.bindValue(":dosage",dosage);
    query.bindValue(":date_s",date_s);
    query.bindValue(":date_d",date_d);

    return query.exec();
}

bool medicament::supprimer(int id_med)
{
    QSqlQuery query;
    QString res=QString::number(id_med);

    query.prepare("delete from meds where id_med= :id_med");
    query.bindValue(":id_med",res);

    return query.exec();
}

QSqlQueryModel * medicament::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from  meds");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom du produit"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Nom DCI"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("dosage"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date de sortie"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Date d'expiration"));

    return model;
}

bool medicament::modifier()
{
    QSqlQuery query;

        QString res = QString::number(id_med);

        QStringList updates;

        if (!nom_c.isEmpty())
            updates << "nom_c=:nom_c";

        if (!dci.isEmpty())
            updates << "dci=:dci";

        if (dosage > 0)
            updates << "dosage=:dosage";

        if (!date_s.isEmpty())
            updates << "date_s=:date_s";

        if (!date_d.isEmpty())
            updates << "date_d=:date_d";

        QString update_query = "UPDATE meds SET " + updates.join(", ") + " WHERE id_med=:id_med";

        query.prepare(update_query);

        query.bindValue(":id_med", res);

        if (!nom_c.isEmpty())
            query.bindValue(":nom_c", nom_c);

        if (!dci.isEmpty())
            query.bindValue(":dci", dci);

        if (dosage > 0)
            query.bindValue(":dosage", dosage);

        if (!date_s.isEmpty())
            query.bindValue(":date_s", date_s);

        if (!date_d.isEmpty())
            query.bindValue(":date_d", date_d);

        return query.exec();
}
bool medicament::ajouterCAB(int id_med,QString cab)
{
        QSqlQuery query;
        QString res=QString::number(id_med);
        QStringList updates;

        if (!cab.isEmpty())
            updates << "cab=:cab";

        QString update_query = "UPDATE meds SET " + updates.join(", ") + " WHERE id_med=:id_med";

        query.prepare(update_query);

        query.bindValue(":id_med", res);

        if (!cab.isEmpty())
            query.bindValue(":cab", cab);


        return query.exec();
}

bool medicament::ModifierStatus(int id_med)
{
        QSqlQuery query;
        QString res=QString::number(id_med);
        QStringList updates;
        QTime currentTime = QTime::currentTime();
        QString hdp =  currentTime.toString("hh:mm");

        if (!hdp.isEmpty())
            updates << "hdp=:hdp";

        QString update_query = "UPDATE meds SET " + updates.join(", ") + " WHERE id_med=:id_med";

        query.prepare(update_query);

        query.bindValue(":id_med", res);

        if (!hdp.isEmpty())
            query.bindValue(":hdp", hdp);

        return query.exec();
}

bool medicament::QtArduino(int id_med)
{
        QSqlQuery query;
        int nbj=0;
        QString res=QString::number(id_med);
        QStringList updates;
        QTime currentTime = QTime::currentTime();
        QString hds =  currentTime.toString("hh:mm");

        if (!hds.isEmpty()){
            updates << "hds=:hds";
            nbj=nbj+1;
            query.prepare("UPDATE medicament SET nbj = :nbj");
            query.bindValue(":nbj", nbj);
        }

        if (nbj > 0)
            updates << "nbj=:nbj";

        QString update_query = "UPDATE medicament SET " + updates.join(", ") + " WHERE id_med=:id_med";

        query.prepare(update_query);

        query.bindValue(":id_med", res);

        if (!hds.isEmpty())
            query.bindValue(":hds", hds);

        if (nbj > 0)
            query.bindValue(":nbj", nbj);

        return query.exec();
}
