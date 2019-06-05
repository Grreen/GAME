#include "game.h"
#include "player.h"
#include "castle.h"

void Game::addPlayer(QString name_player, QString id_image, int number_player)
{
    Player *player = new Player;
    player->nomber_player = number_player;
    player->Name = name_player;
    player->image = QPixmap(id_image+".png");
    player->castle = new Castle(this->map.scene, QPoint(0,0),"21");
    list_players.append(player);

}

Game* Game::GameInstance = 0;

Game* Game::GetInstance()
{
    if(GameInstance == NULL)
        GameInstance = new Game();

    return GameInstance;
}
