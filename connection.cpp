#include "connection.h"

connection::connection()
{

}

bool connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet2");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("noun");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
