#ifndef DATABASELIB_H
#define DATABASELIB_H
#include <QtSql/QSqlDatabase>
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
    QString db_select(QString _request);
};

#endif // DATABASELIB_H
