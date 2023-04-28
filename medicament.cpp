#include "medicament.h"
#include <QObject>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QLabel>

medicament::medicament()
{
    id=0;
    nom_c=" ";
    dci=" ";
    dosage=0;
    date_s=" ";
    date_d=" ";
}

medicament::medicament(int id,QString nom_c,QString dci,int dosage,QString date_s,QString date_d)
{
    this->id=id;
    this->nom_c=nom_c;
    this->dci=dci;
    this->dosage=dosage;
    this->date_s=date_s;
    this->date_d=date_d;
}

bool medicament::ajouter()
{
    QSqlQuery query;

    QString res = QString::number(id);

    query.prepare("insert into medicament (id,nom_c,dci,dosage,date_s,date_d,hdp)" "values (:id, :nom_c, :dci, :dosage, :date_s, :date_d)");

    query.bindValue(":id",res);
    query.bindValue(":nom_c",nom_c);
    query.bindValue(":dci",dci);
    query.bindValue(":dosage",dosage);
    query.bindValue(":date_s",date_s);
    query.bindValue(":date_d",date_d);

    return query.exec();
}

bool medicament::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);

    query.prepare("delete from medicament where ID= :id");
    query.bindValue(":id",res);

    return query.exec();
}

QSqlQueryModel * medicament::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from  medicament");
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

        QString res = QString::number(id);

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

        QString update_query = "UPDATE medicament SET " + updates.join(", ") + " WHERE id=:id";

        query.prepare(update_query);

        query.bindValue(":id", res);

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

bool medicament::ajouterCAB(int id,QString cab)
{
        QSqlQuery query;
        QString res=QString::number(id);
        QStringList updates;

        if (!cab.isEmpty())
            updates << "cab=:cab";

        QString update_query = "UPDATE medicament SET " + updates.join(", ") + " WHERE id=:id";

        query.prepare(update_query);

        query.bindValue(":id", res);

        if (!cab.isEmpty())
            query.bindValue(":cab", cab);

        return query.exec();
}

QSqlQueryModel* medicament::QtArduino()
{
        QSqlQuery query;
        QDate DateSystem = QDate::currentDate();
        //QString date = DateSystem.toString(Qt::ISODate);
        QString sqlQuery = "select * from medicament where date_d > :DateSystem";
        query.prepare(sqlQuery);
        query.bindValue(":DateSystem", DateSystem);

        if (!query.exec()) {
            // Handle error
            qDebug() << query.lastError().text();
        } else {
            // Iterate over the query result and process the data as needed
            while (query.next()) {
                // Get values from query result
                int id = query.value(0).toInt();
                QString nom_c = query.value(1).toString();
                QString dci = query.value(2).toString();
                int dosage = query.value(3).toInt();
                QString date_s = query.value(4).toString();
                QString date_d = query.value(5).toString();

            }
        }
}

bool medicament::ModifierStatus(int id)
{
        QSqlQuery query;
        QString res=QString::number(id);
        QStringList updates;
        QTime currentTime = QTime::currentTime();
        QString hdp =  currentTime.toString("hh:mm");

        if (!hdp.isEmpty())
            updates << "hdp=:hdp";

        QString update_query = "UPDATE medicament SET " + updates.join(", ") + " WHERE id=:id";

        query.prepare(update_query);

        query.bindValue(":id", res);

        if (!hdp.isEmpty())
            query.bindValue(":hdp", hdp);

        return query.exec();
}
