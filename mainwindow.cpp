#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_15->setIcon(QIcon(":/icons/images/search.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

