#include "employes.h"
#include "ui_employes.h"

employes::employes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::employes)
{
    ui->setupUi(this);
}

employes::~employes()
{
    delete ui;
}
