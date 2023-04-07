#include "equipement.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

Equipement::Equipement()
{
   id=0; nombre=0; Qr_code=" ";prix_achat=0 ; nom=" "; etat=" "; notes=" ";
}


Equipement::Equipement(int id,int nombre,QString Qr_code,int prix_achat,QString nom,QString etat,QString notes)
{this->id=id;this->nombre=nombre;this->nom = nom;this->etat = etat; this->Qr_code=Qr_code;this->prix_achat=prix_achat;this->notes=notes;}
int Equipement :: getid(){return id;}
int Equipement :: getnombre(){return nombre;}
QString Equipement :: getQRCode(){return Qr_code;}
int Equipement :: getprix_achat(){return prix_achat;}
QString Equipement :: getnom(){return nom;}
QString Equipement :: getetat(){return etat;}
void Equipement :: setid(int id){this->id=id;}
void Equipement :: setnombre(int nombre){this->nombre=nombre;}
/*
void Equipement :: setQr_code(int Qr_code){this->Qr_code=Qr_code;}
*/
void Equipement :: setprix_achat(int prix_achat){this->prix_achat=prix_achat;}
void Equipement :: setnom(QString nom){this->nom=nom;}
void Equipement :: setetat(QString etat){this->etat=etat;}


bool Equipement::ajouter()
{

    QSqlQuery query;
    QString res = QString::number(id);

    query.prepare("insert into equipement (id,nombre,Qr_code,prix_achat,nom,etat,notes)" "values(:id,:nombre,:Qr_code,:prix_achat,:nom,:etat,:notes)");

    query.bindValue(":id",res);
    query.bindValue(":nombre",nombre);
    query.bindValue(":Qr_code",Qr_code);
    query.bindValue(":prix_achat",prix_achat);
    query.bindValue(":nom",nom);
    query.bindValue(":etat",etat);
    query.bindValue(":notes",notes);

    return query.exec();

}


bool Equipement::modifier()
{
    QSqlQuery query;

    QString res = QString::number(id);

    QStringList updates;

    if (!nom.isEmpty())
        updates << "nom=:nom";

    if (!Qr_code.isEmpty())
        updates << "Qr_code=:Qr_code";

    if (nombre >= 0)
        updates << "nombre=:nombre";

    if (prix_achat >= 0)
        updates << "prix_achat=:prix_achat";

    if (!etat.isEmpty())
        updates << "etat=:etat";

    if (!notes.isEmpty())
        updates << "notes=:notes";

    QString update_query = "UPDATE equipement SET " + updates.join(", ") + " WHERE id=:id";

    query.prepare(update_query);

    query.bindValue(":id", res);

    if (!nom.isEmpty())
        query.bindValue(":nom", nom);

    if (!Qr_code.isEmpty())
        query.bindValue(":Qr_code", Qr_code);

    if (nombre >= 0)
        query.bindValue(":nombre", nombre);

    if (prix_achat >= 0)
        query.bindValue(":prix_achat", prix_achat);

    if (!etat.isEmpty())
        query.bindValue(":etat", etat);

    if (!notes.isEmpty())
        query.bindValue(":notes", notes);

    return query.exec();
}

/*bool Equipement::modifier()
{
    QSqlQuery query;

    QString res = QString::number(id);

    query.prepare("UPDATE equipement SET nombre=:nombre, Qr_code=:Qr_code, prix_achat=:prix_achat, nom=:nom, etat=:etat WHERE id=:id");

    query.bindValue(":id", res);
    query.bindValue(":nombre", nombre);
    query.bindValue(":Qr_code", Qr_code);
    query.bindValue(":prix_achat", prix_achat);
    query.bindValue(":nom", nom);
    query.bindValue(":etat", etat);

    return query.exec();
}*/


bool Equipement::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("Delete from equipement where ID= :id");
    query.bindValue(":id",res);
    return query.exec();
}

QSqlQueryModel * Equipement::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT id, nombre, Qr_code, prix_achat, nom, etat, notes  FROM equipement");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOMBRE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("QR_CODE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRIX_ACHAT"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("ETAT"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("NOTES"));

    return model;
}
QSqlQueryModel * Equipement::afficherasc()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT id, nombre, Qr_code, prix_achat, nom, etat, notes  FROM equipement ORDER BY nom ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOMBRE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("QR_CODE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRIX_ACHAT"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("ETAT"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("NOTES"));

    return model;
}
QSqlQueryModel * Equipement::afficherdesc()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT id, nombre, Qr_code, prix_achat, nom, etat, notes  FROM equipement ORDER BY nom DESC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOMBRE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("QR_CODE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRIX_ACHAT"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("ETAT"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("notes"));

    return model;
}

QSqlQueryModel * Equipement::affichertriprix()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT id, nombre, Qr_code, prix_achat, nom, etat, notes  FROM equipement ORDER BY prix_achat ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOMBRE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("QR_CODE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRIX_ACHAT"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("ETAT"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("notes"));

    return model;
}

QSqlQueryModel * Equipement::affichertriid()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT id, nombre, Qr_code, prix_achat, nom, etat, notes  FROM equipement ORDER BY id ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOMBRE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("QR_CODE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRIX_ACHAT"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("ETAT"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("notes"));

    return model;
}
QSqlQueryModel * Equipement::affichertrinombre()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT id, nombre, Qr_code, prix_achat, nom, etat, notes  FROM equipement ORDER BY nombre ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOMBRE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("QR_CODE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRIX_ACHAT"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("ETAT"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("notes"));

    return model;
}


/*
void Equipement::generateQRCode() {
    std::string nomStr = nom.toStdString();
    std::string notesStr = notes.toStdString();
    std::string etatStr = etat.toStdString();

    std::string text = "Name: " + nomStr + "\nSerial Number: " + notesStr + "\nManufacturer: " + etatStr;

    qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(text.c_str(), qrcodegen::QrCode::Ecc::LOW);

    const int size = qr.getSize();
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            std::cout << (qr.getModule(x, y) ? "##" : "  ");
        }
        std::cout << std::endl;
    }
}
*/


void Equipement::getInventoryStats()
{
    QSqlQuery query;

    // Get the total number of items in the inventory
    query.exec("SELECT COUNT(*) FROM equipement");
    query.next();
    int itemCount = query.value(0).toInt();

    // Get the most popular items

    // Get the total value of the inventory
    query.exec("SELECT SUM(prix_achat) FROM equipement");

    query.next();
    double totalValue = query.value(0).toDouble();

    // Display the statistics in a QMessageBox
    QMessageBox msgBox;
    msgBox.setText(QString("Total number of items: %1\n Total inventory value: %2")
                   .arg(itemCount)

                   .arg(totalValue));
    msgBox.exec();
}
