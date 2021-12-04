#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // setup names
    tables_ru.push_back(QString("Пользователи")); tables_ru.push_back(QString("Номенклатура")); tables_ru.push_back(QString("Прайс по тарифам")); tables_ru.push_back(QString("Станции")); tables_ru.push_back(QString("Сотрудники")); tables_ru.push_back(QString("Начало аренды")); tables_ru.push_back(QString("Окончание аренды")); tables_ru.push_back(QString("Оплата аренды")); tables_ru.push_back(QString("Ввод в эксплуатацию товара")); tables_ru.push_back(QString("Вывод из эксплуатации товара")); tables_ru.push_back(QString("Изменение прайса"));
    tables_en.push_back(QString("users")); tables_en.push_back(QString("nomenclature")); tables_en.push_back(QString("price")); tables_en.push_back(QString("base")); tables_en.push_back(QString("employees")); tables_en.push_back(QString("rent_start")); tables_en.push_back(QString("rent_finish")); tables_en.push_back(QString("payment")); tables_en.push_back(QString("birth")); tables_en.push_back(QString("died")); tables_en.push_back(QString("price_change"));
    comboBox = new QComboBox(this);
    for (int i = 0; i < 10; ++i) {
        comboBox->addItem(tables_ru[i]);
    }
    // setup UI
    ui->setupUi(this);
    ui->verticalLayout->addWidget(comboBox);
    connect(comboBox, SIGNAL(currentIndexChanged(int)), SLOT(changeTable(int)));
    // setup database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("main.db");
    dbl = new DataBaseLib(db);
    bool status = dbl->connect_to_base();
    table = new QSqlRelationalTableModel(this);
    connect(ui->tableView->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(sortBy(int)));
    openTable();
    connect(ui->addButton, SIGNAL(clicked()), SLOT(addRow()),
            Qt::UniqueConnection);
    connect(ui->submitButton, SIGNAL(clicked()), SLOT(acceptAll()),
            Qt::UniqueConnection);
    connect(table, SIGNAL(beforeUpdate(int,QSqlRecord&)), this, SLOT(rowUpdated(int,QSqlRecord&)));
    if (!status) {
        // TODO Error
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::openTable() {
    table->setTable(currentTable);
    updateTable();
}

void MainWindow::updateTable() {
    table->setEditStrategy(QSqlTableModel::OnFieldChange);
    setupTable();
    table->select();

    // table->setTitles(dbl->get_titles(currentTable));
    ui->tableView->setModel(table);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked);
    if (sortOrder) 
        ui->tableView->sortByColumn(sortedIndex, Qt::DescendingOrder);
    else
        ui->tableView->sortByColumn(sortedIndex, Qt::AscendingOrder);

}

void MainWindow::setupTable() {
    switch (currentTableIndex)
    {
    case 0:
        table->setRelation(6, QSqlRelation("statuses", "id", "title")); // <-- Link
        ui->tableView->setItemDelegateForColumn(6, new QSqlRelationalDelegate());
        ui->tableView->setItemDelegateForColumn(5, new DateDelegator());
        break;
    case 1:
        table->setRelation(3, QSqlRelation("nomenclature_type", "id", "title"));
        ui->tableView->setItemDelegateForColumn(3, new QSqlRelationalDelegate());
        table->setRelation(5, QSqlRelation("birth", "id", "title"));
        ui->tableView->setItemDelegateForColumn(5, new QSqlRelationalDelegate());
        table->setRelation(6, QSqlRelation("died", "id", "title"));
        ui->tableView->setItemDelegateForColumn(6, new QSqlRelationalDelegate()); 
        table->setRelation(4, QSqlRelation("bool", "id", "title"));
        ui->tableView->setItemDelegateForColumn(4, new QSqlRelationalDelegate()); 
        //ui->tableView->setItemDelegateForColumn(4, new BoolDelegator());
        break;
    case 2:
        table->setRelation(1, QSqlRelation("nomenclature_type", "id", "title"));
        ui->tableView->setItemDelegateForColumn(1, new QSqlRelationalDelegate());
        break;
    case 4:
        table->setRelation(7, QSqlRelation("positions", "id", "title"));
        ui->tableView->setItemDelegateForColumn(7, new QSqlRelationalDelegate());
        ui->tableView->setItemDelegateForColumn(6, new DateDelegator());
        break;
    case 6:
        currentTableIndex = 5;
    case 5:
        table->setRelation(2, QSqlRelation("users", "id", "mail"));
        ui->tableView->setItemDelegateForColumn(2, new QSqlRelationalDelegate());
        table->setRelation(3, QSqlRelation("nomenclature", "id", "code"));
        ui->tableView->setItemDelegateForColumn(3, new QSqlRelationalDelegate());
        table->setRelation(4, QSqlRelation("base", "id", "number"));
        ui->tableView->setItemDelegateForColumn(4, new QSqlRelationalDelegate());
        currentTableIndex = 7;
    case 7:
        ui->tableView->setItemDelegateForColumn(1, new TimeDelegator());
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
    if (currentTableIndex == 0) {

    }
    int row = table->rowCount();
    table->insertRow(row);
}

void MainWindow::acceptAll() {
    table->submitAll();
}

void MainWindow::deleteCurrentRow() {
    QItemSelectionModel *select = ui->tableView->selectionModel();
    for (const QModelIndex &selected : select->selectedRows()) {
        table->removeRow(selected.row());
    }
    table->select();
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Delete) {
        deleteCurrentRow();
    }
}

void MainWindow::sortBy(int index) {
    if (sortedIndex == index) {
        sortOrder = (sortOrder + 1) % 2;
    }
    sortedIndex = index;
    updateTable();
}

void MainWindow::rowUpdated(int row, QSqlRecord &record)
{
    if (currentTable == "price")
    {
        QString currDate = QDate::currentDate().toString("dd.MM.yyyy");
        QString newValueOfPrice = record.value(2).toString();
        QString productTitle = record.value(1).toString();
        QString productType = dbl->get_id_from_value("nomenclature_type",
                                                     productTitle);
        dbl->update_price_change(productType, newValueOfPrice, currDate);
        qDebug() << productType << newValueOfPrice << productTitle;
    }
}
