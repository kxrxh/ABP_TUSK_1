#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QString>
#include <QButtonGroup>
#include <QComboBox>
#include <QSqlRelationalTableModel>
#include <QTableView>
#include "table/table.h"
#include "databaselib.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QSqlRelationalTableModel  *table;
    DataBaseLib *dbl;

    QString currentTable;
    QComboBox *comboBox;
    void openTable();
public slots:
    void changeTable(int index);

private:
    std::vector<QString> tables_en;
    std::vector<QString> tables_ru;
    bool exists = false;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
