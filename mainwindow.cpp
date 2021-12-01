#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "databaselib.h"
#include "table/table.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // setup UI
    ui->setupUi(this);
    // setup database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("main.db");
    dbl = new DataBaseLib(db);
    bool status = dbl->connect_to_base();
    currentTable = QString("nomenclature_type");
    openTable();
    if (!status) {
        // TODO Error
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::openTable() {
    table = new Table(this);
    table->setData(dbl->get_table(currentTable));
    table->setTitles(dbl->get_titles(currentTable));
    ui->mainLayout->addWidget(table);
}
