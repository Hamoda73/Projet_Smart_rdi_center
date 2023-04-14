#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("2a5");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("mouadh");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
