#include "buy_units.h"
#include "mainwindow.h"
#include "game.h"
#include "graphicspanel.h"
#include "datagraphicsscene.h"
#include <QMessageBox>
#include <QFontDatabase>

#include <iostream>

Buy_units::Buy_units(QWidget *parent) : QWidget (parent)
{
    MainWindow::GetInstance()->setEnabled(false);

    int id = QFontDatabase::addApplicationFont("../Game/second.ttf");
    QFont font = QFont(QFontDatabase::applicationFontFamilies(id).first());

    window = new QWidget(parent);
    window->setFixedSize(QSize(500,500));
    window->setWindowFlag(Qt::ToolTip);

    QBrush *brush = new QBrush;
    QPalette *palette = new QPalette;
    brush->setTextureImage(QImage("../Game/background-2.png"));
    palette->setBrush(QPalette::Window, *brush);
    window->setPalette(*palette);

    QPushButton *melle_first = new QPushButton();
    melle_first->setMinimumSize(QSize(200,200));
    font.setPixelSize(30);
    melle_first->setFont(font);
    melle_first->setStyleSheet("QPushButton { border-image: url(../Game/11.png);"
                               "text-align:top;"
                               "color:white;}");

    melle_first->setText("150$");
    connect(melle_first, &QPushButton::clicked, [this](){this->buy_unit(1);});

    QPushButton *melle_second = new QPushButton();
    melle_second->setMinimumSize(melle_first->minimumSize());
    melle_second->setStyleSheet("QPushButton { border-image: url(../Game/12.png);"
                                "text-align:top;"
                                "color:white;}");
    melle_second->setFont(font);
    melle_second->setText("250$");
    connect(melle_second, &QPushButton::clicked, [this](){this->buy_unit(2);});

    QPushButton *range_first = new QPushButton();
    range_first->setMinimumSize(melle_first->minimumSize());
    range_first->setStyleSheet("QPushButton { border-image: url(../Game/13.png);"
                               "text-align:top;"
                               "color:white;}");
    range_first->setFont(font);
    range_first->setText("100$");
    connect(range_first, &QPushButton::clicked, [this](){this->buy_unit(3);});

    QPushButton *range_second = new QPushButton();
    range_second->setMinimumSize(melle_first->minimumSize());
    range_second->setStyleSheet("QPushButton { border-image: url(../Game/14.png);"
                                "text-align:top;"
                                "color:white;}");
    range_second->setFont(font);
    range_second->setText("150$");
    connect(range_second, &QPushButton::clicked, [this](){this->buy_unit(4);});

    QPushButton *exit_button = new QPushButton();
    font.setPixelSize(30);
    exit_button->setFont(font);
    exit_button->setStyleSheet("background:url(../Game/background-3.png);"
                               "color:white;"
                               "border: 3px solid rgb(64, 64, 64);");
    exit_button->setText("ВЫХОД!");
    connect(exit_button, SIGNAL(clicked()), this, SLOT(close_window()));


    QVBoxLayout *main_layout = new QVBoxLayout;
    QHBoxLayout *firs_line = new QHBoxLayout;
    QHBoxLayout *second_line = new QHBoxLayout;

    firs_line->addWidget(melle_first);
    firs_line->addWidget(melle_second);
    second_line->addWidget(range_first);
    second_line->addWidget(range_second);
    main_layout->addLayout(firs_line);
    main_layout->addLayout(second_line);
    main_layout->addWidget(exit_button);


//    Game *game = Game::GetInstance();

    window->setLayout(main_layout);
    window->show();

}

void Buy_units::buy_unit(int id_unit)
{
    Game *game = Game::GetInstance();
    int index_player;
    int max_cost;
    switch (id_unit)
    {
        case 1:
            max_cost=150;
        break;
        case 2:
            max_cost=250;
        break;
        case 3:
            max_cost=100;
        break;
        case 4:
            max_cost=150;
        break;
    }
    for (int i=0;i<game->list_players.length();i++)
        if(game->list_players[i]->move)
        {
            if(game->list_players[i]->count_money>=max_cost && game->list_players[i]->list_units.length()<10)
            {
                game->list_players[i]->count_money-=max_cost;
                int x,y;
                x = game->list_players[i]->castle->pos().x();
                y = game->list_players[i]->castle->pos().y();
                    if(game->map.map[x/game->map.scene->size_items + 1][y/game->map.scene->size_items]==-2)
                    {
                        game->list_players[i]->addUnit(x+game->map.scene->size_items,y,10+id_unit,game->map.scene);
                        game->list_players[i]->list_units.back()->nomber_unit = game->list_players[i]->list_units.length();
                    }
                    else if(game->map.map[x/game->map.scene->size_items][y/game->map.scene->size_items +1]==-2)
                    {
                        game->list_players[i]->addUnit(x,y+game->map.scene->size_items,10+id_unit,game->map.scene);
                        game->list_players[i]->list_units.back()->nomber_unit = game->list_players[i]->list_units.length();
                    }
                    else if(game->map.map[x/game->map.scene->size_items -1][y/game->map.scene->size_items]==-2)
                    {
                        game->list_players[i]->addUnit(x-game->map.scene->size_items,y,10+id_unit,game->map.scene);
                        game->list_players[i]->list_units.back()->nomber_unit = game->list_players[i]->list_units.length();
                    }
                    else if(game->map.map[x/game->map.scene->size_items][y/game->map.scene->size_items - 1]==-2)
                    {
                        game->list_players[i]->addUnit(x,y-game->map.scene->size_items,10+id_unit,game->map.scene);
                        game->list_players[i]->list_units.back()->nomber_unit = game->list_players[i]->list_units.length();
                    }
                    else
                        QMessageBox::warning(this->window,"","Место спавна занято", QMessageBox::Ok);

                    game->graphicsScene->refresh_panel(game->list_players[i]);

                    DataGraphicsScene *scene = dynamic_cast<DataGraphicsScene*>(MainWindow::GetInstance()->GetInstanceGraphicsView(1)->scene());
                    scene->refresh_scene(game->move_player());

                    break;
            }
            else if(game->list_players[i]->count_money>=max_cost)
                QMessageBox::warning(this->window,"","Превышено количество юнитов(10)!", QMessageBox::Ok);
            else
                QMessageBox::warning(this->window,"","Не хватает монет для покупки!", QMessageBox::Ok);
        }

    MainWindow::GetInstance()->setEnabled(true);
}


void Buy_units::close_window()
{
    MainWindow *win = MainWindow::GetInstance();
    win->setEnabled(true);
    this->window->close();
    delete this;
}
