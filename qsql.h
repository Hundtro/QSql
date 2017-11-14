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
    QSQL();
    QSqlDatabase* Database();
    QSqlQuery* Query();
    void SetDriver(QString driver_name);
    void SetServer(QString server_name);
    void SetDatabaseName(QString database_name);
    void SetUserName(QString user_name);
    void SetPasswd(QString passwd);
    void CreateConnection();
    void OpenConnection();
    void CloseConnection();
    bool ExecuteQuery(QString command);
    bool ReadNextRow();
    std::string GetValue(QString name);
    std::string GetValue(int column);
};

#endif // QSQL_H
