#include "stage.h"
#include "mainwindow.h"
#include "ui_stage.h"
#include <QtCharts>


stage::stage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stage)
{
    ui->setupUi(this);




}

stage::~stage()
{
    delete ui;
}

stage::stage(int id_s, QString nom, QDate date_d, QDate date_f, int nbr_place, QString type)
{
    this->ID_S = id_s;
    this->NOM = nom;
    this->DATE_D = date_d;
    this->DATE_FIN = date_f;
    this->NBR_PLACE = nbr_place;
    this->TYPE = type;
}

void stage::displayInventoryColumnChart()
{
    // Create a QMap to store the unique names and their corresponding nombres
    QMap<QString, int> stats;

    // Get all the equipements in the inventory
    QSqlQuery query;
    query.prepare("SELECT NOM, NBR_PLACE FROM STAGE");
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

    // Create the column chart series and add the data from the QMap
    QBarSeries *series = new QBarSeries();
    QMapIterator<QString, int> i(stats);
    while (i.hasNext()) {
        i.next();
        QBarSet *set = new QBarSet(i.key());
        *set << i.value();
        series->append(set);
    }

    // Create the chart and chart view, and display the chart view
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("STAGE STATESTIC");
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(stats.keys());
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);
    chart->setAxisY(new QValueAxis, series);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(800, 400);
    chartView->show();
}


bool stage::ajouter()
{
    // Create a query to insert the data
    QSqlQuery query(db);
    QString res = QString::number(ID_S);
    query.prepare("INSERT INTO STAGE (ID_S, NOM, DATE_D, DATE_FIN, NBR_PLACE, TYPE) VALUES (:ID_S, :NOM, :DATE_D, :DATE_FIN, :NBR_PLACE, :TYPE)");
    query.bindValue(":ID_S",res);
    query.bindValue(":NOM",NOM);
    query.bindValue(":DATE_D",DATE_D);
    query.bindValue(":DATE_FIN",DATE_FIN);
    query.bindValue(":NBR_PLACE",NBR_PLACE);
    query.bindValue(":TYPE",TYPE);

    // Execute the query and return the result
    return query.exec();
}


bool stage::supprimer(int ID_S)
{
    QSqlQuery query;
    QString res = QString::number(ID_S);
    query.prepare("DELETE FROM STAGE WHERE ID_S = :ID_S");
    query.bindValue(":ID_S", res);

    qDebug() << "Query: " << query.lastQuery(); // Print the query being executed

    return query.exec();
}


QSqlQueryModel* stage::afficher(QString sortColumn)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QString query = "SELECT * FROM STAGE ORDER BY " + sortColumn;
    model->setQuery(query);
    return model;
}
bool stage::modifier()
{
    QSqlQuery query;

    QString res = QString::number(ID_S);

    QStringList updates;

    if (!NOM.isEmpty())
        updates << "NOM=:NOM";

    if (DATE_D != QDate())
        updates << "DATE_D=:DATE_D";

    if (DATE_FIN >= QDate())
        updates << "DATE_FIN=:DATE_FIN";

    if (NBR_PLACE >= 0)
        updates << "NBR_PLACE=:NBR_PLACE";

    if (!TYPE.isEmpty())
        updates << "TYPE=:TYPE";


    QString update_query = "UPDATE STAGE SET " + updates.join(", ") + " WHERE ID_S=:ID_S";

    query.prepare(update_query);

    query.bindValue(":ID_S", res);

    if (!NOM.isEmpty())
        query.bindValue(":NOM", NOM);

    if (DATE_D != QDate())
        query.bindValue(":DATE_D", DATE_D);

    if (DATE_FIN >= QDate())
        query.bindValue(":DATE_FIN", DATE_FIN);

    if (NBR_PLACE >= 0)
        query.bindValue(":NBR_PLACE", NBR_PLACE);

    if (!TYPE.isEmpty())
        query.bindValue(":TYPE", TYPE);


    return query.exec();
}


