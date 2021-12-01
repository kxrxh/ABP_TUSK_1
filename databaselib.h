#ifndef DATABASELIB_H
#define DATABASELIB_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlQuery>
#include <QList>
#include <vector>
#include <QDebug>

class DataBaseLib
{
private:
    QSqlDatabase db;
public:
    DataBaseLib(QSqlDatabase database) { db = database; };
    bool connect_to_base();
    QList<QString> get_database_tables();
    std::vector<std::vector<QString>> get_table(QString table_name);
    std::vector<std::vector<QString>> db_select(QString _request);
};

#endif // DATABASELIB_H
