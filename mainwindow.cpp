#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setTabText(0, "Приветствие");
    ui->tabWidget->setTabText(1, "Клиенты");
}

MainWindow::~MainWindow()
{
    delete ui;
}
