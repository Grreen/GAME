#include "drow.h"
#include <QGraphicsItem>
#include <QCursor>
#include <QPixmap>


void Drow::drow(QGraphicsScene *scene, QString name_pixmap, int x, int y, int width_item)
{
    QPixmap pixmap(name_pixmap+".png");
    QPixmap new_pixmap = pixmap.scaled(width_item,width_item, Qt::IgnoreAspectRatio);
    QGraphicsPixmapItem *item = scene->addPixmap(new_pixmap);
    item->setPos(x,y);
    item->setEnabled(false);
}

