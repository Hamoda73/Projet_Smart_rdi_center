#include "materiel.h"
#include "equipement.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    materiel w;
    w.show();
    return a.exec();


}
