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
///////moheb ////////////


#include "recherche.h"
#include "chercheur.h"
#include <QChart>

#include <QtCharts/QPieSeries>


//////moheb//////////////
#include "employe.h"
#include <QVBoxLayout>

////////GESTION MEDS////////////
#include "medicament.h"
#include <QSystemTrayIcon>
#include <QComboBox>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>
#include <QMessageBox>
#include <QIntValidator>
#include <QDateTime>
#include <QPainter>
#include <QFontMetrics>
#include <QFileDialog>
#include <QPrinter>
#include <QCompleter>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>
#include <QImage>
#include <QPixmap>
#include <QZXing.h>
#include <zxing/BarcodeFormat.h>
#include <zxing/oned/Code128Reader.h>
#include <zxing/qrcode/ErrorCorrectionLevel.h>
#include <vector>
#include <QtSerialPort/QSerialPort>
#include <stage.h>
////////GESTION MEDS////////////
#include "recherche.h"

QT_BEGIN_NAMESPACE
using namespace zxing;
using namespace zxing::oned;
using namespace zxing::qrcode;
QT_END_NAMESPACE




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

    ////gest meds////
    void on_add_here_clicked();

    void on_pb_delete_clicked();

    void on_update_clicked();

    void on_table_meds_3_clicked(const QModelIndex &index);

    void on_table_meds_4_clicked(const QModelIndex &index);

    void showNotification(const QString &title, const QString &message);

    void on_table_meds_5_clicked(const QModelIndex &index);

    void on_update_2_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_pb_pdf_clicked();

    void on_searchBox_4_textChanged(const QString &arg1);

    void on_statspb_clicked();

    void on_generatepb_clicked();

    void on_comboBox_3_currentIndexChanged(int index);

    void on_pb_add_clicked();
    void on_pb_deletechercheur_clicked();
    void on_pb_update_clicked();
    void on_pb_history_clicked();
    void on_bptriasc_clicked();
    void on_pbtridsc_clicked();
    void on_pb_searchC_clicked();
    void on_pb_pdfchercheur_clicked();
    void on_pb_statistiques_clicked();
    void on_txtsearch_C_textChanged(const QString &arg1);
    void on_pb_pdf_all_clicked();
    void on_bptriasc_2_clicked();
    void on_table_c_clicked(const QModelIndex &index);
    void on_pb_excel_clicked();
    void on_pb_ajouter_clicked();
    void on_pb_supprimer_clicked();
    void on_pb_modifier_clicked();
    void on_tab_emp_clicked(const QModelIndex &index);
    void onButtonClicked();
    void on_PDFButton_clicked();
    void on_pushButton_4_clicked();
    void on_lineEdit_8_textChanged(const QString &searchterm);
    void sendSMS(QString account_sid, QString auth_token, QString message, QString from_number, QString to_number, QString picture_url, bool verbose);
    void on_pushButton_7_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_26_clicked();
    void on_pushButton_24_clicked();
    void on_sortByCombo_2_currentTextChanged(const QString &arg1);
    void on_searchLineEdit_2_textEdited(const QString & searchTerm);
    void on_pdf_2_clicked();
    void on_afficher_2_doubleClicked(const QModelIndex &index);
    void on_calendarWidget_clicked(const QDate &date);
    void setupCalendar();




    /// gest meds////

    void on_show_stat_2_clicked();


    void on_pb_ajouter_3_clicked();

     void on_pb_image_clicked();

     void on_pb_etat_clicked();

     void on_pb_delete_3_clicked();

     void on_pushButton_28_clicked();

     void on_afficher_3_doubleClicked(const QModelIndex &index);

     void on_pushButton_27_clicked();

     void on_searchLineEdit_3_textEdited(const QString &searchTerm);

     void on_searchnoor_clicked();






    void on_sortByCombo_3_currentTextChanged(const QString &arg1);

    void on_pushButton_25_clicked();




    void on_tab_todo_doubleClicked(const QModelIndex &index);

    void on_tab_en_cours_doubleClicked(const QModelIndex &index);

    void on_tab_done_doubleClicked(const QModelIndex &index);


    void on_pushButton_12_clicked();

    void on_pushButton_9_clicked();


private:
    Ui::materiel *ui;
    Equipement Eqmp;
    QSortFilterProxyModel *proxyModel;
    QString searchQuery;
    Arduino A;
//// gest meds /////
     medicament mtp;
    QSystemTrayIcon *trayIcon;
    Employe Emp;

    QLineEdit * m_lineEdit;
    QPushButton * m_button;
    QByteArray data;
    QSerialPort serial;
    chercheur ctp;
/// gest meds//////
stage etmp;
QSqlDatabase db;
recherche rtp;

};

///////////////////////////moheb/////////////////////////






///////////////////////////moheb/////////////////////////
#endif // MATERIEL_H

