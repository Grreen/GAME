#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QFileDialog>
#include <QGraphicsGridLayout>
#include <QGraphicsLineItem>
#include <QLineF>
#include <QTextStream>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpinBox>

#include<iostream>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QPen pen;
//    pen.setStyle(Qt::DashLine);
//    pen.setCapStyle(Qt::RoundCap);
//    pen.setColor(Qt::red);
//    pen.setWidth(5);
//    qreal space = 5;
//    pen.setDashOffset(space);

}

MainWindow* MainWindow::mainInstance = 0;

MainWindow* MainWindow::GetInstance(QWidget *parent)
{
    if(mainInstance == NULL)
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

void New_Form::create_line()
{
//    first_layout = new QVBoxLayout;
//    second_layout = new QVBoxLayout;

    for (int i=0;i<count_players;i++)
    {
        QLabel *line = new QLabel("Имя "+QString::number(i+2)+"-го игрока:");
        QLineEdit *line_edit = new QLineEdit;
        first_layout->addWidget(line);
        second_layout->addWidget(line_edit);
    }

    body_layout->insertLayout(-1, first_layout,-1);
//    body_layout->addLayout(second_layout);


}

void New_Form::create_window(MainWindow *parent_window)
{
    parent_window->setVisible(false);
    New_Form *win = new New_Form;
    win->setWindowFlag(Qt::WindowSystemMenuHint);

    QLabel *text_label = new QLabel("Выберите количество игроков");
    QSpinBox *choose_count_playrs =  new QSpinBox;
    QPushButton *btn_ok_choose_players = new QPushButton("Выбрать");

    QVBoxLayout *main_layout = new QVBoxLayout;
    QVBoxLayout *header_layout = new QVBoxLayout;
    QHBoxLayout *header_body_layout = new QHBoxLayout;

    choose_count_playrs->setMinimum(2);
    choose_count_playrs->setMaximum(4);

    header_body_layout->addWidget(choose_count_playrs);
    header_body_layout->addWidget(btn_ok_choose_players);
    header_layout->addWidget(text_label);
    header_layout->addLayout(header_body_layout);
    main_layout->addLayout(header_layout);
    main_layout->addLayout(body_layout);
    win->setLayout(main_layout);

    win->show();

    connect(choose_count_playrs, SIGNAL(valueChanged(int)), win, SLOT(spinboxValueChanged(int)));
    connect(btn_ok_choose_players, SIGNAL(clicked()), win, SLOT(create_line()));
}

