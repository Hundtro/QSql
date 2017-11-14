#ifndef QSQL_H
#define QSQL_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

class QSQL
{
private:
    QString connectionData;
    QSqlDatabase db;
    QSqlQuery* q;

public:
    QSqlDatabase* Database();
    QSqlQuery* Query();
    void AddConnectionValue(QString value);
    void CreateConnection(QString driver);
    void OpenConnection();
    void CloseConnection();
    bool ExecuteQuery(QString command);
    bool ReadNextRow();
    std::string GetValue(QString name);
    std::string GetValue(int column);
};

#endif // QSQL_H
