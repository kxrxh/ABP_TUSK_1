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
#include <QtGui/QKeyEvent>
#include <QSqlRelationalDelegate>
#include "./delegators/datedelegate.h"
#include "./delegators/timedelegator.h"

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
    int sortedIndex = 0;
    void openTable();
    void updateTable();

    void setupTable();
public slots:
    void changeTable(int index);
    void addRow();
    void acceptAll();
    void deleteCurrentRow();
    void rowUpdated(int row, QSqlRecord &record);
private:
    std::vector<QString> tables_en;
    std::vector<QString> tables_ru;
    std::vector<std::vector<QString>> ru_columns;
    int sortOrder = 0;
    
    bool exists = false;
    Ui::MainWindow *ui;
   void keyPressEvent(QKeyEvent *event);
};
#endif // MAINWINDOW_H
