#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "medicament.h"
#include "arduino.h"
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

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
using namespace zxing;
using namespace zxing::oned;
using namespace zxing::qrcode;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_add_here_clicked();

    void on_pb_delete_clicked();

    void on_update_clicked();

    void on_table_meds_3_clicked(const QModelIndex &index);

    void on_table_meds_4_clicked(const QModelIndex &index);

    void showNotification(const QString &title, const QString &message);

    void on_table_meds_5_clicked(const QModelIndex &index);

    void on_update_2_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pb_pdf_clicked();

    void on_searchBox_4_textChanged(const QString &arg1);

    void on_statspb_clicked();

    void on_generatepb_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_pushButton_9_clicked();

    void on_pushButton_12_clicked();

private:
    Ui::MainWindow *ui;
    medicament mtp;
    QSystemTrayIcon *trayIcon;
    QSortFilterProxyModel *proxyModel;
    QLineEdit* m_lineEdit;
    QPushButton* m_button;
    arduino A;
    QByteArray data;
    QSerialPort serial;

};
#endif // MAINWINDOW_H
