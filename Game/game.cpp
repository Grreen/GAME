#include "game.h"
#include "player.h"
#include "castle.h"
#include "mainwindow.h"
#include "datagraphicsscene.h"


#include <QMessageBox>
#include <QScrollBar>
#include <QFontDatabase>

void Game::addPlayer(QString name_player, QString id_image, int number_player)
{
    number_player++;
    Player *player = new Player;
    player->nomber_player = number_player;
    player->Name = name_player;
    player->image = QPixmap("../Game/"+id_image+".png");
    player->count_money = 500;
    switch (number_player)
    {
        case 1:
            player->castle = new Castle(this->map.scene, QPoint(this->map.scene->size_items*2,this->map.scene->size_items*2),"21");
            player->move = true;
        break;
        case 2:
            player->castle = new Castle(this->map.scene, QPoint(this->map.scene->width()-this->map.scene->size_items*3, this->map.scene->height()-this->map.scene->size_items*3), "21");
        break;
        case 3:
            player->castle = new Castle(this->map.scene, QPoint(this->map.scene->width()-this->map.scene->size_items*3,this->map.scene->size_items*2), "21");
        break;
        case 4:
            player->castle = new Castle(this->map.scene, QPoint(this->map.scene->size_items*2, this->map.scene->height()-this->map.scene->size_items*3), "21");
        break;
    }

    list_players.append(player);

}

Player* Game::move_player()
{
    for (int i=0;i<list_players.length();i++)
        if(list_players[i]->move)
            return list_players [i];
    return 0;
}

Game* Game::GameInstance = 0;

Game* Game::GetInstance()
{
    if(!GameInstance)
        GameInstance = new Game();

    return GameInstance;
}

void Game::disenable_window()
{
    MainWindow::GetInstance()->setEnabled(false);
}

void Game::enable_window()
{
    MainWindow::GetInstance()->setEnabled(true);
}

void Game::next_player()
{
    refresh_data_players();
    if(list_players.length()<2)
    {
        this->game_play = false;
        QMessageBox::information(MainWindow::GetInstance(),"Information", "Вот и всё");
    }
    else
    {
        Game *game = Game::GetInstance();
        for(int i=0;i<list_players.length();i++)
            if(list_players[i]->move == true)
            {
                list_players[i]->move = false;
                list_players[i]->refreshUnits();
                if(i<list_players.length()-1)
                {
                        game->graphicsScene->refresh_panel(list_players[i+1]);
                        list_players[i+1]->move = true;
                        willingness_player(list_players[i+1]);
                        game->graphicsView->verticalScrollBar()->setSliderPosition(list_players[i+1]->castle->pos().y()+game->map.scene->size_items/2-game->graphicsView->height()/2);
                        game->graphicsView->horizontalScrollBar()->setSliderPosition(list_players[i+1]->castle->pos().x()+game->map.scene->size_items/2-game->graphicsView->width()/2);
                        list_players[i+1]->refreshUnits();
                }
                else
                {
                    game->graphicsScene->refresh_panel(list_players.first());
                    list_players.first()->move = true;
                    willingness_player(list_players.first());
                    game->graphicsView->verticalScrollBar()->setSliderPosition(list_players.first()->castle->pos().y()+game->map.scene->size_items/2-game->graphicsView->height()/2);
                    game->graphicsView->horizontalScrollBar()->setSliderPosition(list_players.first()->castle->pos().x()+game->map.scene->size_items/2-game->graphicsView->width()/2);
                    list_players.first()->refreshUnits();

                    for (int j=0;j<game->list_players.length();j++)
                        game->list_players[j]->count_money+=25;

                    number_moves++;
                }
                break;
            }

        if(game->map.scene->way_drow)
        {
            for (int i=0;i<game->map.scene->line_group.length();i++)
                delete game->map.scene->line_group[i];
            game->map.scene->line_group.clear();
            game->map.scene->way_drow = false;
        }
    }
}

void Game::willingness_player(Player *player)
{
    MainWindow::GetInstance()->setEnabled(false);

    QWidget *window_qestion = new QWidget();

    QBrush *brush = new QBrush;
    QPalette *palette = new QPalette;
    brush->setTextureImage(QImage("../Game/background-2.png"));
    palette->setBrush(QPalette::Window, *brush);
    window_qestion->setPalette(*palette);
    window_qestion->setStyleSheet("color:white");


    QVBoxLayout *layout = new QVBoxLayout;
    QLabel *name_player = new QLabel("Игрок : "+player->Name);
    QLabel *text = new QLabel("Вы готовы к своему ходу?");
    QPushButton *button = new QPushButton("Да конечно");
    QHBoxLayout *button_layout = new QHBoxLayout;
//    connect(button, SIGNAL(clicked()), window_qestion, SLOT(close()));
//    connect(button, SIGNAL(clicked()), this, SLOT(enable_window()));
    connect(button, &QPushButton::clicked, [window_qestion,this](){window_qestion->close();delete window_qestion; this->enable_window();});

    int id = QFontDatabase::addApplicationFont("../Game/second.ttf");
    QFont font = QFont(QFontDatabase::applicationFontFamilies(id).first());

    layout->setAlignment(Qt::AlignCenter);
    button_layout->setAlignment(Qt::AlignHCenter);
    font.setPixelSize(100);
    name_player->setAlignment(Qt::AlignCenter);
    name_player->setFont(font);
    text->setAlignment(Qt::AlignCenter);
    text->setFont(font);
    font.setPixelSize(50);
    button->setFont(font);
    button->setFixedSize(QSize(900,70));
    button->setStyleSheet("background:url(../Game/background-3.png);"
                          "color:white;"
                          "border: 3px solid rgb(64, 64, 64);");

    button_layout->addWidget(button);
    layout->addWidget(name_player);
    layout->addWidget(text);
    layout->addLayout(button_layout);

    window_qestion->setLayout(layout);

    window_qestion->showFullScreen();

    DataGraphicsScene *scene = dynamic_cast<DataGraphicsScene*>(MainWindow::GetInstance()->GetInstanceGraphicsView(1)->scene());
    scene->refresh_scene(player);
}

void Game::refresh_data_players()
{
    for (int i=0;i<list_players.length();i++)
    {
        if(list_players[i]->list_units.length() > 0 || list_players[i]->castle)
        {
            for (int j=0;j<list_players[i]->list_units.length();j++)
                list_players[i]->list_units[j]->count_steps = list_players[i]->list_units[j]->max_count_steps;
        }
        else
        {
            delete list_players[i];
            list_players.removeAt(i);
        }
    }

}
