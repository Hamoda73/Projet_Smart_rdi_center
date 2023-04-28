#ifndef MATERIEL_H
#define MATERIEL_H

#include <QWidget>
#include "equipement.h"
#include <QStandardItemModel>
#include <QWidget>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>
#include <QCompleter>

#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <arduino.h>

#include "qrcodegen.hpp"

namespace Ui {
class materiel;
}

class materiel : public QWidget
{
    Q_OBJECT

public:
    explicit materiel(QWidget *parent = nullptr);
    ~materiel();
    void readAndInsertData(QSerialPort& serialPort);
    /*void setModel(QAbstractItemModel *model); */

private slots:
    void on_procceed_add_clicked();

    void on_Delete_clicked();

    void on_pushButton_17_clicked();

    void on_clear_clicked();

    void on_pushButton_19_clicked();

    void on_DESC_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_tableView_2_clicked(const QModelIndex &index);

    void on_tableView_3_clicked(const QModelIndex &index);

    void on_pushButton_22_clicked();

    void on_sendemail_clicked();

    void on_to_editingFinished();

    void on_generate_clicked_clicked();

    void on_extract_pdf_clicked();

    void on_pb_recherche_clicked();

    void on_searchbox_textChanged(const QString &arg1);

    void on_comboBox_activated(int index);

    void on_pushButton_16_clicked();

    void on_pushButton_clicked();

    void on_Open_clicked();

    void on_Close_clicked();

private:
    Ui::materiel *ui;
    Equipement Eqmp;
    QSortFilterProxyModel *proxyModel;
    QString searchQuery;
    Arduino A;



};


#endif // MATERIEL_H

