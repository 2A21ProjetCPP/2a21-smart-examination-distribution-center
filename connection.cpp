#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("OptiExam_1");//inserer le nom de la source de données
    db.setUserName("OptiExam_1");//inserer nom de l'utilisateur
    db.setPassword("pass");//inserer mot de passe de cet utilisateur

    if (db.open())
        test=true;





    return  test;
}
