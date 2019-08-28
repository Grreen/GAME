#include "player.h"
#include "unit.h"
#include <QProgressBar>
#include <QPoint>

#include <QLayoutItem>

#include "mainwindow.h"
#include "graphicsview.h"
#include "unitsgraphicsscene.h"
#include "game.h"
#include "graphicsunit.h"
#include "graphicspanel.h"

void Player::addUnit(int x, int y, int id_unit, MyGraphicsScene *scene)
{
    QPoint point(x,y);
    Unit *unit = new Unit(point, scene, id_unit);
    list_units.append(unit);
}

void Player::refreshUnits()
{
    Game *game = Game::GetInstance();

    if(list_units.length()!=0)
    {
        for(int i=0;i<list_units.length();i++)
        {
            if(list_units[i]->choose_unit)
            {
                list_units[i]->choose_unit = false;
                emit game->map.scene->delete_unit_inst();
                QGraphicsDropShadowEffect *bodyShadow = new QGraphicsDropShadowEffect;
                bodyShadow->setBlurRadius(9.0);
                bodyShadow->setColor(QColor(0, 0, 0, 160));
                bodyShadow->setYOffset(-2.0);
                bodyShadow->setXOffset(5.0);
                list_units[i]->setGraphicsEffect(bodyShadow);
            }
            list_units[i]->update(0,0,game->map.scene->size_items, game->map.scene->size_items);

        }
    }
    if(castle)
        castle->update(0,0,game->map.scene->size_items, game->map.scene->size_items);

//    game->graphicsScene->refresh_panel(this);
}

Unit* Player::move_unit()
{
    for (int i=0;i<list_units.length();i++)
        if (list_units[i]->choose_unit)
            return list_units[i];
    return 0;
}
