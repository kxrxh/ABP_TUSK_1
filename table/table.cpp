#include "./table.h"
#include "./ui_table.h"

Table::Table(QWidget *parent) 
    : QWidget(parent), ui(new Ui::Table) 
{
}

void Table::setData(std::vector<std::vector<QString>> data) {
    auto *layout = new QVBoxLayout(this);
    this->setLayout(layout);
    if (data.size() > 0) {
        tableWidget = new QTableWidget(data.size(), data[0].size(), this);
        for (int row = 0; row < data.size(); ++row) {
            for (int col = 0; col < data[0].size(); ++col) {
                tableWidget->setCellWidget(row, col, new QLabel(data[row][col]));
            }
        }
    } else {
        tableWidget = new QTableWidget(1, 1, this);
    }
    layout->addWidget(tableWidget);

}

void Table::setTitles(QStringList titles) {
        tableWidget->setHorizontalHeaderLabels(titles);
}

Table::~Table() {
    delete ui;
}