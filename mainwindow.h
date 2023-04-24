#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "recherche.h"
#include <QMainWindow>
#include <QSortFilterProxyModel>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_3_clicked();

    void on_pb_delete_clicked();

    void on_pb_modifier_clicked();

    void on_tab_recherche_4_clicked(const QModelIndex &index);

    void on_pb_PDF_clicked();

    void on_le_recherche_textChanged(const QString &arg1);

    void on_pb_click_clicked();

    void on_pb_statistique_clicked();

    void on_pb_image_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    recherche rtp;
    QSortFilterProxyModel *proxyModel;

};
#endif // MAINWINDOW_H
