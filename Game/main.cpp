#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsScene>

//#include "player.h"
//#include "map.h"
//#include "unit.h"
#include "mygraphicsscene.h"
#include "game.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow *w = MainWindow::GetInstance();
    w->showFullScreen();
    QGraphicsView *view = w->GetInstanceGraphicsView();
    view->setMinimumSize(QSize(w->width()-200,w->height()-100));
//    w->show();

    Game *game = Game::GetInstance();
    game->game_play = true;
    game->map.scene = new MyGraphicsScene;
    game->map.scene->scene = game->map.scene;
    game->map.drow_map();


    game->addPlayer("First", "01", 1);
    game->list_players[0]->move = true;
    game->addPlayer("Second", "01", 2);
    game->list_players[0]->addUnit(game->map.scene->size_items+50,game->map.scene->size_items+50,"10", game->map.scene, game->map.map);
    game->list_players[1]->addUnit(game->map.scene->size_items*2+50,game->map.scene->size_items*2+50,"10", game->map.scene, game->map.map);

//    game.list_players[0].list_units[0]->next_cell(game.map.scene,QPoint(0,0), QPoint(0,0), 10,10,game.map.map);
//    game.list_players[0].list_units[0]->attack(300);
//    game.list_players[0].list_units.removeAt(0);
//    std::cout<<game.list_players[0].list_units[0]->health<<std::endl;

//    QList <Player> players;
//    for (int i=0;i<2;i++) {
//        Player player;
//        players.append(player);
//    }

//    players[0].move = true;
//    int choose,choose_unit = 0;

//    while(game_play)
//    {
//        while(players[choose].move)
//        {
//            while(players[choose].list_units[choose_unit].move)
//            {

//            }
//        }
//    }


    return a.exec();
}
