#include "connection.h"
#include <QSqlDatabase>

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("medamine");//inserer nom de l'utilisateur
db.setPassword("medamine");//inserer mot de passe de cet utilisateur
if (db.open())
test=true;





    return  test;
}
void Connection::closeConnection(){db.close();}
