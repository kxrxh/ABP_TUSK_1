#ifndef DATABASELIB_H
#define DATABASELIB_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QList>
#include <vector>
#include <QDebug>
#include <QtSql/QSqlRecord>
#include <QStringList>

class DataBaseLib
{
private:
    QSqlDatabase db;
    int get_table_columns_count(QSqlQuery dbquery);

public:
    DataBaseLib(QSqlDatabase database) { db = database; };
    bool connect_to_base();
    void update_price_change(int productType, int newPrice,
                             QString date);
    void update_birth_and_died(int id, QString birthDate, QString diedDate);
    QString get_id_from_value(QString tableName, QString value);
};

#endif // DATABASELIB_H
