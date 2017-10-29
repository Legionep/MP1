#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->size_box->text()="42";

    //connect(ui->pbStart,SIGNAL(clicked()),SLOT(slotCapture()));
    //connect(ui->pbSort,SIGNAL(clicked()),SLOT(slotSort()));
    //connect(ui->comboBox,SIGNAL(currentTextChanged(QString)),SLOT(slotSwitchProtocol(QString)));

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::slotGenerate()
{
    int trash;
    size = ui->size_box->text().toInt();
    MyArray.clear();
    OutArray.clear();
    for(int i=0;size!=MyArray.size();i++)
    {
        trash = qrand()%10000-5000;
        MyArray.push_back(trash);
        OutArray.push_back(trash);
    }
    show_array();
}

void MainWindow::show_array()
{
    ui->textEdit->clear();
    for(int i=0;i<ui->size_box->text().toInt();i++)
    {
        ui->textEdit->append(QString(QString::number(MyArray[i])+" "));
    }
}

void MainWindow::slotInSort()
{
    QTime MyTime;

    string Puz_str;
    string Insert_str;
    string SortFunc_str;
    string QSortFunc_str;

    int Puz_time;
    int Insert_time;
    int SortFunc_time;
    int QSortFunc_time;

    MyTime.start();

    bool no_swap=false;
    bool swap=false;
    int trash;

    while(!no_swap)
    {
        swap=false;
        for(int i=0;i<size-1;i++)
        {

            if(MyArray[i]>MyArray[i+1])
            {
                trash=MyArray[i];
                MyArray[i]=MyArray[i+1];
                MyArray[i+1]=trash;
                swap=true;
            }

        }
        if(!swap) no_swap = true;
    }
      Puz_time = MyTime.restart;

    MyArray.clear();
    for(int i=0;i<size;i++) MyArray.push_back(OutArray[i]);


    MyTime.start();

    int min;
    int num_min;

    for(int i=0;i<size;i++)
    {
        min=MyArray[i];
        num_min=i;
        for(int j=i+1;j<size;j++)
        {
            if(MyArray[j]>min)
            {
                num_min=j;
                min=MyArray[j];
            }
        }
        trash=MyArray[num_min];
        MyArray[num_min]=MyArray[i];
        MyArray[i]=trash;
    }
    Insert_time = MyTime.restart();

    MyArray.clear();
    for(int i=0;i<size;i++) MyArray.push_back(OutArray[i]);


    MyTime.start();

    qSort(MyArray);

    QSortFunc_time = MyTime.restart();
    MyArray.clear();
    for(int i=0;i<size;i++) MyArray.push_back(OutArray[i]);


    MyTime.start();

    sort(MyArray.begin(),MyArray.end());

    SortFunc_time = MyTime.restart();
    MyArray.clear();
    for(int i=0;i<size;i++) MyArray.push_back(OutArray[i]);

    //============================

}


void MainWindow::slotOutSort()
{

}

