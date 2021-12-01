#ifndef TABLE_H
#define TABLE_H

#include <QWidget>
#include <QTableWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Table; }
QT_END_NAMESPACE

class Table : public QWidget {
    Q_OBJECT

public:
    Table(QWidget *parent = nullptr);
    ~Table();
    QTableWidget *tableWidget;
    void setData(std::vector<std::vector<QString>>);

private:
    Ui::Table *ui;
};
#endif

