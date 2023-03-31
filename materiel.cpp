#include "materiel.h"
#include "ui_materiel.h"
#include "equipement.h"
#include <QMessageBox>
#include <qtablewidget.h>
#include <qabstractitemmodel.h>
#include <QRegularExpressionValidator>
#include "emailsender.h"
#include <QPrinter>
#include <QFileDialog>
#include <QPainter>



materiel::materiel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::materiel)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0,9999999,this));
    ui->le_nom->setValidator( new QRegularExpressionValidator(QRegularExpression("[A-Za-z]+"), this));
    ui->le_nom->setMaxLength(12);
    ui->le_etat->setValidator( new QRegularExpressionValidator(QRegularExpression("[A-Za-z]+"), this));
    ui->le_etat->setMaxLength(12);

    ui->le_ids->setValidator(new QIntValidator(0,9999999,this));
    ui->le_nom_2->setValidator( new QRegularExpressionValidator(QRegularExpression("[A-Za-z]+"), this));
    ui->le_nom_2->setMaxLength(12);
    ui->le_etat_2->setValidator( new QRegularExpressionValidator(QRegularExpression("[A-Za-z]+"), this));
    ui->le_etat_2->setMaxLength(12);

    ui->tableView_2->setModel(Eqmp.afficher());
    connect(ui->searchbox, SIGNAL(textChanged(const QString&)), this, SLOT(on_searchbox_textChanged(const QString&)));




}

materiel::~materiel()
{
    delete ui;
}


void materiel::on_procceed_add_clicked()
{
    ui->tableView_2->setModel(Eqmp.afficher());

    if(ui->le_id->text().isEmpty()){
            QMessageBox::warning(this, "Erreur", "ID est requis");

        }
    else {
    int id=ui->le_id->text().toInt();
    int nombre= 0 /*ui->le_nbocc_2->text().toInt()*/;
    QString Qr_code= NULL  /*ui->le_qr_2->text().toInt()*/;
    int prix_achat=ui->le_prix->text().toInt();
    QString nom=ui->le_nom->text();
    QString etat=ui->le_etat->text();
    QString notes=ui->le_notes->text();

    Equipement E(id,nombre,Qr_code,prix_achat,nom,etat,notes);

    bool test=E.ajouter();
    if(test)
    {
        ui->tableView_2->setModel(Eqmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Ajout effectuée \n"
                                             "Click cancel to exit"),QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectuée \n"
                                          "Click cancel to exit "), QMessageBox::Cancel);
    }
    }
}

void materiel::on_Delete_clicked()
{
    ui->tableView_2->setModel(Eqmp.afficher());

    int id=ui->le_ids->text().toInt();
    bool test=Eqmp.supprimer(id);
    if(test)
    { if (id != 0)
        {
         ui->tableView_2->setModel(Eqmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Suppression effectuée \n"
                                             "Click cancel to exit"),QMessageBox::Cancel);
        }

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                              QObject::tr("Suppression non effectuée \n"
                                          "Click cancel to exit "), QMessageBox::Cancel);
    }

}








void materiel::on_pushButton_17_clicked()
{
    ui->tableView_2->setModel(Eqmp.afficher());

    if(ui->le_ids->text().isEmpty()){
            QMessageBox::warning(this, "Erreur", "ID est requis");

        }
    else {
    int id=ui->le_ids->text().toInt();
    int nombre= 0 /*ui->le_nbocc_2->text().toInt()*/;
    QString Qr_code= NULL  /*ui->le_qr_2->text().toInt()*/;
    int prix_achat=ui->le_prix_2->text().toInt();
    QString nom=ui->le_nom_2->text();
    QString etat=ui->le_etat_2->text();
    QString notes=ui->note_update->text();


    Equipement E(id,nombre,Qr_code,prix_achat,nom,etat,notes);

    bool test=E.modifier();
    if(test)
    {
        ui->tableView_2->setModel(Eqmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Update effectuée \n"
                                             "Click cancel to exit"),QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                              QObject::tr("Update non effectuée \n"
                                          "Click cancel to exit "), QMessageBox::Cancel);
    }
    }
}


void materiel::on_clear_clicked()
{

}


void materiel::on_pushButton_19_clicked()
{
         ui->tableView_2->setModel(Eqmp.afficherasc());

}


void materiel::on_DESC_clicked()
{
    ui->tableView_2->setModel(Eqmp.afficherdesc());
}


void materiel::on_comboBox_currentIndexChanged(int index)
{

}


void materiel::on_tableView_2_clicked(const QModelIndex &index)
{
             int id=index.sibling(index.row(),0).data().toInt();
             int nombre=index.sibling(index.row(),1).data().toInt();
             QString nom=index.sibling(index.row(),4).data().toString();
             QString prix_achat=index.sibling(index.row(),3).data().toString();
             QString etat=index.sibling(index.row(),5).data().toString();
             QString notes=index.sibling(index.row(),6).data().toString();


             ui->le_ids->setText(QString::number(id));
             ui->le_nom_2->setText(nom);
             ui->le_prix_2->setText(prix_achat);
             ui->le_etat_2->setText(etat);
             ui->note_update->setText(notes);
            /* ui->le_ids_2->setText(QString::number(id)); */
}


void materiel::on_tableView_3_clicked(const QModelIndex &index)
{

    int id=index.sibling(index.row(),0).data().toInt();
   /* ui->pb_delete_2->setText(QString::number(id)); */

}


void materiel::on_pushButton_22_clicked()
{

}


void materiel::on_sendemail_clicked()
{
        EmailSender emailSender;

        QString user = "mohamedprojectqt@gmail.com";
        QString password = "lyxykrunqhrpfjux";
        QString from = "mohamedprojectqt@gmail.com";
        QString to = ui->to_edit->text();
        QString subject = ui->subject_edit->text();
        QString message = ui->message_edit->text();

        emailSender.sendEmail(user, password, from, to, subject, message);

}


void materiel::on_to_editingFinished()
{

}


void materiel::on_generate_clicked_clicked()
{

/*
    QString text = ui->le_id->text();
    QImage qrImage = QZXing::encodeData(text);
    ui->qrCodeLabel->setPixmap(QPixmap::fromImage(qrImage));
*/
}


void materiel::on_extract_pdf_clicked()
{
    // Get the database connection
    QSqlDatabase db = QSqlDatabase::database();

    // Create a QPrinter object and set its properties
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setOutputFileName("equipement.pdf");

    // Create a QPainter object and set its properties
    QPainter painter(&printer);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);

    // Create a QSqlQuery object and execute the query
    QSqlQuery query("SELECT * FROM equipement", db);

    // Create a QTextDocument object and set its properties
    QTextDocument doc;
    doc.setPageSize(QPageSize(QPageSize::A4).size(QPageSize::Point));
    QString styleSheet = "table { width: 100%; border-collapse: collapse; border-spacing: 0; }"
                         "table thead { background-color: #e5e5e5; }"
                         "table thead th { padding: 8px; border-bottom: 2px solid #bfbfbf; text-align: left; font-weight: 600; }"
                         "table tbody tr:nth-child(even) { background-color: #f2f2f2; }"
                         "table tbody td { padding: 8px; border-bottom: 1px solid #bfbfbf; }";
    doc.setDefaultStyleSheet(styleSheet);

    // Populate the QTextDocument with data from the QSqlQuery
    QString html = "<table><thead><tr><th>id</th><th>nombre</th><th>Qr_code</th><th>prix_achat</th><th>nom</th><th>etat</th><th>notes</th></tr></thead><tbody>";
    while (query.next()) {
        QString id = query.value(0).toString();
        QString nombre = query.value(1).toString();
        QString Qr_code = query.value(2).toString();
        QString prix_achat = query.value(3).toString();
        QString nom = query.value(4).toString();
        QString etat = query.value(5).toString();
        QString notes = query.value(6).toString();
        html += "<tr><td>" + id + "</td><td>" + nombre + "</td><td>" + Qr_code + "</td><td>" + prix_achat + "</td><td>" + nom + "</td><td>" + etat + "</td><td>" + notes + "</td></tr>";
    }
    html += "</tbody></table>";
    doc.setHtml(html);

    // Draw the QTextDocument to the QPainter
    doc.drawContents(&painter);

    // Cleanup
    painter.end();
    db.close();
}


void materiel::on_pb_recherche_clicked()
{
    // Get the search query from the search box
        QString searchQuery = ui->searchbox->text();

        // Create a QSqlQueryModel and set the query
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT id, nombre, Qr_code, prix_achat, nom, etat, notes  FROM equipement WHERE nom LIKE '%" + searchQuery + "%'");

        // Set the model to the table view
        ui->tableView_2->setModel(model);
}


void materiel::on_searchbox_textChanged(const QString &arg1)
{

    // Create a QSqlQuery to retrieve all equipment names that match the search query
        QSqlQuery query;
        query.prepare("SELECT nom FROM equipement WHERE nom LIKE '%" + searchQuery + "%'");
        query.exec();

        // Create a QStringList to hold the search suggestions
        QStringList suggestions;

        // Add all matching equipment names to the suggestion list
        while (query.next()) {
            suggestions.append(query.value(0).toString());
        }

        // Create a QCompleter object and set the suggestion model
        QCompleter *completer = new QCompleter(suggestions, this);
        completer->setCaseSensitivity(Qt::CaseInsensitive);
        completer->setFilterMode(Qt::MatchContains);

        // Set the completer to the search box
        ui->searchbox->setCompleter(completer);
}


void materiel::on_comboBox_activated(int index)
{
    if (index ==0)
    {
    ui->tableView_2->setModel(Eqmp.afficherasc());

    }
    if (index ==1)
    {
    ui->tableView_2->setModel(Eqmp.affichertriprix());

    }
    if (index ==2)
    {
    ui->tableView_2->setModel(Eqmp.affichertriid());

    }
    if (index ==3)
    {
    ui->tableView_2->setModel(Eqmp.affichertrinombre());

    }
}

void materiel::on_pushButton_16_clicked()
{
    Eqmp.getInventoryStats();

}

