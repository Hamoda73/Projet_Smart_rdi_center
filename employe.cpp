#include "employe.h"
#include "qurl.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
Employe::Employe(QString nom,QString prenom,QString email,QString password,QString role,QString cin,QString numtel)
{
    this->nom=nom;
    this->prenom=prenom;
    this->email=email;
    this->password=password;
    this->role=role;
    this->cin=cin;
    this->numtel=numtel;
}
 Employe::Employe()
 {
     cin='0';
     nom="";
     prenom="";
     email="";
     password="";
     role="";
     numtel="";

 }
bool Employe::ajouter(){
    QSqlQuery query;
         query.prepare("INSERT INTO EMPLOYE (NOM,PRENOM,CIN,EMAIL,PASSWORD, ROLE, NUMTEL)"
                       "VALUES ( :nom,:prenom,:cin,:email,:password,:role ,:numtel)");
         query.bindValue(":cin", cin);
         query.bindValue(":nom", nom);
         query.bindValue(":prenom", prenom);
         query.bindValue(":email", email);
         query.bindValue(":password", password);
         query.bindValue(":role", role);
         query.bindValue(":numtel", numtel);
        return query.exec();

}
QSqlQueryModel* Employe::afficher(){
    QSqlQueryModel* model= new QSqlQueryModel;
     model->setQuery("SELECT* FROM employe");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Cin"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("Pwd"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("Role"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("NumTel"));

    return model;
}
bool Employe::supprimer(QString cin){
    QSqlQuery query;
         query.prepare("DELETE FROM EMPLOYE where cin=:cin");
         query.bindValue(":cin", cin);
         return query.exec();
}
bool Employe::modifier()
{
    QSqlQuery query;


    QStringList updates;

    if (!nom.isEmpty())
        updates << "nom=:nom";

    if (!email.isEmpty() )
        updates << "email=:email";
    if (!password.isEmpty() )
        updates << "password=:password";

    if (!numtel.isEmpty())
        updates << "numtel=:numtel";

    if (!prenom.isEmpty() )
        updates << "prenom=:prenom";

    if (!role.isEmpty())
        updates << "role=:role";

    QString update_query = "UPDATE Employe SET " + updates.join(", ") + " WHERE cin=:cin";

    query.prepare(update_query);

    query.bindValue(":cin", cin);

    if (!nom.isEmpty())
        query.bindValue(":nom", nom);

    if (!prenom.isEmpty())
        query.bindValue(":prenom",prenom);

    if (!numtel.isEmpty())
        query.bindValue(":numtel", numtel);

    if (!email.isEmpty())
        query.bindValue(":email", email);

    if (!password.isEmpty())
        query.bindValue(":password", password);
    if (!role.isEmpty())
        query.bindValue(":role", role);

    return query.exec();
}
QSqlQueryModel* Employe::affichercin(){
    QSqlQueryModel* model= new QSqlQueryModel;
     model->setQuery("SELECT* FROM employe ORDER BY cin ASC");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Cin"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("Pwd"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("Role"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("NumTel"));

    return model;
}
QSqlQueryModel* Employe::affichernom(){
    QSqlQueryModel* model= new QSqlQueryModel;
     model->setQuery("SELECT* FROM employe ORDER BY nom ASC");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Cin"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("Pwd"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("Role"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("NumTel"));

    return model;
}
QSqlQueryModel* Employe::afficheremail()
{
    QSqlQueryModel* model= new QSqlQueryModel;
     model->setQuery("SELECT* FROM employe ORDER BY email ASC");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Cin"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("Pwd"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("Role"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("NumTel"));

    return model;
}

