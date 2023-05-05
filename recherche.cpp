#include "recherche.h"
#include <QObject>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
recherche::recherche()
{
    id_r=0;
    titre=" ";
    duree=" ";
    date_debut=" ";
    resultat=" ";
    statut=" ";
    etat_event=" ";
    event=" ";

}
recherche::recherche(int id_r, QString titre, QString duree, QString date_debut, QString resultat, QString statut, QString etat_event, QString event)
{
    this -> id_r=id_r;
    this -> titre=titre;
    this -> duree=duree;
    this -> date_debut=date_debut;
    this -> resultat=resultat;
    this -> statut=statut;
    this -> etat_event=etat_event;
    this -> event=event;

}



bool recherche::ajouter()
{
    QSqlQuery query;

    QString res = QString::number(id_r);

    query.prepare("insert into recherches (id_r,titre,duree,date_debut,resultat,statut,etat_event,event) values (:id_r, :titre, :duree, :date_debut, :resultat, :statut, :etat_event, :event)");

     query.bindValue(":id_r",res);
     query.bindValue(":titre",titre);
     query.bindValue(":duree",duree);
     query.bindValue(":date_debut",date_debut);
     query.bindValue(":resultat",resultat);
     query.bindValue(":statut",statut);
     query.bindValue(":etat_event",etat_event);
     query.bindValue(":event",event);

     return query.exec();

}

QSqlQueryModel * recherche::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from recherches");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("titre"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("duree"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("date de debut"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("resultat"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("statut"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("etat_event"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("event"));

    return model;
}
bool recherche::supprimer (int id_r)
{
    QSqlQuery query;
    QString res = QString::number(id_r);
    query.prepare("delete from recherches where ID_R= :id_r");
    query.bindValue(":id_r",res);

    return query.exec();
}

bool recherche::modifier()
{
    QSqlQuery query;

            QString res = QString::number(id_r);

            QStringList updates;

            if (!titre.isEmpty())
                updates << "titre=:titre";

            if (!duree.isEmpty())
                updates << "duree=:duree";

            if (!date_debut.isEmpty())
                updates << "date_debut=:date_debut";

            if (!resultat.isEmpty())
                updates << "resultat=:resultat";

            if (!statut.isEmpty())
                updates << "statut=:statut";

            if (!etat_event.isEmpty())
                updates << "etat_event=:etat_event";

            if (!event.isEmpty())
                updates << "event=:event";

            QString update_query = "UPDATE recherches SET " + updates.join(", ") + " WHERE ID_R=:id_r";

            query.prepare(update_query);

            query.bindValue(":id_r", res);

            if (!titre.isEmpty())
                query.bindValue(":titre", titre);

            if (!duree.isEmpty())
                query.bindValue(":duree", duree);

            if (!date_debut.isEmpty())
                query.bindValue(":date_debut", date_debut);

            if (!resultat.isEmpty())
                query.bindValue(":resultat", resultat);

            if (!statut.isEmpty())
                query.bindValue(":statut", statut);

            if (!statut.isEmpty())
                query.bindValue(":etat_event", etat_event);

            if (!statut.isEmpty())
                query.bindValue(":event", event);



            return query.exec();
}


//recherche
QSqlQueryModel* recherche::chercherRecherche(QString id_r)
{
    QSqlTableModel* model = new QSqlTableModel();
    model->setTable("recherches");
    model->setFilter("id_r LIKE '%" + id_r + "%'");
    model->select();
    return model;
}

//tri
QSqlQueryModel * recherche::triRecherche(QString test)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    if(test == "par défaut"){
                model->setQuery("SELECT * from recherches");
}
else if(test =="id_r")
{
    model->setQuery("SELECT * from recherches order by id_r asc ");
}
else if(test =="titre")
{
    model->setQuery("SELECT * from recherches order by titre asc ");
}
else if(test =="duree")
{
    model->setQuery("SELECT * from recherches order by duree asc ");
}
else if(test =="date_debut")
{
    model->setQuery("SELECT * from recherches order by date_debut asc ");
}
else if(test =="resultat")
{
    model->setQuery("SELECT * from recherches order by resultat asc ");
}
else if(test =="statut")
{
    model->setQuery("SELECT * from recherches order by statut asc ");
}

return model;
}
//

QSqlQueryModel* recherche::afficherTODO()
{
QSqlQueryModel* model = new QSqlQueryModel();

model->setQuery("select * from recherches where etat_event='todo'");
model->setHeaderData(0, Qt::Horizontal, QObject::tr(" id_r :"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr(" event :"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr(" etat event :"));
return model;
}



QSqlQueryModel* recherche::afficherINPROGRESS()
{
QSqlQueryModel* model = new QSqlQueryModel();

model->setQuery("select * from recherches where etat_event='en_cours'");
model->setHeaderData(0, Qt::Horizontal, QObject::tr(" id_r  :"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr(" event  :"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr(" etat event :"));
return model;
}




QSqlQueryModel* recherche::afficherDONE()
{
QSqlQueryModel* model = new QSqlQueryModel();

model->setQuery("select * from recherches where etat_event='done'");
model->setHeaderData(0, Qt::Horizontal, QObject::tr(" id_r :"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr(" event :"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr(" etat event :"));
return model;
}

bool recherche::modifierEtat(int id_r, const QString &etat)
{
QSqlQuery query;


query.prepare("UPDATE  SET etat_event = :etat WHERE identifiant = :id_r ");
query.bindValue(":etat", etat);
query.bindValue(":id_r", id_r);

return query.exec();
}

