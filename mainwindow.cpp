#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "databaselib.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("main.db");
    DataBaseLib dbl(db);
    bool status = dbl.connect_to_base();
    if (status) {
        //...
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
