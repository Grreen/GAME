#include "castle.h"
#include "game.h"
#include <QPoint>
#include <QGraphicsDropShadowEffect>
#include <QPainter>
#include <QString>

Castle::Castle(MyGraphicsScene *scene, QPoint coord_castle, QString id_image,QObject *parent):
     QGraphicsObject ()
{
    spawnPos = coord_castle;
    health = max_health = 1000;
    image_id = id_image;

    QGraphicsDropShadowEffect *bodyShadow = new QGraphicsDropShadowEffect;
    bodyShadow->setBlurRadius(9.0);
    bodyShadow->setColor(QColor(0, 0, 0, 160));
    bodyShadow->setOffset(4.0);
    this->setGraphicsEffect(bodyShadow);

    scene->addItem(this);
    this->setEnabled(false);
    this->setPos(coord_castle);
}

QRectF Castle::boundingRect() const
{
    Game *game = Game::GetInstance();
    return QRectF(0,0,game->map.scene->size_items,game->map.scene->size_items);
}

void Castle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Game *game = Game::GetInstance();
    QPixmap pixmap = QPixmap(image_id+".png").scaled(game->map.scene->size_items,game->map.scene->size_items);
    painter->drawPixmap(0,0,pixmap);
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::green);
    painter->drawRect(10,0,((game->map.scene->size_items-20)*health/max_health), 5);
}

void Castle::hit(int demage)
{
    health-=demage;
    this->update(0,0,100,100);
    if(health<=0)
        delete  this;
}
