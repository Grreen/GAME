#include "unit.h"
#include <QGraphicsScene>
#include <QPoint>
#include <QPainter>

#include <QGraphicsEffect>
#include "game.h"
#include <iostream>

Unit::Unit(QPoint point,MyGraphicsScene *scene, int id_unit,QObject *parent):
    QGraphicsObject ()
{
    coord = point;
    switch (id_unit)
    {
        case 11:
            health=max_health= 250;
            max_count_steps = count_steps = 15;
            demage = 90;
        break;
        case 12:
            health=max_health= 400;
            max_count_steps = count_steps = 13;
            demage = 140;
        break;
        case 13:
            health=max_health= 150;
            max_count_steps = count_steps = 20;
            demage = 110;
        break;
        case 14:
            health=max_health= 200;
            max_count_steps = count_steps = 18;
            demage = 120;
        break;
        default:
        break;
    }
    this->id_unit = id_unit;
    image = QPixmap("../Game/"+QString::number(id_unit)+".png");

    size_object = scene->size_items;

    QGraphicsDropShadowEffect *bodyShadow = new QGraphicsDropShadowEffect;
    bodyShadow->setBlurRadius(9.0);
    bodyShadow->setColor(QColor(0, 0, 0, 160));
    bodyShadow->setYOffset(-2.0);
    bodyShadow->setXOffset(5.0);

    this->setGraphicsEffect(bodyShadow);

    this->setZValue(2);
    scene->addItem(this);
    this->setPos(coord);

    Game *game = Game::GetInstance();
    game->map.map[coord.x()/game->map.scene->size_items][coord.y()/game->map.scene->size_items] = -3;
}

QRectF Unit::boundingRect() const
{
//    return QRectF(-12,-15,24,30);
    Game *game = Game::GetInstance();
    return QRectF(0,0,size_object,size_object);
}

void Unit::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Game *game = Game::GetInstance();
    painter->drawPixmap(0,0,image.scaled(size_object,size_object));
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::green);
    for (int i=0;i<game->list_players.length();i++)
    {
        if(game->list_players[i]->list_units.indexOf(this)>=0)
            if(game->list_players[i]->move)
                painter->setBrush(Qt::green);
            else
                painter->setBrush(Qt::red);
    }
    painter->drawRect(10,0,(size_object-20)*health/max_health, 5);

    painter->setPen(Qt::black);
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(10,0,size_object-20, 5);

    int count_line = max_health/50;

    for (int i=10+(size_object-20)/count_line;i<size_object-20;i+=(size_object-20)/count_line)
        painter->drawLine(i,0,i,5);
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
    {
        for (int i=0;i<game->list_players.length();i++)
            if(game->list_players[i]->list_units.indexOf(this)>=0)
                game->list_players[i]->list_units.removeOne(this);
        delete  this;
    }
    else
        this->update(0,0,size_object, size_object);
//    game->map.scene->update();
}

void Unit::resize(int size)
{
    size_object = size;
}

