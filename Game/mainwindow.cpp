#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScrollBar>
#include <QFontDatabase>
#include "game.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int id = QFontDatabase::addApplicationFont("../Game/second.ttf");
    QFont font = QFont(QFontDatabase::applicationFontFamilies(id).first());
    font.setPixelSize(35);
    ui->pushButton->setFont(font);
    ui->pushButton->setStyleSheet("background:url(../Game/background-2.png);"
                                  "padding-left:10px;"
                                  "border: 3px solid rgb(64, 64, 64);"
                                  "color:white;");
    font.setPixelSize(17);
    ui->pushButton_2->setFont(font);
    ui->pushButton_2->setStyleSheet("background:url(../Game/background-2.png);"
                                    "border: 3px solid rgb(64, 64, 64);"
                                    "color:white;");
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(close()));

    QHBoxLayout *layout = new QHBoxLayout;
    this->setLayout(layout);
}

MainWindow* MainWindow::mainInstance = 0;

MainWindow* MainWindow::GetInstance(QWidget *parent)
{
    if(!mainInstance)
        mainInstance = new MainWindow(parent);

    return mainInstance;
}

QGraphicsView* MainWindow::GetInstanceGraphicsView(int number)
{
    switch (number)
    {
        case 1:
            return ui->graphicsView;
        break;
        case 2:
        return  ui->graphicsView_2;
        break;
        default:
        break;
    }
}

QPushButton* MainWindow::GetInstanceButton(int number)
{
    switch (number)
    {
        case 1:
        return ui->pushButton;
        case 2:
        return  ui->pushButton_2;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

