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
}
recherche::recherche(int id_r, QString titre, QString duree, QString date_debut, QString resultat, QString statut)
{
    this -> id_r=id_r;
    this -> titre=titre;
    this -> duree=duree;
    this -> date_debut=date_debut;
    this -> resultat=resultat;
    this -> statut=statut;
}

bool recherche::ajouter()
{
    QSqlQuery query;

    QString res = QString::number(id_r);

    query.prepare("insert into recherches (id_r,titre,duree,date_debut,resultat,statut)" "values (:id_r, :titre, :duree, :date_debut, :resultat, :statut)");

     query.bindValue(":id_r",res);
     query.bindValue(":titre",titre);
     query.bindValue(":duree",duree);
     query.bindValue(":date_debut",date_debut);
     query.bindValue(":resultat",resultat);
     query.bindValue(":statut",statut);

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

            return query.exec();
}


//recherche
QSqlQueryModel* recherche::chercherRecherche(QString id_r)
{
    QSqlTableModel* model = new QSqlTableModel();
    model->setTable("recherche");
    // Filtre la requête pour obtenir les livraisons qui ont un départ qui contient la chaîne de caractères donnée
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



