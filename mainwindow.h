#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCoreApplication>
#include <QFileDialog>
#include <QFileInfo>
#include <QFont>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QtWidgets>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <fstream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  QPushButton *BROWSE_BUTTON;
  QPushButton *OK_BUTTON;
  QTableWidget *FILES_TABLE;
  QLabel *FILES_DURATIONS;
  QPushButton *RESET_BUTTON;
  QPushButton *MODE_BUTTON;

private slots:
  void browseBtnEvent();
  void okBtnEvent();
  void resetBtnEvent();
  void modeBtnEvent();
};
#endif // MAINWINDOW_H
