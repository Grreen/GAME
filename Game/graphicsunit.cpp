#include "graphicsunit.h"
#include <QPixmap>
#include <QPainter>

GraphicsUnit::GraphicsUnit(Unit *unit, UnitsGraphicsScene *scene, int number, QObject *parent):
    QGraphicsObject ()
{
    this->unit = unit;
    this->scene = scene;
    this->number = number;

    scene->addItem(this);
}

QRectF GraphicsUnit::boundingRect() const
{
    return QRectF(0,0,120,120);
}

void GraphicsUnit::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap("../Game/"+QString::number(unit->id_unit)+".png");
    pixmap = pixmap.scaled(100,100,Qt::IgnoreAspectRatio);

    painter->drawPixmap(40+(unit->id_unit%2)*120,20,pixmap);
//    painter->setBrush(Qt::green);
//    painter->drawRect(0,0,100,100);
}
