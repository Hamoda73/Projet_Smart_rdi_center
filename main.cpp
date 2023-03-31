#include "materiel.h"
#include "MainWindow.h"
#include "equipement.h"
#include "connection.h"
#include <QMessageBox>
#include <QApplication>

#include "emailsender.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    Connection c;
    bool test=c.createconnect();
    materiel w;

    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    return a.exec();


}
