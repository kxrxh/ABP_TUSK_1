#include "./ui_mainwindow.h"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  tables_ru.push_back(QString("Пользователи"));
  tables_ru.push_back(QString("Номенклатура"));
  tables_ru.push_back(QString("Прайс по тарифам"));
  tables_ru.push_back(QString("Станции"));
  tables_ru.push_back(QString("Сотрудники"));
  tables_ru.push_back(QString("Начало аренды"));
  tables_ru.push_back(QString("Окончание аренды"));
  tables_ru.push_back(QString("Оплата аренды"));
  tables_ru.push_back(QString("Ввод в эксплуатацию товара"));
  tables_ru.push_back(QString("Вывод из эксплуатации товара"));
  tables_ru.push_back(QString("Изменение прайса"));

  tables_en.push_back(QString("users"));
  tables_en.push_back(QString("nomenclature"));
  tables_en.push_back(QString("price"));
  tables_en.push_back(QString("base"));
  tables_en.push_back(QString("employees"));
  tables_en.push_back(QString("rent_start"));
  tables_en.push_back(QString("rent_finish"));
  tables_en.push_back(QString("payment"));
  tables_en.push_back(QString("birth"));
  tables_en.push_back(QString("died"));
  tables_en.push_back(QString("price_change"));
  comboBox = new QComboBox(this);
  for (int i = 0; i < tables_en.size(); ++i) {
    comboBox->addItem(tables_ru[i]);
  }
  std::vector<QString> tmp;
  tmp.push_back(QString("id"));
  tmp.push_back(QString("Имя"));
  tmp.push_back(QString("Фамилия"));
  tmp.push_back(QString("Отчество"));
  tmp.push_back(QString("Номер телефона"));
  tmp.push_back(QString("Почта"));
  tmp.push_back(QString("Дата рождения"));
  tmp.push_back(QString("Статус"));
  ru_columns.push_back(tmp);
  tmp.clear();
  tmp.push_back(QString("id"));
  tmp.push_back(QString("Код"));
  tmp.push_back(QString("Название"));
  tmp.push_back(QString("Тип предмета"));
  tmp.push_back(QString("Использование"));
  tmp.push_back(QString("Дата ввода"));
  tmp.push_back(QString("Дата вывода"));
  ru_columns.push_back(tmp);
  tmp.clear();
  tmp.push_back(QString("id"));
  tmp.push_back(QString("Наименование"));
  tmp.push_back(QString("Цена"));
  tmp.push_back(QString("Дата изменения"));
  ru_columns.push_back(tmp);
  tmp.clear();
  tmp.push_back(QString("id"));
  tmp.push_back(QString("Номер"));
  tmp.push_back(QString("Наименование"));
  tmp.push_back(QString("Адрес"));
  tmp.push_back(QString("Почтовый индекс"));
  tmp.push_back(QString("Координаты"));
  ru_columns.push_back(tmp);
  tmp.clear();
  tmp.push_back(QString("id"));
  tmp.push_back(QString("Имя"));
  tmp.push_back(QString("Фамилия"));
  tmp.push_back(QString("Отчество"));
  tmp.push_back(QString("Номер телефона"));
  tmp.push_back(QString("Почта"));
  tmp.push_back(QString("Дата рождения"));
  tmp.push_back(QString("Должность"));
  ru_columns.push_back(tmp);
  tmp.clear();
  tmp.push_back(QString("id"));
  tmp.push_back(QString("Время"));
  tmp.push_back(QString("Пользователь"));
  tmp.push_back(QString("Предмет"));
  tmp.push_back(QString("Станция"));
  tmp.push_back(QString("Станция"));
  tmp.push_back(QString("Станция"));
  tmp.push_back(QString("Станция"));
  ru_columns.push_back(tmp);
  tmp.clear();
  tmp.push_back(QString("id"));
  tmp.push_back(QString("Время"));
  tmp.push_back(QString("Пользователь"));
  tmp.push_back(QString("Предмет"));
  tmp.push_back(QString("Станция"));
  ru_columns.push_back(tmp);
  tmp.clear();
  tmp.push_back(QString("id"));
  tmp.push_back(QString("Начало"));
  tmp.push_back(QString("Пользователь"));
  tmp.push_back(QString("Скидка"));
  tmp.push_back(QString("Время аренды"));
  tmp.push_back(QString("Сумма"));
  tmp.push_back(QString("Предмет"));
  tmp.push_back(QString("Тариф"));
  ru_columns.push_back(tmp);
  tmp.clear();
  tmp.push_back(QString("id"));
  tmp.push_back(QString("Артикул"));
  tmp.push_back(QString("Дата"));
  ru_columns.push_back(tmp);
  tmp.clear();
  tmp.push_back(QString("id"));
  tmp.push_back(QString("Артикул"));
  tmp.push_back(QString("Дата"));
  ru_columns.push_back(tmp);
  tmp.clear();
  tmp.push_back(QString("id"));
  tmp.push_back(QString("Дата"));
  tmp.push_back(QString("Тип"));
  tmp.push_back(QString("Новая цена"));
  ru_columns.push_back(tmp);
  tmp.clear(); // setup UI
  ui->setupUi(this);
  ui->verticalLayout->addWidget(comboBox);
  connect(comboBox, SIGNAL(currentIndexChanged(int)), SLOT(changeTable(int)));
  // setup database
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName("main.db");
  dbl = new DataBaseLib(db);
  bool status = dbl->connect_to_base();
  table = new QSqlRelationalTableModel(this);
  openTable();
  connect(ui->addButton, SIGNAL(clicked()), SLOT(addRow()),
          Qt::UniqueConnection);
  connect(ui->submitButton, SIGNAL(clicked()), SLOT(acceptAll()),
          Qt::UniqueConnection);
  connect(table, SIGNAL(beforeUpdate(int, QSqlRecord &)), this,
          SLOT(rowUpdated(int, QSqlRecord &)));
  if (!status) {
    
  }
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::openTable() {
  if (opened)
  delete tableView;
  opened = true;
  tableView = new QTableView(this);
  tableView->setSortingEnabled(true);
  ui->mainLayout->addWidget(tableView);
  table->setTable(currentTable);
  updateTable();
}

void MainWindow::updateTable() {
  setupTable();
  table->setEditStrategy(QSqlTableModel::OnManualSubmit);
  table->select();
  tableView->setModel(table);
  tableView->resizeColumnsToContents();
  tableView->setEditTriggers(QAbstractItemView::DoubleClicked);
  if (sortOrder)
    tableView->sortByColumn(sortedIndex, Qt::DescendingOrder);
  else
    tableView->sortByColumn(sortedIndex, Qt::AscendingOrder);
  for (int i = 0; i < ru_columns[currentTableIndex].size(); ++i) {
    table->setHeaderData(i, Qt::Horizontal, ru_columns[currentTableIndex][i]);
  }
}

void MainWindow::setupTable() {
  switch (currentTableIndex) {
  case 0:
    table->setRelation(7, QSqlRelation("statuses", "id", "title"));
    tableView->setItemDelegateForColumn(7, new QSqlRelationalDelegate());
    tableView->setItemDelegateForColumn(6, new DateDelegate());
    tableView->setItemDelegateForColumn(4, new Phonedelegate());
    break;
  case 1:
    table->setRelation(3, QSqlRelation("nomenclature_type", "id", "title"));
    tableView->setItemDelegateForColumn(3, new QSqlRelationalDelegate());
    tableView->setItemDelegateForColumn(5, new DateDelegate(tableView));
    tableView->setItemDelegateForColumn(6, new DateDelegate(tableView));
    table->setRelation(4, QSqlRelation("bool", "id", "title"));
    tableView->setItemDelegateForColumn(4, new QSqlRelationalDelegate());
    break;
  case 2:
    table->setRelation(1, QSqlRelation("nomenclature_type", "id", "title"));
    tableView->setItemDelegateForColumn(1, new QSqlRelationalDelegate());
    tableView->setItemDelegateForColumn(3, new DateDelegate(tableView));
    break;
  case 4:
    table->setRelation(7, QSqlRelation("positions", "id", "title"));
    tableView->setItemDelegateForColumn(7, new QSqlRelationalDelegate());
    tableView->setItemDelegateForColumn(6, new DateDelegate(tableView));
    tableView->setItemDelegateForColumn(4, new Phonedelegate());
    break;
  case 6:
    currentTableIndex = 5;
  case 5:
    table->setRelation(2, QSqlRelation("users", "id", "name"));
    tableView->setItemDelegateForColumn(2, new QSqlRelationalDelegate());
    table->setRelation(3, QSqlRelation("nomenclature", "id", "code"));
    tableView->setItemDelegateForColumn(3, new QSqlRelationalDelegate());
    table->setRelation(4, QSqlRelation("base", "id", "number"));
    tableView->setItemDelegateForColumn(4, new QSqlRelationalDelegate());
    tableView->setItemDelegateForColumn(1, new TimeDelegate());
    break;
  case 7:
    tableView->setItemDelegateForColumn(1, new TimeDelegate());
    table->setRelation(2, QSqlRelation("users", "id", "mail"));
    table->setRelation(6, QSqlRelation("nomenclature", "id", "code"));
    tableView->setItemDelegateForColumn(2, new QSqlRelationalDelegate());
    tableView->setItemDelegateForColumn(6, new QSqlRelationalDelegate());
    break;
  case 8:
    currentTableIndex = 9;
  case 9:
    table->setRelation(2, QSqlRelation("nomenclature", "id", "code"));
    tableView->setItemDelegateForColumn(2, new QSqlRelationalDelegate());
    tableView->setItemDelegateForColumn(2, new DateDelegate());
    break;
  case 10:
    table->setRelation(2, QSqlRelation("nomenclature_type", "id", "title"));
    tableView->setItemDelegateForColumn(2, new QSqlRelationalDelegate());
    break;
  default:
    break;
  }
}

void MainWindow::changeTable(int index) {
  currentTable = tables_en[index];
  currentTableIndex = index;
  openTable();
}

void MainWindow::addRow() {
  int row = table->rowCount();
  table->insertRow(row);
}

void MainWindow::acceptAll() {
  table->submitAll();
  updateTable();
}

void MainWindow::deleteCurrentRow() {
  QItemSelectionModel *select = tableView->selectionModel();
  for (const QModelIndex &selected : select->selectedRows()) {
    table->removeRow(selected.row());
    table->submitAll();
  }
  table->select();
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_Delete) {
    deleteCurrentRow();
  }
}

void MainWindow::rowUpdated(int row, QSqlRecord &record) {
  switch (currentTableIndex) {
  case 1: {
    QString diedDate = record.value(6).toString();
    QString birthDate = record.value(5).toString();
    int id = record.value(0).toInt();
    dbl->update_birth_and_died(id, diedDate, birthDate);
    break;
  }
  case 2: {
    QString currDate = QDate::currentDate().toString("dd.MM.yyyy");
    int newValueOfPrice = record.value(2).toInt();
    QString productTitle = record.value(1).toString();
    int productType =
        dbl->get_id_from_value("nomenclature_type", productTitle).toInt();
    dbl->update_price_change(productType, newValueOfPrice, currDate);
  }
  }
}
