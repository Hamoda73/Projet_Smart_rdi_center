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
#include "arduino.h"


materiel::materiel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::materiel)
{
    ui->setupUi(this);
    ui->tableView_3adruino->setModel(Eqmp.afficherarduino());
    int ret=A.connect_arduino(); // lancer la connexion à arduino
        switch(ret){
        case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();


            break;
        case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
            break;
        case(-1):qDebug() << "arduino is not available";
        }
        QTimer *timer = new QTimer(this);
        QTimer *ref = new QTimer(this);

        // Set the timeout interval (in milliseconds)
        timer->setInterval(100);
        ref->setInterval(2000);
        connect(ref, &QTimer::timeout, [=](){
            ui->tableView_3adruino->setModel(Eqmp.afficherarduino());
        });

        // Connect the timeout() signal of the QTimer object to a lambda function
        connect(timer, &QTimer::timeout, [=]() {


            QByteArray data = A.readL_from_arduino();
            QString dataString = QString::fromUtf8(data).trimmed(); // Convert the data to a QString and remove any leading/trailing white space
            QString AZER = dataString;
            if (AZER == "car") {

                QDateTime currentDateTime = QDateTime::currentDateTime();
                QString dateString = currentDateTime.toString(Qt::ISODate);


                    QString in ="movement detected at :"+dateString ;
                    QSqlQuery query;
                    query.prepare("INSERT INTO HISTARD (HIST,OPEN) VALUES (:HIST,:OPEN)");
                    query.bindValue(":HIST", in);
                    query.bindValue(":OPEN", "---");
                    ui->tableView_3adruino->setModel(Eqmp.afficherarduino());



                    if (!query.exec()) {
                        qDebug() << "Failed to insert data into database";
                        }


                QMessageBox::information(this, "Car Detected", "A car has been detected!"); // Show a message box if the AZER string variable contains "car"
                }
            QString wordToFind = "Car entred at" ;

            bool found = AZER.contains(wordToFind);
            if (found) {
                QDateTime currentDateTime = QDateTime::currentDateTime();
                QString dateString = currentDateTime.toString(Qt::ISODate);
                AZER=AZER+dateString ;
                QSqlQuery query;
                query.prepare("INSERT INTO HISTARD (HIST,OPEN) VALUES (:HIST,:OPEN)");
                query.bindValue(":HIST", "---");
                query.bindValue(":OPEN", AZER);





                if (!query.exec()) {
                    qDebug() << "Failed to insert data into database";
                    }
            }

        });


        timer->start();
        ref->start();




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
    ui->tableView_3adruino->setModel(Eqmp.afficherarduino());
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
             ui->id_gen_edit->setText(QString::number(id));
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
        QString password = "zdweswndyhdpkkzb";
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

    QString aux = ui->id_gen_edit->text();
      Eqmp.generateQRCode(aux);

   // Eqmp.generateQRCode();

}


void materiel::on_extract_pdf_clicked()
{
    // Get the database connection
    QSqlDatabase db = QSqlDatabase::database();

    // Create a QPrinter object and set its properties( of the printer)
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setOutputFileName("equipement1.pdf");

    // Create a QPainter ( drawing ) object and set its properties
    QPainter painter(&printer);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);

    // Create a QSqlQuery object and execute the query to retrieve data from db
    QSqlQuery query("SELECT * FROM equipement", db);

    // Create a QTextDocument object and set its properties ( stores the html data )
    QTextDocument doc;
    doc.setPageSize(QPageSize(QPageSize::A4).size(QPageSize::Point)); // point, return the size in points
    QString styleSheet = "table { width: 100%; border-collapse: collapse; border-spacing: 0; }"
                         "table thead { background-color: #e5e5e5; }"
                         "table thead th { padding: 8px; border-bottom: 2px solid #bfbfbf; text-align: left; font-weight: 600; }"
                         "table tbody tr:nth-child(even) { background-color: #f2f2f2; }"
                         "table tbody td { padding: 8px; border-bottom: 1px solid #bfbfbf; }";
    doc.setDefaultStyleSheet(styleSheet);

    // Populate the QTextDocument with data from the QSqlQuery in the QTextDocument
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

    // Draw the QTextDocument to the QPainter from the doc variable
    doc.drawContents(&painter);

    // Add a watermark to each page of the PDF
        painter.save();
        painter.setOpacity(0.2); // Set the opacity of the watermark
        QFont font = painter.font();
        font.setPointSize(72); // size of the watermark text
        font.setBold(true); // font weight of the watermark text
        painter.setFont(font);
        painter.drawText(QRect(0, 0, printer.width(), printer.height()), Qt::AlignCenter, "SmartLAB"); // Draw the watermark text
        painter.restore();

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

    // Created an QSqlQuery to retrieve all equipment names that match the search query
        QSqlQuery query;
        query.prepare("SELECT nom FROM equipement WHERE nom LIKE '%" + searchQuery + "%'");
        query.exec();

     // Created an QStringList to hold the search suggestions
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

Eqmp.displayInventoryPieChart();

}


void materiel::on_pushButton_clicked()
{

}


void materiel::on_Open_clicked()
{
    A.write_to_arduino("1");




}


void materiel::on_Close_clicked()
{
    A.write_to_arduino("2");







}


