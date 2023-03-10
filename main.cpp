#include "employes.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    employes w;
    w.show();
    return a.exec();
}
