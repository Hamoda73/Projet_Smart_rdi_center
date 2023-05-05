#ifndef EMPLOYES_H
#define EMPLOYES_H

#include <QWidget>
#include <QIntValidator>
#include "employe.h"
#include <QObject>
#include <QVBoxLayout>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include "arduino.h"

namespace Ui {
class employes;
}

class employes : public QWidget
{
    Q_OBJECT

public:
    explicit employes(QWidget *parent = nullptr);
    ~employes();
    void sendSMS(QString phoneNumber, QString message) ;

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();


   /* void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();*/

    void on_tab_emp_clicked(const QModelIndex &index);

    void onButtonClicked();

    void on_PDFButton_clicked();

    void on_pushButton_4_clicked();

    void on_lineEdit_8_textChanged(const QString &searchterm);

    void on_pushButton_7_clicked();
    void sendSMS(QString account_sid, QString auth_token, QString message, QString from_number, QString to_number, QString picture_url, bool verbose);


    void on_pb_ON_clicked();

    void on_pb_OFF_clicked();
    void update_label();

    void on_pb_OPD_clicked();

    void on_pb_CLD_clicked();

private:
    Ui::employes *ui;
    Employe Emp;
    Arduino A;
    QByteArray data;

};

#endif // EMPLOYES_H
