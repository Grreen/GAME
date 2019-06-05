#ifndef GAME_H
#define GAME_H

#include "map.h"
#include "player.h"
#include <QList>

class Game
{
public:
    Map map;
    QList <Player*> list_players;

    bool game_play = false;

    void addPlayer(QString name_player, QString id_image, int number_player);
    static Game* GetInstance();
    static Game* GameInstance;
};

#endif // GAME_H
