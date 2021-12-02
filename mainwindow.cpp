#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "databaselib.h"
#include "table/table.h"
#include <iostream>

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
    tables_en.push_back(QString("birth"));
    tables_en.push_back(QString("died"));
    tables_en.push_back(QString("price_change"));
    comboBox = new QComboBox(this);
    for (int i = 0; i < 10; ++i) {
        comboBox->addItem(tables_ru[i]);
    }
    // setup UI
    ui->setupUi(this);
    ui->centralwidget->layout()->addWidget(comboBox);
    connect(comboBox, SIGNAL(currentIndexChanged(int)), SLOT(changeTable(int)));
    // setup database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("main.db");
    dbl = new DataBaseLib(db);
    bool status = dbl->connect_to_base();
    // currentTable = QString("nomenclature_type");
    table = new QSqlRelationalTableModel(this);
    openTable();
    // changeTable(0);
    std::vector<QString> values;
    for (int i = 0; i < 3; ++i) {
        values.push_back("213");
    }
    // dbl->insert_to_table("users", dbl->get_titles("users"), values);
    if (!status) {
        // TODO Error
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::openTable() {
    table->setTable("users");
    // table->setTitles(dbl->get_titles(currentTable));
    ui->tableView->setModel(table);
    // ui->mainLayout->addWidget(table);
}

void MainWindow::changeTable(int index) {
    currentTable = tables_en[index];
    openTable();
}
