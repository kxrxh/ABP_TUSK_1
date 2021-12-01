#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "databaselib.h"
#include "table/table.h"
#include <QLabel>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("main.db");
    dbl = new DataBaseLib(db);
    bool status = dbl->connect_to_base();
    if (status) {
        std::vector<std::vector<QString>> t;
        t = dbl->get_table("nomenclature_type");
        table = new Table(this);
        table->setData(t);
        table->setTitles(dbl->get_titles("nomenclature_type"));
        ui->mainLayout->addWidget(table);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
