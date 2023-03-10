#include "materiel.h"
#include "ui_materiel.h"

materiel::materiel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::materiel)
{
    ui->setupUi(this);

}

materiel::~materiel()
{
    delete ui;
}
