#include "qsql.h"

QSqlDatabase* QSQL :: Database()
{
    return &db;
}

void QSQL :: AddConnectionValue(QString value)
{
    connectionData += value + ";";
}

QSqlQuery* QSQL :: Query()
{
    return q;
}

void QSQL :: CreateConnection(QString driver)
{
    db = QSqlDatabase::addDatabase(driver);
    db.setDatabaseName(connectionData);
}

void QSQL :: OpenConnection()
{
    if(db.isOpen())
    {
        db.close();
    }
    db.open();
}

void QSQL :: CloseConnection()
{
    if(db.isOpen())
    {
        db.close();
    }
}

bool QSQL :: ExecuteQuery(QString command)
{
    q = new QSqlQuery(db);
    return q->exec(command);
}

bool QSQL :: ReadNextRow()
{
    if(q){ return q->next(); }
    else{ return false; }
}
std::string QSQL :: GetValue(QString name)
{
    return q->value(name).toString().toStdString();
}

std::string QSQL :: GetValue(int column)
{
    return q->value(column).toString().toStdString();
}
