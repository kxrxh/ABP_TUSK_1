#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QString>
#include <QButtonGroup>
#include <QComboBox>
#include <QSqlRelationalTableModel>
#include <QTableView>
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

    QString currentTable = "users";
    int currentTableIndex = 0;
    QComboBox *comboBox;
    void openTable();

    void setupTable();
public slots:
    void changeTable(int index);
    void addRow();
    void accetpAll();
private:
    std::vector<QString> tables_en;
    std::vector<QString> tables_ru;
    bool exists = false;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
