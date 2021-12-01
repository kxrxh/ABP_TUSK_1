#ifndef TABLE_H
#define TABLE_H

#include <QWidget>
#include <QTableWidget>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class Table; }
QT_END_NAMESPACE

class Table : public QWidget {
    Q_OBJECT

public:
    Table(QWidget *parent = nullptr);
    ~Table();
    void setData(std::vector<std::vector<QString>> data);
    void setTitles(QStringList titles);

private:
    Ui::Table *ui;
};
#endif

