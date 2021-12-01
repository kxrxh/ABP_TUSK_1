#include "./table.h"
#include "./ui_table.h"

Table::Table(QWidget *parent) 
    : QWidget(parent), ui(new Ui::Table) 
{
    auto *layout = new QVBoxLayout(this);
    this->setLayout(layout);
    tableWidget = new QTableWidget(10, 10, this);
    layout->addWidget(tableWidget);
}

Table::~Table() {
    delete ui;
}