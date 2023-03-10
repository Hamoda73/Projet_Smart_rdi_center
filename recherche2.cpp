#include "recherche2.h"
#include "ui_recherche2.h"

recherche2::recherche2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::recherche2)
{
    ui->setupUi(this);
}

recherche2::~recherche2()
{
    delete ui;
}
