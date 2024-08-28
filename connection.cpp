#include "connection.h"

connection::connection()
{

}

bool connection::createconnect()
{
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test-bd");
    db.setUserName("jizel");
    db.setPassword("sys");

    if (db.open())
        test=true;


    return test;
}
