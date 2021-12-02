#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "databaselib.h"
#include "./delegators/datedelegator.h"
#include <QSqlRelationalDelegate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // setup names
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
    // currentTable = QString("nomenclature_type");
    table = new QSqlRelationalTableModel(this);
    openTable();
    connect(ui->addButton, SIGNAL(clicked()), SLOT(addRow()),
            Qt::UniqueConnection);
    connect(ui->submitButton, SIGNAL(clicked()), SLOT(accetpAll()),
            Qt::UniqueConnection);
    // changeTable(0);
    // dbl->insert_to_table("users", dbl->get_titles("users"), values);
    if (!status) {
        // TODO Error
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::openTable() {
    table->setTable(currentTable);
    table->setEditStrategy(QSqlTableModel::OnFieldChange);
    setupTable();
    table->select();

    // table->setTitles(dbl->get_titles(currentTable));
    ui->tableView->setModel(table);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked);

    // ui->mainLayout->addWidget(table);
}

void MainWindow::setupTable() {
    switch (currentTableIndex)
    {
    case 0:
        table->setRelation(6, QSqlRelation("statuses", "id", "title")); // <-- Link
        ui->tableView->setItemDelegateForColumn(6, new QSqlRelationalDelegate());
        break;
    case 1:
        table->setRelation(2, QSqlRelation("nomenclature_type", "id", "title"));
        ui->tableView->setItemDelegateForColumn(2, new QSqlRelationalDelegate());
        table->setRelation(4, QSqlRelation("birth", "id", "title"));
        ui->tableView->setItemDelegateForColumn(4, new QSqlRelationalDelegate());
        table->setRelation(5, QSqlRelation("died", "id", "title"));
        ui->tableView->setItemDelegateForColumn(5, new QSqlRelationalDelegate());
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

void MainWindow::accetpAll() {
    table->submitAll();
}
