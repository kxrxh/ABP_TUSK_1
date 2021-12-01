#include "./table.h"
#include "./ui_table.h"

Table::Table(QWidget *parent) 
    : QWidget(parent), ui(new Ui::Table) 
{
    ui->setupUi(this);
}

void Table::setData(std::vector<std::vector<QString>> data) {
    if (data.size() > 0) {
        ui->tableWidget->setColumnCount(data[0].size());
        ui->tableWidget->setRowCount(data.size());
        for (int row = 0; row < data.size(); ++row) {
            for (int col = 0; col < data[0].size(); ++col) {
                ui->tableWidget->setCellWidget(row, col, new QLabel(data[row][col]));
            }
        }
    } else {
        ui->tableWidget->setColumnCount(0);
    }
}

void Table::setTitles(QStringList titles) {
    ui->tableWidget->setHorizontalHeaderLabels(titles);
}

Table::~Table() {
    delete ui;
}