#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    Table *table;
    DataBaseLib *dbl;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
