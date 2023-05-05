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
#include "medicament.h"
#include "stage.h"
#include <QTextStream>
#include <QSortFilterProxyModel>
#include "chercheur.h"
#include <QFile>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVBoxLayout>
#include <QPlainTextEdit>
#include <QAuthenticator>
#include "QDebug"
#include <QIODevice>
#include <QDateTime>
#include "employe.h"
#include "recherche.h"

materiel::materiel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::materiel)
{
    ui->setupUi(this);


    /// amine ///////
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
          ///moheb funny funny
        ui->textemail->setValidator(new QRegularExpressionValidator(QRegularExpression("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}"),this));
        ui->textnom->setValidator(new QRegularExpressionValidator(QRegularExpression("[a-zA-Z]+"),this));
        ui->textprenom->setValidator(new QRegularExpressionValidator(QRegularExpression("[a-zA-Z]+"),this));
        ui->textage->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]+"),this));
        ui->textcin->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]+"),this));

        QSortFilterProxyModel *proxyModel1 = new QSortFilterProxyModel(this);
            proxyModel1->setSourceModel(ui->table_c->model());

            ui->table_c->setModel(ctp.afficher());
        ///moheb funny funny
        /// amine ////////

            ui->le_cin->setValidator (new QIntValidator(0, 99999999, this));
                ui->tab_emp->setModel(Emp.afficher());
                ui->le_cin->setMaxLength(8);
                ui->le_tel->setMaxLength(8);
                ui->le_email->setValidator( new QRegularExpressionValidator(QRegularExpression("[A-Za-z]+[@]+[A-Za-z]+[.]+[A-Za-z]+"), this));
connect(ui->pb_tri, SIGNAL(clicked()), this, SLOT(onButtonClicked()));


    //////yassine/////
     ui->line_id->setValidator (new QIntValidator(0, 99999999, this));
    ui->line_dosage->setValidator (new QIntValidator(0, 99999999, this));
    ui->table_meds->setModel(mtp.afficher());
        ui->table_meds_3->setModel(mtp.afficher());
        ui->table_meds_4->setModel(mtp.afficher());
        ui->table_meds_5->setModel(mtp.afficher());
        ui->table_meds_6->setModel(mtp.afficher());

        trayIcon = new QSystemTrayIcon(this);
            trayIcon->setIcon(QIcon("C:/Users/mdkhe/OneDrive/Desktop/Integration/Yassine/ME/meds/images/notif.png"));
            trayIcon->setVisible(true);
            proxyModel = new QSortFilterProxyModel(this);
            proxyModel->setSourceModel(ui->table_meds->model());
            ui->table_meds->setModel(proxyModel);
            connect(ui->comboBox_2, SIGNAL(currentIndexChanged(int)), this, SLOT(on_comboBox_2_currentIndexChanged(int)));

            m_lineEdit = ui->le_code;
            m_button = ui->generatepb;
            connect(m_button, SIGNAL(clicked()), this, SLOT(generateBarcode()));
            /////yassine//////
            ///  moheb funny funny ///////////
          /*  ui->textemail->setValidator(new QRegularExpressionValidator(QRegularExpression("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}"),this));
                ui->textnom->setValidator(new QRegularExpressionValidator(QRegularExpression("[a-zA-Z]+"),this));
                ui->textprenom->setValidator(new QRegularExpressionValidator(QRegularExpression("[a-zA-Z]+"),this));
                ui->textage->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]+"),this));
                ui->textcin->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]+"),this));
                QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
                proxyModel->setSourceModel(ui->table_c->model());

                ui->table_c->setModel(ctp.afficher());*/

            /////// moheb funny funny ///////////
            /// MouadhGammoudi ///
            setupCalendar();
            stage etmp;
            QSqlQueryModel* model = etmp.afficher("ID_S");

            //////////////
            ////// nour Aben /////
            recherche rtp;

            ui->le_id_3->setValidator(new QIntValidator(0,99999999,this));
            ui->le_titre->setValidator(new QRegularExpressionValidator(QRegularExpression("[a-zA-Z]+"),this));
            ui->le_resultat->setValidator(new QRegularExpressionValidator(QRegularExpression("[a-zA-Z]+"),this));
            ui->le_statut->setValidator(new QRegularExpressionValidator(QRegularExpression("[a-zA-Z]+"),this));
            ui->afficher_3->setModel(rtp.afficher());
            proxyModel = new QSortFilterProxyModel(this);
            proxyModel->setSourceModel(ui->afficher_3->model());

            /*ui->cB->setChecked(true);
            ui->cB_2->setChecked(true);
            ui->cB_3->setChecked(true);
            ui->cB_4->setChecked(true);*/

            ui->sortByCombo_3->addItem("id_r");
            ui->sortByCombo_3->addItem("titre");
            ui->sortByCombo_3->addItem("duree");
            ui->sortByCombo_3->addItem("date_debut");
            ui->sortByCombo_3->addItem("resultet");
            ui->sortByCombo_3->addItem("statut");
            /////////

    ui->tableView_3adruino->setModel(Eqmp.afficherarduino());

////arduino  me ////
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
            ui->afficher_2->setModel(model);
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

////// arduino yassine ////////

        /////ARUIDNO
         int ret1=A.connect_arduino(); // lancer la connexion à arduino
          switch(ret1){
          case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
              break;
          case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
              break;
          case(-1):qDebug() << "arduino is not available";
          }
          QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
 ////// arduino yassine ////////



}

materiel::~materiel()
{
    delete ui;
}

//////////amino ////////////////////
void materiel::on_pb_ajouter_clicked()
{
    QString numtel=ui->le_tel->text();
    QString cin=ui->le_cin->text();
    QString nom=ui->le_nom_3->text();
    QString prenom=ui->le_prenom->text();
    QString email=ui->le_email->text();
    QString password=ui->le_pwd->text();
    QString role=ui->le_role->text();

    Employe E (nom,prenom,email,password,role,cin,numtel);
    bool test=E.ajouter();
    ;
    if(ui->le_cin->text().isEmpty())
    {
        QMessageBox::critical(nullptr,QObject::tr("ajout non effectue :"),
                              QObject::tr("il faut saisir le cin de l employe ! \n"
                                          "Click cancel to exit "), QMessageBox::Cancel);
    }
             if(test)
             {
                 ui->tab_emp->setModel(Emp.afficher());
                 QMessageBox::information(nullptr, QObject::tr("ok"),
                             QObject::tr("ajout effectué.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

         }
             else
                 QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                             QObject::tr("Ajout non effectué.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);


}

void materiel::on_pb_supprimer_clicked()
{
    Employe E1;
    E1.setCin(ui->les_cin->text());
    bool test=E1.supprimer(E1.getCin());
    QMessageBox msgbox;
    if(test)
    {
        ui->tab_emp->setModel(Emp.afficher());
        msgbox.setText("suppression avec succes");
    }
    else
        msgbox.setText("echec");
    msgbox.exec();
}

void materiel::on_pb_modifier_clicked()
{

        QString cin=ui->le_cin_2->text();
        QString numtel=ui->le_tel_2->text();
        QString email=ui->le_email_2->text();
        QString password=ui->le_pwd_2->text();
        QString role=ui->le_role_3->text();
        QString nom=ui->le_nom_4->text();
        QString prenom=ui->le_prenom_2->text();

        Employe E (nom,prenom,email,password,role,cin,numtel);

        bool test=E.modifier();
        if(test)
        {
            ui->tab_emp->setModel(Emp.afficher());
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
void materiel::on_tab_emp_clicked(const QModelIndex &index)
{


             QString numtel=index.sibling(index.row(),6).data().toString();
             QString cin=index.sibling(index.row(),0).data().toString();
             QString nom=index.sibling(index.row(),2).data().toString();
             QString prenom=index.sibling(index.row(),1).data().toString();
             QString email=index.sibling(index.row(),3).data().toString();
             QString password=index.sibling(index.row(),4).data().toString();
             QString role=index.sibling(index.row(),5).data().toString();

             ui->le_tel_2->setText(numtel);
             ui->le_cin_2->setText(cin);
             ui->le_nom_4->setText(nom);
             ui->le_prenom_2->setText(prenom);
             ui->le_email_2->setText(email);
             ui->le_pwd_2->setText(password);
             ui->le_role_3->setText(role);
               ui->les_cin->setText(cin);




}


void materiel::onButtonClicked()
{
        QString selectedText = ui->comboBox_6->currentText();
        if(selectedText=="nom")
          ui->tab_emp->setModel(Emp.affichernom());
        else
        {
            if(selectedText=="cin")
               ui->tab_emp->setModel(Emp.affichercin());
            else
                ui->tab_emp->setModel(Emp.afficheremail());
        }
}


void materiel::on_PDFButton_clicked()
{
    QPrinter printer(QPrinter::PrinterResolution);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName("employes.pdf");

            QPainter painter(&printer);
            painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

            // Get the table view's data model
            QAbstractItemModel *model = ui->tab_emp->model();

            // Set up the table view's visual properties
            ui->tab_emp->setAlternatingRowColors(true);
            ui->tab_emp->resizeColumnsToContents();

            // Draw the table view onto the PDF document
            QRect rect = painter.viewport();
            int headerHeight = painter.fontMetrics().height();
            int pageHeight = rect.height() - headerHeight;
            int currentPage = 0;
            int totalPages = ceil(ui->tab_emp->height() / pageHeight);
            do {
                painter.drawText(10, 10, QString("Page %1 of %2").arg(currentPage+1).arg(totalPages));
                if (currentPage > 0) {
                    printer.newPage();
                }
                QRect pageRect(0, headerHeight, rect.width(), pageHeight);
                painter.setViewport(pageRect);
                ui->tab_emp->render(&painter, QPoint(), QRegion(), QWidget::DrawChildren);
                currentPage++;
            } while (painter.viewport().bottom() < ui->tab_emp->height());
            painter.save();
                    painter.setOpacity(0.2); // Set the opacity of the watermark
                    QFont font = painter.font();
                    font.setPointSize(45); // size of the watermark text
                    font.setBold(true); // font weight of the watermark text
                    painter.setFont(font);
                    painter.drawText(QRect(0, 0, printer.width(), printer.height()), Qt::AlignCenter, "Employes table RDI Center"); // Draw the watermark text
                    painter.restore();

}



void materiel::on_pushButton_4_clicked()
{

    QSqlQuery query;
        query.prepare("SELECT role, COUNT(*) FROM employe GROUP BY role");
        query.exec();

        QMap<QString, int> employeeCounts;

        while (query.next()) {
            QString roleName = query.value("role").toString();
            int employeeCount = query.value(1).toInt();
            employeeCounts[roleName] = employeeCount;
        }

        QPieSeries *series = new QPieSeries();

        QMapIterator<QString, int> i(employeeCounts);
        while (i.hasNext()) {
            i.next();
            QString roleName = i.key();
            int employeeCount = i.value();
            QPieSlice *slice = series->append(roleName, employeeCount);
            slice->setLabel(QString("%1 (%2)").arg(roleName).arg(employeeCount));
        }


        QChart *chart = new QChart();
                    chart->addSeries(series);
                    chart->setTitle("Employes Roles Stats");
                    QChartView *chartView = new QChartView(chart);
                    chartView->setRenderHint(QPainter::Antialiasing);
                    chartView->resize(800, 600);
                    chartView->show();
    }


void materiel::on_lineEdit_8_textChanged(const QString &searchterm)
{
    QString query = "SELECT * FROM EMPLOYE WHERE CIN LIKE '%" + searchterm + "%' ";

        QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery(query);
        ui->tab_emp->setModel(model);
}

void sendSMS(QString phoneNumber, QString message) {
    QString twilioSID = "AC5228336343591367be0e3ab3fc0b9217";
    QString twilioAuthToken = "45c891eddaaf808894260713cf74f0d2";
    QString twilioNumber = "+16203838314";

    QUrl url(QString("https://api.twilio.com/2010-04-01/Accounts/%1/Messages.json").arg(twilioSID));

    QUrlQuery query;
    query.addQueryItem("From", twilioNumber);
    query.addQueryItem("To", phoneNumber);
    query.addQueryItem("Body", message);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setRawHeader("Authorization", "Basic " + QByteArray(QString("%1:%2").arg(twilioSID).arg(twilioAuthToken).toUtf8()).toBase64());

    QNetworkAccessManager manager;
    QNetworkReply *reply = manager.post(request, query.toString(QUrl::FullyEncoded).toUtf8());

    while (!reply->isFinished()) {
        qApp->processEvents();
    }

    if (reply->error() == QNetworkReply::NoError) {
        qDebug() << "SMS sent successfully";
    } else {
        qDebug() << "SMS sending failed:" << reply->errorString();
    }

    reply->deleteLater();
}

void materiel::sendSMS(QString account_sid, QString auth_token, QString message, QString from_number, QString to_number, QString picture_url, bool verbose)
{
    if (account_sid.isEmpty() || auth_token.isEmpty() || message.isEmpty() || from_number.isEmpty() || to_number.isEmpty()) {
           qDebug() << "You didn't include all necessary inputs!";
           qDebug() << "Call using -h for help.";
           return;
       }

       QUrl url("https://api.twilio.com/2010-04-01/Accounts/" + account_sid + "/Messages.json");
       QNetworkRequest request(url);
       QByteArray auth = QString("%1:%2").arg(account_sid, auth_token).toLocal8Bit().toBase64();
       request.setRawHeader("Authorization", "Basic " + auth);
       request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

       QUrlQuery params;
       params.addQueryItem("From", from_number);
       params.addQueryItem("To", to_number);
       params.addQueryItem("Body", message);
       if (!picture_url.isEmpty()) {
           params.addQueryItem("MediaUrl", picture_url);
       }

       QNetworkAccessManager *manager = new QNetworkAccessManager(this);
       QNetworkReply *reply = manager->post(request, params.toString(QUrl::FullyEncoded).toUtf8());

       QObject::connect(reply, &QNetworkReply::finished, [=](){
           QString response = QString(reply->readAll());
           if (reply->error() != QNetworkReply::NoError) {
               qDebug() << "Message send failed.";
               if (verbose && !response.isEmpty()) {
                   qDebug() << "Response:" << response;
               }
           } else {
               if (verbose) {
                   qDebug() << "SMS sent successfully!";
                   qDebug() << "Response:" << response;
               }
           }
           reply->deleteLater();
           manager->deleteLater();
       });

       QObject::connect(manager, &QNetworkAccessManager::authenticationRequired, [&](QNetworkReply *reply, QAuthenticator *authenticator){
           Q_UNUSED(reply);
           authenticator->setUser(account_sid);
           authenticator->setPassword(auth_token);
       });
}


void materiel::on_pushButton_7_clicked()
{
        QString account_sid = "AC5228336343591367be0e3ab3fc0b9217";
        QString auth_token = "3401176baebfc5ae2fe15b85170fc2c9";
        QString from_number = "+16203838314"; // votre numéro Twilio
        //QString to_number = "+21698755023"; // numéro de téléphone du destinataire
        QString to_number = ui->phoneNumberLineEdit->text();
        //QString message = "Hello, world!"; // message à envoyer
        QString message = ui->messageTextEdit->text();
        QString picture_url = ""; // URL de l'image, si vous voulez en envoyer une
        bool verbose = true; // afficher les messages de débogage ou non

        sendSMS(account_sid, auth_token, message, from_number, to_number, picture_url, verbose);

}

////////////////// amino //////////////////////////////


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
        QString password = "qfdfpsmfppqucpen";
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


















/////////yassine ////////////
void materiel::on_add_here_clicked()
{
                    if(ui->le_id_2->text().isEmpty()){
                        QMessageBox::warning(this, "Erreur", "ID est requis");
                        ui->le_id_2->setStyleSheet("color: white;");
                    }else if(ui->le_commercial->text().isEmpty()){
                        QMessageBox::warning(nullptr, QObject::tr("Not OK"),
                                    QObject::tr("Date d'expiration est requis.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
                    }else if(ui->le_dci->text().isEmpty()){
                        QMessageBox::warning(nullptr, QObject::tr("Not OK"),
                                    QObject::tr("Date d'expiration est requis.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
                    }else if(ui->le_dosage->text().isEmpty()){
                        QMessageBox::warning(nullptr, QObject::tr("Not OK"),
                                    QObject::tr("Date d'expiration est requis.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
                    }else if(ui->le_ds->text().isEmpty()){
                        QMessageBox::warning(nullptr, QObject::tr("Not OK"),
                                    QObject::tr("Date d'expiration est requis.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
                    }
                    else if(ui->le_de->text().isEmpty()){
                        QMessageBox::warning(nullptr, QObject::tr("Not OK"),
                                    QObject::tr("Date d'expiration est requis.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
                    }
                else{

    int id_med=ui->le_id_2->text().toInt();
    QString nom_c=ui->le_commercial->text();
    QString dci=ui->le_dci->text();
    int dosage=ui->le_dosage->text().toInt();
    QString date_s=ui->le_ds->text();
    QString date_d=ui->le_de->text();

    medicament m(id_med,nom_c,dci,dosage,date_s,date_d);

    bool test=m.ajouter();

    if(test)
    {
        ui->table_meds->setModel(mtp.afficher());
        ui->table_meds_3->setModel(mtp.afficher());
        ui->table_meds_4->setModel(mtp.afficher());
        ui->table_meds_5->setModel(mtp.afficher());
        ui->table_meds_6->setModel(mtp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Ajout effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else{
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("Ajout non effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
                }
}

void materiel::on_pb_delete_clicked()
{
        int id_med = ui->searchBox_3->text().toInt();

    if(ui->searchBox_3->text().isEmpty()){
        QMessageBox::warning(this, "Erreur", "ID est requis");
        ui->searchBox_3->setStyleSheet("color: white;");
    }
    else
    {
    bool test=mtp.supprimer(id_med);

    if(test)
    {
        ui->table_meds->setModel(mtp.afficher());
        ui->table_meds_3->setModel(mtp.afficher());
        ui->table_meds_4->setModel(mtp.afficher());
        ui->table_meds_5->setModel(mtp.afficher());
        ui->table_meds_6->setModel(mtp.afficher());
}
    else{
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("Suppressio, non effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}
}


void materiel::on_update_clicked()
{

    if(ui->line_id->text().isEmpty()){
        QMessageBox::warning(this, "Erreur", "ID est requis");
        ui->line_id->setStyleSheet("color: white;");
    }
    else{
        int id_med=ui->line_id->text().toInt();
        QString nom_c=ui->line_c->text();
        QString dci=ui->line_dci->text();
        int dosage=ui->line_dosage->text().toInt();
        QString date_s=ui->line_ds->text();
        QString date_d=ui->line_de->text();

        medicament E(id_med,nom_c,dci,dosage,date_s,date_d);

        bool test=E.modifier();
        if(test)
        {
            ui->table_meds->setModel(mtp.afficher());
            ui->table_meds_3->setModel(mtp.afficher());
            ui->table_meds_4->setModel(mtp.afficher());
            ui->table_meds_5->setModel(mtp.afficher());
            ui->table_meds_6->setModel(mtp.afficher());

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


void materiel::on_table_meds_3_clicked(const QModelIndex &index)
{
             int id_med=index.sibling(index.row(),0).data().toInt();
             QString commercial=index.sibling(index.row(),1).data().toString();
             QString dci=index.sibling(index.row(),2).data().toString();
             QString dosage=index.sibling(index.row(),3).data().toString();
             QString dateSortie=index.sibling(index.row(),4).data().toString();
             QString dateExpire=index.sibling(index.row(),5).data().toString();

             ui->line_id->setText(QString::number(id_med));
             ui->line_c->setText(commercial);
             ui->line_dci->setText(dci);
             ui->line_dosage->setText(dosage);
             ui->line_ds->setText(dateSortie);
             ui->line_de->setText(dateExpire);
}


void materiel::on_table_meds_4_clicked(const QModelIndex &index)
{
        int id_med=index.sibling(index.row(),0).data().toInt();
        ui->searchBox_3->setText(QString::number(id_med));
}

void materiel::on_table_meds_5_clicked(const QModelIndex &index)
{
    int id_med=index.sibling(index.row(),0).data().toInt();
    QString commercial=index.sibling(index.row(),1).data().toString();
    QString dci=index.sibling(index.row(),2).data().toString();
    QString dosage=index.sibling(index.row(),3).data().toString();
    QString dateSortie=index.sibling(index.row(),4).data().toString();
    QString dateExpire=index.sibling(index.row(),5).data().toString();

    ui->notif_id->setText(QString::number(id_med));
    ui->notif_cm->setText(commercial);
    ui->notif_dci->setText(dci);
    ui->notif_d->setText(dosage);
    ui->notif_ds->setText(dateSortie);
    ui->notif_de->setText(dateExpire);
}

void materiel::showNotification(const QString &title, const QString &message)
{
    trayIcon->showMessage(title, message, QSystemTrayIcon::Information, 5000);
}

void materiel::on_update_2_clicked()
{
    QString message = ui->notif_de->text();
    QString dateString2 = "28/04/2023";
    QDateTime date = QDateTime::fromString(message, "dd/MM/yyyy");
    QDateTime currentTime = QDateTime::fromString(dateString2, "dd/MM/yyyy");
    if (date > currentTime) {
        showNotification("La date du médicament n'est pas expiré !", message);
    } else if (date < currentTime) {
        showNotification("La date du médicament est expiré  !", message);
    } else {
        showNotification("ATTENTION : La date du médicament expire aujourd'hui !", message);
    }
}

void materiel::on_comboBox_2_currentIndexChanged(int index)
{
    QString columnName = ui->comboBox_2->itemText(index);
    if(columnName=="Identifiant")
    {
        int columnIndex = ui->table_meds->model()->headerData(1, Qt::Horizontal).toStringList().indexOf(columnName);
        proxyModel->sort(0, Qt::AscendingOrder);
    }
    else if(columnName=="Nom du produit")
    {
        int columnIndex = ui->table_meds->model()->headerData(2, Qt::Horizontal).toStringList().indexOf(columnName);
        proxyModel->sort(1, Qt::AscendingOrder);
    }
    else if(columnName=="Nom DCI")
    {
        int columnIndex = ui->table_meds->model()->headerData(3, Qt::Horizontal).toStringList().indexOf(columnName);
        proxyModel->sort(2, Qt::AscendingOrder);
    }
    else if(columnName=="dosage")
    {
        int columnIndex = ui->table_meds->model()->headerData(4, Qt::Horizontal).toStringList().indexOf(columnName);
        proxyModel->sort(3, Qt::AscendingOrder);
    }
    else if(columnName=="Date de sortie")
    {
        int columnIndex = ui->table_meds->model()->headerData(5, Qt::Horizontal).toStringList().indexOf(columnName);
        proxyModel->sort(4, Qt::AscendingOrder);
    }
    else if(columnName=="Date d'expiration")
    {
        int columnIndex = ui->table_meds->model()->headerData(6, Qt::Horizontal).toStringList().indexOf(columnName);
        proxyModel->sort(5, Qt::AscendingOrder);
    }
}

void materiel::on_pb_pdf_clicked()
{
    // Get the database connection
    QSqlDatabase db = QSqlDatabase::database();

    // Create a QPrinter object and set its properties
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setOutputFileName("medicaments.pdf");

    // Create a QPainter object and set its properties
    QPainter painter(&printer);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);

    // Create a QSqlQuery object and execute the query
    QSqlQuery query("SELECT * FROM meds", db);

    // Create a QTextDocument object and set its properties
    QTextDocument doc;
    doc.setPageSize(QPageSize(QPageSize::A4).size(QPageSize::Point));
    QString styleSheet = "title { font-family: Arial;font-size: 24px;color: blue;}"
                         "h1 {font-family: 'Poppins', sans-serif;font-weight: 700;font-size: 30px;color: #333;text-transform: uppercase;letter-spacing: 4px;text-align: center;margin-top: 50px;}"
                         "h2 {font-family: 'Poppins', sans-serif;font-weight: 300;font-size: 30px;color: #333;text-transform: uppercase;letter-spacing: 4px;text-align: center;}"
                         "table { width: 100%; border-collapse: collapse; border-spacing: 0; font-size: 0.9em; win-width: 400px; margin: 25px 0;}"
                         "table thead { background-color: #e5e5e5; }"
                         "table thead th { padding: 8px; border-bottom: 2px solid #bfbfbf; text-align: left; font-weight: 600; }"
                         "table thead tr { background-color:#009879; color:#ffffff; text-align: left; font-weight: bold;}"
                         "table tbody tr{ border-bottom: 1px solid #dddddd;}"
                         "table tbody tr:nth-of-type(even){ background-color: #f3f3f3;}"
                         "table tbody tr:last-of-type { border-bottom: 2px solid #009879;}"
                         "table tbody td { padding: 8px; border-bottom: 1px solid #bfbfbf; }";
    doc.setDefaultStyleSheet(styleSheet);


    // Populate the QTextDocument with data from the QSqlQuery
    QString html = "<center><br><h2>Liste des médicaments</h2><table><thead><tr><th>identifiant</th><th>nom commercial</th><th>nom dci</th><th>dosage</th><th>date de sortie</th><th>date d'expiration</th><th>code à barre</th></tr></thead><tbody>";
    while (query.next()) {
        QString id_med = query.value(0).toString();
        QString nom_c = query.value(1).toString();
        QString dci = query.value(2).toString();
        QString dosage = query.value(3).toString();
        QString date_s = query.value(4).toString();
        QString date_d = query.value(5).toString();
        QString cab = query.value(6).toString();
        html += "<head><title></title></head><body><tr><td>" + id_med + "</td><td>" + nom_c + "</td><td>" + dci + "</td><td>" + dosage + "</td><td>" + date_s + "</td><td>" + date_d + "</td><td>" + cab + "</td></tr>";
    }
    QImage image("signature.png");
    QRect rect(320, 650, 200, 200); // Set the position and size of the image
    painter.drawImage(rect, image);
    html += "</tbody></table>";
    doc.setHtml(html);

    // Draw the QTextDocument to the QPainter
    doc.drawContents(&painter);
}

void materiel::on_searchBox_4_textChanged(const QString &arg1)
{
    QString searchText = ui->searchBox_4->text();
    QRegularExpression regExp(searchText, QRegularExpression::CaseInsensitiveOption);
    proxyModel->setFilterRegularExpression(regExp);
}

void materiel::on_statspb_clicked()
{
    int d500 = 0, d1000 = 0;

    QSqlQuery query;

    // Compter le nombre des meds ou le dosage est 500g
    query.prepare("SELECT COUNT(*) FROM MEDS WHERE DOSAGE = '500'");
    if (query.exec() && query.next()) {
            d500 = query.value(0).toInt();
    }

    // Compter le nombre des meds ou le dosage est 1000g
    query.prepare("SELECT COUNT(*) FROM MEDS WHERE DOSAGE = '1000'");
    if (query.exec() && query.next()) {
            d1000 = query.value(0).toInt();
    }

    QPieSeries *series = new QPieSeries();
    series->setHoleSize(0.25);
    series->append("500g", d500);
    series->append("1000g", d1000);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setTitle("Dosage des médicaments");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->setTheme(QChart::ChartThemeDark);
    series->setHoleSize(0.35);
    series->setPieSize(0.7);
    series->setVerticalPosition(0.6);
    series->setLabelsVisible(true);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(600, 500);
    chartView->show();

    // Create a layout to add the chart view to
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(chartView);
    layout->setAlignment(Qt::AlignCenter);
    layout->setContentsMargins(50, 80, 100, 100);
    layout->setSpacing(100);
}


void materiel::on_generatepb_clicked()
{
    QString data = m_lineEdit->text();
    zxing::BarcodeFormat format = zxing::BarcodeFormat::CODE_128; // Change the format to the desired barcode format
    int width = 200; // Change the width and height to the desired size
    int height = 200;
    QImage barcode = QZXing::encodeData(data, QZXing::EncoderFormat_QR_CODE, QSize(width, height), QZXing::EncodeErrorCorrectionLevel_H);
    QPixmap qrCodePixmap = QPixmap::fromImage(barcode);

    // Save the QR code image as a file
    QString fileName = "barcodemeds.png";
    if(qrCodePixmap.save(fileName)) {
            qDebug() << "QR code image saved as file: " << fileName;
    } else {
            qDebug() << "Failed to save QR code image as file: " << fileName;
    }

    // Load the QR code image
    QImage qrCodeImage("barcodemeds.png");

    // Create a QZXing decoder object
    QZXing decoder;

    // Decode the QR code image
    QString qrCodeData = decoder.decodeImage(qrCodeImage);

    // Convert the QR code data to a barcode format
    QString barcodeData;
    for (int i = 0; i < qrCodeData.length(); i++) {
            barcodeData += QString::number(qrCodeData[i].unicode(), 16);
    }

    // Output the barcode data
    qDebug() << "Barcode data: " << barcodeData;

    int id_med=ui->le_idg->text().toInt();
    bool test=mtp.ajouterCAB(id_med,barcodeData);

    if(test)
    {
            ui->table_meds->setModel(mtp.afficher());
            ui->table_meds_3->setModel(mtp.afficher());
            ui->table_meds_4->setModel(mtp.afficher());
            ui->table_meds_5->setModel(mtp.afficher());
            ui->table_meds_6->setModel(mtp.afficher());
            QMessageBox::information(nullptr, QObject::tr("OK"),
                                     QObject::tr("Code à barre crée.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else{
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("Code à barre non crée.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void materiel::on_comboBox_3_currentIndexChanged(int index)
{
    QString columnName = ui->comboBox_3->itemText(index);
    if(columnName=="Code 128")
    {
            QZXing* decoder = new QZXing(QZXing::DecoderFormat_CODE_128);

            QString fileName = QFileDialog::getOpenFileName(this, tr("Ouvrir Image"), ".", tr("Fichiers Images (*.png *.jpg *.bmp)"));
            if (fileName.isEmpty()) {
            return;
            }
            QImage image(fileName);
            if (image.isNull()) {
            QMessageBox::warning(this, tr("Erreur"), tr("Chargement Impossible %1.").arg(fileName));
            return;
            }
            QString decodedText = decoder->decodeImage(image);

            if(decodedText != ""){
            qDebug() << "Barcode data: " << decodedText;
            }
            int id_med=ui->le_idg->text().toInt();
            bool test=mtp.ajouterCAB(id_med,decodedText);

            if(test)
            {
            ui->table_meds->setModel(mtp.afficher());
            ui->table_meds_3->setModel(mtp.afficher());
            ui->table_meds_4->setModel(mtp.afficher());
            ui->table_meds_5->setModel(mtp.afficher());
            ui->table_meds_6->setModel(mtp.afficher());
            QMessageBox::information(nullptr, QObject::tr("OK"),
                                     QObject::tr("Code à barre modifié.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else{
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("Code à barre non modifié.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
            }
    }
    else if(columnName=="Code 39")
    {
            QZXing* decoder = new QZXing(QZXing::DecoderFormat_CODE_39);

            QString fileName = QFileDialog::getOpenFileName(this, tr("Ouvrir Image"), ".", tr("Fichiers Images (*.png *.jpg *.bmp)"));
            if (fileName.isEmpty()) {
            return;
            }
            QImage image(fileName);
            if (image.isNull()) {
            QMessageBox::warning(this, tr("Erreur"), tr("Chargement Impossible %1.").arg(fileName));
            return;
            }
            QString decodedText = decoder->decodeImage(image);

            if(decodedText != ""){
            //this->acceptDrops();
            qDebug() << "Barcode data: " << decodedText;
            }
            int id_med=ui->le_idg->text().toInt();
            bool test=mtp.ajouterCAB(id_med,decodedText);

            if(test)
            {
            ui->table_meds->setModel(mtp.afficher());
            ui->table_meds_3->setModel(mtp.afficher());
            ui->table_meds_4->setModel(mtp.afficher());
            ui->table_meds_5->setModel(mtp.afficher());
            ui->table_meds_6->setModel(mtp.afficher());
            QMessageBox::information(nullptr, QObject::tr("OK"),
                                     QObject::tr("Code à barre modifié.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else{
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("Code à barre non modifié.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
            }
    }
    else if(columnName=="Code 93")
    {
            QZXing* decoder = new QZXing(QZXing::DecoderFormat_CODE_93);

            QString fileName = QFileDialog::getOpenFileName(this, tr("Ouvrir Image"), ".", tr("Fichiers Images (*.png *.jpg *.bmp)"));
            if (fileName.isEmpty()) {
            return;
            }
            QImage image(fileName);
            if (image.isNull()) {
            QMessageBox::warning(this, tr("Erreur"), tr("Chargement Impossible %1.").arg(fileName));
            return;
            }
            QString decodedText = decoder->decodeImage(image);

            if(decodedText != ""){
            qDebug() << "Barcode data: " << decodedText;
            }
            int id_med=ui->le_idg->text().toInt();
            bool test=mtp.ajouterCAB(id_med,decodedText);

            if(test)
            {
            ui->table_meds->setModel(mtp.afficher());
            ui->table_meds_3->setModel(mtp.afficher());
            ui->table_meds_4->setModel(mtp.afficher());
            ui->table_meds_5->setModel(mtp.afficher());
            ui->table_meds_6->setModel(mtp.afficher());
            QMessageBox::information(nullptr, QObject::tr("OK"),
                                     QObject::tr("Code à barre modifié.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else{
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("Code à barre non modifié.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
            }
    }
    else if(columnName=="EAN-13")
    {
            QZXing* decoder = new QZXing(QZXing::DecoderFormat_EAN_13);

            QString fileName = QFileDialog::getOpenFileName(this, tr("Ouvrir Image"), ".", tr("Fichiers Images (*.png *.jpg *.bmp)"));
            if (fileName.isEmpty()) {
            return;
            }
            QImage image(fileName);
            if (image.isNull()) {
            QMessageBox::warning(this, tr("Erreur"), tr("Chargement Impossible %1.").arg(fileName));
            return;
            }
            QString decodedText = decoder->decodeImage(image);

            if(decodedText != ""){
            qDebug() << "Barcode data: " << decodedText;
            }
            int id_med=ui->le_idg->text().toInt();
            bool test=mtp.ajouterCAB(id_med,decodedText);

            if(test)
            {
            ui->table_meds->setModel(mtp.afficher());
            ui->table_meds_3->setModel(mtp.afficher());
            ui->table_meds_4->setModel(mtp.afficher());
            ui->table_meds_5->setModel(mtp.afficher());
            ui->table_meds_6->setModel(mtp.afficher());
            QMessageBox::information(nullptr, QObject::tr("OK"),
                                     QObject::tr("Code à barre modifié.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else{
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("Code à barre non modifié.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
            }
    }
}



///////////////////////////// moheb ////////////////////////////////

void materiel::on_pb_add_clicked()
{


    int CIN_c=ui->textcin->text().toInt();
    QString nom=ui->textnom->text();
    QString prenom=ui->textprenom->text();
    int age=ui->textage->text().toInt();
    QString email=ui->textemail->text();
    QDate currentDate;


    chercheur m(CIN_c, nom, prenom, age, email,currentDate);

    bool test=m.ajouter();

    if(test)
    {
        ui->table_c->setModel(ctp.afficher());  //Actualise automatique de la liste des chercheurs


        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectue.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectue.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}


void materiel::on_pb_deletechercheur_clicked()
{
    int CIN_c = ui->textcindelete->text().toInt();

    bool test=ctp.supprimer(CIN_c);

    if(test)
    {

        ui->table_c->setModel(ctp.afficher());

        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppression, effectue.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Suppression, non effectue.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void materiel::on_pb_update_clicked()
{
    int CIN_c=ui->textcinupdate->text().toInt();
    QString nom=ui->textnomupdate->text();
    QString prenom=ui->textprenomupdate->text();
    int age=ui->textageupdate->text().toInt();
    QString email=ui->textemailupdate->text();
    QDate currentDate;

    chercheur E(CIN_c, nom, prenom, age, email, currentDate);

    bool test=E.modifier();
    if(test)
    {

        ui->table_c->setModel(ctp.afficher());

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


void materiel::on_pb_history_clicked()
{
    // Récupération de l'ID entré par l'utilisateur
    int CIN_C = ui->textcinhistory->text().toInt();

    // Recherche de la livraison dans la base de données à partir de l'ID
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT currentDate FROM chercheur WHERE CIN_C = :CIN_C");

    query.bindValue(":CIN_C", CIN_C);

    if(query.exec())
    {
        model->setQuery(query);
        ui->table_ch->setModel(model);
    }

}

void materiel::on_bptriasc_clicked()
{
    int CIN_c=ui->textcin->text().toInt();
    QString nom=ui->textnom->text();
    QString prenom=ui->textprenom->text();
    int age=ui->textage->text().toInt();
    QString email=ui->textemail->text();
    QDate currentDate;
    chercheur m(CIN_c, nom, prenom, age, email, currentDate);
    ui->table_c->setModel(ctp.afficherTriCroissant());
}


void materiel::on_pbtridsc_clicked()
{
    int CIN_c=ui->textcin->text().toInt();
    QString nom=ui->textnom->text();
    QString prenom=ui->textprenom->text();
    int age=ui->textage->text().toInt();
    QString email=ui->textemail->text();
    QDate currentDate;
    chercheur m(CIN_c, nom, prenom, age, email, currentDate);
    ui->table_c->setModel(ctp.afficherTriDecroissant());
}


void materiel::on_pb_searchC_clicked()
{
    QString CIN_C = ui->txtsearch_C->text();
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM chercheur WHERE  CIN_C LIKE :CIN_C");
    query.bindValue(":CIN_C", "%" + CIN_C + "%");
    if(query.exec())
    {
        model->setQuery(query);
        ui->table_c->setModel(model);
    }
}

void materiel::on_pb_statistiques_clicked()
{
    int d500 = 0, d1000 = 0;

    QSqlQuery query;

    // Compter le nombre des chercheurs ou leurs ages sont <50
    query.prepare("SELECT COUNT(*) FROM chercheur WHERE age < 50");
    if (query.exec() && query.next()) {
        d500 = query.value(0).toInt();
    }

    // Compter le nombre des chercheurs ou leurs ages sont >=50
    query.prepare("SELECT COUNT(*) FROM chercheur WHERE age >= 50");
    if (query.exec() && query.next()) {
        d1000 = query.value(0).toInt();
    }

    QPieSeries *series = new QPieSeries();
    series->setHoleSize(0.25);
    series->append("-50 ans", d500);
    series->append("+50 ans", d1000);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setTitle("Age Des Chercheurs");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->setTheme(QChart::ChartThemeDark);
    series->setHoleSize(0.35);
    series->setPieSize(0.7);
    series->setVerticalPosition(0.6);
    series->setLabelsVisible(true);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(600, 500);
    chartView->show();

    // Create a layout to add the chart view to
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(chartView);
    layout->setAlignment(Qt::AlignCenter);
    layout->setContentsMargins(50, 80, 100, 100);
    layout->setSpacing(100);
}


void materiel::on_pb_pdfchercheur_clicked()
{

    QString strTitle="chercheurs" ;
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter le tableau au format PDF", QString(), "*.pdf");
    if (!fileName.isEmpty()) {
        QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->table_ch->model()->rowCount();
        const int columnCount = ui->table_ch->model()->columnCount();

        QPainter painter;
        QPixmap image("notif.png");
        QRectF targetRect(100, 100, 300, 200);
        QRectF sourceRect(0, 0, image.width(), image.height());
        painter.drawPixmap(targetRect, image, sourceRect);

        out <<  "<html>\n"
               "<head>\n"
               "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            <<  QString("<title>%1</title>\n").arg(strTitle)
            <<  "</head>\n"
               "<body bgcolor=#ffffff link=#5000A0>\n"
               "<table border=1 cellspacing=0 cellpadding=2 margin-left=60px >\n";

        // headers
        out << "<thead><tr bgcolor=#f0f0f0>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->table_ch->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->table_ch->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->table_ch->isColumnHidden(column)) {
                    QString data = ui->table_ch->model()->data(ui->table_ch->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }
        out <<  "</table>\n"
               "</body>\n"
               "</html>\n";

        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(fileName);
        document->print(&printer);
    }
}


void materiel::on_txtsearch_C_textChanged(const QString &arg1)
{
    QString CIN_C = ui->txtsearch_C->text();
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM chercheur WHERE  CIN_C LIKE :CIN_C");
    query.bindValue(":CIN_C", "%" + CIN_C + "%");
    if(query.exec())
    {
        model->setQuery(query);
        ui->table_c->setModel(model);
    }
}


void materiel::on_pb_pdf_all_clicked()
{
    // Create a PDF file
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);

    QString fileName = QFileDialog::getSaveFileName((QWidget*)0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) {
        fileName.append(".pdf");
    }
    printer.setOutputFileName(fileName);

    // Extract data from the database
    QSqlQuery query;
    query.prepare("SELECT * FROM chercheur");
    query.exec();

    // Create the table
    int numColumns = query.record().count();
    int numRows = 0;
    while(query.next()) {
        numRows++;
    }

    int cellWidth = 95;
    int cellHeight = 30;
    int margin = 10;
    int tableWidth = numColumns * cellWidth;
    int tableHeight = (numRows + 1) * cellHeight;
    QRectF tableRect(margin, margin + 250, tableWidth, tableHeight);

    QPainter painter;
    painter.begin(&printer);



    // Draw the title
    QFont titleFont("Time New Roman", 25, QFont::Bold);
    QPen titlePen(Qt::red);
    painter.setFont(titleFont);
    painter.setPen(titlePen);
    painter.drawText(QRectF(0, margin, printer.width(), 200), Qt::AlignCenter, "Liste des Chercheurs");

    // Draw the table header
    QFont headerFont("Arial", 12, QFont::Bold);
    QPen headerPen(Qt::black);
    headerPen.setWidth(1);
    painter.setFont(headerFont);
    painter.setPen(headerPen);


    for (int i = 0; i < numColumns; i++) {
        QString columnName = query.record().fieldName(i);
        QRectF cellRect(margin + i * cellWidth, margin + 250 + cellHeight, cellWidth, cellHeight);
        // painter.drawRect(cellRect);
        painter.fillRect(cellRect, QColor(80, 96, 233
                                          ));
        painter.drawText(cellRect, Qt::AlignCenter, columnName);
    }

    // Draw the table body
    QFont bodyFont("Arial", 10);
    QPen bodyPen(Qt::black);
    bodyPen.setWidth(1);
    painter.setFont(bodyFont);
    painter.setPen(bodyPen);
    int row = 1;
    query.first();
    while(query.isValid()) {
        for (int i = 0; i < numColumns; i++) {
            QString cellValue = query.value(i).toString();
            QRectF cellRect(margin + i * cellWidth, margin + 250 + row * cellHeight + cellHeight, cellWidth, cellHeight);
            painter.drawRect(cellRect);
            painter.drawText(cellRect, Qt::AlignCenter, cellValue);
        }
        query.next();
        row++;
    }

    // Add the logo at the top
    QImage logoImage("C:/Users/Mouheb/Desktop/c1/labosmartchercheur.png");
    painter.drawImage(QRectF(margin, margin, 200, 50), logoImage);

    painter.end();
}


void materiel::on_bptriasc_2_clicked()
{
    int CIN_c=ui->textcin->text().toInt();
    QString nom=ui->textnom->text();
    QString prenom=ui->textprenom->text();
    int age=ui->textage->text().toInt();
    QString email=ui->textemail->text();
    QDate currentDate;
    chercheur m(CIN_c, nom, prenom, age, email, currentDate);
    ui->table_c->setModel(ctp.afficherTriNom());
}


void materiel::on_table_c_clicked(const QModelIndex &index)
{
    int CIN_C=index.sibling(index.row(),0).data().toInt();
    int age=index.sibling(index.row(),3).data().toInt();
    QString prenom=index.sibling(index.row(),2).data().toString();
    QString nom=index.sibling(index.row(),1).data().toString();
    QString email=index.sibling(index.row(),4).data().toString();

    ui->textcindelete->setText(QString::number(CIN_C));
    ui->textcinhistory->setText(QString::number(CIN_C));
    ui->textcinupdate->setText(QString::number(CIN_C));
    ui->textnomupdate->setText(nom);
    ui->textprenomupdate->setText(prenom);
    ui->textageupdate->setText(QString::number(age));
    ui->textemailupdate->setText(email);

}


void materiel::on_pb_excel_clicked()
{
    QVariant value;
    // Execute a query to retrieve data from the database
    QSqlQuery query("SELECT * FROM chercheur");


    // Create a new Excel file
    QXlsx::Document xlsx;
    int row = 1;

    // Retrieve column names from the query result and write them to the first row of the Excel file
    QSqlRecord record = query.record();
    for (int i = 0; i < record.count(); i++) {
        QString columnName = record.fieldName(i);
        xlsx.write(row, i + 1, columnName);
    }

    // Retrieve data from the query result and write them to the Excel file
    row++;
    while (query.next()) {
        QSqlRecord record = query.record();
        for (int i = 0; i < record.count(); i++) {
            value = record.value(i);
            xlsx.write(row, i + 1, value.toString());
        }
        row++;
    }

    // Save the Excel file to a user-selected location
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Save Excel file", "", "Excel files (*.xlsx)");
    if (!fileName.isEmpty()) {
        if (xlsx.saveAs(fileName)) {
            QMessageBox::information(nullptr, "Excel File Saved", "Excel file saved successfully.");
        } else {
            QMessageBox::warning(nullptr, "Excel File Not Saved", "Failed to save Excel file.");
        }
    }
}



////////////////////////////  moheb /////////////////////////////////////











////////////////////////////  amine  /////////////////////////////////////




////// Mouadh Gammoudi /////

void materiel::on_pushButton_15_clicked()
{
    QSqlQuery query(db);
        int ID_S = ui->le_id_s->text().toInt();
        QString NOM = ui->le_nom_5->text();
        QDate DATE_D = ui->date_debut->date();
        QDate DATE_FIN = ui->date_fin->date();
        int NBR_PLACE = ui->spinBox_place->value();
        QString TYPE = ui->comboBox_type->currentText();

        stage s(ID_S , NOM,  DATE_D, DATE_FIN, NBR_PLACE, TYPE);

        bool test = s.ajouter();
        if(test)
        {

            QMessageBox::information(nullptr, QObject::tr("OK"),
                                     QObject::tr("Ajout effectué \n"
                                                 "Click cancel to exit"), QMessageBox::Cancel);

        }
        else
        {
            QSqlError error = query.lastError();
            qDebug() << "Error message: " << error.text();
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("Ajout non effectué \n"
                                              "Click cancel to exit "), QMessageBox::Cancel);
        }
}
void materiel::on_pushButton_26_clicked()
{
    stage etmp;
        int id = ui->le_id_s->text().toInt();
        bool test = etmp.supprimer(id);
        if(test)
        {

            QMessageBox::information(nullptr, QObject::tr("OK"),
                                     QObject::tr("Suppression effectuée \n"
                                                 "Click cancel to exit"), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("Suppression non effectuée \n"
                                              "Click cancel to exit "), QMessageBox::Cancel);
        }
}
void materiel::on_pushButton_24_clicked(){

    int ID_S = ui->le_id_s->text().toInt();
    QString NOM = ui->le_nom_5->text();
    QDate DATE_D = ui->date_debut->date();
    QDate DATE_FIN = ui->date_fin->date();
    int NBR_PLACE = ui->spinBox_place->value();
    QString TYPE = ui->comboBox_type->currentText();

stage s(ID_S , NOM,  DATE_D, DATE_FIN, NBR_PLACE, TYPE);


bool test=s.modifier();
if(test)
{

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
void materiel::on_sortByCombo_2_currentTextChanged(const QString &arg1)
{
    // Get the selected sort column from the combo box
        QString sortColumn = arg1;

        // Call the afficher function with the selected sort column
        stage etmp;
        QSqlQueryModel* model = etmp.afficher(sortColumn);

        // Set the model for the table view to display the results
        ui->afficher_2->setModel(model);
}
void materiel::on_searchLineEdit_2_textEdited(const QString &searchTerm)
{
    QString query = "SELECT * FROM STAGE WHERE ID_S LIKE '%" + searchTerm + "%' OR NOM LIKE '%" + searchTerm + "%' OR DATE_D LIKE '%" + searchTerm + "%' OR DATE_FIN LIKE '%" + searchTerm + "%' OR NBR_PLACE LIKE '%" + searchTerm + "%' OR TYPE LIKE '%" + searchTerm + "%'";

    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(query);
    ui->afficher_2->setModel(model);
}
void materiel::on_pdf_2_clicked()
{
    QSqlDatabase db = QSqlDatabase::database();


         QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPageSize(QPageSize(QPageSize::A4));
        printer.setOutputFileName("Stages.pdf");


        QPainter painter(&printer);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setRenderHint(QPainter::TextAntialiasing);


        QSqlQuery query("SELECT * FROM STAGE", db);


        QTextDocument doc;
        doc.setPageSize(QPageSize(QPageSize::A4).size(QPageSize::Point));
        QString styleSheet = "body {background-image: url('C:/Users/Chma3/Desktop/smartlab/slab.png'); background-repeat: no-repeat; background-size: cover;}"
                             "table { margin:10px;width: 90%; border-collapse: collapse; border-spacing: 0; font-family: Arial, sans-serif; font-size: 14px; color: #333; }"
                             "table thead { background-color: #3c763d; color: #fff; }"
                             "h1 {font-family: 'Poppins', sans-serif;font-weight: 700;font-size: 30px;color: #333;text-transform: uppercase;letter-spacing: 4px;text-align: center;margin-top: 50px;}"
                             "h2 {font-family: 'Poppins', sans-serif;font-weight: 300;font-size: 30px;color: #333;text-transform: uppercase;letter-spacing: 4px;text-align: center;}"
                             "table thead th { padding: 8px; border-bottom: 2px solid #3c763d; text-align: center; font-weight: 600; color: #333; }"
                             "table tbody tr:nth-child(even) { background-color: #d9edf7; }"
                             "table tbody td { padding: 8px; border-bottom: 1px solid #ccc; }"
                             "table tbody td:first-child { color: #333; font-weight: 400; }";
        doc.setDefaultStyleSheet(styleSheet);
        QImage image("C:/Users/mdkhe/OneDrive/Documents/materiel/img/slab.png");
        QRect rect(200, 0, 200, 200); // Set the position and size of the image
        painter.drawImage(rect, image);




        QString html = "<center><br><br><br><br><br><br><h2>Smart Lab raport</h2><hr><h1>Liste des stages</h1><table><thead><tr><th>Id</th><th>Nom</th><th>Date debut</th><th>Date fin</th><th>Nembre limite</th><th>Type</th></tr></thead><tbody>";
        while (query.next()) {
            QString ID_S = query.value(0).toString();
            QString Nom = query.value(1).toString();
            QString DATE_D = query.value(2).toString();
            QString DATE_FIN = query.value(3).toString();
            QString NBR_PLACE = query.value(4).toString();
            QString TYPE = query.value(5).toString();

           html += "<tr><td>" + ID_S + "</td><td>" + Nom + "</td><td>" + DATE_D + "</td><td>" + DATE_FIN + "</td><td>" + NBR_PLACE + "</td><td>" + TYPE + "</td><td>";
        }
        html += "</tbody></table>";
        doc.setHtml(html);


        doc.drawContents(&painter);
    QMessageBox::information(nullptr, QObject::tr("OK"),
                             QObject::tr("Export PDF successful."), QMessageBox::Cancel);

        // Cleanup
        painter.end();

}
void materiel::on_afficher_2_doubleClicked(const QModelIndex &index)
{
    // Get the selected row's data
    int row = index.row();
    QString id_s = ui->afficher_2->model()->index(row, 0).data().toString();
    QString nom = ui->afficher_2->model()->index(row, 1).data().toString();
    QDate date_d = ui->afficher_2->model()->index(row, 2).data().toDate();
    QDate date_fin = ui->afficher_2->model()->index(row, 3).data().toDate();;
    QString nbr_place = ui->afficher_2->model()->index(row, 4).data().toString();
    QString type = ui->afficher_2->model()->index(row, 5).data().toString();



    // Display the data in the input fields

    ui->le_id_s->setText(id_s);
    ui->le_nom_5->setText(nom);
    ui->date_debut->setDate(date_d);
    ui->date_fin->setDate(date_fin);
    ui->spinBox_place->setValue(nbr_place.toInt());
    ui->comboBox_type->setCurrentText(type);

}
void materiel::on_calendarWidget_clicked(const QDate &date)
{


        QSqlQuery queryStage;
        queryStage.prepare("SELECT NOM FROM STAGE WHERE :date BETWEEN DATE_D AND DATE_FIN");
        queryStage.bindValue(":date", date);
        queryStage.exec();

        QStringList stageList;
        while (queryStage.next()) {
           QString nom = queryStage.value(0).toString();
           stageList.append(nom);
        }
        if (!stageList.isEmpty()) {
           QString nom = stageList.join("\n");
           ui->stagelabel->setText(nom);
        } else {
           ui->stagelabel->setText("No stage on selected date");
        }
}
void materiel::setupCalendar() {
        // Retrieve the dates from the database
        QList<QDate> holidays;
        QSqlQuery query("SELECT DATE_D, DATE_FIN FROM STAGE");
        while (query.next()) {
           QDate start_date = query.value(0).toDate();
           QDate end_date = query.value(1).toDate();
           while (start_date <= end_date) {
               holidays.append(start_date);
               start_date = start_date.addDays(1);
           }
        }

        // Add a highlight to dates between DATE_D and DATE_FIN
        QTextCharFormat format;
        format.setForeground(Qt::green);
        for (const auto &holiday : holidays) {
           ui->calendarWidget->setDateTextFormat(holiday, format);
        }
}

void materiel::on_show_stat_2_clicked()
{
    etmp.displayInventoryColumnChart();

}
///////////////////////////////////////////// mouadh //////////////////////


///////////////// nour ////////////////////////////



void materiel::on_pb_ajouter_3_clicked()
{
    int id_r=ui->le_id_3->text().toInt();
    QString titre=ui->le_titre->text();
    QString duree=ui->la_duree->text();
    QString date_debut=ui->la_date->text();
    QString resultat=ui->le_resultat->text();
    QString statut=ui->le_statut->text();
    QString event = ui->le_etatt->text() ;
    QString etat_event = "todo" ;


    recherche R(id_r,titre,duree,date_debut,resultat,statut,etat_event,event);

    bool test=R.ajouter();
    if (test)
    {
        ui->afficher_3->setModel(rtp.afficher());
        ui->tab_todo->setModel(rtp.afficherTODO()) ;
        ui->tab_en_cours->setModel(rtp.afficherINPROGRESS()) ;
        ui->tab_done->setModel(rtp.afficherDONE()) ;
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectue\n" "Click cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectue.\n" "Click cancel to exit."),QMessageBox::Cancel);
    }

    ui->le_id_3->clear();
    ui->le_titre->clear();
    ui->la_duree->clear();
    ui->la_date->clear();
    ui->le_resultat->clear();
    ui->le_statut->clear();
    ui->le_etatt->clear() ;
   // ui->le_event->clear();
}
void materiel::on_pb_image_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("choose"),"", tr("Images (*.png *.jpg *.jpeg *.bmp *.gif)"));
    if (QString::compare(filename, QString()) !=0)
    {
        QImage image;
        bool valid = image.load(filename);

        if (valid)
        {
            image = image.scaledToWidth(ui->label_image->width(), Qt::SmoothTransformation);
            image = image.scaledToHeight(ui->label_image->height(), Qt::SmoothTransformation);
            ui->label_image->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            //error

        }
    }
}

void materiel::on_pb_etat_clicked()
{
    QString selectedItem = ui->comboBox_etat->currentText();
    int id_r = ui->le_etat_3->text().toInt() ;


    if (selectedItem == "todo")
    {
        rtp.modifierEtat( id_r ,"todo") ;

        ui->afficher_3->setModel(rtp.afficher());
        ui->tab_todo->setModel(rtp.afficherTODO()) ;
        ui->tab_en_cours->setModel(rtp.afficherINPROGRESS()) ;
        ui->tab_done->setModel(rtp.afficherDONE()) ;
        ui->le_etat_3->clear() ;
    }
    else if (selectedItem == "en_cours")
    {
        rtp.modifierEtat(id_r,"en_cours") ;

        ui->afficher_3->setModel(rtp.afficher());
        ui->tab_todo->setModel(rtp.afficherTODO()) ;
        ui->tab_en_cours->setModel(rtp.afficherINPROGRESS()) ;
        ui->tab_done->setModel(rtp.afficherDONE()) ;
        ui->le_etat_3->clear() ;
    }
    else if (selectedItem == "done")
    {
        rtp.modifierEtat(id_r  ,"done") ;

        ui->afficher_3->setModel(rtp.afficher());
        ui->tab_todo->setModel(rtp.afficherTODO()) ;
        ui->tab_en_cours->setModel(rtp.afficherINPROGRESS()) ;
        ui->tab_done->setModel(rtp.afficherDONE()) ;
        ui->le_etat_3->clear() ;
    }
}


void materiel::on_pb_delete_3_clicked()
{
    int id_r = ui->m_id->text().toInt();

        bool test = rtp.supprimer(id_r);

        if (test)
        {

            ui->afficher_3->setModel(rtp.afficher());
            QMessageBox::information(nullptr, QObject::tr("OK"),
                                     QObject::tr("SUPP effectue\n" "Click cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                  QObject::tr("SUPP non effectue\n" "Click cancel to exit."),QMessageBox::Cancel);
        }
}


void materiel::on_pushButton_28_clicked()
{
    int id_r=ui->m_id->text().toInt();
    QString titre=ui->m_titre->text();
    QString duree=ui->m_duree->text();
    QString date_debut=ui->m_date->text();
    QString resultat=ui->m_resultat->text();
    QString statut=ui->m_statut->text();
    //QString etat_event=ui->m_etat->text();
    //QString event=ui->m_event->text();
    QString event = ui->m_etat->text() ;
    QString etat_event = "TODO" ;

    recherche R(id_r,titre,duree,date_debut,resultat,statut,etat_event,event);

    bool test=R.modifier();
    if(test)
    {

        ui->afficher_3->setModel(rtp.afficher());
        ui->tab_todo->setModel(rtp.afficherTODO()) ;
        ui->tab_en_cours->setModel(rtp.afficherINPROGRESS()) ;
        ui->tab_done->setModel(rtp.afficherDONE()) ;
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


void materiel::on_afficher_3_doubleClicked(const QModelIndex &index)
{
    int id=index.sibling(index.row(),0).data().toInt();
    QString titre=index.sibling(index.row(),1).data().toString();
    QString duree=index.sibling(index.row(),2).data().toString();
    QString date_debut=index.sibling(index.row(),3).data().toString();
    QString resultat=index.sibling(index.row(),4).data().toString();
    QString statut=index.sibling(index.row(),5).data().toString();
    QString etat_event=index.sibling(index.row(),7).data().toString();
    QString event=index.sibling(index.row(),8).data().toString();

    ui->m_id->setText(QString::number(id));
    ui->m_titre->setText(titre);
    ui->m_duree->setText(duree);
    ui->m_date->setText(date_debut);
    ui->m_resultat->setText(resultat);
    ui->m_statut->setText(statut);
    ui->m_etat->setText(etat_event);
   // ui->m_event->setText(event);

}

void materiel::on_pushButton_27_clicked()
{
    QPdfWriter pdf("recherches.pdf");

            QPainter painter(&pdf);
            int i = 4100;
            const QImage image("C:/Users/mdkhe/OneDrive/Documents/materiel/logo.png");
            const QPoint imageCoordinates(155,0);
            int width1 = 1600;
            int height1 = 1600;
            QImage img=image.scaled(width1,height1);
            painter.drawImage(imageCoordinates, img );


            QColor dateColor(0x486b00);
            painter.setPen(dateColor);

            painter.setFont(QFont("Montserrat SemiBold", 11));
            QDate cd = QDate::currentDate();
            painter.drawText(8400,250,cd.toString("Tunis"));
            painter.drawText(8100,500,cd.toString("dd/MM/yyyy"));

            QColor titleColor(0x341763);
            painter.setPen(titleColor);
            painter.setFont(QFont("Montserrat SemiBold", 25));

            QColor color("#486b00");
            painter.setPen(color);
            painter.drawText(3000,2700,"LISTE DES RECHERCHES");

            painter.setPen(Qt::black);
            painter.setFont(QFont("Time New Roman", 15));
            painter.drawRect(100,3300,9400,500);

            painter.setFont(QFont("Montserrat SemiBold", 10));

            /*QPen pen(QColor("#486b00"));
            pen.setWidth(2);
            painter.setPen(pen);
            painter.drawLine(500, 3600, 8000, 100);
            QBrush brush(QColor("#486b00"));
            painter.fillRect(500, 3600, 8000, 100, brush);*/

   /*
            painter.setPen(Qt::black);
            painter.setFont(QFont("Arial", 15));
            QBrush brush(Qt::blue);
            painter.setBrush(brush);
            painter.drawRect(500, 3600, 8000, 100);
           // painter.setFont(QFont("Arial", 10));
   */


            painter.drawText(500,3600,"id_r");
            painter.drawText(2000,3600,"titre");
            painter.drawText(3300,3600,"duree");
            painter.drawText(4500,3600,"date_debut");
            painter.drawText(6000,3600,"resultat");
            painter.drawText(7200,3600,"statut");

            painter.setFont(QFont("Montserrat", 10));
            painter.drawRect(100,3300,9400,9000);

            QSqlQuery query;
            query.prepare("select * from recherches");
            query.exec();
            int y=4300;
            while (query.next())
            {
                   painter.drawLine(100,y,9490,y);
                   y+=500;
                   painter.drawText(500,i,query.value(0).toString());
                   painter.drawText(2000,i,query.value(1).toString());
                   painter.drawText(3300,i,query.value(2).toString());
                   painter.drawText(4500,i,query.value(3).toString());
                   painter.drawText(6000,i,query.value(4).toString());
                   painter.drawText(7200,i,query.value(5).toString());




                   i = i + 500;
            }
            QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
                                     QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}


void materiel::on_searchLineEdit_3_textEdited(const QString &searchTerm)
{

    // Created an QSqlQuery to retrieve all equipment names that match the search query
        QSqlQuery query;
        query.prepare("SELECT * FROM recherches WHERE titre LIKE '%" + searchQuery + "%'");
        query.exec();

     // Created an QStringList to hold the search suggestions
        QStringList suggestions;

       // Add all matching equipment names to the suggestion list
        while (query.next()) {
            suggestions.append(query.value(1).toString());
        }

        // Create a QCompleter object and set the suggestion model
        QCompleter *completer = new QCompleter(suggestions, this);
        completer->setCaseSensitivity(Qt::CaseInsensitive);
        completer->setFilterMode(Qt::MatchContains);

        // Set the completer to the search box
        ui->searchLineEdit_3->setCompleter(completer);
}
void materiel::on_searchnoor_clicked()
{
    // Get the search query from the search box
        QString searchQuery = ui->searchLineEdit_3->text();

        // Create a QSqlQueryModel and set the query
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM recherches WHERE titre LIKE '%" + searchQuery + "%'");

        // Set the model to the table view
        ui->afficher_3->setModel(model);
}


void materiel::on_sortByCombo_3_currentTextChanged(const QString &arg1)
{
    QString trieOption=ui->sortByCombo_3->currentText();
    ui->afficher_3->setModel(rtp.triRecherche(trieOption));
}


void materiel::on_pushButton_25_clicked()
{
    int d500 = 0, d1000 = 0;

    QSqlQuery query;


    query.prepare("SELECT COUNT(*) FROM recherches WHERE statut = terminé");
    if (query.exec() && query.next()) {
        d500 = query.value(0).toInt();
    }

    query.prepare("SELECT COUNT(*) FROM recherches WHERE statut = En cours");
    if (query.exec() && query.next()) {
        d1000 = query.value(0).toInt();
    }

    QPieSeries *series = new QPieSeries();
    series->setHoleSize(0.25);
    series->append("terminé", d500);
    series->append("En cours", d1000);

    QPieSlice *slice = new QPieSlice();
    slice->setExploded();
    slice->setLabelVisible();


    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setTitle("STATUT DES RECHERCHES");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);


    chart->setTheme(QChart::ChartThemeDark);
    chart->setTheme(QChart::ChartThemeBlueCerulean);

    series->setHoleSize(0.35);
    series->setPieSize(0.7);
    series->setVerticalPosition(0.6);
    series->setLabelsVisible(true);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(600, 500);
    chartView->show();

    // Create a layout to add the chart view to
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(chartView);
    layout->setAlignment(Qt::AlignCenter);
    layout->setContentsMargins(50, 80, 100, 100);
    layout->setSpacing(100);

}







void materiel::on_tab_todo_doubleClicked(const QModelIndex &index)
{
    QAbstractItemModel *model = ui->tab_todo->model();
        QString value = model->data(model->index(index.row(), 0)).toString();
        int id_r = value.toInt() ;
        ui->le_etat_3->setText(QString::number(id_r));
}


void materiel::on_tab_en_cours_doubleClicked(const QModelIndex &index)
{
    QAbstractItemModel *model = ui->tab_todo->model();
        QString value = model->data(model->index(index.row(), 0)).toString();
        int id_r = value.toInt() ;
        ui->le_etat_3->setText(QString::number(id_r));
}


void materiel::on_tab_done_doubleClicked(const QModelIndex &index)
{
    QAbstractItemModel *model = ui->tab_todo->model();
        QString value = model->data(model->index(index.row(), 0)).toString();
        int id_r = value.toInt() ;
        ui->le_etat_3->setText(QString::number(id_r));
}


void materiel::on_pushButton_9_clicked()
{
    QString message = ui->code_arduino->text();
    QByteArray data = message.toLocal8Bit();
    A.write_to_arduino(data);
    if(data=="0000"){

    int id;
    QString nom_c;
    QString dci;
    int dosage;
    QString date_s;
    QString date_d;

    medicament m(id,nom_c,dci,dosage,date_s,date_d);

    id=ui->arduino_id->text().toInt();
    bool test1=mtp.ModifierStatus(id);

    if(test1)
    {
            ui->tab_arduino->setModel(mtp.afficher());
            ui->table_meds->setModel(mtp.afficher());
            ui->table_meds_3->setModel(mtp.afficher());
            ui->table_meds_4->setModel(mtp.afficher());
            ui->table_meds_5->setModel(mtp.afficher());
            ui->table_meds_6->setModel(mtp.afficher());
    }
    }
    else
    {
    QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                          QObject::tr("Code incorrect.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

/*void MainWindow::update_label()
{
    QByteArray data = A.read_from_arduino();
    QString message = QString::fromUtf8(data);
    if(message=="0000")
    {
               ui->arduino_label->setText("DOOR OPENED");
    }
    else {
            ui->arduino_label->setText("DOOR CLOSED");
    }
}*/

void materiel::on_pushButton_12_clicked()
{
    QString message = ui->code_arduino_2->text();
    QByteArray data = message.toLocal8Bit();
    A.write_to_arduino(data);
    if(data=="0000"){

    int id;
    QString nom_c;
    QString dci;
    int dosage;
    QString date_s;
    QString date_d;

    medicament m(id,nom_c,dci,dosage,date_s,date_d);

    id=ui->arduino_id_2->text().toInt();
    bool test1=mtp.QtArduino(id);

    if(test1)
    {
            ui->tab_arduino_2->setModel(mtp.afficher());
            ui->table_meds->setModel(mtp.afficher());
            ui->table_meds_3->setModel(mtp.afficher());
            ui->table_meds_4->setModel(mtp.afficher());
            ui->table_meds_5->setModel(mtp.afficher());
            ui->table_meds_6->setModel(mtp.afficher());
    }
    }
    else
    {
    QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                          QObject::tr("Code incorrect.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

/*













*/
