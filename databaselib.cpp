#include "databaselib.h"

// PRIVATE:
int DataBaseLib::get_table_columns_count(QSqlQuery dbquery) {
  QSqlRecord rec = dbquery.record();
  return rec.count();
}
// PABLIC:
bool DataBaseLib::connect_to_base() {
  db.setDatabaseName("main.db");
  return db.open();
}

void DataBaseLib::update_price_change(int productType, int newPrice,
                                      QString date) {
  QSqlQuery query(db);
  query.prepare("INSERT INTO price_change (date, type, new_price) "
                "VALUES (:date, :type, :new_price)");
  query.bindValue(":date", date);
  query.bindValue(":type", productType);
  query.bindValue(":new_price", newPrice);
  query.exec();
}

QString DataBaseLib::get_id_from_value(QString tableName, QString value) {
  QString id;
  QSqlQuery query(db);
  QString request =
      QString("SELECT id FROM %1 WHERE title = '%2'").arg(tableName, value);
  query.exec(request);
  while (query.next()) {
    id = query.value(0).toString();
  }
  return id;
}

void DataBaseLib::update_birth_and_died(int id, QString birthDate,
                                        QString diedDate) {
  QSqlQuery query(db);
  query.prepare("INSERT INTO died (date, code) "
                "VALUES (:date, :code)");
  query.bindValue(":date", diedDate);
  query.bindValue(":code", id);
  query.exec();
  query.prepare("INSERT INTO birth (date, code) "
                "VALUES (:date, :code)");
  query.bindValue(":date", birthDate);
  query.bindValue(":code", id);
  query.exec();
}
