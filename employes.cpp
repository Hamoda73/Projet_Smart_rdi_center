#include "employes.h"
#include "employe.h"
#include "ui_employes.h"
#include "employe.h"
#include <QMessageBox>
#include <QString>
#include <QRegularExpressionValidator>
#include <QSqlQuery>
#include <QLineEdit>
#include <QPrinter>
#include <QPainter>
#include <QPdfWriter>
#include <QVBoxLayout>
  #include <QPlainTextEdit>
  #include <QAuthenticator>
//#include<QtCharts/QPieSeries>
//#include<QChart>
employes::employes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::employes)
{
    ui->setupUi(this);
    ui->le_cin->setValidator (new QIntValidator(0, 99999999, this));
    ui->tab_emp->setModel(Emp.afficher());
    ui->le_cin->setMaxLength(8);
    ui->le_tel->setMaxLength(8);
    ui->le_email->setValidator( new QRegularExpressionValidator(QRegularExpression("[A-Za-z]+[@]+[A-Za-z]+[.]+[A-Za-z]+"), this));
    //ui->le_email->setValidator( new QRegularExpressionValidator(QRegularExpression("[@]+"), this));
    //ui->le_email->setValidator( new QRegularExpressionValidator(QRegularExpression("[.]+"), this));

        // set the input mask to restrict input to a phone number
       // ui->le_email->setInputMask("A9@AAA.AA");

    //qDebug() <<QSqlDatabase::drivers();
    // In the MainWindow constructor or initialization function
    connect(ui->pb_tri, SIGNAL(clicked()), this, SLOT(onButtonClicked()));



}

employes::~employes()
{
    delete ui;
}


void employes::on_pb_ajouter_clicked()
{
    QString numtel=ui->le_tel->text();
    QString cin=ui->le_cin->text();
    QString nom=ui->le_nom->text();
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


void employes::on_pb_supprimer_clicked()
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


void employes::on_pb_modifier_clicked()
{

        QString cin=ui->le_cin_2->text();
        QString numtel=ui->le_tel_2->text();
        QString email=ui->le_email_2->text();
        QString password=ui->le_pwd_2->text();
        QString role=ui->le_role_2->text();
        QString nom=ui->le_nom_2->text();
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

/*void employes::on_pushButton_9_clicked()
{
    ui->tab_emp->setModel(Emp.afficherasc());
}
*/





/*void employes::on_pushButton_10_clicked()
{
    ui->tab_emp->setModel(Emp.afficherdsc());
}
*/

void employes::on_tab_emp_clicked(const QModelIndex &index)
{


             QString numtel=index.sibling(index.row(),6).data().toString();
             QString cin=index.sibling(index.row(),2).data().toString();
             QString nom=index.sibling(index.row(),0).data().toString();
             QString prenom=index.sibling(index.row(),1).data().toString();
             QString email=index.sibling(index.row(),3).data().toString();
             QString password=index.sibling(index.row(),4).data().toString();
             QString role=index.sibling(index.row(),5).data().toString();

             ui->le_tel_2->setText(numtel);
             ui->le_cin_2->setText(cin);
             ui->le_nom_2->setText(nom);
             ui->le_prenom_2->setText(prenom);
             ui->le_email_2->setText(email);
             ui->le_pwd_2->setText(password);
             ui->le_role_3->setText(role);
               ui->les_cin->setText(cin);




}
void employes::onButtonClicked()
    {
        QString selectedText = ui->comboBox->currentText();
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




void employes::on_PDFButton_clicked()
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


void employes::on_pushButton_4_clicked()
{

        // Create a QMap to store the unique names and their corresponding nombres
           /* QMap<QString, int> stats;

            // Get all the equipements in the inventory
            QSqlQuery query;
            query.prepare("SELECT role,COUNT(*) FROM EMPLOYE GROUP BY role");
            query.exec();
            int count = 0;
               int totalEmployeeCount = 0;
               QMap<QString, int> employeeCounts;
            // Iterate through the results and add up the nombres for each unique name
            while(query.next()) {


                f(stats.contains(role)) {
                    if (stats[nom] != nombre) {
                        // If the name already exists in the map and the nombre is different, divide the nombre by 2
                        nombre = nombre / 2;
                    } else {
                        // If the name already exists in the map and the nombre is the same, skip it
                        continue;
                    }
                }
                stats[nom] = nombre;
                count++;
                        QString roleName = query.value("role").toString();
                        int employeeCount = query.value(1).toInt();
                        totalEmployeeCount += employeeCount;
                        employeeCounts[roleName] = employeeCount;
            }

            // Create the pie chart series and add the data from the QMap
            QPieSeries *series = new QPieSeries();
            QMapIterator<QString, int> i(stats);
            while (i.hasNext()) {
                i.next();
                series->append(i.key(), i.value());
            }*/

            // Create the chart and chart view, and display the chart view
           /* QChart *chart = new QChart();
            chart->addSeries(series);
            chart->setTitle("Employes Roles Stats");
            QChartView *chartView = new QChartView(chart);
            chartView->setRenderHint(QPainter::Antialiasing);
            chartView->resize(800, 600);
            chartView->show();*/
           /* QSqlQuery query;
                query.prepare("SELECT role, COUNT(*) FROM employees GROUP BY role");
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
                }*/

               /* QChart *chart = new QChart();
                chart->addSeries(series);
                chart->setTitle("Employee Role Statistics");
                chart->legend()->hide();

                QChartView *chartView = new QChartView(chart);
                chartView->setRenderHint(QPainter::Antialiasing);
                chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                //ui->chartLayout->addWidget(chartView);*/
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

       /* QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Employee Role Statistics");
        chart->legend()->hide();

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
       // ui->chartLayout->addWidget(chartView);*/
        QChart *chart = new QChart();
                    chart->addSeries(series);
                    chart->setTitle("Employes Roles Stats");
                    QChartView *chartView = new QChartView(chart);
                    chartView->setRenderHint(QPainter::Antialiasing);
                    chartView->resize(800, 600);
                    chartView->show();
    }






void employes::on_lineEdit_8_textChanged(const QString &searchterm)
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




/*oid employes::on_pushButton_7_clicked()
{


        QString phoneNumber = ui->phoneNumberLineEdit->text();
        QString message = ui->messageTextEdit->text();
        sendSMS(phoneNumber, message);

        QMessageBox::information(this, "SMS Sent", "Your SMS message has been sent.");


 }
*/
void employes::sendSMS(QString account_sid, QString auth_token, QString message, QString from_number, QString to_number, QString picture_url, bool verbose)
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

void employes::on_pushButton_7_clicked()
{
        QString account_sid = "AC5228336343591367be0e3ab3fc0b9217";
        QString auth_token = "45c891eddaaf808894260713cf74f0d2";
        QString from_number = "+16203838314"; // votre numéro Twilio
        //QString to_number = "+21698755023"; // numéro de téléphone du destinataire
        QString to_number = ui->phoneNumberLineEdit->text();
        //QString message = "Hello, world!"; // message à envoyer
        QString message = ui->messageTextEdit->text();
        QString picture_url = ""; // URL de l'image, si vous voulez en envoyer une
        bool verbose = true; // afficher les messages de débogage ou non

        sendSMS(account_sid, auth_token, message, from_number, to_number, picture_url, verbose);

}



