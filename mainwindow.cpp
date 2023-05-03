#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "medicament.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator (new QIntValidator(0, 99999999, this));
    ui->le_idg->setValidator (new QIntValidator(0, 99999999, this));
    ui->le_idg_2->setValidator (new QIntValidator(0, 99999999, this));
    ui->arduino_id->setValidator (new QIntValidator(0, 99999999, this));
    ui->arduino_id_2->setValidator (new QIntValidator(0, 99999999, this));
    ui->le_code->setValidator (new QIntValidator(0, 99999999, this));
    ui->le_dosage->setValidator (new QIntValidator(0, 99999999, this));
    ui->line_id->setValidator (new QIntValidator(0, 99999999, this));
    ui->line_dosage->setValidator (new QIntValidator(0, 99999999, this));
    ui->table_meds->setModel(mtp.afficher());
    ui->table_meds_3->setModel(mtp.afficher());
    ui->table_meds_4->setModel(mtp.afficher());
    ui->table_meds_5->setModel(mtp.afficher());
    ui->table_meds_6->setModel(mtp.afficher());
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon("C:/Users/Mahmoud/Desktop/ME/meds/images/notif.png"));
    trayIcon->setVisible(true);
    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(ui->table_meds->model());
    ui->table_meds->setModel(proxyModel);
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_comboBox_currentIndexChanged(int)));

    m_lineEdit = ui->le_code;
    m_button = ui->generatepb;
    connect(m_button, SIGNAL(clicked()), this, SLOT(generateBarcode()));

    /////ARUIDNO
    int ret=A.connect_arduino();
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
        break;
    case(-1):qDebug() << "arduino is not available";
    }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_here_clicked()
{
                    if(ui->le_id->text().isEmpty()){
                        QMessageBox::warning(this, "Erreur", "ID est requis");
                        ui->le_id->setStyleSheet("color: white;");
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

    int id=ui->le_id->text().toInt();
    QString nom_c=ui->le_commercial->text();
    QString dci=ui->le_dci->text();
    int dosage=ui->le_dosage->text().toInt();
    QString date_s=ui->le_ds->text();
    QString date_d=ui->le_de->text();

    medicament m(id,nom_c,dci,dosage,date_s,date_d);

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

void MainWindow::on_pb_delete_clicked()
{
        int id = ui->searchBox_3->text().toInt();

    if(ui->searchBox_3->text().isEmpty()){
        QMessageBox::warning(this, "Erreur", "ID est requis");
        ui->searchBox_3->setStyleSheet("color: white;");
    }
    else
    {
    bool test=mtp.supprimer(id);

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


void MainWindow::on_update_clicked()
{

    if(ui->line_id->text().isEmpty()){
        QMessageBox::warning(this, "Erreur", "ID est requis");
        ui->line_id->setStyleSheet("color: white;");
    }
    else{
        int id=ui->line_id->text().toInt();
        QString nom_c=ui->line_c->text();
        QString dci=ui->line_dci->text();
        int dosage=ui->line_dosage->text().toInt();
        QString date_s=ui->line_ds->text();
        QString date_d=ui->line_de->text();

        medicament E(id,nom_c,dci,dosage,date_s,date_d);

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


void MainWindow::on_table_meds_3_clicked(const QModelIndex &index)
{
             int id=index.sibling(index.row(),0).data().toInt();
             QString commercial=index.sibling(index.row(),1).data().toString();
             QString dci=index.sibling(index.row(),2).data().toString();
             QString dosage=index.sibling(index.row(),3).data().toString();
             QString dateSortie=index.sibling(index.row(),4).data().toString();
             QString dateExpire=index.sibling(index.row(),5).data().toString();

             ui->line_id->setText(QString::number(id));
             ui->line_c->setText(commercial);
             ui->line_dci->setText(dci);
             ui->line_dosage->setText(dosage);
             ui->line_ds->setText(dateSortie);
             ui->line_de->setText(dateExpire);
}


void MainWindow::on_table_meds_4_clicked(const QModelIndex &index)
{
        int id=index.sibling(index.row(),0).data().toInt();
        ui->searchBox_3->setText(QString::number(id));
}

void MainWindow::on_table_meds_5_clicked(const QModelIndex &index)
{
    int id=index.sibling(index.row(),0).data().toInt();
    QString commercial=index.sibling(index.row(),1).data().toString();
    QString dci=index.sibling(index.row(),2).data().toString();
    QString dosage=index.sibling(index.row(),3).data().toString();
    QString dateSortie=index.sibling(index.row(),4).data().toString();
    QString dateExpire=index.sibling(index.row(),5).data().toString();

    ui->notif_id->setText(QString::number(id));
    ui->notif_cm->setText(commercial);
    ui->notif_dci->setText(dci);
    ui->notif_d->setText(dosage);
    ui->notif_ds->setText(dateSortie);
    ui->notif_de->setText(dateExpire);
}

void MainWindow::showNotification(const QString &title, const QString &message)
{
    trayIcon->showMessage(title, message, QSystemTrayIcon::Information, 5000);
}

void MainWindow::on_update_2_clicked()
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


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    QString columnName = ui->comboBox->itemText(index);
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

void MainWindow::on_pb_pdf_clicked()
{
    // Get the database connection
    QSqlDatabase db = QSqlDatabase::database();

    // Create a QPrinter object and set its properties
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setOutputFileName("C:/Users/Mahmoud/Desktop/ME/meds/PDF/Tableau des medicaments.pdf");

    // Create a QPainter object and set its properties
    QPainter painter(&printer);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);

    // Create a QSqlQuery object and execute the query
    QSqlQuery query("SELECT * FROM medicament", db);

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
        QString id = query.value(0).toString();
        QString nom_c = query.value(1).toString();
        QString dci = query.value(2).toString();
        QString dosage = query.value(3).toString();
        QString date_s = query.value(4).toString();
        QString date_d = query.value(5).toString();
        QString cab = query.value(6).toString();
        html += "<head><title></title></head><body><tr><td>" + id + "</td><td>" + nom_c + "</td><td>" + dci + "</td><td>" + dosage + "</td><td>" + date_s + "</td><td>" + date_d + "</td><td>" + cab + "</td></tr>";
    }
    QImage image("C:/Users/Mahmoud/Desktop/ME/meds/images/signature.png");
    QRect rect(320, 650, 200, 200); // Set the position and size of the image
    painter.drawImage(rect, image);
    html += "</tbody></table>";
    doc.setHtml(html);

    // Draw the QTextDocument to the QPainter
    doc.drawContents(&painter);
}

void MainWindow::on_searchBox_4_textChanged(const QString &arg1)
{
    QString searchText = ui->searchBox_4->text();
    QRegularExpression regExp(searchText, QRegularExpression::CaseInsensitiveOption);
    proxyModel->setFilterRegularExpression(regExp);
}

void MainWindow::on_statspb_clicked()
{
    int d500 = 0, d1000 = 0;

    QSqlQuery query;

    // Compter le nombre des meds ou le dosage est 500g
    query.prepare("SELECT COUNT(*) FROM MEDICAMENT WHERE DOSAGE = '500'");
    if (query.exec() && query.next()) {
            d500 = query.value(0).toInt();
    }

    // Compter le nombre des meds ou le dosage est 1000g
    query.prepare("SELECT COUNT(*) FROM MEDICAMENT WHERE DOSAGE = '1000'");
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


void MainWindow::on_generatepb_clicked()
{
    QString data = m_lineEdit->text();
    zxing::BarcodeFormat format = zxing::BarcodeFormat::CODE_128; // Change the format to the desired barcode format
    int width = 200; // Change the width and height to the desired size
    int height = 200;
    QImage barcode = QZXing::encodeData(data, QZXing::EncoderFormat_QR_CODE, QSize(width, height), QZXing::EncodeErrorCorrectionLevel_H);
    QPixmap qrCodePixmap = QPixmap::fromImage(barcode);

    // Save the QR code image as a file
    QString fileName = "C:/Users/Mahmoud/Desktop/ME/meds/barcode.png";
    if(qrCodePixmap.save(fileName)) {
            qDebug() << "QR code image saved as file: " << fileName;
    } else {
            qDebug() << "Failed to save QR code image as file: " << fileName;
    }

    // Load the QR code image
    QImage qrCodeImage("C:/Users/Mahmoud/Desktop/ME/meds/barcode.png");

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

    int id=ui->le_idg->text().toInt();
    bool test=mtp.ajouterCAB(id,barcodeData);

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

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    QString columnName = ui->comboBox_2->itemText(index);
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
            int id=ui->le_idg->text().toInt();
            bool test=mtp.ajouterCAB(id,decodedText);

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
            int id=ui->le_idg->text().toInt();
            bool test=mtp.ajouterCAB(id,decodedText);

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
            int id=ui->le_idg->text().toInt();
            bool test=mtp.ajouterCAB(id,decodedText);

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
            int id=ui->le_idg->text().toInt();
            bool test=mtp.ajouterCAB(id,decodedText);

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

void MainWindow::on_pushButton_9_clicked()
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

void MainWindow::on_pushButton_12_clicked()
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
