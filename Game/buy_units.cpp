#include "buy_units.h"
#include "mainwindow.h"
#include "game.h"

#include <iostream>

Buy_units::Buy_units(QWidget *parent) : QWidget (parent)
{
    MainWindow *win = MainWindow::GetInstance();
    win->setEnabled(false);

    window = new QWidget(parent);
    window->setFixedSize(QSize(500,500));

    QPushButton *melle_first = new QPushButton();
    melle_first->setMinimumSize(QSize(200,200));
//    melle_first->setStyleSheet("border-image:url(10.png)");
    melle_first->setText("First");
//    connect(melle_first, SIGNAL(clicked()),this,SLOT(write()));//ok
    connect(melle_first, SIGNAL(clicked()), this, SLOT(buy_melle_first()));
    QPushButton *melle_second = new QPushButton();
    melle_second->setMinimumSize(melle_first->minimumSize());
    melle_second->setText("Second");
    connect(melle_second, SIGNAL(clicked()), this, SLOT(buy_melle_second()));
    QPushButton *range_first = new QPushButton();
    range_first->setMinimumSize(melle_first->minimumSize());
    range_first->setText("Third");
    connect(range_first, SIGNAL(clicked()), this, SLOT(buy_range_first()));
    QPushButton *range_second = new QPushButton();
    range_second->setMinimumSize(melle_first->minimumSize());
    range_second->setText("Forth");
    connect(range_second, SIGNAL(clicked()), this, SLOT(buy_range_second()));

    QVBoxLayout *main_layout = new QVBoxLayout;
    QHBoxLayout *firs_line = new QHBoxLayout;
    QHBoxLayout *second_line = new QHBoxLayout;

    firs_line->addWidget(melle_first);
    firs_line->addWidget(melle_second);
    second_line->addWidget(range_first);
    second_line->addWidget(range_second);
    main_layout->addLayout(firs_line);
    main_layout->addLayout(second_line);

//    Game *game = Game::GetInstance();

    window->setLayout(main_layout);
    window->show();

}

void Buy_units::buy_melle_first()
{
    Game *game = Game::GetInstance();

    game->list_players[0]->addUnit(game->map.scene->size_items-100,game->map.scene->size_items+50,"10",game->map.scene, game->map.map);
    MainWindow *win = MainWindow::GetInstance();
    win->setEnabled(true);
}

void Buy_units::buy_melle_second()
{

}

void Buy_units::buy_range_first()
{

}

void Buy_units::buy_range_second()
{

}
