#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsScene>

#include "mygraphicsscene.h"
#include "game.h"
#include "choose_count_players.h"
#include "graphicspanel.h"
#include "datagraphicsscene.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow *w = MainWindow::GetInstance();
    w->showFullScreen();

    QGraphicsView *view_1 = w->GetInstanceGraphicsView(1);
    view_1->setGeometry(200,w->height()-200,w->width()-500, 200);
    view_1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view_1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    DataGraphicsScene *new_scene = new DataGraphicsScene(w);
    view_1->setScene(new_scene);
    new_scene->setSceneRect(view_1->rect());

    QGraphicsView *view_2 = w->GetInstanceGraphicsView(2);
    view_2->setGeometry(0,w->height()-200, 200, 201);
    QPushButton *button_1 = w->GetInstanceButton(1);
    button_1->setGeometry(w->width()-300,0,300,50);
    button_1->setText("ВЫЙТИ");
    QPushButton *button_2 = w->GetInstanceButton(2);
    button_2->setGeometry(w->width()-300,button_1->height(),300,50);
    button_2->setText("ХОД СЛЕДУЮЩЕГО ИГРОКА");


    Game *game = Game::GetInstance();
    game->game_play = true;//перенести все остальное в инициализацию Game
    game->map.scene = new MyGraphicsScene;
    game->map.scene->scene = game->map.scene;
    game->map.drow_map();

    Game::connect(button_2, SIGNAL(clicked()), game, SLOT(next_player()));

    Choose_count_players *wind = new Choose_count_players(w);

//    game->addPlayer("First", "01", 1);
//    game->addPlayer("Second", "01", 2);
//    game->addPlayer("Third", "01", 3);
//    game->addPlayer("Fourth", "01", 4);




    return a.exec();
}
