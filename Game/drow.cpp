#include "drow.h"
#include <QGraphicsItem>


void Drow::drow(QGraphicsScene *scene, QString name_pixmap, int x, int y)
{
    QGraphicsPixmapItem *item = scene->addPixmap(QPixmap(name_pixmap+".png"));
    item->setPos(x,y);
}
