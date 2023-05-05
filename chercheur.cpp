#include "chercheur.h"
#include <QCompleter>
chercheur::chercheur()
{

}



/*----------------------------------------------------------------------------------*/

chercheur::chercheur(int CIN_c, QString nom, QString prenom, int age, QString email, QDate currentDate)
{
    this->CIN_c = CIN_c;
    this->nom = nom;
    this->prenom = prenom;
    this->age = age;
    this->email = email;
    this->currentDate = currentDate;
}

/*----------------------------------------------------------------------------------*/

bool chercheur::ajouter()
{
    QSqlQuery query;

    QString res = QString::number(CIN_c);
    QDate currentDate = QDate::currentDate();

    query.prepare("insert into chercheur (cin_c,nom,prenom,age,email,currentDate)" "values (:CIN_c, :nom, :prenom, :age, :email,:currentDate)");
    query.bindValue(":CIN_c",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":age",age);
    query.bindValue(":email",email);
    currentDate.toString(Qt::ISODate);
    query.bindValue(":currentDate",currentDate);

    // Log the modification
    QStringList values;
    values << QString("CIN: %1,").arg(res)
                                                                   << QString("Nom: %1,").arg(nom)
                                                                   << QString("Prenom: %1,").arg(prenom)
                                                                   << QString("Age: %1,").arg(age)
           << QString("Email: %1,").arg(email);

                                                               writeToLog(values);

    return query.exec();
}

/*----------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------------*/

QSqlQueryModel * chercheur::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from  chercheur");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Age"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Date"));
    return model;
}

/*----------------------------------------------------------------------------------*/

bool chercheur::supprimer(int CIN_c)
{
    QSqlQuery query;
    QString res=QString::number(CIN_c);

    query.prepare("delete from chercheur where CIN_C= :CIN_c");
    query.bindValue(":CIN_c",res);


    return query.exec();
}

/*----------------------------------------------------------------------------------*/

bool chercheur::modifier()
{
    QSqlQuery query;

    QString res = QString::number(CIN_c);

    QStringList updates;

    if (!nom.isEmpty())
        updates << "nom=:nom";

    if (!prenom.isEmpty())
        updates << "prenom=:prenom";

    if (age > 0)
        updates << "age=:age";

    if (!email.isEmpty())
        updates << "email=:email";



    QString update_query = "UPDATE chercheur SET " + updates.join(", ") + " WHERE CIN_C=:CIN_c";

    query.prepare(update_query);

    query.bindValue(":CIN_c", res);

    if (!nom.isEmpty())
        query.bindValue(":nom", nom);

    if (!prenom.isEmpty())
        query.bindValue(":prenom", prenom);

    if (age > 0)
        query.bindValue(":age", age);

    if (!email.isEmpty())
        query.bindValue(":email", email);

    // Log the modification
    QStringList values;
    values << QString("CIN: %1,").arg(res)
           << QString("Nom: %1,").arg(nom)
           << QString("Prenom: %1,").arg(prenom)
           << QString("Age: %1,").arg(age)
           << QString("Email: %1,").arg(email);

    writeToLog(values);

    return query.exec();


}

/*----------------------------------------------------------------------------------*/

QSqlQueryModel * chercheur::afficherHistorique()
{
    QSqlQuery query;
    QString res=QString::number(CIN_c);

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from  chercheur where CIN_c = :CIN_c");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Titre recherche"));
    return model;
}
/*----------------------------------------------------------------------------------*/

QSqlQueryModel * chercheur::afficherTriCroissant()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from  chercheur ORDER BY currentDate ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Age"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));
    return model;
}

/*----------------------------------------------------------------------------------*/

QSqlQueryModel * chercheur::afficherTriDecroissant()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from  chercheur ORDER BY AGE ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Age"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));
    return model;
}



/*----------------------------------------------------------------------------------*/

QSqlQueryModel*  chercheur::chercherChercheur(QString depart)
{
    QSqlTableModel* model = new QSqlTableModel();
    model->setTable("chercheur");
    // Filtre la requête pour obtenir les livraisons qui ont un départ qui contient la chaîne de caractères donnée
    model->setFilter("DEPART LIKE '%" + depart + "%'");
    model->select();
    return model;
}

/*----------------------------------------------------------------------------------*/

QSqlQueryModel * chercheur::afficherTriNom()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from  chercheur ORDER BY NOM ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Age"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));
    return model;
}

/*----------------------------------------------------------------------------------*/

void chercheur::writeToLog(QStringList values)
{
    QFile file("C:/Users/mdkhe/OneDrive/Documents/build-materiel-Desktop_Qt_6_5_0_MinGW_64_bit-Debug/liste1.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        return;
    }
    QTextStream out(&file);
    out << QDateTime::currentDateTime().toString(Qt::ISODate) << " - ";

    for (int i = 0; i < values.size(); i++) {
        out << values.at(i);
        if (i != values.size() - 1) {
            out << ",";
        }
    }
    out << "\n";

    file.close();
}

/*----------------------------------------------------------------------------------*/
