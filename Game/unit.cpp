#include "unit.h"
#include <QGraphicsScene>
#include <QPoint>
#include <QPainter>

#include <QGraphicsEffect>
#include "game.h"
#include <iostream>

Unit::Unit(QPoint point,QGraphicsScene *scene, QString id_unit,QObject *parent):
    QGraphicsObject ()
{
    coord = point;
    health=max_health= 250;
    max_count_steps = count_steps = 6;
    demage = 100;


    QGraphicsDropShadowEffect *bodyShadow = new QGraphicsDropShadowEffect;
    bodyShadow->setBlurRadius(9.0);
    bodyShadow->setColor(QColor(0, 0, 0, 160));
    bodyShadow->setOffset(4.0);
    this->setGraphicsEffect(bodyShadow);
    this->setZValue(2);
    scene->addItem(this);
//    this->setActive(false);
//    this->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->setPos(coord);

    Game *game = Game::GetInstance();
    game->map.map[coord.y()/game->map.scene->size_items][coord.x()/game->map.scene->size_items] = -3;
}

QRectF Unit::boundingRect() const
{
//    return QRectF(-12,-15,24,30);
    Game *game = Game::GetInstance();
    return QRectF(0,0,game->map.scene->size_items,game->map.scene->size_items);
}

void Unit::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    painter->drawPixmap(coord.x()-50, coord.y()-50, QPixmap("10.png"));
    Game *game = Game::GetInstance();
    QPixmap pixmap = QPixmap("10.png").scaled(game->map.scene->size_items,game->map.scene->size_items);
    painter->drawPixmap(0,0,pixmap);
    painter->setPen(Qt::NoPen);
    for (int i=0;i<game->list_players.length();i++)
    {
        if(game->list_players[i]->list_units.indexOf(this)>=0)
            if(game->list_players[i]->move)
                painter->setBrush(Qt::green);
            else
                painter->setBrush(Qt::red);
    }
    painter->drawRect(10,0,(game->map.scene->size_items-20)*health/max_health, 5);

}

void Unit::hit()
{
    Game *game = Game::GetInstance();
    int index_player, index_attack_unit;
    for (int i=0;i<game->list_players.length();i++)
    {
        if(game->list_players[i]->move)
        {
            index_player = i;
            break;
        }
    }
    for (int i=0;i<game->list_players[index_player]->list_units.length();i++)
    {
        if(game->list_players[index_player]->list_units[i]->choose_unit)
        {
            index_attack_unit = i;
            break;
        }
    }
    health-=game->list_players[index_player]->list_units[index_attack_unit]->demage;
    if(health<=0)
        delete  this;
    this->update(0,0,game->map.scene->size_items, game->map.scene->size_items);
}

