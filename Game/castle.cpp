#include "castle.h"
#include "game.h"
#include <QPoint>
#include <QGraphicsDropShadowEffect>
#include <QPainter>
#include <QString>

Castle::Castle(MyGraphicsScene *scene, QPoint coord_castle, QString id_image,QObject *parent):
     QGraphicsObject ()
{
    coord = coord_castle;
    health = max_health = 1000;
    image_id = id_image;
    size_object = scene->size_items;

    Game *game = Game::GetInstance();
    game->map.map[coord.x()/size_object][coord.y()/size_object] = -3;

    QGraphicsDropShadowEffect *bodyShadow = new QGraphicsDropShadowEffect;
    bodyShadow->setBlurRadius(9.0);
    bodyShadow->setColor(QColor(0, 0, 0, 160));
    bodyShadow->setOffset(4.0);
    this->setGraphicsEffect(bodyShadow);
    this->setZValue(2);

    scene->addItem(this);
    this->setEnabled(false);
    this->setPos(coord_castle);
}

QRectF Castle::boundingRect() const
{
    return QRectF(0,0,size_object,size_object);
}

void Castle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Game *game = Game::GetInstance();
    QPixmap pixmap = QPixmap("../Game/"+image_id+".png").scaled(size_object,size_object);
    painter->drawPixmap(0,0,pixmap);
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::green);
    for (int i=0;i<game->list_players.length();i++)
    {
        if(game->list_players[i]->castle == this)
            if(game->list_players[i]->move)
                painter->setBrush(Qt::green);
            else
                painter->setBrush(Qt::red);
    }
    painter->drawRect(0,0,(size_object*health/max_health), 5);

    painter->setPen(Qt::black);
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(0,0,size_object, 5);

    int count_line = max_health/60;
    for (float i=size_object/count_line;i<size_object-(size_object/count_line);i+=size_object/count_line)
    {
        painter->drawLine(i,0,i,5);
    }
}
void Castle::hit()
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
            if(game->list_players[i]->castle == this)
            {
                delete this;
                game->list_players[i]->castle = 0;
                break;
            }
    }
    else
        this->update(0,0,size_object,size_object);
}

void Castle::resize(int size)
{
    size_object = size;
}
