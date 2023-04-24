#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "recherche.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QDebug>
#include <algorithm>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0,99999999,this));
    ui->le_titre->setValidator(new QRegularExpressionValidator(QRegularExpression("[a-zA-Z]+"),this));
    ui->le_resultat->setValidator(new QRegularExpressionValidator(QRegularExpression("[a-zA-Z]+"),this));
    ui->le_statut->setValidator(new QRegularExpressionValidator(QRegularExpression("[a-zA-Z]+"),this));
    ui->tab_recherche_4->setModel(rtp.afficher());
    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(ui->tab_recherche_4->model());

    /*ui->cB->setChecked(true);
    ui->cB_2->setChecked(true);
    ui->cB_3->setChecked(true);
    ui->cB_4->setChecked(true);*/

    ui->comboBox->addItem("id_r");
    ui->comboBox->addItem("titre");
    ui->comboBox->addItem("duree");
    ui->comboBox->addItem("date_debut");
    ui->comboBox->addItem("resultet");
    ui->comboBox->addItem("statut");
}

MainWindow::~MainWindow()
{
    delete ui;
}

//ajout
void MainWindow::on_pb_ajouter_3_clicked()
{
    int id_r=ui->le_id->text().toInt();
    QString titre=ui->le_titre->text();
    QString duree=ui->la_duree->text();
    QString date_debut=ui->la_date->text();
    QString resultat=ui->le_resultat->text();
    QString statut=ui->le_statut->text();
    recherche R(id_r,titre,duree,date_debut,resultat,statut);

    bool test=R.ajouter();
    if (test)
    {
        ui->tab_recherche_4->setModel(rtp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectue\n" "Click cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectue.\n" "Click cancel to exit."),QMessageBox::Cancel);
    }
}

//suppression
void MainWindow::on_pb_delete_clicked()
{
    int id_r = ui-> le_ids->text().toInt();

    bool test = rtp.supprimer(id_r);

    if (test)
    {

        ui->tab_recherche_4->setModel(rtp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("SUPP effectue\n" "Click cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                              QObject::tr("SUPP non effectue\n" "Click cancel to exit."),QMessageBox::Cancel);
    }
}

//modification
void MainWindow::on_pb_modifier_clicked()
{
            int id_r=ui->m_id->text().toInt();
            QString titre=ui->m_titre->text();
            QString duree=ui->m_duree->text();
            QString date_debut=ui->m_date->text();
            QString resultat=ui->m_resultat->text();
            QString statut=ui->m_statut->text();

            recherche E(id_r,titre,duree,date_debut,resultat,statut);

            bool test=E.modifier();
            if(test)
            {

                ui->tab_recherche_4->setModel(rtp.afficher());
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


//affichage
void MainWindow::on_tab_recherche_4_clicked(const QModelIndex &index)
{

         int id=index.sibling(index.row(),0).data().toInt();
         QString titre=index.sibling(index.row(),1).data().toString();
         QString duree=index.sibling(index.row(),2).data().toString();
         QString date_debut=index.sibling(index.row(),3).data().toString();
         QString resultat=index.sibling(index.row(),4).data().toString();
         QString statut=index.sibling(index.row(),5).data().toString();

         ui->m_id->setText(QString::number(id));
         ui->m_titre->setText(titre);
         ui->m_duree->setText(duree);
         ui->m_date->setText(date_debut);
         ui->m_resultat->setText(resultat);
         ui->m_statut->setText(statut);




}

//PDF
void MainWindow::on_pb_PDF_clicked()
{   /*
         // Get the database connection
         QSqlDatabase db = QSqlDatabase::database();



         // Create a QPrinter object and set its properties
         QPrinter printer(QPrinter::PrinterResolution);
         printer.setOutputFormat(QPrinter::PdfFormat);
         printer.setPageSize(QPageSize(QPageSize::A4));
         printer.setOutputFileName("C:/Users/PC/Desktop/Recherchee/PDF/Tableau des recherches.pdf");


         // Create a QPainter object and set its properties
         QPainter painter(&printer);
         painter.setRenderHint(QPainter::Antialiasing);
         painter.setRenderHint(QPainter::TextAntialiasing);
         painter.drawPixmap(25,25,QPixmap("c:/User/PC/Desktop/logo.png"));



         // Create a QSqlQuery object and execute the query
         QSqlQuery query("SELECT * FROM recherches", db);

         // Create a QTextDocument object and set its properties
         QTextDocument doc;
         doc.setPageSize(QPageSize(QPageSize::A4).size(QPageSize::Point));
         QString styleSheet = "title { font-family: Arial;font-size: 24px;color: blue;}"
                              "h1 {font-family: 'Poppins', sans-serif;font-weight: 700;font-size: 30px;color: #333;text-transform: uppercase;letter-spacing: 4px;text-align: center;margin-top: 50px;}"
                              "h2 {font-family: 'Poppins', sans-serif;font-weight: 300;font-size: 30px;color: #486b00;text-transform: uppercase;letter-spacing: 4px;text-align: center;}"
                              "table { width: 100%; border-collapse: collapse; border-spacing: 0; font-size: 0.9em; win-width: 400px; margin: 25px 0;}"
                              "table thead { background-color: #e5e5e5; }"
                              "table thead th { padding: 8px; border-bottom: 2px solid #bfbfbf; text-align: left; font-weight: 600; }"
                              "table thead tr { background-color:#00561B; color:#ffffff; text-align: left; font-weight: bold;}"
                              "table tbody tr{ border-bottom: 1px solid #dddddd;}"
                              "table tbody tr:nth-of-type(even){ background-color: #f3f3f3;}"
                              "table tbody tr:last-of-type { border-bottom: 2px solid #00561B;}"
                              "table tbody td { padding: 8px; border-bottom: 1px solid #bfbfbf; }";




         doc.setDefaultStyleSheet(styleSheet);


         // Populate the QTextDocument with data from the QSqlQuery
         QString html = "<center><br><h2>Liste des recherches</h2><table><thead><tr><th>identifiant</th><th>titre</th><th>durée</th><th>date de début</th><th>résultat</th><th>statut</th></thead><tbody>";
         while (query.next()) {

                int id_r = query.value(0).toInt();
                QString titre = query.value(1).toString();
                QString duree = query.value(2).toString();
                QString date_debut = query.value(3).toString();
                QString resultat = query.value(4).toString();
                QString statut = query.value(5).toString();
                html += "<head><title></title></head><body><tr><td>" + QString::number(id_r) + "</td><td>" + titre + "</td><td>" + duree + "</td><td>" + date_debut + "</td><td>" + resultat + "</td><td>" + statut + "</td></tr>";
         }
         html += "</tbody></table>";
         doc.setHtml(html);

         // Draw the QTextDocument to the QPainter
         doc.drawContents(&painter);

         QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
                                  QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
    */
         QPdfWriter pdf("C:/Users/PC/Desktop/Recherchee/PDF/Tableau des recherches.pdf");

         QPainter painter(&pdf);
         int i = 4100;
         const QImage image("c:/Users/PC/Desktop/logo.png");
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

//recherche

void MainWindow::on_le_recherche_textChanged(const QString &searchTerm)
{
    /*QString query = "SELECT * FROM recherches WHERE id_r LIKE '%" + searchTerm + "%' OR titre LIKE '%" + searchTerm + "%' OR duree LIKE '%" + searchTerm + "%' OR date_debut LIKE '%" + searchTerm + "%' OR resultat LIKE '%" + searchTerm + "%' OR statut LIKE '%" + searchTerm + "%'";

        QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery(query);
        ui->tab_recherche_4->setModel(model);*/

         QString chaine_c=ui->le_recherche->text();

         int  id_r=0;
         QString titre="";
         QString duree="";
         QString date_debut="";
         QString resultat="";
         QString statut="";

         recherche rtp(id_r, titre, duree, date_debut, resultat, statut);
         if(chaine_c !="")
         {
                ui->tab_recherche_4->setModel(rtp.chercherRecherche(chaine_c));
         }
         else
         {
                QString trieOption=ui->comboBox->currentText();
                ui->tab_recherche_4->setModel(rtp.triRecherche(trieOption));

         }
}

//tri
void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{

        QString trieOption=ui->comboBox->currentText();
        ui->tab_recherche_4->setModel(rtp.triRecherche(trieOption));

}



//todo list
void MainWindow::on_pb_click_clicked()
{
    if(ui->cB->isChecked())
    {
        //ui->label->setText("Oui,la recherche n°=1 est réalisée");
        QMessageBox::information(this, "Recherche","Oui,la recherche n°=1 a été réalisée");
    }

     if(ui->cB_2->isChecked())
    {
        QMessageBox::information(this, "Recherche","Oui,la recherche n°=2 a été réalisée");
    }

     if(ui->cB_3->isChecked())
    {
        QMessageBox::information(this, "Recherche","Oui,la recherche n°=3 a été réalisée");
    }

     if(ui->cB_4->isChecked())
    {
        QMessageBox::information(this, "Recherche","Oui,la recherche n°=4 a été réalisée");
    }
     if(ui->cB_5->isChecked())
     {
        QMessageBox::information(this, "Recherche","Oui,la recherche n°=5 a été réalisée");
     }

   else
    {
        //ui->label->setText("Aucune recherche est réalisée");
        QMessageBox::information(this, "Recherche","Aucune recherche n'est réalisée");
    }
}

//statistique
void MainWindow::on_pb_statistique_clicked()
{

    int d500 = 0, d1000 = 0;

    QSqlQuery query;

    // Compter le nombre des chercheurs ou leurs ages sont <50
    query.prepare("SELECT COUNT(*) FROM recherches WHERE statut = terminé");
    if (query.exec() && query.next()) {
        d500 = query.value(0).toInt();
    }

    // Compter le nombre des chercheurs ou leurs ages sont >=50
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

   /* int d500 = 0, d1000 = 0;

    QSqlQuery query;

    // Compter le nombre des chercheurs ou leurs ages sont <50
    query.prepare("SELECT COUNT(*) FROM recherches WHERE statut = terminé");
        if (query.exec() && query.next()) {
        d500 = query.value(0).toInt();
    }

    // Compter le nombre des chercheurs ou leurs ages sont >=50
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



    QChart * chart = new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setTitle("STATUT DES RECHERCHES");
    chart->setTheme(QChart::ChartThemeBlueCerulean);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);


    QChartView * chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->resize(600, 500);
    chartview->show();


    // Create a layout to add the chart view to
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(chartview);
    layout->setAlignment(Qt::AlignCenter);
    layout->setContentsMargins(50, 80, 100, 100);
    layout->setSpacing(100);
*/


}


//insert image
void MainWindow::on_pb_image_clicked()
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
            //error handling

        }
    }
}

