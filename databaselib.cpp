#include "databaselib.h"
#include <QDebug>

bool DataBaseLib::connect_to_base() {
    db.setDatabaseName("main.db");
    return db.open();
}

QList<QString> DataBaseLib::get_database_tables() {
    return db.tables(QSql::Tables);
}

std::vector<std::vector<QString>> DataBaseLib::db_select(QString _request) {
  QSqlQuery query(db);
  query.exec(_request);
  std::vector<std::vector<QString>> all_rows_vector;
  while (query.next()) {
      std::vector<QString> row_vector;
      for (int i = 0; i < 7; ++i) {
          row_vector.push_back(query.value(i).toString());
      }
      all_rows_vector.push_back(row_vector);
  }
  return all_rows_vector;
}

std::vector<std::vector<QString>> DataBaseLib::get_table(QString table_name) {
    std::vector<std::vector<QString>> data;
    return db_select("SELECT * FROM " + table_name);
}