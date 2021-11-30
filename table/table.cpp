#include "./table.h"
#include "./ui_table.h"

Table::Table(QWidget *parent) : QWidget(parent), ui(new Ui::Table) {
}

Table::~Table() {
    delete ui;
}