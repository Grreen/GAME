#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "game.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow* MainWindow::mainInstance = 0;

MainWindow* MainWindow::GetInstance(QWidget *parent)
{
    if(!mainInstance)
        mainInstance = new MainWindow(parent);

    return mainInstance;
}

QGraphicsView* MainWindow::GetInstanceGraphicsView()
{
    return ui->graphicsView;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

}
