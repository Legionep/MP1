#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QObject>
#include <QTime>
#include <QDateTime>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


namespace Ui {class MainWindow;}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private:
    void swap(int a,int b);
    void show_array();
    int size;
    vector<int> MyArray;
    vector<int> OutArray;


private slots:
    void slotGenerate();
    void slotInSort();
    void slotOutSort();

};

#endif // MAINWINDOW_H
