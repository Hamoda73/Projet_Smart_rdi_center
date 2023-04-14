#include "equipement.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <qsqlerror>

#include "ui_materiel.h"



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

    // Check if there is already an existing record with the same name
    query.prepare("SELECT COUNT(*) FROM equipement WHERE nom = :nom");
    query.bindValue(":nom", nom);
    if (!query.exec()) {
        qDebug() << "Error counting equipements with same name: " << query.lastError().text();
        return false;
    }
    int count = 0;
    if (query.next()) {
        count = query.value(0).toInt();
    }

    // Insert the new record
    query.prepare("INSERT INTO equipement (id, nombre, Qr_code, prix_achat, nom, etat, notes) VALUES (:id, :nombre, :Qr_code, :prix_achat, :nom, :etat, :notes)");
    query.bindValue(":id", res);
    query.bindValue(":nombre", count + 1); // Increment count by 1 and use it as the new value for nombre
    query.bindValue(":Qr_code", Qr_code);
    query.bindValue(":prix_achat", prix_achat);
    query.bindValue(":nom", nom);
    query.bindValue(":etat", etat);
    query.bindValue(":notes", notes);
    if (!query.exec()) {
        qDebug() << "Error inserting new equipement: " << query.lastError().text();
        return false;
    }

    // Update the nombre variable in all existing records with the same name
    query.prepare("UPDATE equipement SET nombre = :nombre WHERE nom = :nom");
    query.bindValue(":nombre", count + 1);
    query.bindValue(":nom", nom);
    if (!query.exec()) {
        qDebug() << "Error updating equipements with same name: " << query.lastError().text();
        return false;
    }

    return true;
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
    // First, retrieve the name of the equipement that is being deleted
        QSqlQuery queryGetNom;
        queryGetNom.prepare("SELECT nom FROM equipement WHERE ID=:id");
        queryGetNom.bindValue(":id", id);
        if (!queryGetNom.exec() || !queryGetNom.next()) {
            qDebug() << "Error retrieving nom of equipement to delete:" << queryGetNom.lastError().text();
            return false;
        }
        QString nomToDelete = queryGetNom.value(0).toString();

        // Delete the equipement
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM equipement WHERE ID=:id");
        queryDelete.bindValue(":id", id);
        if (!queryDelete.exec()) {
            qDebug() << "Error deleting equipement:" << queryDelete.lastError().text();
            return false;
        }

        // Decrement the nombre variable of all other equipements with the same name
        QSqlQuery queryDecrement;
        queryDecrement.prepare("UPDATE equipement SET nombre=nombre-1 WHERE nom=:nom AND ID!=:id");
        queryDecrement.bindValue(":nom", nomToDelete);
        queryDecrement.bindValue(":id", id);
        if (!queryDecrement.exec()) {
            qDebug() << "Error decrementing nombre variable:" << queryDecrement.lastError().text();
            return false;
        }

        return true;
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








void Equipement::getInventoryStats()
{/*
    QPieSeries *series = new QPieSeries();
    series->append("Equipment 1", 10);
    series->append("Equipment 2", 20);
    series->append("Equipment 3", 5);

    // Create a chart view and set the series
    QPieSlice *slice = series->slices().at(1);
    slice->setExploded(true);
    slice->setLabelVisible(true);

    QPieChart *chart = new QPieChart();
    chart->addSeries(series);
    chart->setTitle("Available Equipments");

    // Create a chart view and set the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Set the chart view as the main window
    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(400, 300);
    window.show();
    */
}

void Equipement::displayInventoryPieChart()
{
    // Create a QMap to store the unique names and their corresponding nombres
        QMap<QString, int> stats;

        // Get all the equipements in the inventory
        QSqlQuery query;
        query.prepare("SELECT nom, nombre FROM equipement");
        query.exec();

        // Iterate through the results and add up the nombres for each unique name
        while(query.next()) {
            QString nom = query.value(0).toString();
            int nombre = query.value(1).toInt();
            if(stats.contains(nom)) {
                if (stats[nom] != nombre) {
                    // If the name already exists in the map and the nombre is different, divide the nombre by 2
                    nombre = nombre / 2;
                } else {
                    // If the name already exists in the map and the nombre is the same, skip it
                    continue;
                }
            }
            stats[nom] = nombre;
        }

        // Create the pie chart series and add the data from the QMap
        QPieSeries *series = new QPieSeries();
        QMapIterator<QString, int> i(stats);
        while (i.hasNext()) {
            i.next();
            series->append(i.key(), i.value());
        }

        // Create the chart and chart view, and display the chart view
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Equipement Inventory Stats");
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->resize(800, 600);
        chartView->show();
}




////int id, QString refference, QString nomequip, QString etatequip, QString dateajout, int nombredepanne, int garantie
void Equipement::generateQRCode(QString id) {

        QString data = id;
        QImage qrCodeImage = QZXing::encodeData(data.toUtf8(), QZXing::EncoderFormat_QR_CODE, QSize(200, 200));
        QPixmap qrCodePixmap = QPixmap::fromImage(qrCodeImage);
        // we convert it to a qpixmap cuz we cant display a qimage in a qlabel widget
        // Create a new dialog window to display the QR code image
        QDialog *qrCodeDialog = new QDialog();
        // Layout puts the image in the middle of the qlabel
        QVBoxLayout *layout = new QVBoxLayout(qrCodeDialog);
        QLabel *qrCodeLabel = new QLabel(qrCodeDialog);

        // the qlabel to show the qpixmap
        qrCodeLabel->setPixmap(qrCodePixmap);
        layout->addWidget(qrCodeLabel);
        qrCodeDialog->setLayout(layout);

        // Show the dialog window (execute it)
        qrCodeDialog->exec();
}
